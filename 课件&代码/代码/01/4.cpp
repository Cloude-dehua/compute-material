#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	int y = (m-2*n)/2;
	int x = n - y;
	if(x>=0 && y>=0 && m%2==0) {	// 用if来判断解是否合法 
		printf("%d %d\n", x, y);
	} else {
		printf("No answer\n", x, y);
	}
	return 0;
}

