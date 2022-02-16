/*   author: ekantchandrakar   */

#include<bits/stdc++.h>

#define ll long long int
#define pb push_back
#define mod 1000000007
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

using namespace std;

void naivePatternSearchUsingSTL() {
	string text = "abaabaaabbaabbaababaab";
	string pattern = "ab";
	int n = text.length();
	int m = pattern.length();

	for(int i = 0; i <= n - m; i++){ // T.C. O((n - m)*m)
		if(text.substr(i, m) == pattern){
			cout << i << " ";
		}
	}
	cout << endl;
}

void naivePatternSearch() {
	string text = "abaabaaabbaabbaababaab";
	string pattern = "ab";
	int n = text.length();
	int m = pattern.length();

	for(int i = 0; i <= n - m; i++){
		int j;
		for(j = 0; j < m; j++){
			if(text[i + j] != pattern[j]){
				break;
			}
		}

		if(j == m){ // pattern matched
			cout << i << " ";
		}
	}
}

void solve(){
	naivePatternSearchUsingSTL();
	naivePatternSearch();	
}

int main() {
	fast_io;
	
	int t = 1; // cin >> t;
	while(t--){
		solve();
	}

	return 0;
}
 