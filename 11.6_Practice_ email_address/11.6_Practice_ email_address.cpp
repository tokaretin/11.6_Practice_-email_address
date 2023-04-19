#include <iostream>
#include <string>

std::string first_part_email(std::string str) {
    std::string firstPartEmail;
    for (int i = 0; str[i] != '@'; i++) {
        if (i == str.length() - 1)break;
        firstPartEmail += str[i];
    }
    return firstPartEmail;
}

bool error_or_not(std::string str) {
    if (first_part_email(str).length() == str.length()) return false;
}

bool first_part_is_valid(std::string str) {
    if (!error_or_not(str)) return false;
    std::string validCharFirstPart = "!#$%&'*+-.0123456789/=?ABCDEFGHIJKLMNOPQRSTUVWXYZ^_`abcdefghijklmnopqrstuvwxyz{|}~";
    if (first_part_email(str).length() < 1 || first_part_email(str).length() > 64) return false;

    bool match = false;

    for (int i = 0; i < first_part_email(str).length(); i++) {
        match = false;
        if (first_part_email(str)[0] == '.' || first_part_email(str)[first_part_email(str).length() - 1]
            == '.' || first_part_email(str)[i] == '.' && first_part_email(str)[i]
            == first_part_email(str)[i + 1] && first_part_email(str)[i] == '.') return false;
        for (int j = 0; j < validCharFirstPart.length(); j++) {
            if (first_part_email(str)[i] == validCharFirstPart[j]) {
                match = true;
                break;
            }
        }
        if (!match) break;
    }

    if (match) {
        return true;
    }
    else {
        return false;
    }
}


bool second_part_is_valid(std::string str) {
    if (!error_or_not(str)) return false;
    std::string validCharSecondPart = "-.0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    std::string secondPartEmail;
    for (int i = first_part_email(str).length() + 1; i < str.length(); i++) {
        secondPartEmail += str[i];
    }
    if (secondPartEmail.length() < 1 || secondPartEmail.length() > 63) return false;

    bool match = false;

    for (int i = 0; i < secondPartEmail.length(); i++) {
        if (secondPartEmail[0] == '.' || secondPartEmail[secondPartEmail.length() - 1] == '.' ||
            secondPartEmail[i] == '.' && secondPartEmail[i] == secondPartEmail[i + 1] && secondPartEmail[i] == '.')
            return false;
        match = false;
        for (int j = 0; j < validCharSecondPart.length(); j++) {
            if (secondPartEmail[i] == validCharSecondPart[j]) {
                match = true;
                break;
            }
        }
        if (!match) break;
    }

    if (match) {
        return true;
    }
    else {
        return false;
    }
}

int main() {
    std::string email;
    std::cout << "Input the e-Mail address:" << '\n';
    std::cin >> email;
    std::cout << (first_part_is_valid(email) && second_part_is_valid(email) ? "Yes!" : "No!");
}