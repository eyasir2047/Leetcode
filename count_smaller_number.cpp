class Solution {
public:
    
    // Function to merge two sub-vectors in a sorted order and update the count of smaller elements
    void merge(vector<int> &count, vector<pair<int, int>> &v, int left, int mid, int right){
        vector<pair<int,int>> temp(right-left+10); // Create a temporary vector to store the merged sub-vectors
        int i=left; // Initialize the left sub-vector index
        int j=mid+1; // Initialize the right sub-vector index
        int k=0; // Initialize the temporary vector index
        
        // Compare the elements of the left and right sub-vectors and merge them in a sorted order
        while(i<=mid && j<=right){
            
            if(v[i].first <=v[j].first){ // If the left sub-vector element is smaller
                temp[k++] = v[j++]; // Add the right sub-vector element to the temporary vector //utla , karon decreasing order, normaly increasing order thake
            }
            
            else{
                count[v[i].second] += right-j+1; // Update the count of smaller elements for the left sub-vector element
                temp[k++] = v[i++]; // Add the left sub-vector element to the temporary vector
            }
        }
        
        // If there are any remaining elements in the left sub-vector, add them to the temporary vector
        while(i<=mid){
            temp[k++] = v[i++];
        }
        
        // If there are any remaining elements in the right sub-vector, add them to the temporary vector
        while(j<=right){
            temp[k++] = v[j++];
        }
        
        // Copy the sorted and merged elements from the temporary vector to the input vector
        for(int u=left;u<=right;u++){
            v[u] = temp[u-left]; //temp(0,1,2,3,....,n-1)
            //v[i],(left,.....right)
        }
    }
    
    // Recursive function to divide the input vector into smaller sub-vectors
    void mergeSort(vector<int> &count, vector<pair<int,int>> &v, int left, int right){
        // Base case: if left index is greater than right index, return
        if(left<right){
            int mid = left + (right-left)/2;
            mergeSort(count, v, left, mid);
            mergeSort(count, v, mid+1, right);
            merge(count, v, left, mid, right);
        }
    }
    
    // Main function to count the number of smaller elements in a given array
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>> v(n);
        // Create a vector of pairs where each pair contains the element and its index in the input vector
        for(int i=0;i<n;i++){
            pair<int, int> p;
            p.first = nums[i];
            p.second = i;
            v[i] = p;
        }
        
        // Create a vector of integers representing the count of smaller elements and
        vector<int> count(n, 0);
        mergeSort(count, v, 0, n-1);
        return count;
        
    }
};