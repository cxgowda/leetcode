class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
           int left = 0;
        int right = nums.size() - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;  // avoid overflow
            
            if (nums[mid] == target) {
                return mid;  // target found
            }
            else if (nums[mid] < target) {
                left = mid + 1;  // search right half
            }
            else {
                right = mid - 1; // search left half
            }
        }
        
        // If not found, left is the correct insertion position
        return left;
    }
};