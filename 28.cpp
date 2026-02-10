class Solution {
public:
    int strStr(string haystack, string needle) {
            int n = haystack.size();
        int m = needle.size();

        // If needle is longer than haystack, impossible to match
        if (m > n) return -1;

        // Try matching needle starting from each position in haystack
        for (int i = 0; i <= n - m; i++) {
            int j = 0;
            while (j < m && haystack[i + j] == needle[j]) {
                j++;
            }
            if (j == m) {
                return i;  // full match found
            }
        }

        return -1;  // no match
    }
};