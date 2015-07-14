/*
	Segment tree to sum intervals :
		no of ele	= N
		ht of seg tree  = log2(N)
		size		= 2*(2^ht) + 10		(for N = 10^6 ele take size = 3*(10^6))
*/
#include<iostream>

#define MAXX 1000006

using namespace std;

int *ST;
int ht, size, N, arr[MAXX];

void update(int node, int start, int end, int L, int R, int val){
	if(L>end || R<start) return;
	if(start>=L && end<=R) ST[node] += (end-start+1)*val;
	else{
		update(node<<1, start, (start+end)>>1, L, R, val);
		update((node<<1)+1, ((start+end)>>1)+1, end, L, R, val);
		ST[node] = ST[node<<1] + ST[(node<<1)+1];
	}
}

int query(int node, int start, int end, int L, int R){
	if(L>end || R<start) return 0;
	if(start>=L && end<=R) return ST[node];		//i.e start, end are inside the segment L, R
	int x = query(node<<1, start, (start+end)>>1, L, R);
	int y = query((node<<1)+1, ((start+end)>>1)+1, end, L, R);
return x+y;
}

void build(int node, int start, int end){
	if(start == end) ST[node] = arr[start];
	else{
		build(node<<1, start, (start+end)>>1);
		build((node<<1)+1, ((start+end)>>1)+1, end);
		ST[node] = ST[node<<1] + ST[(node<<1)+1];
	}
}

void init(){
	ht = log2(N);
	size = 2*(pow(2, ht)) + 10;
	ST = new int[size];
	for(int i=0;i<size;i++) ST[i]=0;
}

int main(){
	int Q;
	cin>>N;
	for(int i=0;i<N;i++) cin>>arr[i];
	init();
	build(1, 0, N-1);	
return 0;
}

