class Solution {
public:
    bool isPalindrome(int x) {
    if (x < 0 || (x % 10 == 0 && x != 0)) // numbers ending with 0 (except 0 itself) cannot be palindromes
        return false;
    
    int reversed = 0;
    while (x > reversed) {
        reversed = reversed * 10 + x % 10;
        x /= 10;
    }
    
    // For odd length palindrome, we need to handle the middle digit
    return x == reversed || x == reversed / 10;
}
};