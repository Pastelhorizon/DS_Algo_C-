/*In this problem to find the longest valid parenthesis, just use a stack like the histogram problem, that all.
 pop the stack if a pair is formed and calculate the size
 else
 push into the stack ...O(n) time...*/
#include<bits/stdc++.h>
using namespace std
int longestValidParentheses(string a) {
   stack<pair<char,int> > st;
   int max_size = 0;
   for(int i = 0;i<a.size();i++)
   {
       int size;
       if(st.empty()==0 && st.top().first == '(' && a[i] == ')')//if pair is formed
       {
           st.pop();//pop the stack
           //calculate size
           if(st.empty())
           {
               size = i+1;
           }
           else
           {
               size = i-st.top().second;
           }
           max_size = max(max_size,size);//update max size
       }
       else//or else push the element
       {
           st.push(make_pair(a[i],i));
       }
   }
   return max_size;
    
}
int main()
{
    string s;
    cin>>s;
    cout<<longestValidParentheses(s);
}
