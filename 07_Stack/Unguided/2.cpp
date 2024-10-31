#include <iostream>
#include <stack>
#include <string>


void reverseCharacters(const std::string &sentence) {
   std::stack<char> characters;

    for (char ch : sentence) {
        characters.push(ch);
    }

    std::cout << "DataStack array :\n";
    std::cout << "Data : ";

    while (!characters.empty()) {
        std::cout << characters.top();
        characters.pop();
    }
    std::cout << std::endl;
}

int main() {
    std::string input;

    std::cout << "Masukan kata : ";
    std::getline(std::cin, input);

    reverseCharacters(input);
    
    return 0;

}
