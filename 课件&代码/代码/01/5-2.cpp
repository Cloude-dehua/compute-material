#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
int main(){
	for(int i=1; ;i++) {	// ö������i��ƽ�� 
		int m = i*i;
		if(m<1000) continue;	// continue������������ѭ��
		if(m>10000) break;		// break��������ѭ�� 
		
		int aa = m/100;			// ǧλ�Ͱ�λ
		int bb = m%100;			// ��λ��ʮλ
		if(aa%10 == aa/10 && bb%10 == bb/10) {
			printf("%d\n", m);
		}
	} 

	return 0;
}

