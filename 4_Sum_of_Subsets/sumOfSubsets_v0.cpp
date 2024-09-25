#include <iostream> 
#include <vector>
using namespace std;

void findSubsets(vector<int>& nums, int index, vector<int>& currentSubset, int currentSum, int targetSum) {
    // If the current sum equals the target sum, print the subset
    if (currentSum == targetSum) {
        cout << "{ ";
        for (int num : currentSubset) {
            cout << num << " ";
        }
        cout << "}" << endl;
        return;
    }

    // If the sum exceeds the target or we reach the end, return
    if (currentSum > targetSum || index == nums.size()) {
        return;
    }

    // Option 1: Include the current element in the subset
    currentSubset.push_back(nums[index]);
    findSubsets(nums, index + 1, currentSubset, currentSum + nums[index], targetSum);

    // Option 2: Exclude the current element from the subset
    currentSubset.pop_back();
    findSubsets(nums, index + 1, currentSubset, currentSum, targetSum);
}

void subsetSum(vector<int>& nums, int targetSum) {
    vector<int> currentSubset;
    findSubsets(nums, 0, currentSubset, 0, targetSum);
}

int main() {
    vector<int> nums = {5,10,12,13,15,18};
    int targetSum = 30;

    cout << "Subsets with sum " << targetSum << ":" << endl;
    subsetSum(nums, targetSum);

    return 0;
}
