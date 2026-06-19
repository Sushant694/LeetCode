#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
class Solution {
public:
    int maxSum(std::vector<int>& nums) {

        // Creating the seperate bucket
        std::vector<int> bucket[10];
        for(int i = 0; i < nums.size(); i++) {
            // Convert the number into the string
            std::string num_str = std::to_string(nums[i]);
            int Max_Num = 0;

            for(char ch : num_str) {
                // Convert the character into the number 
                int curr_char = ch - '0';
                if(curr_char > Max_Num) {
                    Max_Num = curr_char;
                }
            }
            bucket[Max_Num].push_back(nums[i]);
        }

        int ans = -1;
        for(int i = 0; i < 10; i++) {
            if(bucket[i].size() < 2) {
                continue;
            }
            std::sort(bucket[i].begin(), bucket[i].end());
            int n = bucket[i].size();
            ans = std::max(ans, bucket[i][n-1] + bucket[i][n-2]);
        }
        return ans;
    }
};

int main() {
    std::vector<int> nums = {2536,1613,3366,162};
    Solution obj;
    std::cout << obj.maxSum(nums);
    return 0;
}