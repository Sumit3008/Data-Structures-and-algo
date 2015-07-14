#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

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
using namespace __gnu_pbds;

typedef pair <int, int> pi_i;
typedef pair<int, pi_i> pi_ii;

bool cmp(int a, int b){ return a>b; }
template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template<class T> T lcm(T a, T b) { return a * b / gcd(a, b); }

typedef tree <int, null_type, less<int>, rb_tree_tag, 
	tree_order_statistics_node_update> OS_Tree;

//X.find_by_order(k) -->	gives the kth order statistic(i.e kth smallest element)	(returns iterator)
//X.order_of_key(k)  -->	gives the no of ele strictly smaller than k (returns int(key))
int main(){
	ios_base::sync_with_stdio(false);
	//freopen("out.txt","w",stdout);
	
	OS_Tree X;
	X.insert(1);X.insert(2);X.insert(4);X.insert(8);X.insert(16);
	
	OS_Tree::iterator it = X.find_by_order(2);	//4 (kth smallest)
	cout << *it << endl;
	
	
	int ord = X.order_of_key(-5);	//gives the no of items smaller than -5
	cout << ord << endl;
	
	
	ord = X.order_of_key(3);		//gives the no of items strictly smaller than key
	cout << ord << endl;
return 0;	
}
