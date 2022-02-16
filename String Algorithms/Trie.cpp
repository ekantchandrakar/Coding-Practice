/*   author: ekantchandrakar   */

#include<bits/stdc++.h>

#define ll long long int
#define pb push_back
#define mod 1000000007
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

using namespace std;

int cnt = 0;
struct node {
	node* nxt[26];
	bool is_end;
	node() {
		for(int i = 0; i < 26; i++) {
			nxt[i] = NULL;
		}
		is_end = false;	
		cnt++;
	}
};

node* root = NULL;

// O(|s|)
void insert_trie(string s){
	node* curr = root;
	for(int i = 0; i < s.size(); i++){
		int index = s[i] - 'a';
		// new node 
		if(curr->nxt[index] == NULL){
			curr->nxt[index] = new node();		
		}
		// goto that node down the branch
		curr = curr->nxt[index];	
	}
	// curr -> last node (last node doesnt mean the leaf node)
	curr->is_end = true;
}

// O(|s|)
bool search_trie(string s){
	node* curr = root;
	for(int i = 0; i < s.size(); i++){
		int index = s[i] - 'a';
		if(curr->nxt[index] == NULL){
			return false;
		}
		curr = curr->nxt[index];
	}

	return curr->is_end;	
}

int main() {
	fast_io;
	root = new node();
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		string s;
		cin >> s;
		insert_trie(s);	
	}

	if (search_trie("apar")) {
		cout << "Found";
	} else {
		cout << "Not Found";
	}
	cout << cnt; // to count the no of nodes created including the root node
	return 0;
}
