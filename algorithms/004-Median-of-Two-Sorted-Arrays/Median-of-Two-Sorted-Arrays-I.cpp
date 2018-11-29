/*
There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

You may assume nums1 and nums2 cannot be both empty.

Example 1:

nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:

nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5
*/


#include<vector>
#include<iostream>
using namespace std;

// O（m+n）
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int ptr1 = 0;
		int ptr2 = 0;
		int len = nums1.size() + nums2.size();
		int ans = 0;
		while(ptr1 + ptr2 < (len + 1)/2){
			if(ptr1 >= nums1.size()){
				ans = nums2[ptr2]; 
				++ptr2;
			}
			else if(ptr2 >= nums2.size()){
				ans = nums1[ptr1];
				++ptr1;
			}
			else if(nums1[ptr1] >= nums2[ptr2]){
				ans = nums2[ptr2]; 
				++ptr2;
			}else if(nums1[ptr1] < nums2[ptr2]){
				ans = nums1[ptr1];
				++ptr1;
			}
		//std::cout<<ans<<endl;			
		}
		
		if(len&1) return ans;   //odd
		                        //even
		if(ptr1<nums1.size()&&ptr2<nums2.size()) 
			ans += nums1[ptr1] > nums2[ptr2] ? nums2[ptr2] : nums1[ptr1];
		else if(ptr1 >= nums1.size())
			ans += nums2[ptr2];
		else if(ptr2 >= nums2.size())
			ans += nums1[ptr1];
		
		return ans/2.0;
		
    }
};


int main(){
	
	vector<int> nums1{0};
	vector<int> nums2{};
	Solution s;
	int ret = s.findMedianSortedArrays(nums1, nums2);
	std::cout<<"ret = "<<ret<<endl;
	return 0;
}