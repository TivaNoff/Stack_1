#include <iostream>
#include <stack>
#include <unordered_map>

bool isValid(std::string s) {
    std::stack<char> st;
    std::unordered_map<char, char> parenthesesMap = {
        {')', '('},
        {'}', '{'},
        {']', '['}
    };

    for (char ch : s) {
        if (parenthesesMap.find(ch) != parenthesesMap.end()) {
            char topElement = st.empty() ? '#' : st.top();
            if (topElement != parenthesesMap[ch]) {
                return false;
            }
            st.pop();
        }
        else {
            st.push(ch);
        }
    }

    return st.empty();
}

int main() {
    std::string input1 = "()";
    std::string input2 = "()[]{}";
    std::string input3 = "(]";

    std::cout << std::boolalpha;

    std::cout << "Input: " << input1 << " Output: " << isValid(input1) << std::endl;
    std::cout << "Input: " << input2 << " Output: " << isValid(input2) << std::endl;
    std::cout << "Input: " << input3 << " Output: " << isValid(input3) << std::endl;

    return 0;
}
