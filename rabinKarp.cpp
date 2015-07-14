#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string>
#include<cstdlib>
#include<cstring>

#define LL long long

#define MAXX 100005
#define PRIME1 1000000007
#define PRIME2 1000000009

using namespace std;

string T, P;	//T = text, P = pattern
int N, M; 
LL hashP, hashT, base = 256;

LL power(LL a, LL b, LL mod){
	if(b == 0) return 1;
	else if(b == 1) return a%mod;
	else if(b%2 == 0) return (power((a*a)%mod, b/2, mod)%mod);
	else{
		LL aa = power((a*a)%mod, b/2, mod)%mod;
		return ((a*aa)%mod);
	}
}

void search(){
	LL magic = power(base, M-1, PRIME1);
	
	//initial hash
	for(int i=0;i<M;i++){
		hashP = (hashP*base + P[i]) % PRIME1;
		hashT = (hashT*base + T[i]) % PRIME1;
	}
	
	for(int i=0;i<=N-M;i++){
		if(hashP == hashT){
			//can check for char 1 by one, or can use hashes with 2 bases
			//and 2 primes so that prob of collisions is very low
			cout<<"Match at : "<<i<<endl;
		}
		if(i < N-M){
			hashT = (base*(hashT - T[i]*magic) + T[i+M]) % PRIME1;
			while(hashT < 0) hashT += PRIME1;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	
	cin>>T>>P;
	N = T.size();
	M = P.size();		
	search();
return 0;
}


