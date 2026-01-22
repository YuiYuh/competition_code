#include<iostream>
using namespace std;
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> st;
        for(int i = 0; i < tokens.size(); i++){
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/"){
                long long num1 = st.top();
                st.pop();
                long long num2 = st.top();
                st.pop();
               if(tokens[i] == "+") st.push(num1 + num2); 
               if(tokens[i] == "-") st.push(num2 - num1);
               if(tokens[i] == "*") st.push(num1 * num2);
               if(tokens[i] == "/") st.push(num2 / num1);
            }else{
                st.push(stoll(tokens[i]));
            }
        }
        long long result = st.top();
        st.pop();
        return result;
    }
};