class Solution {
public:
void merge(vector<int>&nums,int l,int mid,int r){
    int len1=mid-l+1;
    int len2=r-mid;

   int arr1[len1];
   int arr2[len2];

    int k=l;//mainArrayIndex

    //copy the array 
    for(int i=0;i<len1;i++){
        arr1[i]=nums[k++];
 }
    for(int i=0;i<len2;i++){
        arr2[i]= nums[k++];
    }

    //merge two sorted array

    k=l;

    int index1=0,index2=0;

    while(index1<len1 && index2<len2){
        if(arr1[index1]<arr2[index2]){
            nums[k++]=arr1[index1++];
        }
        else{
            nums[k++]=arr2[index2++];
        }
    }

    while(index1<len1){
      
            nums[k++]=arr1[index1++];
       
    }

    while(index2<len2){
        nums[k++]=arr2[index2++];
    }





}
void mergeSorting(vector<int>& nums,int l,int r){
    int mid=l+(r-l)/2;
    //base case
   if(l>=r) return ;

    mergeSorting(nums,l,mid);
     mergeSorting(nums,mid+1,r);
     merge(nums,l,mid,r);

}
    vector<int> sortArray(vector<int>& nums) {
       int n=nums.size();

        int l=0, r=n-1;

        int mid=l+(r-l)/2;

        mergeSorting(nums,l,r);

       return nums;
        
    }
};