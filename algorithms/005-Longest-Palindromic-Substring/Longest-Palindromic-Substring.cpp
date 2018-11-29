
/*Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example 1:

Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:

Input: "cbbd"
Output: "bb"
*/

#include<string>
#include<iostream>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
		int start = 0;
		int longest = -1;
		for(int i = 0; i < s.size(); ++i){
			int tmp;
			 //odd
			tmp = rangePalindrome(i,i,s) - 1;
			if(tmp > longest){
			longest = tmp;
			start = i - tmp/2;
			}
			 
			//even	
			tmp = rangePalindrome(i,i+1,s);  
			if(tmp > longest){
			longest = tmp;
			start = i - tmp/2 +1;
			}
		}
		//std::cout<<longest;
		return s.substr(start,longest);
	}
	//return the number of Palindrome
	int rangePalindrome(int lhs, int rhs,const string& s){
		int numPalindrome = 0;
		while(lhs >=0 && rhs < s.size()){
			if(s[lhs] != s[rhs])
				break;
			--lhs;
			++rhs;
			numPalindrome += 2;
		}
		return numPalindrome;
	}
};


int main(){
	Solution s;
	std::cout<<s.longestPalindrome("c");
	return 0;
}