/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);
Example 1:

Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
Example 2:

Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:

P     I    N
A   L S  I G
Y A   H R
P     I


*/

#include<iostream>
#include<string>
using namespace std;


class Solution {
public:
    string convert(string s, int numRows) {
		string ans;
		if(numRows <=1) return s;
		int numRows2 = (numRows -1 )*2 ;  //one circle
		for(int i = 0; i < numRows && i < s.size(); ++i){
			for(int j = i ; j < s.size(); ){
				//cout<<s[j]<<" ";
				ans.push_back(s[j]);
				int interval= numRows2-2*i;
				if(interval%numRows2!=0  && j+interval < s.size()){
					ans.push_back(s[j+interval]);
					//cout<<s[j+interval]<<" ";
				}
				j+=numRows2;	
			}
			//cout<<"||";
		}
		return ans;
    }
};

int main(){
	Solution s;
	std::string str("123456789abcdefg");
	int numRows = 5;
	std::string ans = s.convert(str,numRows);
	cout<<ans<<endl;
	return 0;
}