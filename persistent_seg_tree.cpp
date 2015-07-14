/*
	* Initially we have an array arr of size n
	* We have q update queries i.e creating new versions, and in each update we need to update a 
		single ele in the array.(i.e increase arr[i] by X)
	* We have u ask queries, i.e Q(i, x, y) = in the ith version get the sum from x to y
	* As creating a new version only affects O(log n) nodes, hence we can create these new nodes
	* root array keeps the roots of all versions
*/
#include<bits/stdc++.h>

#define IT(a,it) for(auto it=a.begin(); it != a.end(); it++)
#define REV_IT(a,it) for(auto it=a.rbegin(); it != a.rend(); it++)
#define LL long long
#define LD long double
#define MP make_pair
#define FF first
#define SS second
#define PB push_back
#define INF (int)(1e9)
#define EPS (double)(1e-9)

#ifndef ONLINE_JUDGE
#  define LOG(x) cerr << #x << " = " << (x) << endl
#else
#  define LOG(x) 0
#endif

#define MAXX 500005

using namespace std;

typedef pair <int, int> pi_i;
typedef pair<int, pi_i> pi_ii;

bool cmp(int a, int b){ return a>b; }
template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template<class T> T lcm(T a, T b) { return a * b / gcd(a, b); }

int arr[MAXX], root[MAXX], ST[6*MAXX], L[6*MAXX], R[6*MAXX], n;
int nextIdxFree = 2, ir;

void build(int idx, int start, int end){
	if(start == end){
		ST[idx] = arr[start];return;
	}
	int mid = (start+end)/2;
	L[idx] = nextIdxFree++;
	R[idx] = nextIdxFree++;
	build(L[idx], start, mid);
	build(R[idx], mid+1, end);
	ST[idx] = ST[L[idx]] + ST[R[idx]];
}

//i.e adding a new version, it returns the index of the interval in the new version
int upd(int idx, int start, int end, int idxToUpdate, int valToUpdate){
	int newVerID = nextIdxFree++;
	if(start == end){
		ST[newVerID] = (arr[start]+=valToUpdate);
		return newVerID;
	}
	int mid = (start+end)/2;
	L[newVerID] = L[idx], R[newVerID] = R[idx];	//in case when we do not update interval of left or right chld
	if(idxToUpdate <= mid){		//go to the left seg
		L[newVerID] = upd(L[newVerID], start, mid, idxToUpdate, valToUpdate);
	}else{
		R[newVerID] = upd(R[newVerID], mid+1, end, idxToUpdate, valToUpdate);
	}
	ST[newVerID] = ST[L[newVerID]] + ST[R[newVerID]];
	return newVerID;
}

int sum(int idx, int start, int end, int ll, int rr){
	if(start > rr || end < ll) return 0;
	if(start >= ll && end <= rr) return ST[idx];
	int mid = (start+end)/2;
	return sum( L[idx], start, mid, ll, rr) + sum( R[idx], mid+1, end, ll, rr);
}

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("out.txt","w",stdout);
	
	cin >> n;
	for(int i=0;i<n;i++) cin >> arr[i];
	
	build(1, 0, n-1);
	root[0] = 1;	//index of the initial seg tree
	
	//cout << sum(root[0], 0, n-1, 0, 4) << endl;
	
	int q, u;
	
	cin >> q;
	
	int id, val;
	for(int i=1;i<=q;i++){
		cin >> id >> val;
		root[i] = upd(root[i-1], 0, n-1, id, val);	//using prev version to create new ver
	}
	cin >> u;
	int ver, xx, yy;
	while( u-- ){
		cin >> ver >> xx >> yy;
		cout << sum(root[ver], 0, n-1, xx, yy) << endl;
	}
return 0;
}
