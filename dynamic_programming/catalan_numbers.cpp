/*This is the also the answer to the problem of how many distinct binary search trees can we have if we have numbers 1 to n

    So the answer to this problem is based upon the formula G(n) = SUMMATION(F(i,n))
        where F(i,n) is the number of unique binary search trees with "i" as the root of the tree
        so, F(i,n) = G(i-1) * G(n-1)...
This is how we can calculate the nth catalan number*/

int G(int,vector<int>&);
int F(int,int,vector<int>&);
int F(int i,int n,vector<int> &dp)
{
    return G(i-1,dp)*G(n-i,dp);
}
int G(int n,vector<int> &dp)
{
    if(n==0||n==1)
        return 1;
    if(n==2)
        return 2;
    if(dp[n]!=0)
        return dp[n];
    for(int i = 1;i<=n;i++)
    {
        dp[n]+=F(i,n,dp);
    }
    return dp[n];
}


int Solution::numTrees(int n) {
    vector<int> dp(n+1,0);
    return G(n,dp);
    
}
