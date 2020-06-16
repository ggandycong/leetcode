/*

Given a linked list, determine if it has a cycle in it.

To represent a cycle in the given linked list, we use an integer pos which represents the position (0-indexed) in the linked list where tail connects to. If pos is -1, then there is no cycle in the linked list.

*/

class Solution {
public:
    bool hasCycle(ListNode *head) {
        
        if(head == NULL)
            return false;
        ListNode *p1 = head;
        ListNode *p2 = head;
        
        while(p1 && p2->next && p2->next->next){
            if(p2->next->next == p1)
                return true;
            p2 = p2->next->next;
            p1 = p1->next;
            
        }
        return false;
    }
};
