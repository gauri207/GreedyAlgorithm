bool com(Job a,Job b){
    return a.profit>b.profit;
}

class Solution 
{
    public:
    
    vector<int> JobScheduling(Job arr[], int n){
    { 
        //Sort the jobs according to maximum profit
        sort(arr,arr+n,com);
        
        //we will keep a deadline check array, at which deadline the jobs had done
        bool check[n+1] = {0};
        
        int profit = 0;
        int noOfJobs = 0;
        
        //IMP* any job can be done on or before its deadline
        //So for every job (starting with jobs of maximum profit, since we have to
        //find maximum porfit) it can be done on or before its deadling
        
        //So we will check on check array if that deadline is free or not
        //If free/false then we will do that job in that deadline
        //If not free/true then we will traverse backward to the check array as
        //Jobs can only be done on its deadline or "before it".
        
        
        //Iterate throught the jobs array
        for(int i=0;i<n;i++){
            
            //Iterate to the check array backwards
            //why j=min() because maybe the deadline is more than n but we can do it
            //before n also.
            for(int j=min(n,arr[i].dead); j>=1; j--){
                if(check[j]==0){
                    profit+=arr[i].profit;
                    noOfJobs++;
                    check[j] = 1;
                    break;
                }
            }
        }
        
        return {noOfJobs, profit};
        
        
    } 
};