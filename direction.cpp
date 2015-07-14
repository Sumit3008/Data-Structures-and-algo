#include<iostream>
#include<algorithm>

#define MP make_pair
#define FF first
#define SS second

using namespace std;

typedef pair<int, int> pi_i;

int crossProd(pi_i A, pi_i B){
	return (A.FF*B.SS - A.SS*B.FF);
}

int direction(pi_i p0, pi_i p1, pi_i p2){	//gives  orientation of first vector w.r.t. the other, 
						//i.e if +ve first is clockwise w.r.t second
	//vec(p0->p1) ==> shifting to (0,0) ==> vec(p1 - p0) ==> gives vector p1 originating from (0,0)
	pi_i vector1 = MP(p1.FF - p0.FF, p1.SS - p0.SS);	//shifting to origin
	pi_i vector2 = MP(p2.FF - p0.FF, p2.SS - p0.SS);
return crossProd(vector1, vector2);
}

int main(){
	pi_i A, B, C;
	cin>>A.FF>>A.SS;
	cin>>B.FF>>B.SS;
	cin>>C.FF>>C.SS;
	
	cout<<direction(A, B, C)<<endl;		//gives direcn of vec AB w.r.t AC i.e +ve or -ve
return 0;
}
