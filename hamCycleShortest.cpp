/*
	Shortest Hamiltonian cycle : cover all vertices(not a cycle) 
	using (DP + Bitmask)
	Complexity = O(2^n * n^2) time, memory = O(2^n * n)
	
	Source : http://codeforces.com/blog/entry/337
	
	Notation : 
			1) bit(i, mask) - the ith bit of the mask
			2) count(mask) - no of nonzero bits in the mask (__builtin_popcount(mask))
			3) dp[mask][i] - length of the shortest ham walk generated by vertices in mask that
			   starts at 0 and ends at i.
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>

#define INF 1e9
#define MAXX 20
#define SUBSETS 1100000		//2^20 = 1048575 

using namespace std;

int dp[SUBSETS][MAXX], n, m, d[MAXX+5][MAXX+5];
int ans = INF, ansI = 0;

int bit(int idx, int mask){
	int bit = 0;
	for(int i=0;i<=idx;i++) bit = mask & 1, mask=mask >> 1;
return bit;
}

int poww(int a, int b){
	if(b==0) return 1;if(b==1) return a;
	if(b%2==0){ return poww(a*a, b/2); }
	return a*poww(a*a, b/2);
}

void recoverWalk(){
	int mark[MAXX];
	for(int i=0;i<n;i++) mark[i]=0;
	
	cout<<"HAM CYCLE : ";
	int currNode = ansI, mask = poww(2, n)-1;
	cout<<"0 "<<currNode<<" ";
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n;j++){
			if(j != currNode && mark[j]==0){
				if(dp[mask][currNode] == dp[mask ^ poww(2, currNode)][j] + d[currNode][j]){
					mask = mask ^ poww(2, currNode);
					cout<<j<<" ";
					currNode = j;
					mark[j]=1;
					break;
				}
			}
		}
	}
	cout<<endl;
}

int main(){
	memset(dp, -1, sizeof dp);
	
	cin>>n>>m;
	
	int p, q, wt;
	for(int i=0;i<n;i++) for(int j=0;j<n;j++) d[i][j]=INF;
	for(int i=0;i<m;i++){
		cin>>p>>q>>wt;
		d[p][q]=wt;d[q][p]=wt;
	}
	
	dp[1][0] = 0;	//only one node i.e node 0, therefore no cycle
	for(int mask=1;mask<(1<<n);mask++){
		for(int i=0;i<n;i++){
			if(__builtin_popcount(mask) > 1 && bit(i, mask) == 1 && bit(0, mask) == 1 && i>0){
				int minn = INF;
				for(int j=0;j<n;j++){
					if(bit(j, mask) == 1 && d[i][j] != INF && i != j){
						//dp[mask ^ poww(2, i)][j] = min dist of all vertices in mask that end at j
						//which exclude i and starts at 0.
						minn = min(minn, dp[mask ^ (1<<i)][j] + d[j][i]);	//adding i
					}
				}
				dp[mask][i] = minn;
			}else dp[mask][i] = INF;
		}
	}
	
	ans = INF, ansI = 0;
	for(int i=1;i<n;i++){
		if(ans > dp[(1<<n)-1][i] + d[0][i]) ans = dp[(1<<n)-1][i] + d[0][i], ansI = i;
	}
	if(n > 2)cout<<ans<<endl;
	else cout<<INF<<endl;
	
	if(ans < INF && n > 2){
		recoverWalk();
	}
return 0;
}
