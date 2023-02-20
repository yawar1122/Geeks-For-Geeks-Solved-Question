//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
vector<int> find(int arr[], int n , int x )
{
    // code here
    int s = 0;
    int e = n - 1;
    int mid=s+(e-s)/2;
    int first=-1;
    int last=-1;
    
    while(s <= e){
        if(arr[mid]==x){
            first = mid;
            e = mid - 1;
        }
        
        if(arr[mid] < x){
            s = mid + 1;
        }
        else if(arr[mid] > x){
            e = mid - 1;
        }
        
        mid=s+(e-s)/2;
    }
    
    s=0;
    e=n-1;
    mid=s+(e-s)/2;
    
    while(s<=e){
        if(arr[mid]==x){
            last=mid;
            s=mid+1;
        }
        
        if(arr[mid] < x){
            s = mid+1;
        }
        else if(arr[mid] > x){
            e = mid-1;
        }
        
        mid=s+(e-s)/2;
    }
    
    return {first,last};
}

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends