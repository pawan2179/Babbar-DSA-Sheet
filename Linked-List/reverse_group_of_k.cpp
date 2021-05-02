//Reverse Lineked List in group of k


class Solution
{
    public:
    struct node *reverse (struct node *head, int k)
    { 
        // Complete this method
        node *prev = NULL;
        node *cur = head;
        node *nxt = NULL;
        int count = 0;
        
        //Reverse k elements of Linked List with last element pointing to NULL
        while(cur != NULL and count < k) {
            nxt = cur->next;
            cur -> next = prev;
            prev = cur;
            cur = nxt;
            count++;
        }
        
        //head->next is NULL after reversing. Set it to new value if there are elements to be reversed furthur
        if(nxt != NULL)    head->next = reverse(nxt, k);
        
        //New head
        return prev;
    }
};
