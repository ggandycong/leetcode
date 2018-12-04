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

//***
class Solution {
public:
    string convert(string s, int numRows) 
    {
        if(numRows<=1  || s.length() <= numRows)
            return s;
        string* str = new string[numRows];
        int step = 0,row = 0;
        for(int i = 0; i<s.length();++i)
        {
            str[row].push_back(s[i]);
            if(row == 0)
                step = 1;
            if(row == numRows-1)
                step = -1;
            
            row +=step;
        }
        s.clear();
        for(int i = 0; i<numRows;++i)
        {
            s.append(str[i]);
        }
        delete[] str;
        return s;
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