#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
struct Point{		// 结构体定义 
	double x, y;	// 成员变量 
}; 

double Dis(Point p1, Point p2) {
	return sqrt( (p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y));
}

int main(){
	Point p1 = {1,2};
	Point p2 = {2,3};
	printf("%lf", Dis(p1, p2));

	return 0;
}

