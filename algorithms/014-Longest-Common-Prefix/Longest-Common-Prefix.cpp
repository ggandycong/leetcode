/*
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:

Input: ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
*/


#include<iostream>
#include<string>
#include<vector>
using namespace std;


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty())
			return string();
		int lcp = 0;
		int minWidth = ~(unsigned int)0/2;  //min width
		for(int i = 0; i < strs.size();++i){
			minWidth = minWidth < strs[i].size() ? minWidth : strs[i].size();
		}
		int lenght = strs.size();
		for(int i =0; i< minWidth;++i){
			for(int j = 1;j<lenght;++j){
				if(strs[j-1][i] != strs[j][i]){
					return strs[0].substr(0,lcp);
				}
			}
			++lcp;
		}
		return strs[0].substr(0,lcp);
    }
};

int main(){
	Solution s;
	vector<string> vs;
	cout<<s.longestCommonPrefix(vs)<<endl;
	return 0;
}