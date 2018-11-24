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

using namespace std;

// Brute Force
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i = 0; i < nums.size(); ++i){
			int val = target - nums[i] ;
			for(int j = i+1; j<nums.size();++j)
				if(val == nums[j]){
					return vector<int>{i,j};
				}
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