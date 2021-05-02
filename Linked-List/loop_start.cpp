//Find starting point of Loop (collision point) in a linked list

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        //If there is 1 or 0 node, cycle cannot exist
        if(head==NULL || head->next == NULL)    return NULL;
        
        ListNode *slow = head;
        ListNode *fast = head;
        
        //Find intersection point where fast and slow meet
        while(fast != NULL and fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow)    break;
        }
        
        //If loop doesn't exist
        if(fast == NULL || fast->next == NULL)    return NULL;
        
        //Find collision point
        ListNode *dummy = head;
        while(dummy != slow) {
            slow = slow->next;
            dummy = dummy->next;
        }
        
        return slow;
        
    }
};
