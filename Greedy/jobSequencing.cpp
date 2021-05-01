//Problem - Job Sequencing - https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1

class Solution 
{
    public:
    
    static bool compare(Job a, Job b) {
        return a.profit > b.profit;
    }
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        sort(arr, arr+n, compare);
        
        int maxi = arr[0].dead;
        
        for(int i = 1; i < n; i++) {
            if(arr[i].dead > maxi)    maxi = arr[i].dead;
        }
        
        int jobCount = 0;
        int profit = 0;
        
        vector<int>deadline(maxi+1, -1);
        
        for(int i = 0; i < n; i++) {
            int ind = arr[i].dead;
            while(ind > 0 and deadline[ind] != -1)    ind--;
            if(ind > 0) {
                profit += arr[i].profit;
                deadline[ind] = arr[i].id;
                jobCount++;
            }
        }
        vector<int> ans(2);
        ans[0] = jobCount;
        ans[1] = profit;
        
        return ans;
    } 
};
