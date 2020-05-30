#include<bits/stdc++.h>
using namespace std;
void print_vector(vector<int> &s)
{
    for(int i = 0;i<s.size();i++)
    {
        cout<<s[i]<<" ";
    }
    cout<<endl;
}
int hist_area(vector<int> a)
{
    stack<int> st;
    int max_area = a[0];
    st.push(0);
    a.push_back(0);
    int area = 0;
    //print_vector(a);
    for(int i = 1;i<a.size();i++)
    {
        if(st.empty()||a[i]>=a[st.top()])
        {
            st.push(i);
        }
        else
        {
            int j = st.top();
            st.pop();
            if(st.empty())
            {
                max_area = max(i*a[j],max_area);
            }
            else
            {
                max_area = max(max_area,(i-j)*a[j]);
            }
            i--;
        }
        //cout<<max_area<<endl;
    }
    return max_area;
}

int maximalRectangle(vector<vector<int> > &a) {
    
    vector<int> his(a[0].size(),0);
    int max_area = 0;
    for(int i = 0;i<a.size();i++)
    {
        for(int j = 0;j<a[0].size();j++)
        {
            if(a[i][j])
            {
                his[j]++;
            }
            else
            {
                his[j] = 0;
            }
        }
        //print_vector(his);
        max_area = max(hist_area(his),max_area);
    }
    return max_area;
}
int main()
{
    
    int r,c;
    cin>> r>>c;
    vector<vector<int> >x(r,vector<int> (c,0));
    for(int i = 0;i<r;i++)
    {
        for(int j = 0;j<c;j++)
        {
            cin>>x[i][j];
        }
    }
    int result = maximalRectangle(x);
    cout<<"Result = "<< result;
}