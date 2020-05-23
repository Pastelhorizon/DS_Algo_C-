//Here, the rod must be cut so as to have minimum cost
// There is a rod of length N lying on x-axis with its left end at x = 0 and right end at
//  x = N. Now, there are M weak points on this rod denoted by 
//  positive integer values(all less than N) A1, A2, …, AM. You have to cut rod at all 
//  these weak points. You can perform these cuts in any order. After a cut, rod gets 
//  divided into two smaller sub-rods. Cost of making a cut is the length of the sub-rod 
//  in which you are making a cut.

// Your aim is to minimise this cost.
// Return an array denoting the sequence in which you will make cuts. 
// If two different sequences of cuts give same cost, return the lexicographically smallest. 
//https://www.interviewbit.com/problems/rod-cutting/
#include<bits/stdc++.h>
using namespace std;
vector<int> rodCut(int a, vector<int> &b)
{
    //SECTION - 1 = Filling the table
    b.insert(b.begin(),0);
    b.push_back(a);
    sort(b.begin(),b.end());
    int n = b.size();
    vector<vector<long> > dp(n,vector<long>(n,0));
    vector<vector<long> > pos(n,vector<long>(n,0));
    /*First we will fill up the table, starting from the base case i.e, if there is only 
    one cut in between two cut positions(gaps = 2). Then the gaps gonna increase upto covering all
    the cuts. Let the left limit is i and right limit is j. In each gap loop, we want to check the min possible cost by considering all the cuts in between i and j
    (lets say k). We will store this minimum value and the cut position in the table.*/
    for(int gaps = 2; gaps<n;gaps++)
    {
        for(int i = 0,j=i+gaps;j<n;i++,j++)
        {
            long min_val = LONG_MAX;
            long min_pos = 0;
            for(int k = i+1;k<j;k++)
            {
                long temp = b[j]-b[i]+dp[i][k]+dp[k][j];
                if(temp<min_val)
                {
                    min_val = temp;
                    min_pos = k;
                }
            }
            dp[i][j] = min_val;
            pos[i][j] = min_pos;
        }
    }
    //SECTION - 2 = Getting the result
    /*Here, we can either use recursion, or implement the recursion technique by iteration and get the cuts using the table pos[i][j]*/
     stack<pair<int,int> > st;
     int flag = 1;//if flag == 1->{current_node mode}, if flag == 0->{stack mode}
     pair<int,int> curr = make_pair(0,n-1);
     vector<int> res;
     while(flag==1||st.empty()==0)//if we are in the stack mode and stack is empty, then exit the loop
     {
         if(flag==1)//current_node mode
         {
             //here, either we go to stack mode if we encounter a leaf node, or we execute the current node
             if(curr.first+1>=curr.second)//if leaf node is encountered, then go to stack mode
             {
                 flag = 0;
             }
             else//Execute the curr node
             {
                 int k = pos[curr.first][curr.second];
                 res.push_back(b[k]);
                 st.push(make_pair(k,curr.second));
                 curr = make_pair(curr.first,k);
             }
         }
         else//stack mode
         {
             //here, we pop the top element of the stack, set it as current node and swtich to current_node mode
             curr = st.top();
             st.pop();
             flag = 1;
         }
     }
     return res;
}
int main()
{
    int a = 10;
    vector<int> b {1,2,5};
    vector<int> res = rodCut(a,b);
    for(int i = 0;i<res.size();i++)
    {
        cout<<res[i]<<" ";
    }
    cout<<endl;
}