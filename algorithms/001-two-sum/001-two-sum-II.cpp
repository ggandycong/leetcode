/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].

*/

#include<algorithm>
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// Hash Table: O(n)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int ,int >unordmap;  //key： (second values)  value: (first index)
		for(int i = 0; i < nums.size(); ++i)
		{
			auto it = unordmap.find(nums[i]);
			//it will find.
			if(it != unordmap.end()){
				return vector<int>{it->second, i};
			}
			unordmap[target - nums[i]] = i;
		}
		return vector<int>();
    }
};


int main()
{
	vector<int> nums{2,7,11,15};
	int target = 18;
	Solution s;
	vector<int>  ret = s.twoSum(nums,target);
	for(int i = 0;i<ret.size();++i){
		std::cout<<ret[i]<<" ";
	}
	std::cout<<"\n";
	return 0;
}