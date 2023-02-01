class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        //applying  binary search at the indices of array
        int n=nums.size();
        int left=0, right=n-1;
        int mid=0;
        while(left<=right){
             mid=left+(right-left)/2;

            if((mid==0 || nums[mid]>=nums[mid-1])&& (mid==n-1 || nums[mid+1]<nums[mid])){
                break;
            }
            else if(mid>0 && nums[mid]<nums[mid-1] ){
                right=mid-1;
            }
            else left=mid+1;
        }


        return mid;

    }
};