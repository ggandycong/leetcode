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

//Coud you solve it without converting the integer to a string?
//不借助字符串。  ***参考官方。
class Solution {
public:
    bool isPalindrome(int x) {
		 if(x < 0 || (x%10 == 0&& x!=0))
			 return false;
		 int reversal =  0;
		 while(reversal < x){
			 reversal  = reversal *10 + x%10;
			 x/=10;
		 }
		 return x == reversal || x == reversal /10;
	}
};

int main(){
	Solution s;
	int val;
	cin>>val;
	cout<<"ret is "<<s.isPalindrome(val)<<endl;
	return 0;
}