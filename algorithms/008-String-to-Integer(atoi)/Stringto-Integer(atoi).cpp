/*
Implement atoi which converts a string to an integer.

The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.

The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned.

Note:

Only the space character ' ' is considered as whitespace character.
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. If the numerical value is out of the range of representable values, INT_MAX (231 − 1) or INT_MIN (−231) is returned.
Example 1:

Input: "42"
Output: 42
Example 2:

Input: "   -42"
Output: -42
Explanation: The first non-whitespace character is '-', which is the minus sign.
             Then take as many numerical digits as possible, which gets 42.
Example 3:

Input: "4193 with words"
Output: 4193
Explanation: Conversion stops at digit '3' as the next character is not a numerical digit.
Example 4:

Input: "words and 987"
Output: 0
Explanation: The first non-whitespace character is 'w', which is not a numerical 
             digit or a +/- sign. Therefore no valid conversion could be performed.
Example 5:

Input: "-91283472332"
Output: -2147483648
Explanation: The number "-91283472332" is out of the range of a 32-bit signed integer.
             Thefore INT_MIN (−231) is returned.


*/
#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        if(str.empty())
			return 0;
		int start =0;
		int whitespace = 0;
		//discards as many whitespace characters as necessary
		for(int i = 0; i< str.size(); ++i){
			if(str[i] == ' '){
				whitespace ++;
				continue;
			}
			if(str[i] == '+' || str[i] == '-' || isDigit(str[i])){
				start = i;
				break;
			}
			else       //other character, error
				return 0;
		}
		if(whitespace == str.size())  // all characters is whitespace
			return 0;
		
		if((start == (str.size() -1)) && !isDigit(str[start]) ){   //only +/- sign 
			return 0;
		}
			
		int i = isDigit(str[start]) ? start : start+1;
		for(; i< str.size(); ++i){     //i start from digit
			if(!isDigit(str[i]))
			{
				return stringToi(str.substr(start,i-start));
			}
		}
		return stringToi(str.substr(start,str.size() - start));
    }
	bool isDigit(const char& c){
		if(c >= '0' && c <= '9')
			return true;
		return false;
	}
	int stringToi(string str){
		int MAX = 2147483648-1;
		int MIN = -2147483648;
		if(str.size() == 1 && (str[0] =='-' || str[0] == '+'))  //only sign
			return 0;
		bool sign  = (str[0] == '-' || str[0] =='+') ? true :  false;
		int i = sign ? 1 : 0;
		long long  ret = 0;
		for(; i< str.size();++i){
			ret *= 10;
			int num = str[i] -'0';
			ret += num;
			if(ret > MAX)
				break;
		}
		if(sign && str[0] == '-')
			return -ret < MIN ? MIN : -ret;
		return ret > MAX ? MAX : ret;
	}
};

int main(){
	Solution s;
	string str;
	cin>>str;
	cout<<s.myAtoi(str)<<endl;
	return 0;
}

