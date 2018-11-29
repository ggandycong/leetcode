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

// Log（m+n）     借鉴：http://windliang.cc/2018/07/18/leetCode-4-Median-of-Two-Sorted-Arrays/
//本题重点，理解在两个数组中使用二分查找。


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int m = nums1.size();
		int n = nums2.size();
		if(m > n)    //to ensure m < n , means j > 0
			return findMedianSortedArrays(nums2,nums1);
		int iMin = 0, iMax = m;
		while(iMin <= iMax){
			int i = iMin + (iMax - iMin)/2;
			int j = (m+n+1)/2-i;
			if(j!=0 && i!=m && nums2[j-1] > nums1[i]){
				iMin = i + 1;
			}
			else if( i!=0 && j!=n && nums1[i-1] > nums2[j]){
				iMax = i - 1;
			}else {   //达到要求
				double maxLeft = 0;
				if(i == 0) maxLeft = nums2[j-1];
				else if(j == 0) maxLeft = nums1[i-1];
				else maxLeft = nums1[i-1] > nums2[j-1] ? nums1[i-1] : nums2[j-1];
				if((m+n)&1) return maxLeft;  //奇数
				
				double minRight = 0 ;
				if(i == m) minRight = nums2[j];
				else if(j == n) minRight = nums1[i];
				else minRight = nums1[i] < nums2[j] ? nums1[i] : nums2[j];
				return (maxLeft + minRight)/2.0;      //偶数
			}
		}
		return 0.0;
    }
};


int main(){
	
	vector<int> nums1{1,2,5};
	vector<int> nums2{3,4};
	Solution s;
	double ret = s.findMedianSortedArrays(nums1, nums2);
	std::cout<<"ret = "<<ret<<endl;
	return 0;
}