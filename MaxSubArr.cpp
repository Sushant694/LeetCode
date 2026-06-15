#include <iostream>
#include <vector>
#include <algorithm>
class Solution {
public:
    int maxSubArray(std::vector<int>& nums) {
        int MaxSum = 0;
        if(nums.size() == 1) {
            MaxSum = nums[0];
        }
        for(int st = 0; st < nums.size(); st++) {
            // Using the Brute Force Approach
            int Sum = 0;
            for(int end = st; end < nums.size(); end++) {
                Sum += nums[end];
                MaxSum = std::max(Sum, MaxSum);
            }
        }
        return MaxSum;
    }
};

int main() {
    std::vector<int> nums = {5,4,-1,7,8};
    Solution obj;
    auto result = obj.maxSubArray(nums); 
    std::cout << "The maximun subarray of given array is: " << result << std::endl;
    return 0;
}