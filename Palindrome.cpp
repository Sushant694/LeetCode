#include <iostream>
#include <cctype>
class CheckPalindrome {
public: 
    bool isPalindrome(std::string s) {
        bool check = false;
        std::string result = "";
        std::string Reverse = "";    // To store the reverse number
        for(char c : s) {
            // removing the spaces and non-alpha characters
            if(c != ' ' && std::isalnum(c)) {
                char Lower_Case = std::tolower(c);
                result += Lower_Case;
            }
        }

        for(int i = result.length() - 1; i >= 0; i--) {
            Reverse += result[i];
        }

        return result == Reverse;
    }
};

int main() {
    std::string s = "A man, a plan, a canal: Panama";
    CheckPalindrome obj;
    bool result = obj.isPalindrome(s);
    std::cout << "The given string is: " << std::boolalpha << result << '\n';
    return 0;
}