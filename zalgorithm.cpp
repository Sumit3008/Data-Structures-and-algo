#include<bits/stdc++.h>
#include<unistd.h>
 
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
template<class T> T lcm(T a, T b) { return a * (b / gcd(a, b)); }
//to increase stack size : -Wl,--stack,1677721600

string s;
int n, Z[MAXX];

void zval(){
	int L = 0, R = 0;
	for(int i = 1;i<n;i++){
		if(i > R){
			L = R = i;
			while(R < n && s[R-L] == s[R]) R++;
			Z[i] = R-L;R--;
		}else{
			int b = R-i+1;
			if(Z[i-L] < b) Z[i] = Z[i-L];
			//else if(Z[i-L] > b) Z[i] = b;
			else{
				L = i;
				while(R < n && s[R-L] == s[R]) R++;
				Z[i] = R-L;R--;
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("out.txt","w",stdout);

	cin >> s;
	n = s.size();
	zval();

return 0;
}

