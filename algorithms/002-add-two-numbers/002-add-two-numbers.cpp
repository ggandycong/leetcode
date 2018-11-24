/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.

*/
#include<iostream>
#include<vector>
using namespace std;

 //Definition for singly-linked list.
 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *pRet = new ListNode(0);
		pRet->next = NULL;
		ListNode *pRetHead = pRet;
		//it means carry bits;
		int carry = 0;
		while(l1 != NULL || l2 != NULL || carry ){
			int sum = carry;
			sum += l1 ? l1->val : 0;
			sum += l2 ? l2->val : 0;
			ListNode *pNode = new ListNode(sum%10);
			pNode->next = NULL;
			pRet->next = pNode;
			pRet = pNode;
			carry = sum / 10;
			
			l1 = l1 ? l1->next : NULL;
			l2 = l2 ? l2->next : NULL;
		}
		return pRetHead->next;
    }
	ListNode* createNodeByVector(const vector<int>& vItem){
		ListNode* pRet = NULL;
		ListNode* pCur = NULL;
		for(int i = 0; i< vItem.size(); ++i){
			if(i == 0){
				pCur = new ListNode(vItem[i]);
				pCur->next = NULL;
				pRet = pCur;
			}else{
				ListNode* pTemp = new ListNode(vItem[i]);
				pTemp->next = NULL;
				pCur->next = pTemp;
				pCur = pTemp;
			}
		}
		return pRet;	
	}
	void print(ListNode* pNode){
		if(pNode){
			std::cout<<pNode->val;
			print(pNode->next);
		}
	}
};

int main(){
	vector<int> v1{2,4,3};
	vector<int> v2{5,6,4};
	Solution s;
	//ListNode* p = s.createNodeByVector(vector<int>{1,2});
	ListNode*ret = s.addTwoNumbers(s.createNodeByVector(v1),s.createNodeByVector(v2));
	s.print(ret);
	return 0;
}