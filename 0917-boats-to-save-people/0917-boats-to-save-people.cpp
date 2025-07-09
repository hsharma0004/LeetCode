class Solution {
public:
    int numRescueBoats(vector<int>& nums, int limit) {
        sort(nums.begin(),nums.end());
        int i = 0;
        int j = nums.size()-1;
        int cnt = 0;
        int sum = nums[i] + nums[j];
        while(i <= j){
          if((nums[i] + nums[j]) <= limit){
            cnt++;
            i++;
            j--;
          }
          else{
            cnt++;
            j--;
          }
        } 
        return cnt;
    }
};