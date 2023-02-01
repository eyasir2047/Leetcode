class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();

        
        int left=0, right=n-1;

        int mid=left+(right-left)/2;

        if(nums[left]<=nums[right]){
            return nums[left];//the array is already sorted
        }
        //minimum element
        while(left<=right){
            if(nums[mid]>=nums[0]){
                    left=mid+1;
            }
            else{ //arr[mid]<=arr[n-1]
                right=mid-1;
            }
            mid=left+(right-left)/2;
        }

        return nums[left];
    }
};