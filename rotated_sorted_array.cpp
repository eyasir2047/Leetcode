
class Solution {
   
public:

    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int left=0, right=n-1;
        int mid;
        while(left<=right){
                mid=left+(right-left)/2;

                if(nums[mid]==target){
                    return mid;
                }
                else if(nums[left]<=nums[mid]){ 

                        if(target>=nums[left] && target<nums[mid]){
                           right=mid-1;//right ta ke range ar moddhe ana
                        }
                        else{
                           left=mid+1;
                        }
                }
                else{
                    if(target>nums[mid] && target<=nums[right]){
                        //left ta range ar moddhe ana
                        left=mid+1;
                    }
                    else{
                        right=mid-1;
                    }
                }
        }
        return -1;
    
    }
};