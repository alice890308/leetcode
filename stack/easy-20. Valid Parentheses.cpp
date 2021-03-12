#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        int len = s.size();
        for(int i = 0; i < len; i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                stk.push(s[i]);
            }
            else if (s[i] == ')') {
                if (!stk.empty() && stk.top() == '(') {
                    stk.pop();
                } else {
                    return false;
                }
            }
            else if (s[i] == ']') {
                if (!stk.empty() && stk.top() == '[') {
                    stk.pop();
                } else {
                    return false;
                }
            }
            else if (s[i] == '}') {
                if (!stk.empty() && stk.top() == '{') {
                    stk.pop();
                } else {
                    return false;
                }
            }
        }
        if (stk.empty())
            return true;
        return false;
    }
};
