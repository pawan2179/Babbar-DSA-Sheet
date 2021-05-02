//N meetings in one room - https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1

class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    struct meeting {
        int start;
        int end;
        int id;
    };
    
    #define meeting struct meeting
    
    static bool compare(meeting a, meeting b) {
        if(a.end < b.end)    return true;
        if(a.end > b.end)    return false;
        if(a.id < b.id)    return true;
        return false;
    }
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        meeting meet[n];
        
        for(int i = 0; i < n; i++) {
            meet[i].start = start[i];
            meet[i].end = end[i];
            meet[i].id = i+1;
        }
        
        sort(meet, meet+n, compare);
        
        int limit = meet[0].end;
        int count = 1;
        
        for(int i = 1; i < n; i++) {
            if(meet[i].start > limit) {
                count++;
                limit = meet[i].end;
            }
        }
        return count;
    }
    
};
