#include <iostream>
#include <map>
#include <vector>

using namespace std;

vector<int> twoSum(const vector<int>& nums, int target) {
    map<int, int> map;
    const size_t sz = nums.size();
    for (int i = 0; i < sz; i++) {
        if (map.contains(target - nums[i])) {
            return {i, map[target - nums[i]]};
        }
        map[nums[i]] = i;
    }

    return {-1, -1};
}

int main() {
    vector<int> nums = {5, 7, 2, 15};
    int target = 9;

    vector<int> result = twoSum(nums, target);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }

    return 0;
}
