/*
Program:https://leetcode.com/problems/container-with-most-water/

Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container and n is at least 2.

 



The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.

 

Example:

Input: [1,8,6,2,5,4,8,3,7]
Output: 49
*/

#include<iostream>
#include<vector>
using namespace std;

//O(n)
class Solution {
public:
    int maxArea(vector<int>& height) {
			int lhs = 0, rhs = height.size() -1;
			int maxArea= -1;
			while(lhs <= rhs){
				int area = (height[lhs] < height[rhs] ? height[lhs] : height[rhs]) * (rhs - lhs);
				maxArea = maxArea > area ? maxArea : area;
				height[lhs] < height[rhs] ? ++lhs : --rhs;
			}
			return maxArea;
    }
};


int main(){
	Solution s;
	vector<int> height{1,8,6,2,5,4,8,3,7};
	cout<<s.maxArea(height);
	return 0;
}