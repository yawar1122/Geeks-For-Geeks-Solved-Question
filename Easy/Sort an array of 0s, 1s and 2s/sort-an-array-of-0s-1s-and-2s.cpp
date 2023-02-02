//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends

class Solution
{
    public:
    void sort012(int a[], int n)
    {
        // code here
         int count0,count1,count2;

        count0=0;

        count1=0;

        count2=0;

        for(int i=0;i<n;i++)

        {

            if(a[i]==0)

            {

                count0=count0+1;

            }

            if(a[i]==1)

            {

                count1=count1+1;

            }

            if(a[i]==2)

            {

                count2=count2+1;

            }

        }

        for(int i=0;i<n;i++)

        {

            if(i<count0)

            {

                a[i]=0;

            }

            else if(count0<=i & i<(count0+count1))

            {

                a[i]=1;

            }

            else

            {

                a[i]=2;

            }

        }

    }


    
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}


// } Driver Code Ends