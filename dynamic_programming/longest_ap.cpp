int Solution::solve(const vector<int> &a) {
    vector<int> A=a;
    int ans = 2; 
    int n = A.size(); 
    if (n <= 2) 
        return n; 
  
    vector<int> llap(n, 2); 
  
    sort(A.begin(), A.end()); 
  
    for (int j = n - 2; j >= 0; j--) 
    { 
        int i = j - 1; 
        int k = j + 1; 
        while (i >= 0 && k < n) 
        { 
            if (A[i] + A[k] == 2 * A[j]) 
            { 
                llap[j] = max(llap[k] + 1, llap[j]); 
                ans = max(ans, llap[j]); 
                i -= 1; 
                k += 1; 
            } 
            else if (A[i] + A[k] < 2 * A[j]) 
                k += 1; 
            else
                i -= 1; 
        } 
    } 
    return ans; 
}