#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
int main(){
	int t[10];		// ��������ˮ�ɻ��� 
	int cnt = 0;	// ��¼ˮ�ɻ����ĸ��� 
	for(int a=1; a<10; a++) {			// ö�ٰ�λ 
		for(int b=0; b<10; b++) {		// ö��ʮλ
			for(int c=0; c<10; c++) {	// ö�ٸ�λ 
				int x = a*100 + b*10 + c;
				if(x== a*a*a+b*b*b+c*c*c) {	// ������������ˮ�ɻ� 
					t[cnt++] = x;		
				}
			}
		}
	} 
	
	int n, m;
	while(scanf("%d%d", &n, &m)==2) {		// ==2��ʾscanf�ɹ������������� 
		int flag = 0;
		for(int i=0; i<cnt; i++) {	// ��������ˮ�ɻ��� 
			if(n<=t[i] && t[i]<=m) {
				if(flag) printf(" ");	// flag==0��ֻ��ӡ�����ݣ������ȴ�ӡһ���ո���������ݣ���������ȥ����β�ո� 
				flag = 1;
				printf("%d", t[i]);
			}
		}
		if(!flag) printf("no");		// flag==0��ʾ[n,m]û��ˮ�ɻ��� 
		printf("\n");
	}
	

	return 0;
}

