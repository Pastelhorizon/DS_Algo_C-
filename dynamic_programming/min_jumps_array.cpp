/*
Given an array of non-negative integers, A, of length N, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Return the minimum number of jumps required to reach the last index.

If it is not possible to reach the last index, return -1.

algo - either u can calculate the min number of jumps required to get to every ith position starting from i = 0 upto n-1.
OR
Starting from i = n-1, go to the smallest j<i from where we can jump directly to i. Then i becomes j.
Keep doing this process until i = 0(until we reach the starting index)
Here we have used the first method
*/

#include<bits/stdc++.h>
#define ll long long
using namespace std;
int jump(vector<int> &a)
{
  ll n = a.size();
    vector<ll> min_jumps(a.size(),-1);
    vector<ll> last_pos(a.size(),0);
    ll jump;
    min_jumps[0] = 0;
    for(ll i = 1;i<n;i++)
    {
        min_jumps[i] = LLONG_MAX;
        for(ll j= 0;j<i;j++)
        {
            if(j+a[j]>=i)
            {
                if(min_jumps[j]+1<min_jumps[i]&&min_jumps[j]!=-1)
                {
                    min_jumps[i] = min_jumps[j]+1;
                    last_pos[i] = j;
                }
            }
        }
        if(min_jumps[i]==LLONG_MAX)
        {
            min_jumps[i] = -1;
        }
       //cout<<min_jumps[i]<<" ";
    }
    if(n>1&&a[0] == 0)
    {
        return -1;
    }
    // if(min_jumps[n-1]==LLONG_MAX)
    //     return -1;
    // for(int i = 0;i<n;i++)
    // {
    //     cout<<min_jumps[i]<<" ";
    // }
    // cout<<"\n";
    return min_jumps[n-1];
}
int main()
{
    int n;
    cin>>n;
    vector<int> a;
    for(int i = 0;i<n;i++)
    {
        int temp;
        cin>>temp;
        a.push_back(temp);
    }
    cout<<jump(a);
}
