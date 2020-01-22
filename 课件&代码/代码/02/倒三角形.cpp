#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
int main(){
	for(int i=0; i<9; i++) {		// 遍历行 
		for(int j=0; j<i; j++) {	// 打印i个* 
			printf("*"); 
		}
		for(int j=9-i; j>=1; j--) {	// 打印数字 
			printf("%d", j);
		}
		printf("\n");
	}

	return 0;
}

