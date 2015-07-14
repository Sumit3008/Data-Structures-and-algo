#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>

#define PB push_back

using namespace std;

typedef pair <int, int> pi_i;
typedef pair<int, pi_i> pi_ii;

bool cmp(int a, int b){ return a>b; }
template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template<class T> T lcm(T a, T b) { return a * b / gcd(a, b); }

int n, a[20];

void permute(int idx, vector<int> vv){
	if(idx >= n){
		for(int i=0;i<vv.size();i++) cout<<vv[i]<<" ";cout<<endl;
		return;
	}
	for(int j=idx;j<n;j++){		//we start from idx to cover cases where idx stays at the same pos'n
		swap(vv[idx], vv[j]);
		permute(idx+1, vv);
		swap(vv[idx], vv[j]);	//backtrack step
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("out.txt","w",stdout);
	
	cin>>n;
	vector<int> vv;
	for(int i=0;i<n;i++) cin>>a[i], vv.PB(a[i]);
	permute(0, vv);
return 0;
}


