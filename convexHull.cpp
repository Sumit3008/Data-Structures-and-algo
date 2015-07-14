#include<iostream>
#include<algorithm>
#include<utility>
#include<vector>

#define MP make_pair
#define FF first
#define SS second
#define PB push_back

#define MAXX 100005

using namespace std;

typedef pair<int, int> pi_i;

pi_i initPoint;
vector<pi_i> points;
int n;

int dist(pi_i p1, pi_i p2){	//be careful for overflows
	return ((p1.FF-p2.FF) * (p1.FF-p2.FF)) + ((p1.SS-p2.SS) * (p1.SS-p2.SS));
}

int crossProd(pi_i A, pi_i B){
	return (A.FF*B.SS - A.SS*B.FF);
}

int direction(pi_i p0, pi_i p1, pi_i p2){	//gives  orientation of first vector w.r.t. the other, 
						//i.e if +ve first is clockwise w.r.t second
	pi_i vector1 = MP(p1.FF - p0.FF, p1.SS - p0.SS);	//shifting to origin
	pi_i vector2 = MP(p2.FF - p0.FF, p2.SS - p0.SS);
return crossProd(vector1, vector2);
}

bool compare(pi_i a, pi_i b){
	int d = direction(initPoint, a, b);
	if(d == 0)
		if(dist(initPoint, a) >= dist(initPoint, b)) return 0;	//we need to choose the smalest distance
		else return 1;
	if(d < 0) return 0;	//i.e 'a' is counterclockwise of 'b'
	else return 1;
}

void convexHull(){
	int minIdx = 0;
	for(int i=0;i<n;i++){
		if(points[i].SS < points[minIdx].SS) minIdx = i;
		else if(points[i].SS == points[minIdx].SS)
			if(points[i].FF <= points[minIdx].FF) minIdx = i;
	}
	swap(points[0], points[minIdx]);
	initPoint = points[0];
	
	sort(points.begin()+1, points.end(), compare);
	//qsort(&points[1], n-1, sizeof(pair<int, int>), compare);
	
	vector<pi_i> stack;
	int top;
	stack.PB(points[0]);
	stack.PB(points[1]);
	stack.PB(points[2]);
	top = 2;
	
	for(int i=3;i<n;i++){
		while(direction(stack[top-1], stack[top], points[i]) <= 0){//make non left(counter) turn(i.e right(clock) or collinear)
			stack.pop_back();top--;
		}
		stack.PB(points[i]);top++;
	}
	
	//checking if the 3 points are collinear or not if collinear delete the second point
	if(stack.size() == 3){
		if(direction(stack[top-2], stack[top-1], 
			stack[top]) == 0){
			pi_i ttt = stack[top];
			stack.pop_back();stack.pop_back();
			stack.PB(ttt);	
		}
	}
	
	//ADD CASE FOR DELETING THE REPEATING POINTS FROM THE STACK COMPARE CURR POINT TO NEXT PT
	
	cout<<endl;
	for(int i=stack.size()-1;i>=0;i--){
		cout<<stack[i].FF<<" "<<stack[i].SS<<endl;
	}
}

int main(){
	
	cin>>n;int x, y;
	for(int i=0;i<n;i++){
		cin>>x>>y;
		points.PB(MP(x, y));
	}
	convexHull();

return 0;
}

/*
8
0 3
1 1
2 2
4 4
0 0
1 2
3 1
3 3
*/


