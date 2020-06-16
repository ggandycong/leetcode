
/*
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

To represent a cycle in the given linked list, we use an integer pos which represents the position (0-indexed) in the linked list where tail connects to. If pos is -1, then there is no cycle in the linked list.

Note: Do not modify the linked list.


*/



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *p1 = head;
        ListNode *p2 = head;
        
        while(p1 && p2->next && p2->next->next){     
            p2 = p2->next->next;
            p1 = p1->next;
            //找到重叠的点。（注意p1,p2起点要一致，然后再开始分别以1，2步往前走）
            if(p2 == p1){
                ListNode *start = head;
                while(p2 != start){
                    p2 = p2->next;
                    start = start->next;
                }
                return p2;
            }
           
            
        }
        return NULL;
    }
     
};