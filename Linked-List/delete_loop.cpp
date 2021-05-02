/*  *Remove loop from a linked list
    *Uses concept of finding intersection point of a linked list with a special case if intersection point being head of the list
    */
    
class Solution
{
    public:
    //Function to remove a loop in the linked list.
    void removeLoop(Node* head)
    {
        // code here
        // just remove the loop without losing any nodes
        Node *slow = head;
        Node *fast = head;
        
        //Find collision point of fast and slow pointer
        while(fast != NULL and fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow)    break;
        }
        
        //Corner case
        if(fast == NULL || fast->next == NULL)    return ;
        
        //Special case -  if head is the collision point, iterate to last node and remove connection
        if(fast == head) {
            while(fast->next != slow) {
                fast = fast->next;
            }
            fast->next = NULL;
            return ;
        }
        
        //Find the node which is collision point and remove connection from back of linked list
        Node *dummy = head;
        while(dummy->next != slow->next) {
            dummy = dummy->next;
            slow = slow->next;
        }
        slow->next = NULL;
        
        return ;
    }
};
