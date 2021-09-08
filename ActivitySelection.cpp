// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of activities that can
    //be performed by a single person.
    int activitySelection(vector<int> start, vector<int> end, int n)
    {
        // Your code here
        int i;
        vector<pair<int,int>>meetings;
        for(i=0;i<n;i++){
            meetings.push_back({end[i],start[i]});    //make pair with end[] as first
            
        }
        sort(meetings.begin(),meetings.end());
        
        int lastTime=meetings[0].first;
        int totalMeetings=1;
        for(i=1;i<n;i++){
            if(meetings[i].second>lastTime){
                totalMeetings++;
                lastTime=meetings[i].first;
            }
        }
        return totalMeetings;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    
    //testcases
    cin >> t;
    while(t--)
    {
        //size of array
        int n;
        cin >> n;
        vector<int> start(n), end(n);
        
        //adding elements to arrays start and end
        for(int i=0;i<n;i++)
            cin>>start[i];
        for(int i=0;i<n;i++)
            cin>>end[i];
        Solution ob;
        //function call
        cout << ob.activitySelection(start, end, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends