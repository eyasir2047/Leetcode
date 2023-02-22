#include<iostream>
using namespace std;
#include<stack>
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int>st;
        int j=0;
        for(int i=0;i<pushed.size();i++){
            st.push(pushed[i]);
            while(!st.empty() && j<popped.size() && st.top()==popped[j]){
                st.pop();
                j++;
            }
        }

        if(j==popped.size()) return true;


        return false;

    }
};
int main(){
    
}