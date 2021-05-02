//Remove duplicates from an unsorted linked list

class Solution
{
    public:
    //Function to remove duplicates from unsorted linked list.
    Node * removeDuplicates( Node *head) 
    {
     // your code goes here
        unordered_map<int, bool> hashmap;
        Node *cur = head;
        Node *front = NULL;
        
        //Mark first value to be present in hashmap
        hashmap[head->data] = true;
        
        while(cur != NULL) {
            front = cur->next;
            
            //Search for an element not already encountered or end of the linked list
            while(front != NULL and hashmap.find(front->data) != hashmap.end())    front = front->next;
            cur->next = front;
            if(front != NULL)
                hashmap[front->data] = true;
            cur = cur->next;
        }
        return head;
    }
};
