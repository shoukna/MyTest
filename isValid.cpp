class Solution {
public:
    bool isValid(string s) {
        stack<char>s1;
        for(int i=0;i<s.length();i++){
            if(s[i]=='['||s[i]=='('||s[i]=='{'){
                s1.push(s[i]);
            }
            else{
                if(s1.empty()) return false;
                if(s[i]=='}'&&s1.top()=='{'){
                    s1.pop();
                    continue;
                }
                if(s[i]==')'&&s1.top()=='('){
                    s1.pop();
                    continue;
                }
                if(s[i]==']'&&s1.top()=='['){
                    s1.pop();
                    continue;
                }   
                else return false;
                
            }
        }
        if(s1.empty())return true;
        else return false;
        

    }
};
