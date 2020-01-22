#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn = 100 + 10; 
char s[maxn];		// 保存元素“大数字” 
int a[maxn];
int b[maxn];
int c[maxn]; 
bool isHWNum(int* a, int len) {
// 判断长度为len的a数组（每一位保存在一个单元）是否为回文数 
	for(int i=0; i<=len/2; i++) {	// 检查前i个到倒数第i个是否相等 
		if(a[i] != a[len-1-i]) return false;	// 不等则不是回文数 
	}
	return true;	// 全部相等 
} 


int main(){
	int k, n;
	while(scanf("%d", &k)==1) {
		scanf("%s", s);
		int len = strlen(s);
		for(int i=0; i<len; i++) {	// 遍历s，将每一位翻译成普通数字 
			if('0'<=s[i] && s[i]<='9') {	// 0-9数字 
				a[i] = s[i] - '0';
			} else {	// A-F 
				a[i] = s[i] - 'A' + 10;
			}
		}
		int step = 0;
		while(!isHWNum(a, len) && step<=30) {
//			for(int i=0; i<len; i++) { printf("%d ", a[i]);}
//			printf("\n");
			// 第一步：将a反转到b 
			for(int i=0; i<len; i++) {
				b[i] = a[len-1-i];
			} 
			// 第二步：c = a+b
			int tmp = 0;	// 保存进位 
			for(int i=0; i<len; i++) {
				tmp += a[i] + b[i]; 	// 当前两位和上一次的进位
				c[i] = tmp % k;			// 转换为k进制后保存当前结果 
				tmp /= k;				// 进位 
			} 
			while(tmp>0) {	// 最高位可能进位 
				c[len] = tmp % k;			// 转换为k进制后保存当前结果 
				tmp /= k;
				len++;	
			}
			// 第三步：a = c 
			for(int i=0; i<len; i++) {
				a[i] = c[i];
			} 
			step++;		// 步数加一 
		}
		if(step<=30) {		// 在30步以内找到了 
			printf("%d\n", step);
		} else {
			printf("Impossible\n");
		}
	}

	return 0;
}

