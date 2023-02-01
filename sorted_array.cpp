class Solution {
public:/*
int firstsearch(vector<int>& arr,int left,int right,int x,int n){

    if(left<=right){

        int mid=left+(right-left)/2;
        if( (mid==0 || arr[mid-1]<x ) && arr[mid]==x){//sorted array that's why arr[mid-1]<x
                return mid;
        }

        else if(arr[mid]<x){
            firstsearch(arr,mid+1,right,x,n);
        }
        else{
            firstsearch(arr,left,mid-1,x,n);
        }

    }

    return -1;
}

int secondsearch(vector<int>& arr,int left,int right,int x,int n){

    if(left<=right){
        

        int mid=left+(right-left)/2;
        if((mid==n-1 || arr[mid+1]>x ) && arr[mid]==x){
                return mid;
        }

        else if(arr[mid]<x){
            secondsearch(arr,mid+1,right,x,n);
        }
        else{
            secondsearch(arr,left,mid-1,x,n);
        }

    }

    return -1;
}
*/
//iterative approach
int firstsearch(vector<int>& arr,int left,int right,int x,int n){

    while(left<=right){
        int mid=left+(right-left)/2;
        if((mid==0 || arr[mid-1]<x) && arr[mid]==x){
            return mid;
        }
        else if(arr[mid]<x){
            left=mid+1;
        }
        else{
            right=mid-1;
        }
    }



    return -1;
}

int secondsearch(vector<int>& arr,int left,int right,int x,int n){
    int ans=-1;
     while(left<=right){
        int mid=left+(right-left)/2;
       
            
          if(arr[mid]<x){
            left=mid+1;
        }
        else if(arr[mid]>x){
            right=mid-1;
        }
        else{
           ans=mid;
           left=mid+1;  // 2 2 
           // left=0,right=1 mid=0  ans=0 left=1 mid=1 ans=1  left=2
        }
    }

    return ans;
}


    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>ans;
       
        int first=0,second=0;
        int n=nums.size();
         first=firstsearch(nums,0,n-1,target,n);
         second=secondsearch(nums,0,n-1,target,n);

         ans.push_back(first);
            ans.push_back(second);

            return ans;




    }
};