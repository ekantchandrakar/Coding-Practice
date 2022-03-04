/*   author: ekantchandrakar   */

#include<bits/stdc++.h>

#define ll long long int
#define pb push_back
#define mod 1000000007
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

using namespace std;

void solve(){
	int n;
	cin >> n;
	string s, t;
	cin >> s >> t;

	vector<int> vec1, vec2;

	for(int i = 0; i < n; i++){
		if(s[i] == 'a' && t[i] == 'b'){
			vec1.pb(i);
		} 
		if(s[i] == 'b' && t[i] == 'a'){
			vec2.pb(i);
		} 
	}

	if(vec1.size() % 2 != vec2.size() % 2){
		cout << -1;
		return;
	}

	vector<pair<int, int>> p;
	while(vec1.size() && vec1.size() > 1){
		int j = vec1.back();
		vec1.pop_back();

		int k = vec1.back();
		vec2.pop_back();

		swap(s[j], t[k]);

		p.push_back({j, k});
	}
	while(vec2.size() && vec2.size() > 1){
		int j = vec2.back();
		vec2.pop_back();

		int k = vec2.back();
		vec2.pop_back();

		swap(s[j], t[k]);

		p.push_back({j, k});
	}

	while(vec1.size() && vec2.size()){
		int j = vec1.back();
		vec1.pop_back();

		int k = vec2.back();
		vec2.pop_back();


		swap(s[j], t[j]);
		swap(s[j], t[k]);

		p.push_back({j, j});
		p.push_back({j, k});
	}
	cout << p.size() << endl;
	for(auto i: p){
		cout << i.first + 1 << " " << i.second + 1<< endl;
	}
}

int main() {
	fast_io;
	
	int t = 1; // cin >> t;
	while(t--){
		solve();
	}

	return 0;
}
