#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;

bool isPrime(int x) {
// �ж�x�Ƿ�Ϊ���� 
	int m = (int)(sqrt(x)+0.5);
	for(int i=2; i<=m; i++) {		// �ж�[2, sqrt(x)]���Ƿ��������ܱ�x���� 
		if(x%i==0) return false;
	}
	return true;
}

const int maxn = 30;
int primes[maxn];
void build() {
// ���������primes 
	int cnt = 0;
	for(int i=2; cnt<maxn; i++) {
		if(isPrime(i)) {
			primes[cnt++] = i;
		}
	}
}

void parse(char* s, int* a, int& cnt) {
// �����������ַ���sÿһλ��������������a�У�cntΪ����������λ��
	int len = strlen(s);
	int num = 0;
	cnt = 0;
//	10,6,4,2,1
	for(int i=0; i<len; i++) {	// �����ַ�����ÿһ���ַ� 
		if('0'<=s[i] && s[i]<='9') {	// ���� 
			num = num*10+s[i]-'0';
		} else {	// ���������ţ���ʾ��һλ������� 
			a[cnt++] = num;
			num = 0;		// ���㣬�������һ��λ���� 
		}
	} 
	a[cnt++] = num;	// ��������������Ҳ��������
	// ��תa���飬ʹ�������λ�������ֵ�λ
	for(int i=0; i<cnt/2; i++) {	// ��ǰ�벿�ֺ��벿�������� 
		swap(a[i], a[cnt-1-i]);
	} 
}

int main(){
	build();		// ��ʼ�������� 
	char s1[100], s2[100];
	int a[30], b[30], c[30], cnt1, cnt2;
	while(scanf("%s%s", s1, s2)==2 && !(strcmp(s1, "0")==0 && strcmp(s2, "0")==0)) {
		memset(a, 0, sizeof(a));	// ��ʼ�� 
		memset(b, 0, sizeof(b));
		parse(s1, a, cnt1);		// �����ַ����������� 
		parse(s2, b, cnt2);
//		printf("cnt1=%d, cnt2=%d\n", cnt1, cnt2); 
//		for(int i=cnt1-1; i>=0; i--) printf("%d,", a[i]); 
//		printf("\n");
		// ģ��ӷ����ӵ͵������ÿһλ
		int tmp = 0;	// �����λ
		int i=0;		// ɨ��ÿһλ���������ӽ����λ��	 
		for(; i<cnt1 || i<cnt2; i++) {
			tmp += a[i] + b[i];			// ��ǰ����λ��Ӳ������ϴν�λ 
			c[i] = tmp % primes[i];		// ��Ϊ���ܽ�λ������Ҫ�Ե�ǰ������ȡ�� 
//			printf("%d,", c[i]);
			tmp /= primes[i];			// ���㵱ǰλ�Ľ�λ 
		} 
		while(tmp>0) {	// ���λ��λ 
			c[i] = tmp%primes[i];
			tmp /= primes[i]; 
			i++;
		} 
		// ������������λ 
		for(int j=i-1; j>=0; j--) {
			if(j<i-1) printf(",");
			printf("%d", c[j]);
		}	
		printf("\n");
	}

	return 0;
}

