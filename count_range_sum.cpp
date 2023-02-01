class Solution {
public:

    int countRangeSum(vector<int>& nums, int lower, int upper) {
        

        int n = nums.size();
        vector<long long> v(n + 1); // Create a vector to store the prefix sum
        // Compute the prefix sum of the input array
        for (int i = 0; i < n; i++) {
            v[i + 1] = v[i] + nums[i];
        }


       
        return mergeSort(v, 0, n, lower, upper); // Call the helper function to find the range count
    }


private:
    int mergeSort(vector<long long>& v, int left, int right, int lower, int upper) {
        if (left >= right) {
            return 0; // Base case: if left index is greater than or equal to right index, return 0
        }
        int mid = left + (right - left) / 2;
        int count = mergeSort(v, left, mid, lower, upper) + mergeSort(v, mid + 1, right, lower, upper);

       

        //we get the two sorted arrays
        
        int j = mid + 1, k = mid + 1;
        // Iterate through the left half of the array
        for (int i = left; i <= mid; i++) {
            while (j <= right && v[j] - v[i] < lower) { // Move pointer j to find the lower bound// v[j]>v[i]
                j++; //this loop ensures that we are in the lower range
            }
            while (k <= right && v[k] - v[i] <= upper) { // Move pointer k to find the upper bound
                k++;//this loop ensures the max upper bound
            }
            count += k - j; // Add the count to the total count
        }

        //two sorted array merge
     inplace_merge(v.begin() + left, v.begin() + mid + 1, v.begin() + right + 1);
    
        return count;
    }
};