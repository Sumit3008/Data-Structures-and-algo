/*
	BINARY INDEXED TREE
	
	INPUT : array A[1 . . . . N];
*/
#include<stdio.h>
#include<iostream>
#include<algorithm>

#define MAXX 1000006

using namespace std;

int BIT[MAXX], N, A[MAXX];

void update(int idx, int val){		//A[idx] += val;
	while(idx <= N){
		BIT[idx] += val;
		idx += (idx & -idx);	// i = 20 = 10100b ==>  (i & -i) = 100b, i.e gives no generated by last occuring 1
	}
}

//eg : idx = 13 = 1101b
//	1st 1 at 0 : 2^0 = 1(idx & -idx)	===>  idx = idx - (idx & -idx) ==> idx = 13 - 1 = 12 = 1100b
//	2nd 1 at 2 : 2^2 = 4(idx & -idx)	===>  idx = idx - (idx & -idx) ==> idx = 12 - 4 = 8  = 1000b
//	3rd 1 at 3 : 2^3 = 8(idx & -idx)	===>  idx = idx - (idx & -idx) ==> idx = 8 - 8 = 0   = 0000b
//	hence we sum for query : Query[13] = BIT[12] + BIT[8] + BIT[0];

int query(int idx){	//sum from 1....idx
	int sum = 0;
	while(idx > 0){
		sum += BIT[idx];
		idx -= (idx & -idx);
	}
return sum;
}

int main(){
	cin>>N;
	for(int i=1;i<=N;i++){
		cin>>A[i];
		update(i, A[i]);
	}
return 0;
}


