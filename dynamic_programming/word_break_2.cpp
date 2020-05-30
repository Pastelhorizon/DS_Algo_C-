#include<bits/stdc++.h>
using namespace std ;
const int ALPHABET_SIZE = 26; 
  
// trie node 
struct TrieNode 
{ 
    struct TrieNode *children[ALPHABET_SIZE]; 
  
    // isEndOfWord is true if the node represents 
    // end of a word 
    bool isEndOfWord; 
}; 
  
// Returns new trie node (initialized to NULLs) 
struct TrieNode *getNode(void) 
{ 
    struct TrieNode *pNode =  new TrieNode; 
  
    pNode->isEndOfWord = false; 
  
    for (int i = 0; i < ALPHABET_SIZE; i++) 
        pNode->children[i] = NULL; 
  
    return pNode; 
} 
  
// If not present, inserts key into trie 
// If the key is prefix of trie node, just 
// marks leaf node 
void insert(struct TrieNode *root, string key) 
{ 
    struct TrieNode *pCrawl = root; 
  
    for (int i = 0; i < key.length(); i++) 
    { 
        int index = key[i] - 'a'; 
        if (!pCrawl->children[index]) 
            pCrawl->children[index] = getNode(); 
  
        pCrawl = pCrawl->children[index]; 
    } 
  
    // mark last node as leaf 
    pCrawl->isEndOfWord = true; 
} 
  
// Returns true if key presents in trie, else 
// false 
bool search(struct TrieNode *root, string key) 
{ 
    struct TrieNode *pCrawl = root; 
  
    for (int i = 0; i < key.length(); i++) 
    { 
        int index = key[i] - 'a'; 
        if (!pCrawl->children[index]) 
            return false; 
  
        pCrawl = pCrawl->children[index]; 
    } 
  
    return (pCrawl != NULL && pCrawl->isEndOfWord); 
} 
void print_dp(vector<vector<int> > &dp)
{
    for(int i = 0;i<dp.size();i++)
    {
        for(int j = 0;j<dp[0].size();j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
}
void subs(string s, vector<vector<int> > &dp, int a, int b, struct TrieNode* root)
{
    if(a>=s.size()||b>=s.size())
    {
        return ;
    }
    if(dp[a][b]!=-1)
    {
        return;
    }
    if(search(root,s.substr(a,b-a+1)))
    {
        dp[a][b] = 1;
    }
    else
    {
        dp[a][b] = 0;
    }
    subs(s,dp,a+1,b+1,root);
    subs(s,dp,a,b+1,root);
}
void sent(int i,int j, int index, string s, vector<string> &texts, vector<vector<int> > &dp)
{
    if(i>=s.size()||j>=s.size())
    {
        //cout<<i<<" "<<j<<" "<<" "<<index<<" size = "<<texts.size()<<" "<<texts[index]<<endl;
        // if(dp[i][j-1]==0)
        // {
        //     cout<<texts[index]<<" (deleted) "<<index<<endl;
        //     texts.erase(texts.begin()+index);
        // }
        return ;
    }
    //cout<<i<<" "<<j<<" "<<" "<<index<<" size = "<<texts.size()<<" "<<texts[index]<<endl;
    if(j==s.size()-1&&dp[i][j]==0)
    {
        //cout<<texts[index]<<" (deleted) "<<index<<endl;
        texts.erase(texts.begin()+index);
        return;
    }
    if(dp[i][j] == 1)
    {
        // if(i==0)
        // {
            
        // }
        // else
        // {

        // }
        
        if(j<s.size()-1)
        {   
            texts.push_back(texts[index]); 
            sent(i,j+1,texts.size()-1,s,texts,dp);
        }
        texts[index].append(s.substr(i,j-i+1));
        texts[index].append(" ");
        //texts[index].append(" ");
        sent(j+1,j+1,index,s,texts,dp);
    }
    else
    {
        sent(i,j+1,index,s,texts,dp);
    }
}
struct TrieNode* make_dict(vector<string> &s)
{   
    TrieNode *root = getNode();
    for(int i = 0;i<s.size();i++)
    {
        insert(root,s[i]);
    }
    return root;
}
vector<string> wordBreak(string a, vector<string> &b) {
    struct TrieNode *root = make_dict(b);
    vector<vector<int> > dp(a.size(),vector<int>(a.size(),-1));
    subs(a,dp,0,0,root);
    //print_dp(dp);
    vector<string> texts;
    texts.push_back("");
    sent(0,0,0,a,texts,dp);
    return texts;
}

int main()
{
    string a = "catsanddog";
    vector<string> b {"cat","cats","sand","and","dog","an","d"};
    struct TrieNode *root = make_dict(b);
    vector<vector<int> > dp(a.size(),vector<int>(a.size(),-1));
    subs(a,dp,0,0,root);
    //print_dp(dp);
    vector<string> texts;
    texts.push_back("");
    sent(0,0,0,a,texts,dp);
    //cout<<texts.size()<<endl;
    for(int i = 0;i<texts.size();i++)
    {
        cout<<texts[i]<<endl;
    }
}