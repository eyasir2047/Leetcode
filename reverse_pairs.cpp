class Solution {
public:

int merge(vector<int>& arr,int low,int mid, int high){
        int cnt=0;
        int j=mid+1;

        for(int i=low;i<=mid;i++){
            while(j<=high && arr[i]>(2LL*arr[j])){
                j++;
            }

            cnt+=j-(mid+1);//not j-(mid+1)=1 as j++ , one move ahead
        }

       // ArrayList<Integer>temp= new ArrayList();
       vector<int>temp;

        int left=low, right= mid+1;

        while(left<=mid && right<=high){
            if(arr[left]<=arr[right]){
               // temp.add(arr[left++]);
               temp.push_back(arr[left++]);
            }
            else{
              //  temp.add(arr[right++]);
               temp.push_back(arr[right++]);
            }
        }
        while(left<=mid){
            temp.push_back(arr[left++]);
        }
        while(right<=high){
            // temp.add(arr[right++]);
            temp.push_back(arr[right++]);
        }

        for(int i=low;i<=high;i++){
           // arr[i]=temp.get(i-low); //arr=low,low+1,....,right
            //temp=0,1,2,......
            arr[i]=temp[i-low];
        }

        return cnt;
    }


    int mergeSort(vector<int>& arr,int low, int high){

            if(low>=high) return 0;
            int mid=low+(high-low)/2;

            int rev=0;

            rev+=mergeSort(arr,low,mid);
            rev+=mergeSort(arr,mid+1,high);
            rev+= merge(arr,low,mid,high);

            return rev;
    }
    int reversePairs(vector<int>& nums) {
         return mergeSort(nums,0,nums.size()-1);
    }
};