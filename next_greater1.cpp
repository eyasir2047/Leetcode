class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        //int size1=nums1.size();
        int size2=nums2.size();

        unordered_map<int,int>mp;
        stack<int>st;
        for(int i=size2-1;i>=0;i--){
            int element=nums2[i];
            while(!st.empty() && st.top()<=element)
            st.pop();

            int res=0;
            if(st.empty())
                res=-1;
            
            else // st.top>nums2[i]
            res=st.top();

            mp.insert({element,res});

            st.push(element);
        }

        vector<int>ans;
        for(auto x: nums1){
            ans.push_back(mp[x]);
        }
        return ans;

        
    }   
};