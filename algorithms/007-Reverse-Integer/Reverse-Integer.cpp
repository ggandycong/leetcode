/*
Given a 32-bit signed integer, reverse digits of an integer.

Example 1:

Input: 123
Output: 321
Example 2:

Input: -123
Output: -321
Example 3:

Input: 120
Output: 21
Note:
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.



*/


//note: Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range
#include<iostream>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int max32 = ~(unsigned int)0 / 2;
		int min32 = -max32-1;
		int ans = 0;
		while(x){
			int digit = x%10;
			x/=10;
			//the imporant point,   overflow
			if(ans > max32/10 || (ans == max32/10 && digit > 7) ) return 0;
			if(ans < min32/10 || (ans == min32/10 && digit < -8)) return 0;
			ans = ans*10 + digit;
		}
		return ans;
    }
};

int main(){
	Solution s;
	int val;
	cin>>val;
	cout<<s.reverse(val)<<endl;
	return 0;
}