// Problem Link : https://leetcode.com/problems/valid-parentheses/


class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for(auto& ch : s){
            if(ch == '[' || ch == '{' || ch == '(')
                stk.push(ch);
            else if(!stk.empty()){
                if(ch == ']' && stk.top() != '[') return false;
                if(ch == ')' && stk.top() != '(') return false;
                if(ch == '}' && stk.top() != '{') return false;
                stk.pop();
            }
            else
                return false;
        }
        return stk.empty();
    }
};