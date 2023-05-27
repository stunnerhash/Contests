#include <bits/stdc++.h>
using namespace std;


struct Node {
    int start, end;
    int max_range, max_prefix, max_suffix, sum;
};

vector<Node> seg_tree;

Node merge_nodes(const Node& left, const Node& right) {
    Node parent;
    parent.start = left.start;
    parent.end = right.end;
    parent.sum = left.sum + right.sum;
    parent.max_prefix = max(left.max_prefix, left.sum + right.max_prefix);
    parent.max_suffix = max(right.max_suffix, right.sum + left.max_suffix);
    parent.max_range = max({left.max_range, right.max_range, left.max_suffix + right.max_prefix});
    return parent;
}

void build_tree(const vector<int>& arr, int idx, int start, int end) {
    if (start == end) {
        seg_tree[idx].start = start;
        seg_tree[idx].end = end;
        seg_tree[idx].max_range = 1;
        seg_tree[idx].max_prefix = 1;
        seg_tree[idx].max_suffix = 1;
        seg_tree[idx].sum = arr[start];
        return;
    }

    int mid = (start + end) / 2;
    build_tree(arr, 2 * idx + 1, start, mid);
    build_tree(arr, 2 * idx + 2, mid + 1, end);
    seg_tree[idx] = merge_nodes(seg_tree[2 * idx + 1], seg_tree[2 * idx + 2]);
}

Node query_tree(int idx, int start, int end, int qstart, int qend) {
    if (qstart > end || qend < start) {
        Node null_node;
        null_node.max_range = 0;
        return null_node;
    }
    if (qstart <= start && qend >= end) {
        return seg_tree[idx];
    }

    int mid = (start + end) / 2;
    Node left_node = query_tree(2 * idx + 1, start, mid, qstart, qend);
    Node right_node = query_tree(2 * idx + 2, mid + 1, end, qstart, qend);
    if (left_node.max_range == 0) {
        return right_node;
    }
    if (right_node.max_range == 0) {
        return left_node;
    }
    return merge_nodes(left_node, right_node);
}



void solve(){
	int n,q; cin>>n>>q;
	vector<int> a(n),b(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];	
	b[0] = 0;
	for(int i = 1;i<n;i++){
		if(a[i]>a[i-1]) b[i] = b[i-1];
		else b[i] = 1 - b[i-1];
	}
	cerr<<endl;
	seg_tree.resize(4 * n);

    build_tree(b, 0, 0, n - 1);

	while(q--){
		int l,r; cin>>l>>r;
		l--; r--;
		Node res =  query_tree(0, 0,n-1, l, r);
		int left = 
		cout<<rng.first+1<<' '<< rng.second+1<<endl;
		for(int i = rng.first;i<=rng.second;i++) cerr<<b[i]<<' ';
		cerr<<endl;
	}	
}

signed main() {
	solve();
	return 0;
}
// If it works... don't touch it.