#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
void jin(int n, int k, int* a, int& cnt) {
// 将十进制正整数n转换为k进制后保存在数组a中,cnt表示最后有多少位（通过引用可以让实参拿到形参的值） 
	cnt = 0;
	if(n==0) {		// n等于0，转换后就一个零 
		a[cnt++] = 0;	
	}
	while(n>0) {	// 模拟短除法，非零一直做循环 
		a[cnt++] = n % k;		// 得余数
		n /= k;					// 得商 
	}	
}

int main(){
	int n;
	int a[20], cnt;
	while(scanf("%d", &n)==1) {
		jin(n, 16, a, cnt);
		for(int i=cnt-1; i>=0; i--) {
			if(a[i]>=10) {
				printf("%c", a[i]-10+'A');	// 将10-15转成'A'-'F' 
			} else {
				printf("%d", a[i]);
			} 
		}
		printf("H\n");
	} 
	
	return 0;
}

