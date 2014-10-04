// tree[]�O���o�Ӱ϶�����T, lazy[]������s��T (����аO)
long long tree[100005*4],lazy[100005*4];
inline void up(int r){  // �ΦX�l���T
	tree[r] = tree[r<<1] + tree[r<<1|1];
}
/*
���]��N�Ӥ������}�C, �ئ�segment tree���I�s�覡�� build(1,N,1)
build ( �}�C�����I��m, �}�C�k���I��m, segment tree��root��m)
�ҥH�ڭ̭n�ؤ@�ӱq�}�C���� 1, �k�� N, �åB��ʾ�root�q 1 �}�l���u�q��
root����ĳ�q0�}�l ( code�����
*/
void build(int L,int R,int r){
	lazy[r] = 0;
	if(L==R)
		scanf(" %lld",&tree[r]);  // ��tree[r] = array[L]; ( �p�G�s�barray�̪���
	else{
		int mid = (L+R)>>1;
		build(L,mid,r<<1);  // ���j�سy���l��
		build(mid+1,R,r<<1|1);  // ���j�سy�k�l��
		up(r);  // ���j�^�Ӯ�, �Τl�`�I��s���`�I�����e
	}
}
inline void down(int L,int R,int mid,int r){  // ��T�V�U�ǻ�
	lazy[r<<1] += lazy[r];
	lazy[r<<1|1] += lazy[r];
	tree[r<<1] += (mid-L+1)*lazy[r];
	tree[r<<1|1] += (R-mid)*lazy[r];
	lazy[r] = 0;  // �ǧ���@�w�n�O�o�^��l���A
}
long long query(int x,int y,int L,int R,int r){
	if(x<=L && R<=y){  // �p�G�{�b��[L,R] �]�t�� [x,y] �h�����^��
		return tree[r];
	}
	long long ans = 0;  // �������k�l�𪺵���
	int mid = (L+R)>>1;
	if(lazy[r])  // �p�G���ݭn��s����, ���V�U��s, ������s����, �������j��T�|��
		down(L,R,mid,r);
	if(x<=mid)  // �p�Gx <= mid, ��ܦ���T�b���l��, �n���j�h���o
		ans += query(x,y,L,mid,r<<1);
	if(mid<y)  // �p�Gy > mid, ��ܦ���T�b�k�l��, �n���j�h���o
		ans += query(x,y,mid+1,R,r<<1|1);
	return ans;
}
void update(int x,int y,int z,int L,int R,int r){  // ��[x,y]�϶����[�Wz�o�ӭ�
	if(x<=L && R<=y){  // �p�G�{�b��[L,R] �]�t�� [x,y] �h�����[�W�o�ӭ�
		lazy[r] +=z;  // �����s�֥[
		tree[r] += (long long)(R-L+1)*z;  // �o�Ӱ϶����M�W�[�F�o��h
	}
	else{
		int mid = (L+R)>>1;
		if(lazy[r]!=0)  // �p�G���ݭn��s����, ���V�U��s, ������s����, �������j��T�|��
			down(L,R,mid,r);
		if(x<=mid)  // ����ݭn��s����, ���j��s���l��
			update(x,y,z,L,mid,r<<1);
		if(mid<y)  // �k��ݭn��s����, ���j��s�k�l��
			update(x,y,z,mid+1,R,r<<1|1);
		up(r);  // ���k�l�𵲧���, �Q�Υ��k�l���s�ثe�o�Ӥ��`�I����T
	}
}
