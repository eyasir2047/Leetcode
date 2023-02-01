//have to implement the bucket sort also'
//radix sort implementation -> selection,merge,quick & counting sort
//radix sort->counting sort
#include<iostream>
#include<vector>
#include<algorithm>
#include <fstream>
using namespace std;



//#include<bits/stdc++.h>
int get_max(int arr[],int n){
    int mx=arr[0];
    for(int i=1;i<n;i++){
       if(arr[i]>mx){
           mx=arr[i];
       }
    }
    
    return mx;
}

void countSort(int arr[],int n,int exp){
    int count[10]={0};
    int output[n];
    
    for(int i=0;i<n;i++){
        count[(arr[i]/exp)%10]++;
    }
    
    for(int i=1;i<10;i++){
        count[i]=count[i]+count[i-1];
    }
    
    //stable counting counting sort
    
    for(int i=n-1;i>=0;i--){
        output[--count[(arr[i]/exp)%10]]=arr[i];
        //count[(arr[i]/exp)%10]--;
    }
    
    for( int i=0;i<n;i++){
    arr[i]=output[i];
    }
}
void radixSort(int arr[], int n) 
{ 
   // code here
   
   int maxi=get_max(arr,n);
   
   for(int exp=1; maxi/exp>0; exp*=10){
       countSort(arr,n,exp);
   }
} 

//{ Driver Code Starts.

int main() 
{ 
  // freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);
   ofstream myfile;
   myfile.open ("example.txt");
         
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        
        for(int i=0;i<n;i++)
            cin>>arr[i];
  
        radixSort(arr, n); 
        
        for(int i=0;i<n;i++)
            cout<<arr[i]<<" ";
        
        cout<<endl;
    }

    myfile.close();
    return 0; 
} 
