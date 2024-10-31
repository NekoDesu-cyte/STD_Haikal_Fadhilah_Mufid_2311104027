#include <iostream>
#include <stack>
#include <string>
#include <algorithm>

bool isPalindrom(const std::string &str) {
    std::stack<char> S;
    std::string reversed;

    for (char ch : str) {
        S.push(ch);
    }
    while (!S.empty()) {
        reversed += S.top();
        S.pop();
    }
    return str == reversed;
}

int main () {
    std::string kalimat;

    std::cout << "Masukan kalimat : ";
    std::getline(std::cin, kalimat);

    kalimat.erase(std::remove(kalimat.begin(), kalimat.end(), ' '), kalimat.end());

    if(isPalindrom(kalimat)) {
        std::cout << "kalimat tersebut merupakan kalimat palindrom" << std::endl;
    } else {
    std::cout << "Kalimat tersebut adalah bukan kalimat palindrom" << std::endl;
    }
    return 0;
}