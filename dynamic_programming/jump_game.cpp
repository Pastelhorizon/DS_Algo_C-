/*Given an array of non-negative integers, A, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.
*/

vector<int> dp;
int ways(vector<int> &a, int i)
{
    if(i>=a.size()-1)
    {
        return 1;
    }
    if(dp[i]!=-1)
    {
        return dp[i];
    }
    int res = 0;
    for(int j = a[i];j>0;j--)
    {
        res = ways(a,i+j);
        if(res == 1)
            break;
        
    }
    dp[i] = res;
    return res;
}
int Solution::canJump(vector<int> &a) {
    dp.resize(a.size());
   // memset(dp,-1,dp.size());
   for(int i = 0;i<dp.size();i++)
   {
       dp[i] = -1;
   }
    return ways(a,0);
}
