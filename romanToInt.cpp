class Solution {
public:
    int romanToInt(string s) {
        int n=0;
        for(int i=0;i<s.length();){            
            if(s[i]=='I'){
                if(i+1>s.length()) break; 
                else if(s[i+1]=='V'){
                    n=n+4;
                    i=i+2;
                }
                else if(s[i+1]=='X'){
                    n=n+9;
                    i=i+2;
                }
                else{
                    n=n+1;
                    i=i+1;
                }
            }
             if(s[i]=='V'){
                 n=n+5;
                 i=i+1;
            }
             if(s[i]=='X'){
                if(i+1>s.length()) break; 
                else if(s[i+1]=='L'){
                    n=n+40;
                    i=i+2;
                }
                else if(s[i+1]=='C'){
                    n=n+90;
                    i=i+2;
                }
                else{
                    n=n+10;
                    i=i+1;
                }
            }
             if(s[i]=='L'){
                 n=n+50;
                 i=i+1;
            }
             if(s[i]=='C'){
                if(i+1>s.length()) break; 
                else if(s[i+1]=='D'){
                    n=n+400;
                    i=i+2;
                }
                else if(s[i+1]=='M'){
                    n=n+900;
                    i=i+2;
                }
                else{
                    n=n+100;
                    i=i+1;
                }
            }
            if(s[i]=='D'){
                 n=n+500;
                 i=i+1;
            }          
            if(s[i]=='M'){
                 n=n+1000;
                 i=i+1;
            }            
        
            
           } 
        return n;
        }
    
};
