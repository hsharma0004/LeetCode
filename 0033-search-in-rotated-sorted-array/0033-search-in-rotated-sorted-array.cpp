class Solution {
public:
    int search(vector<int>& arr, int k) {
        int start = 0;
        int end = arr.size() - 1;
        while (start <= end) {
            int mid = (start + end) / 2;
            if (arr[mid] == k)
                return mid;

            if (arr[start] <= arr[mid]) {
                if (k <= arr[mid] && k >= arr[start])
                    end = mid - 1;
                else
                    start = mid + 1;
            } else {
                if (k >= arr[mid] && k <= arr[end])
                    start = mid + 1;
                else
                    end = mid - 1;
            }
        }
        return -1;
    }
};