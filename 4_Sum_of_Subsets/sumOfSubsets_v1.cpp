// v1: storing all valid subsets (not just printing them) 

#include <iostream>
#include <vector>
using namespace std;

void findSubsets(const vector<int>& nums, int index, int currentSum, int targetSum, vector<int>& subset, vector<vector<int>>& result) {
    // Base case: If the target is zero, we've found a valid subset
    if (currentSum == targetSum) {
        result.push_back(subset);
        return;
    }
    
    // If we exceed the target or go out of bounds, return and stop exploring
    if (targetSum < 0 || index >= nums.size()) {
        return;
    }

    // Include the current element and continue exploring
    subset.push_back(nums[index]);
    findSubsets(nums, index + 1, currentSum + nums[index], targetSum, subset, result);
    
    // Exclude the current element and explore further
    subset.pop_back();
    findSubsets(nums, index + 1, currentSum, targetSum, subset, result);
}

vector<vector<int>> subsetSum(const vector<int>& nums, int target) {
    vector<vector<int>> result;     // To store all valid subsets
    vector<int> subset;             // To build the current subset
    findSubsets(nums, 0, 0, target, subset, result);
    return result;
}

int main() {

    vector<int> nums = {5,10,12,13,15,18};
    int target = 30;

    // Get all subsets that sum to the target
    vector<vector<int>> subsets = subsetSum(nums, target);

    // Output the results
    cout << "Subsets that sum to " << target << ":\n";
    for (const auto& subset : subsets) {
        cout << "{ ";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "}\n";
    }

    return 0;
}