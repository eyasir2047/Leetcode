class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int sum=0;
        int left=0,right=n-1;
        int maxleft=0,maxright=0;
        while(left<=right){
            if(height[left]<=height[right]){
                if(height[left]>=maxleft)
                maxleft=height[left];
                else sum+=maxleft-height[left];
                left++;

            }
            else{
                if(height[right]>=maxright)
                maxright=height[right];
                else sum+=maxright-height[right];
                right--;
            }
        }

        return sum;
        /*
        stack<int>st;

        for(int i=0;i<n;i++){
            while(!st.empty() && height[st.top()]<height[i]){
                int curr=st.top();
                st.pop();
                if(st.empty()) break;
                int diff=i-st.top()-1;
                sum+=(min(height[st.top()],height[i])-height[curr])*diff;
            }
            st.push(i);
        }
        return sum;
        */
       /* int mxl[n],mxr[n];

         mxl[0]=height[0];
        for(int i=1;i<n;i++)
        mxl[i]=max(mxl[i-1],height[i]);

         mxr[n-1]=height[n-1];
        for(int i=n-1;i>=0;i--)
        mxr[i]=max(mxr[i+1],height[i]);

        int water[n],sum=0;

         for(int i=0;i<n;i++){
             water[i]=(min(mxl[i],mxr[i]))-height[i];
            // sum+=water[i];
         }
         for(int i=0;i<n;i++)
          sum+=water[i];

         return sum;
*/


        
    }
};