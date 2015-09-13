#include<iostream>

using namespace std;

int a[1000005];

int find(int val){
	if(a[val] < 0) return val;	//negative val means we found root
	else{
		a[val] = find(a[val]);
		return a[val];
	}
}

void merge(int ele1, int ele2){
	int root1 = find(ele1), root2 = find(ele2);	//finding what tree both elements belong to
	if(root1 == root2) return;
	if(a[root1] < a[root2]){	//merge root2 into root1 (because they are negative no's)
		a[root1] += a[root2];	//adding the count of the 2 trees
		a[root2] = root1;	//changing the parent pointer
	}else{
		a[root2] += a[root1];
		a[root1] = root2;
	}
}

int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++) a[i] = -1;
return 0;
}

