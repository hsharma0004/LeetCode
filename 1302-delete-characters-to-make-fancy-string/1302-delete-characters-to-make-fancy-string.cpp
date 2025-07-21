class Solution {
public:
    string makeFancyString(string s) {
        string ans;
        char x = s[0];
        ans.push_back(x);
        int cnt = 1;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == x) {
                cnt++;
                if (cnt < 3)
                    ans.push_back(s[i]);
            } else {
                x = s[i];
                cnt = 1;
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};