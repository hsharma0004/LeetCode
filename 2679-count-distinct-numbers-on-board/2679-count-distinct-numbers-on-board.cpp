class Solution {
public:
    int distinctIntegers(int n) {
      if(n == 1) return 1;
      else if(n > 1) return  n-1;
      return -1;
    }
};