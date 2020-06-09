// CPP code for demonstrating 
// string::compare (const string& str) const 

#include<iostream> 
using namespace std; 

void compareOperation(string s1, string s2) 
{ 
	// returns a value < 0 (s1 is smaller then s2) 
	if((s1.compare(s2)) < 0) 
		cout << s1 << " is smaller than " << s2 << endl; 

	// returns 0(s1, is being comapared to itself) 
	if((s1.compare(s1)) == 0) 
		cout << s1 << " is equal to " << s1 << endl; 
	else
		cout << "Strings didn't match "; 
	
} 

// Driver Code 
int main() 
{ 
	string s1("01"); 
	string s2("010"); 
	compareOperation(s1, s2); 
	
	return 0; 
} 
