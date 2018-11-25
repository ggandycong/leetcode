/*
Given a string, find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length of 3. 
Example 2:

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3. 
             Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/

#include<iostream>
#include<string>

using namespace std;


//cong: use hash table 
//O(n)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int hash[256];   //index: alphabet, value: The index of this alphabet latest relative to current position. 
		for(int i = 0; i < 256; ++i)
			hash[i] = -1;
		int start = 0;
		int longest  = 0;
		for(int i = 0; i<s.size(); ++i){
			  //hash[s[i]] < start it means that we only care about  the range of position [start, i]
			if(hash[s[i]] == -1 || hash[s[i]] < start){
				hash[s[i]] = i;
				int tmp = i - start + 1;  //note:  need add 1; [0,1] it's length is 2 not 1.
				longest = longest > tmp ? longest : tmp;
				//std::cout<<"start = "<<start<<"i = "<<i<<std::endl;
			}else{
				start = hash[s[i]] + 1; 
				hash[s[i]] = i;
			}
		}
		return longest;
    }
};


int main(){
	string str("tmmzuxt");
	Solution s;
	std::cout<<s.lengthOfLongestSubstring(str);
	return 0;
}