/*
 * 2D BIT, spoj problem MATSUM
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

#define MAXX 1200

using namespace std;

typedef pair <int, int> pi_i;
typedef pair<int, pi_i> pi_ii;

bool cmp(int a, int b){ return a>b; }
template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template<class T> T lcm(T a, T b) { return a * b / gcd(a, b); }

int n, BIT[MAXX][MAXX];
char str[20];

void upd(int x, int y, int val){
	int y1;
	while(x <= n){
		y1 = y;
		while(y1 <= n){
			BIT[x][y1] += val;
			y1 += (y1 & -y1);
		}
		x += (x & -x);
	}
}

int query(int x, int y){
	int y1, sum = 0;
	while(x > 0){
		y1 = y;
		while(y1 > 0){
			sum += BIT[x][y1];
			y1 -= (y1 & -y1);
		}
		x -= (x & -x);
	}
	return sum;
}

int main(){
	//ios_base::sync_with_stdio(false);cin.tie(0);
	//freopen("out.txt","w",stdout);
	
	int t, x1, y1, v, x2, y2;
	scanf("%d", &t);
	
	while(t--){
		scanf("%d", &n);
		scanf("%s", str);
		while(str[0] != 'E'){
			if(str[1] == 'E'){
				scanf("%d%d%d", &x1, &y1, &v);x1++;y1++;
				x2 = x1;y2 = y1;
				LL temp = query(x2, y2) - query(x2, y1-1) - query(x1-1, y2) + query(x1-1, y1-1);
				upd(x1, y1, v-temp);
			}else{
				scanf("%d%d%d%d", &x1, &y1, &x2, &y2);x1++;x2++;y1++;y2++;
				int ans = query(x2, y2) - query(x2, y1-1) - query(x1-1, y2) + query(x1-1, y1-1);
				printf("%d\n", ans);
			}
			scanf("%s", str);
		}
		for(int i = 0;i<=n;i++) for(int j = 0;j<=n;j++) BIT[i][j] = 0;
		printf("\n");
	}

return 0;
}
