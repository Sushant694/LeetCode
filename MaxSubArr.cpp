#include <iostream>
#include <vector>
#include <algorithm>
class Solution {
public:
    int maxSubArray(std::vector<int>& nums) {
        // Using the KADANE'S ALGORITHMN
        int CurrSum = 0, MaxSum = INT_MIN;
        for(int val: nums) {
            CurrSum += val;
            MaxSum = std::max(CurrSum, MaxSum);

            if(CurrSum < 0) {
                CurrSum = 0;
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