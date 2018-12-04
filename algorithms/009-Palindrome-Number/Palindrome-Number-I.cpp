/*
Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.

Example 1:

Input: 121
Output: true
Example 2:

Input: -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
Example 3:

Input: 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
*/

#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;  // 根据题意描述，如果负数，那么不可能是回文
 		string str;
		while(x){
			int val = x%10;
			str.push_back(val);
			x/=10;
		}
		for(int lhs = 0, rhs = str.size() -1; lhs<=rhs; ++lhs,--rhs){
			if(str[lhs] != str[rhs])
				return false;
		}
		return true;
    }
};

int main(){
	Solution s;
	int val;
	cin>>val;
	cout<<"ret is "<<s.isPalindrome(val)<<endl;
	return 0;
}