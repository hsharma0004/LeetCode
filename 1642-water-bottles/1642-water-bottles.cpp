class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = numBottles;
        while (numBottles >= numExchange) {
            int empty = 0;
            if (numBottles % numExchange != 0)
                empty += (numBottles % numExchange);
            int ExBottles = numBottles / numExchange;
            ans += ExBottles;
            if (empty > 0)
                ExBottles += empty;
            numBottles = ExBottles;
        }
        return ans;
    }
};