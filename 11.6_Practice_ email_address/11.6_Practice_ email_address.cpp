#include <iostream>

using namespace std;

/*функция checkDotAndAt(string str) проверяет наличие 
символов "@" и "." в строке. Она возвращает false, если 
один из этих символов отсутствует в начале или конце строки. 
Далее, эта функция проверяет, что символ "." не встречается 
подряд, и возвращает false, если символ "@" встречается более 
одного раза. Возвращаемое значение типа bool.*/
bool checkDotAndAt(string str) {
    if (str[0] == '.' || str[str.length() - 1] == '.') { return false; }
    if (str[0] == '@' || str[str.length() - 1] == '@') { return false; }
    bool statusDot = true;
    bool statusAt = false;
    for (unsigned int i = 1; i < str.length() - 1; i++) {
        if (str[i] == '.') {
            if (!statusDot) { return false; }
            statusDot = false;
        }   
        else {
            statusDot = true;
        }
        if (str[i] == '@') {
            if (statusAt) { return false; }
            statusAt = true;
        }
    }
    return statusAt;
}

/*функция checkChar(char ch) проверяет, является ли 
переданный символ допустимым для email-адреса. Возвращает 
true, если символ является буквой (a-z, A-Z), цифрой (0-9), 
точкой "." или дефисом "-". Возвращаемое значение типа bool.*/
bool checkChar(char ch) {
    bool result = false;
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9') || ch == '.' || ch == '-') {
        result = true;
    }
    return result;
}

/*функция checkSpecChars(char ch) проверяет, является ли 
переданный символ специальным символом, которые могут 
использоваться в email-адресах. Список специальных символов 
определяется внутри функции. Если символ является одним из 
специальных символов, то функция возвращает true, в противном 
случае - false. Возвращаемое значение типа bool.*/
bool checkSpecChars(char ch) {
    string allowedChar = "!#$%&'*+-/=?^_`{|}~";
    for (unsigned int i = 0; i < allowedChar.length(); i++) {
        if (allowedChar[i] == ch) return true;
    }
    return false;
}

/*функция indexChar(string str, char ch) находит индекс
первого вхождения символа ch в строке str. Если символ не 
найден, то функция возвращает -1. Возвращаемое значение типа int.*/
int indexChar(string str, char ch) {
    int index = -1;
    for (unsigned int i = 0; i < str.length(); i++) {
        if (str[i] == ch) {
            index = i;
            return index;
        }
    }
    return index;
}

/* функция getSubStr(string str, int begin, int end) 
возвращает подстроку str, начинающуюся с индекса begin и 
заканчивающуюся индексом end. Возвращаемое значение типа string.*/
string getSubStr(string str, int begin, int end) {
    string result;
    for (int i = begin; i < end; i++) {
        result += str[i];
    }
    return result;
}

/*функция beforeAt(string str) проверяет, что все символы 
перед символом "@" допустимы для email-адреса. Эта функция 
возвращает false, если длина перед символом "@" больше 64 
или меньше 1, или если встречается символ, который не допустим 
для email-адреса. Возвращаемое значение типа bool.*/
bool beforeAt(string str) {
    if (str.length() > 64 || str.length() < 1) return false;
    for (int i = 0; i < str.length(); i++) {
        if (!(checkChar(str[i]) || checkSpecChars(str[i]))) return false;
    }
    return true;
}

/*функция afterAt(string str) проверяет, что все символы 
после символа "@" допустимы для email-адреса. Она возвращает 
false, если длина после символа "@" больше 63 или меньше 1, 
или если встречается символ, который не допустим для email-адреса. 
Возвращаемое значение типа bool.*/
bool afterAt(string str) {
    if (str.length() > 63 || str.length() < 1) return false;
    for (int i = 0; i < str.length(); i++) {
        if (!checkChar(str[i])) return false;
    }
    return true;
}

/*функция isValidEmail(string str) проверяет, является ли 
переданная строка действительным email-адресом. Она использует 
предыдущие функции для проверки наличия символов "@" и ".", 
корректности символов до и после "@", и возвращает true, если все провер*/
bool isValidEmail(string str) {

    bool result = false;
    if (!checkDotAndAt(str)) return result;

    if (beforeAt(getSubStr(str, 0, indexChar(str, '@')))
        && afterAt(getSubStr(str, indexChar(str, '@') + 1, str.length()))) {
        result = true;
    }
    return result;
}

int main()
{
    cout << "Enter your email: ";
    string email;
    cin >> email;
    cin.ignore(32767, '\n');

    cout << (isValidEmail(email) ? "Yes" : "No");

    return 0;
}