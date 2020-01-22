#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn = 100 + 10; 
char s[maxn];		// ����Ԫ�ء������֡� 
int a[maxn];
int b[maxn];
int c[maxn]; 
bool isHWNum(int* a, int len) {
// �жϳ���Ϊlen��a���飨ÿһλ������һ����Ԫ���Ƿ�Ϊ������ 
	for(int i=0; i<=len/2; i++) {	// ���ǰi����������i���Ƿ���� 
		if(a[i] != a[len-1-i]) return false;	// �������ǻ����� 
	}
	return true;	// ȫ����� 
} 


int main(){
	int k, n;
	while(scanf("%d", &k)==1) {
		scanf("%s", s);
		int len = strlen(s);
		for(int i=0; i<len; i++) {	// ����s����ÿһλ�������ͨ���� 
			if('0'<=s[i] && s[i]<='9') {	// 0-9���� 
				a[i] = s[i] - '0';
			} else {	// A-F 
				a[i] = s[i] - 'A' + 10;
			}
		}
		int step = 0;
		while(!isHWNum(a, len) && step<=30) {
//			for(int i=0; i<len; i++) { printf("%d ", a[i]);}
//			printf("\n");
			// ��һ������a��ת��b 
			for(int i=0; i<len; i++) {
				b[i] = a[len-1-i];
			} 
			// �ڶ�����c = a+b
			int tmp = 0;	// �����λ 
			for(int i=0; i<len; i++) {
				tmp += a[i] + b[i]; 	// ��ǰ��λ����һ�εĽ�λ
				c[i] = tmp % k;			// ת��Ϊk���ƺ󱣴浱ǰ��� 
				tmp /= k;				// ��λ 
			} 
			while(tmp>0) {	// ���λ���ܽ�λ 
				c[len] = tmp % k;			// ת��Ϊk���ƺ󱣴浱ǰ��� 
				tmp /= k;
				len++;	
			}
			// ��������a = c 
			for(int i=0; i<len; i++) {
				a[i] = c[i];
			} 
			step++;		// ������һ 
		}
		if(step<=30) {		// ��30�������ҵ��� 
			printf("%d\n", step);
		} else {
			printf("Impossible\n");
		}
	}

	return 0;
}

