class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        //vector of vector
    
    int m= mat.size();// row
    int n = mat[0].size();//column

   unordered_map<int, priority_queue<int,vector<int>, greater<int>>>mp;
   //unordered_map<int,int>mp;
   //priority_queue<int>q;
   //vector<int>v;
   // array element sorted in ascending order

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            mp[i-j].push(mat[i][j]);
        }
    }

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            //top ka element smallest
            mat[i][j]=mp[i-j].top();
            mp[i-j].pop();
        }
    }

        return mat;

    }
};