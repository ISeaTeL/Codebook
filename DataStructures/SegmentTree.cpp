// tree[] store the info in this area, lazy[] store update info
long long tree[100005*4],lazy[100005*4];
inline void up(int r){  // Merge sub-tree info
	tree[r] = tree[r<<1] + tree[r<<1|1];
}
/*
 * Assume N elements in array
 * Using build(1, N, 1) to buile a segment tree
 * Prototype:
 *  build( left end point of array, right end point of array, tree root)
 * So build(1, N, 1) means that we want to build a segment tree from 
 * an array whose left end point is 1 and right end point is N, and
 * the root of segment tree is 1;
*/
void build(int L,int R,int r){
	lazy[r] = 0;
	if(L==R)
		scanf(" %lld",&tree[r]);  // Or tree[r] = array[L]; (if in array
	else{
		int mid = (L+R)>>1;
		build(L,mid,r<<1);  // rec build left-sub-tree
		build(mid+1,R,r<<1|1);  // rec build right-sub-tree
		up(r);  // update parent node with info in child nodes
	}
}
inline void down(int L,int R,int mid,int r){  // sent info to leaf
	lazy[r<<1] += lazy[r];
	lazy[r<<1|1] += lazy[r];
	tree[r<<1] += (mid-L+1)*lazy[r];
	tree[r<<1|1] += (R-mid)*lazy[r];
	lazy[r] = 0;  // Finished, need to reset state
}
long long query(int x,int y,int L,int R,int r){
	if(x<=L && R<=y){  // [L,R] is in [x,y]
		return tree[r];
	}
	long long ans = 0;  // record answer of left and right child tree
	int mid = (L+R)>>1;
	if(lazy[r])  // if need update, do it first
		down(L,R,mid,r);
	if(x<=mid)  // some info in left sub tree, query left
	    ans += query(x,y,L,mid,r<<1);
	if(mid<y)  // some info in right sub tree, query right
		ans += query(x,y,mid+1,R,r<<1|1);
	return ans;
}
void update(int x,int y,int z,int L,int R,int r){
    // Add z to all elements in [x,y]
    //
	if(x<=L && R<=y){  // if [L,R] all in [x,y], directly add z
		lazy[r] +=z;  // using lazy update
		tree[r] += (long long)(R-L+1)*z;  // update the interval
	}
	else{
		int mid = (L+R)>>1;
		if(lazy[r]!=0)  // if it needs update, do it first
			down(L,R,mid,r);
		if(x<=mid)  // left side needs update, go left
			update(x,y,z,L,mid,r<<1);
		if(mid<y)  // right side needs update, go right
			update(x,y,z,mid+1,R,r<<1|1);
		up(r);  // update parent node by children nodes
	}
}
