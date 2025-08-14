class Solution {
  public:
  
   bool isSafe(int newX, int newY, vector<vector<bool>> &vis, vector<vector<int>> &arr, int n){
    if((newX >= 0 && newX < n) && (newY >= 0 && newY < n) && (vis[newX][newY] != 1) && (arr[newX][newY] == 1)){
     return true;
    }
    return false;
}

void solve(int x, int y, vector<vector<int>> &arr, int n, vector<string> &ans, vector<vector<bool>> &visited, string path) {

     // Base Case
     if(x == n-1 && y == n-1){
         ans.push_back(path);
         return ;
     }

     // 4 movement D,L,R,U
     visited[x][y] = 1;

     // Down
     if(isSafe(x+1,y,visited,arr,n)){
      solve(x+1,y,arr,n,ans,visited,path+'D');
     }

     // Left
     if(isSafe(x,y-1,visited,arr,n)){
      solve(x,y-1,arr,n,ans,visited,path+'L');
     }

     // Right
     if(isSafe(x,y+1,visited,arr,n)){
      solve(x,y+1,arr,n,ans,visited,path+'R');
     }

     // Up
     if(isSafe(x-1,y,visited,arr,n)){
      solve(x-1,y,arr,n,ans,visited,path+'U');
     }
     
    visited[x][y] = 0;
}
  
  
    vector<string> ratInMaze(vector<vector<int>>& arr) {
    vector<string> ans;
    int n = arr.size();
    if(arr[0][0] == 0) return ans;
    vector<vector<bool>> visited(n,vector<bool>(n,0));
    string path ="";

    solve(0,0,arr,n,ans,visited,path);
    return ans;
    }
};
