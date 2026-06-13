#include <iostream>
#include <vector>
class Solution {
public:
    void maxSubArray(std::vector<int>& nums) {
        for(int st = 0; st < nums.size(); st++) {
            for(int end = st; end < nums.size(); end++) {
                // printing 
                for(int i = st; i <= end; i++) {
                    std::cout << nums[i];
                }
                std::cout << " ";
            }
            std::cout << std::endl;
        }

    }
};

int main() {
    std::vector<int> nums = {5,4,-1,7,8};
    Solution obj;
    obj.maxSubArray(nums); 

    return 0;
}