/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
long res;
long max_track(TreeNode* a,int index)
{
    if(a->left==NULL&&a->right==NULL)
    {
        if(a->val>res)
            res = a->val;
        return a->val;
    }
    long l_sum = INT_MIN;
    if(a->left!=NULL)
    {
        l_sum =a->val+ max_track(a->left,index*2+1);
    }
    
    long r_sum = INT_MIN;
    if(a->right!=NULL)
    {
        r_sum = a->val+ max_track(a->right,index*2+2);
    }
    
    long max_sum = max((l_sum+r_sum-long(a->val)),max(long(a->val),max(l_sum,r_sum)));
   
    if(max_sum>res)
            res = max_sum;
    return max(long(a->val),max(l_sum,r_sum));
}
int Solution::maxPathSum(TreeNode* a) {
    res = INT_MIN;
   max_track(a,0);
    return int(res);
}