/*   author: ekantchandrakar   */

#include<bits/stdc++.h>

#define ll long long int
#define pb push_back
#define mod 1000000007
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

using namespace std;

// summation
struct segmentTree {
	int n;
	vector<int> st;

	void init(int _n){
		this -> n = _n;
		st.resize(4*n, 0);
	}

	void build(int start, int end, int node, vector<int> &v){
		// leaf node as the base case
		if(start == end) {
			st[node] = v[start];
			return;
		}			

		int mid = (start + end) / 2;
		
		build(start, mid, 2 * node , v); // left subtree [start, mid]
		
		build(mid + 1, end, 2 * node + 1, v); // right subtree [mid + 1, end]

		st[node] = min(st[2*node], st[2* node + 1]);
	}

	int query(int start, int end, int node, int l, int r){
		// No overlapping 
		if(r < start || end < l){
			return INT_MAX;
		}

		// complete overlapping
		if(l <= start && end <= r){
			return st[node];
		}

		// partial overlapping (do D/C)
		int mid = (start + end) / 2;
		int q1 = query(start, mid, 2*node, l, r);
		int q2 = query(mid + 1, end, 2*node + 1, l, r);

		return min(q1, q2);
	}

	void build(vector<int> &v){
		build(0, n - 1, 1, v);
	}

	int query(int l, int r){
		query(0, n - 1, 1, l, r);
	}
};

void solve(){
	int n, q;
	cin >> n >> q;
	vector<int> v(n);
	for(int i = 0; i < n; i++){
		cin >> v[i];
	}

	segmentTree tree;
	tree.init(n);

	tree.build(v);

	/*
	for(int i = 0; i < 15; i++){
		cout << tree.st[i] << endl;
	}
	*/
	for(int i = 1; i <= q; i++){
		int l, r;
		cin >> l >> r;
		cout << tree.query(l - 1, r - 1) << endl;
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
