/*
Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, two is written as II in Roman numeral, just two one's added together. Twelve is written as, XII, which is simply X + II. The number twenty seven is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
Given a roman numeral, convert it to an integer. Input is guaranteed to be within the range from 1 to 3999.

Example 1:

Input: "III"
Output: 3
Example 2:

Input: "IV"
Output: 4
Example 3:

Input: "IX"
Output: 9
Example 4:

Input: "LVIII"
Output: 58
Explanation: L = 50, V= 5, III = 3.
Example 5:

Input: "MCMXCIV"
Output: 1994
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
*/

#include<iostream>
#include<string>
using namespace std;


class Solution {
public:
    int romanToInt(string s) {   //input is valid Roman
         string Roman("MDCLXVI");
		 int b[4] = {1000,100,10,1};
		 int ans = 0,digit = 0;
		 int r = 0,i = 0;
		 for(; r < Roman.size(); r+=2){
			 if(Roman[r] == s[i] || (r > 0&& Roman[r-1] == s[i])){
				 if(Roman[r] == s[i]){
					 if((i+1<s.size()) && s[i+1] == Roman[r-1]){
						 digit = 4;
						 i= i+2;
					 }else if(r>1&&(i+1<s.size())&&s[i+1] == Roman[r-2]){
						 digit = 9;
						 i=i+2;
					 }else{
						 for(;i<i+3&&i<s.size();++i){
							 if(Roman[r] == s[i])
								 digit++;
							 else 
								 break;
						 }
					 }
				 }else if( r>0 &&Roman[r-1] == s[i]){
					 digit = 5;
					 ++i;
					 for(;i<i+3&&i<s.size();++i){
						 if(s[i] == Roman[r])
							 digit++;
						 else
							 break;
					 }
				 }
			 }
			 ans += digit*b[r/2];
			 digit = 0;
		 } 
		 return ans;
    }
};

int main(){
	Solution s;
	string str;
	cin>>str;
	cout<<s.romanToInt(str);
	return 0;
}