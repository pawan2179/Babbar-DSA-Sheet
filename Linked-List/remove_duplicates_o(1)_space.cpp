//Removed duplicates from a sorted Linked List without extra space

Node *removeDuplicates(Node *head)
{
 // your code goes here
     Node *cur = head;
     Node *fast = NULL;
     
     while(cur != NULL) {
         fast = cur->next;
         
         //While we don't come to the end of list or we find same element
         while(fast != NULL and fast->data == cur->data)    fast = fast->next;
         cur->next = fast;
         cur = fast;
     }
     return head;
}
