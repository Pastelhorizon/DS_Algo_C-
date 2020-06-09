/*Given an expression, A, with operands and operators (OR , AND , XOR), in how many ways can you evaluate the expression to true, by grouping in different ways?

Operands are only true and false.

Return the number of ways to evaluate the expression modulo 103 + 3.



Input Format:

The first and the only argument of input will contain a string, A.

The string A, may contain these characters:
    '|' will represent or operator 
    '&' will represent and operator
    '^' will represent xor operator
    'T' will represent true operand
    'F' will false

Output:

Return an integer, representing the number of ways to evaluate the string.*/

typedef long long ll;
vector<vector<vector<ll>>> dp;
ll ways(string a, int i, int j, bool tr)
{
    if(i>j)
    {
        return ll(tr);
    }
    if(i==j)
    {
        if(a[i] == 'T')
        {
            return ll(tr);
        }
        else
        {
            return ll(!tr);
        }
    }
    if(dp[i][j][int(tr)] != -1)
    {
        return dp[i][j][int(tr)];
    }
    ll res = 0;
    for(int k = i+1;k<j;k+=2)
    {
        ll lt = ways(a,i,k-1,true)%1003;
        ll lf = ways(a,i,k-1,false)%1003;
        ll rt = ways(a,k+1,j,true)%1003;
        ll rf = ways(a,k+1,j,false)%1003;
        
        if(a[k] == '&')
        {
            if(tr == true)
            {
                res += (lt*rt)%1003;
            }
            else
            {
                res += (lt*rf + lf*rt + lf*rf)%1003;
            }
        }
        else if(a[k] == '|')
        {
            if(tr == true)
            {
                res += (lt*rf + lf*rt + lt*rt)%1003;
            }
            else
            {
                res += (lf*rf)%1003;
            }
        }
        else if(a[k] == '^')
        {
            if(tr == true)
            {
                res += (lt*rf + lf*rt)%1003;
            }
            else
            {
                res += (lt*rt +lf*rf)%1003;
            }
        }
        res = res%1003;
    }
    dp[i][j][int(tr)] = res;
    return res;
}
int Solution::cnttrue(string a) {
    dp.resize(a.size());
    for(int i = 0;i<a.size();i++)
    {
        dp[i].resize(a.size());
        for(int j = 0;j<a.size();j++)
        {
            dp[i][j].resize(2);
            dp[i][j][0] = -1;
            dp[i][j][1] = -1;
        }
    }
    return ways(a,0,a.size()-1,true)%1003;
    
}
