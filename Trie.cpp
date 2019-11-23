#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<deque>
#include<string>
#include<limits.h>
#include<vector>
#include<cmath>
#include<cstdlib>
#include<cassert>
#include<cctype>
#include<cstring>

#define IT(a,it) for(auto it=a.begin(); it != a.end(); it++)
#define ITT(a,it) for(typeof(a.begin()) it=a.begin();it!=a.end();it++)
#define REV_IT(a,it) for(auto it=a.rbegin(); it != a.rend(); it++)
#define REV_ITT(a,it) for(typeof(a.rbegin()) it=a.rbegin(); it != a.rend(); it++)
#define LL long long
#define LD long double
#define MP make_pair
#define FF first
#define SS second
#define PB push_back
#define INF (int)(1e9)
#define L_INF (LL)(1e18)
#define EPS (double)(1e-9)
#define L_EPS (LD)(1e-18)
#define PI (double)(3.141592653589793238)

#ifndef ONLINE_JUDGE
#  define LOG(x) cerr << #x << " = " << (x) << endl
#else
#  define LOG(x) 0
#endif

#define MAXX 100005
#define ALPHABET_SIZE 28

using namespace std;

typedef pair <int, int> pi_i;
typedef pair<int, pi_i> pi_ii;

bool cmp(int a, int b){ return a>b; }
template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template<class T> T lcm(T a, T b) { return a * b / gcd(a, b); }

struct node{
	bool isEnd;
	int ct;
	struct node *child[ALPHABET_SIZE];	
};

typedef struct node *Node;
Node head;

int n;
string words[MAXX];

LL get(string msg){
	Node curr = head;
	LL ans = 0;
	for(int i=0;i<msg.size();i++){
		int chr = msg[i]-'a';
		curr = curr->child[chr];
		ans++;
		//cout<<msg[i];
		if(curr->ct == 1) return ans;
	}
	//cout<<endl<<endl;
return ans;
}

void insert(string msg){
	Node curr = head;
	for(int i=0;i<msg.size();i++){
		int chr = msg[i]-'a';
		if(curr->child[chr] == NULL){
			curr->child[chr] = new node();
			curr->child[chr]->ct = 0;
		}
		curr = curr->child[chr];
		curr->ct++;
	}
	curr->isEnd = true;
}

void init(){
	head = NULL;
	head = new node();
	head->isEnd = false;
	head->ct = 0;
}

int main(){
	ios_base::sync_with_stdio(false);
	freopen("inn2.txt","r",stdin);
	freopen("out.txt","w",stdout);
	
	int t;
	//t = 100;
	cin>>t;
	int cas = 1;
	while(t--){
		init();
		cin>>n;
		//n = 100000;
		LL ans = 0;
		for(int i=0;i<n;i++){
			cin>>words[i];
			//words[i] = "abcdefghij";
			insert(words[i]);
			LL val = get(words[i]);
			ans += val;
			//LOG(val);
		}
		cout<<"Case #"<<cas<<": ";cas++;
		cout<<ans<<endl;
	}
return 0;	
}
