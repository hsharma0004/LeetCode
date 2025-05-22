class Solution {
public:
vector<int> prefix(vector<int> height)
{
    vector<int> ansp(height.size(),0);
    ansp[0] = height[0];
    for (int i = 1; i < height.size(); i++)
    {
        ansp[i] = max(ansp[i-1],height[i]);
    }
   return ansp; 
}

vector<int> suffix(vector<int> height)
{
    vector<int> anss(height.size(),0);
    anss[height.size()-1] = height[height.size()-1];
    for (int i = height.size()-2; i >= 0; i--)
    {
        anss[i] = max(anss[i+1],height[i]);
    }
   return anss; 
}
    int trap(vector<int>& height) {
    int total = 0;
    vector<int> prefixMax = prefix(height);
    vector<int> suffixMax = suffix(height);
    for (int i = 0; i < height.size(); i++)
    {
        int leftMax = prefixMax[i];
        int rightMax = suffixMax[i];
        if (height[i] < leftMax && height[i] < rightMax)
            total += min(leftMax, rightMax) - height[i];
    }
    return total;       
    }
};