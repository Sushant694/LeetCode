#include <iostream>
#include <vector>


class Solution {
public:

    // helper function
    int BinarySearch(std::vector<int>& nums, int target, int first, int last) {
        
        if (first <= last) {

            int mid = (first + last) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            if (nums[mid] < target) {
                return BinarySearch(nums, target, mid + 1, last);
            }
            if (nums[mid] > target) {
                return BinarySearch(nums, target, first, mid - 1);
            }
        }
        return -1;
    }
    int search(std::vector<int>& nums, int target) {
     
        return BinarySearch(nums, target, 0, nums.size() - 1);
    }
};

int main() {

    std::vector<int> nums = {-1,0,3,5,9,12};
    int target = 9;
    Solution obj;
    int result = obj.BinarySearch(nums, target, 0, nums.size() - 1);
    std::cout << "The result is: " << result << std::endl; 

    return 0; 
}