/*
Given an input string (s) and a pattern (p), implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).

Note:

s could be empty and contains only lowercase letters a-z.
p could be empty and contains only lowercase letters a-z, and characters like . or *.
Example 1:

Input:
s = "aa"
p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
Example 2:

Input:
s = "aa"
p = "a*"
Output: true
Explanation: '*' means zero or more of the precedeng element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".
Example 3:

Input:
s = "ab"
p = ".*"
Output: true
Explanation: ".*" means "zero or more (*) of any character (.)".
Example 4:

Input:
s = "aab"
p = "c*a*b"
Output: true
Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore it matches "aab".
Example 5:

Input:
s = "mississippi"
p = "mis*is*p*."
Output: false

*/

#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
		return regularMath(s,0,p,0);
    }
	bool regularMath(string s, int p1, string p, int p2){
		 if( p2 == p.size()){
			if(p1 == s.size())
				return true;
			return false;
		}
		if(p1 == s.size()){   // if the s is empty
			if(p[p2] != '*' && (p2 + 1) < p.size() && p[p2+1] == '*'){    //p[p2] 
				return regularMath(s,p1,p,p2+2);
			}
			return false;
		}
		if(s[p1] == p[p2] || p[p2] == '.'){
			if(p2+1 < p.size() && p[p2+1] == '*'){
				return regularMath(s,p1,p,p2+2) || regularMath(s,p1+1,p,p2);
			}
			else return regularMath(s,p1+1, p, p2+1);
		}else{
			if(p2+1 < p.size() && p[p2+1] == '*')
				return regularMath(s,p1,p,p2+2);
			else 
				return false;
		}			
	}
};


int main(){
	Solution solu;
	string s("aaaaaaaaaaaaab");
	string p("a*a*a*a*a*a*a*a*a*a*c");
	cout<<"ret "<<solu.isMatch(s,p);
	return 0;
}
