#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;

bool isPrime(int x) {
// 判断x是否为素数 
	int m = (int)(sqrt(x)+0.5);
	for(int i=2; i<=m; i++) {		// 判断[2, sqrt(x)]中是否有数字能被x整除 
		if(x%i==0) return false;
	}
	return true;
}

const int maxn = 30;
int primes[maxn];
void build() {
// 填充素数表primes 
	int cnt = 0;
	for(int i=2; cnt<maxn; i++) {
		if(isPrime(i)) {
			primes[cnt++] = i;
		}
	}
}

void parse(char* s, int* a, int& cnt) {
// 将火星数字字符串s每一位解析保存在数组a中，cnt为最后解析到的位数
	int len = strlen(s);
	int num = 0;
	cnt = 0;
//	10,6,4,2,1
	for(int i=0; i<len; i++) {	// 解析字符串的每一个字符 
		if('0'<=s[i] && s[i]<='9') {	// 数字 
			num = num*10+s[i]-'0';
		} else {	// 解析到逗号，表示这一位解析完毕 
			a[cnt++] = num;
			num = 0;		// 清零，方便解析一下位数字 
		}
	} 
	a[cnt++] = num;	// 将最后解析的数字也放入数组
	// 反转a数组，使得数组低位保存数字低位
	for(int i=0; i<cnt/2; i++) {	// 报前半部分后后半部分做交换 
		swap(a[i], a[cnt-1-i]);
	} 
}

int main(){
	build();		// 初始化素数表 
	char s1[100], s2[100];
	int a[30], b[30], c[30], cnt1, cnt2;
	while(scanf("%s%s", s1, s2)==2 && !(strcmp(s1, "0")==0 && strcmp(s2, "0")==0)) {
		memset(a, 0, sizeof(a));	// 初始化 
		memset(b, 0, sizeof(b));
		parse(s1, a, cnt1);		// 解析字符串到数组中 
		parse(s2, b, cnt2);
//		printf("cnt1=%d, cnt2=%d\n", cnt1, cnt2); 
//		for(int i=cnt1-1; i>=0; i--) printf("%d,", a[i]); 
//		printf("\n");
		// 模拟加法，从低到高相加每一位
		int tmp = 0;	// 保存进位
		int i=0;		// 扫描每一位，最后是相加结果的位数	 
		for(; i<cnt1 || i<cnt2; i++) {
			tmp += a[i] + b[i];			// 当前两个位相加并加上上次进位 
			c[i] = tmp % primes[i];		// 因为可能进位，所有要对当前进制做取余 
//			printf("%d,", c[i]);
			tmp /= primes[i];			// 计算当前位的进位 
		} 
		while(tmp>0) {	// 最高位进位 
			c[i] = tmp%primes[i];
			tmp /= primes[i]; 
			i++;
		} 
		// 输出，先输出高位 
		for(int j=i-1; j>=0; j--) {
			if(j<i-1) printf(",");
			printf("%d", c[j]);
		}	
		printf("\n");
	}

	return 0;
}

