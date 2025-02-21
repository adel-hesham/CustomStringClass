#include "string.hpp"

int main() 
{
    string s1;
    string s2("Hello");
    string s3(" World!");

    string s4 = s2;
    string s5;
    s5 = s3;

    string s6 = std::move(s5);
    string s7;
    s7 = std::move(s6);

    s1 = "Embedded Systems";

    string s8 = s2 + s3;

    std::cout << "s1: " << s1 << " | Empty: " << s1.empty() << std::endl;
    std::cout << "s2: " << s2 << " | Size: " << s2.size() << std::endl;
    std::cout << "s3: " << s3 << " | Size: " << s3.size() << std::endl;
    std::cout << "s4: " << s4 << std::endl;
    std::cout << "s5: " << s5 << std::endl;
    std::cout << "s6: " << s6 << std::endl;
    std::cout << "s7: " << s7 << std::endl;
    std::cout << "Concatenation: " << s8 << std::endl;
    
    std::cout << "s2 == s4: " << (s2 == s4) << std::endl;
    std::cout << "s2 != s3: " << (s2 != s3) << std::endl;
    std::cout << "s2 > s3: " << (s2 > s3) << std::endl;
    std::cout << "s2 < s3: " << (s2 < s3) << std::endl;

    std::cout << "s2[1]: " << s2[1] << std::endl;
    s2[1] = 'a';
    std::cout << "s2 after modification: " << s2 << std::endl;

    s3.clear();
    std::cout << "s3 after clear: " << s3 << " | Empty: " << s3.empty() << std::endl;

    std::cout << "Enter a word: ";
    string input;
    std::cin >> input;
    std::cout << "You entered: " << input << std::endl;

    return 0;
}
