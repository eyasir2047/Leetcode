#include<bits/stdc++.h>
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int>left;
       stack<pair<int,int>>s;
      // stack<int>s;
        int n=heights.size();
        for(int i=0;i<n;i++){
            if(s.empty()) left.push_back(-1);
            else if(s.size()>0 && s.top().first<heights[i]) 
            left.push_back(s.top().second);
            else if(s.size()>0 && s.top().first>=heights[i]){
               while(s.size()>0 && s.top().first>=heights[i]) s.pop();
               if(s.empty()) left.push_back(-1);
               else left.push_back(s.top().second);
            }
            s.push({heights[i],i});
        }

        while(!s.empty()) s.pop();

        vector<int>right;

        for(int i=n-1;i>=0;i--){
            if(s.empty()) right.push_back(n);
            else if(s.size()>0 && s.top().first<heights[i]) 
            right.push_back(s.top().second);
            else if(s.size()>0 && s.top().first>=heights[i]){
               while(s.size()>0 && s.top().first>=heights[i]) s.pop();
               if(s.empty()) right.push_back(n);
               else right.push_back(s.top().second);
            }
            s.push({heights[i],i});
        }

        reverse(right.begin(),right.end());
        
        int mx_area = 0;    //Stores max_area
        for(int i=0;i<n;++i)
            mx_area = max(mx_area,heights[i]*(right[i]-left[i]-1));
        return mx_area;
       
        



        
    }
};