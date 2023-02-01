class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        //two sorted arrays merge
    
        

       int index1=0, index2=0;

        int k=0;//mainArrayIndex
        int arr[n+m];

        while(index1<m && index2<n){
            if(nums1[index1]<=nums2[index2]){
                arr[k]=nums1[index1];
                k++;
                index1++;
            }
            else{
                arr[k]=nums2[index2];
                k++;
                index2++;
            }
        }

        while(index1<m){
            arr[k]=nums1[index1];
                k++;
                index1++;
        }

        while(index2<n){
            arr[k]=nums2[index2];
                k++;
                index2++;
        }

        for(int i=0;i<=(m+n-1);i++){
            nums1[i]=arr[i];
        }
    }
};