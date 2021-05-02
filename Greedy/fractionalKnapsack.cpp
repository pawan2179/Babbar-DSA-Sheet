//Fractional Knapsack - 

class Solution
{
    public:
    
    //Sort the array according to maximum of (value/weight) ratio
    static bool compare(Item a, Item b) {
        return ((double)a.value)/a.weight > ((double)b.value/b.weight);
    }
    
    //Function to get maximum value in knapsack
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        sort(arr, arr+n, compare);
        double profit = 0;
        
        for(int i = 0; i < n; i++) {
        
            // Entire of current Item can be taken
            if(arr[i].weight < W) {
                profit += arr[i].value;
                W -= arr[i].weight;
            }
            //Entire of current Item cannot be taken
            else {
                profit += ((double)arr[i].value/arr[i].weight)*W;
                break;
            }
        }
        return profit;
    }
        
};
