/*   author: ekantchandrakar   */

#include<bits/stdc++.h>

#define ll long long int
#define pb push_back
#define mod 1000000007
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

using namespace std;

void generateBrackets(string output, int n, int open, int close, int i){
	// Base case
	if(i == 2 * n){
		cout << output << endl;
		return;
	}	

	// Opening Bracket at ith position 
	if(open < n){
		generateBrackets(output + '(', n, open + 1, close, i + 1);
	}

	// Closing Bracket at ith position
	if(close < open){
		generateBrackets(output + ')', n, open, close + 1, i + 1);
	}
}

void generateBrackets2(string output, int n, int open, int close, int i){
	// Base case
	if(i == 2 * n){
		cout << output << endl;
		return;
	}	

	// Opening Bracket at ith position 
	if(open < n){
		output += '(';
		generateBrackets2(output, n, open + 1, close, i + 1);
		output.pop_back();
	}

	// Closing Bracket at ith position
	if(close < open){
		output += ')';
		generateBrackets2(output, n, open, close + 1, i + 1);
		output.pop_back();
	}
}

void solve(){
	string output;
	int n;
	cin >> n;
	generateBrackets(output, n, 0, 0, 0);	
}

int main() {
	fast_io;
	
	int t = 1; // cin >> t;
	while(t--){
		solve();
	}

	return 0;
}
