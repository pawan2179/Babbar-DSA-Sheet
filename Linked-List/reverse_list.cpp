//Reverse a Linked List

class Solution
{
    public:
    //Function to reverse a linked list.
    struct Node* reverseList(struct Node *head)
    {
        // code here
        // return head of reversed list
        if(head == NULL || head->next == NULL)    return head;
        Node *cur = head;
        Node *prev = NULL;
        Node *nxt;
        
        while(cur != NULL) {
            nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
        }
        return prev;
    }
    
};
