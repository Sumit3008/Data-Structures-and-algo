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
	pi_i vector1 = MP(p1.FF - p0.FF, p1.SS - p0.SS);
	pi_i vector2 = MP(p2.FF - p0.FF, p2.SS - p0.SS);
return crossProd(vector1, vector2);
}

bool pointOnSegment(pi_i A, pi_i B, pi_i P){
	if(min(A.FF, B.FF) <= P.FF && max(A.FF, B.FF) >= P.FF
		&&
		min(A.SS, B.SS) <= P.SS && max(A.SS, B.SS) >= P.SS) return true;
return false;
}

bool doSegIntersect(pi_i A, pi_i B, pi_i C, pi_i D){
	int d1 = direction(A, B, C);	//direcn of C w.r.t AB
	int d2 = direction(A, B, D);
	int d3 = direction(C, D, A);
	int d4 = direction(C, D, B);
	if((d1 > 0 && d2 < 0) || (d1 < 0 && d2 > 0)
		&&
		(d3 > 0 && d4 < 0) || (d3 < 0 && d4 > 0)) return true;
	if(d1==0 && pointOnSegment(A, B, C)) return true; 
	if(d2==0 && pointOnSegment(A, B, D)) return true;
	if(d3==0 && pointOnSegment(C, D, A)) return true;
	if(d4==0 && pointOnSegment(C, D, B)) return true;
return false;
}

int main(){
	pi_i A, B, C, D;
	cin>>A.FF>>A.SS;
	cin>>B.FF>>B.SS;
	cin>>C.FF>>C.SS;
	cin>>D.FF>>D.SS;
	
	bool b = doSegIntersect(A, B, C, D);	//segments are AB and CD
	cout<<b<<endl;
return 0;
}

