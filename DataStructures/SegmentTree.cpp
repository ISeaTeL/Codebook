// tree[]記錄這個區間的資訊, lazy[]紀錄更新資訊 (延遲標記)
long long tree[100005*4],lazy[100005*4];
inline void up(int r){  // 統合子樹資訊
	tree[r] = tree[r<<1] + tree[r<<1|1];
}
/*
假設有N個元素的陣列, 建成segment tree的呼叫方式為 build(1,N,1)
build ( 陣列左端點位置, 陣列右端點位置, segment tree的root位置)
所以我們要建一個從陣列左端 1, 右端 N, 並且整棵樹的root從 1 開始的線段樹
root不建議從0開始 ( code比較醜
*/
void build(int L,int R,int r){
	lazy[r] = 0;
	if(L==R)
		scanf(" %lld",&tree[r]);  // 或tree[r] = array[L]; ( 如果存在array裡的話
	else{
		int mid = (L+R)>>1;
		build(L,mid,r<<1);  // 遞迴建造左子樹
		build(mid+1,R,r<<1|1);  // 遞迴建造右子樹
		up(r);  // 遞迴回來時, 用子節點更新父節點的內容
	}
}
inline void down(int L,int R,int mid,int r){  // 資訊向下傳遞
	lazy[r<<1] += lazy[r];
	lazy[r<<1|1] += lazy[r];
	tree[r<<1] += (mid-L+1)*lazy[r];
	tree[r<<1|1] += (R-mid)*lazy[r];
	lazy[r] = 0;  // 傳完後一定要記得回初始狀態
}
long long query(int x,int y,int L,int R,int r){
	if(x<=L && R<=y){  // 如果現在的[L,R] 包含於 [x,y] 則直接回傳
		return tree[r];
	}
	long long ans = 0;  // 紀錄左右子樹的答案
	int mid = (L+R)>>1;
	if(lazy[r])  // 如果有需要更新的話, 先向下更新, 不先更新的話, 等等遞迴資訊會錯
		down(L,R,mid,r);
	if(x<=mid)  // 如果x <= mid, 表示有資訊在左子樹, 要遞迴去取得
		ans += query(x,y,L,mid,r<<1);
	if(mid<y)  // 如果y > mid, 表示有資訊在右子樹, 要遞迴去取得
		ans += query(x,y,mid+1,R,r<<1|1);
	return ans;
}
void update(int x,int y,int z,int L,int R,int r){  // 把[x,y]區間都加上z這個值
	if(x<=L && R<=y){  // 如果現在的[L,R] 包含於 [x,y] 則直接加上這個值
		lazy[r] +=z;  // 延遲更新累加
		tree[r] += (long long)(R-L+1)*z;  // 這個區間的和增加了這麼多
	}
	else{
		int mid = (L+R)>>1;
		if(lazy[r]!=0)  // 如果有需要更新的話, 先向下更新, 不先更新的話, 等等遞迴資訊會錯
			down(L,R,mid,r);
		if(x<=mid)  // 左邊需要更新的話, 遞迴更新左子樹
			update(x,y,z,L,mid,r<<1);
		if(mid<y)  // 右邊需要更新的話, 遞迴更新右子樹
			update(x,y,z,mid+1,R,r<<1|1);
		up(r);  // 左右子樹結束後, 利用左右子樹更新目前這個父節點的資訊
	}
}
