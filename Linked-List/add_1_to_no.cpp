//Add 1 to a number represented by a linked list

class Solution
{
    public:
    void reverse(Node **head) {
        if(*head==NULL || (*head)->next == NULL)    return ;
        
        Node *cur = *head;
        Node *prev = NULL;
        Node *nxt = NULL;
        
        while(cur != NULL) {
            nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
        }
        *head = prev;
    }
    
    Node* addOne(Node *head) 
    {
        // Your Code here
        // return head of list after adding one
        reverse(&head);
        int carry = 1;
        
        Node *cur = head;
        int sum;
        while(cur->next != NULL) {
            
            sum = cur->data + carry;
            cur->data = (sum) % 10;
            carry = (sum) / 10;
            cur = cur->next;
        }
        
        sum = cur->data + carry;
        cur->data = (sum)%10;
        carry = (sum) / 10;
        if(carry != 0) {
            Node *newnode = new Node(carry);
            cur->next = newnode;
        }
        
        reverse(&head);
        return head;
    }
};
