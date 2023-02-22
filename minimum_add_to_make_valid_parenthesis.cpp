class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char>st;
        int n=s.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push(s[i]);
            }
            else{
                if(st.empty()) st.push(s[i]);
                else{
                    char ch=st.top();
                    //st.pop();
                    if(ch=='('){
                            st.pop();
                    }
                    else{
                        st.push(s[i]);
                    }
                }
            }
        }

        int k=st.size();
        return k;
    }
};