#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
int main(){
	int n;
	scanf("%d", &n);
	while(n--) {
		int m, f;
//		scanf("%1d%d",&f, &m);		// %1d��ʾֻ����һλ�����λ����f�У�ʣ�����m��
//		printf("%d\n", m); 
		
		scanf("%d", &m);
		int x = 0;
		int len =0;			// �������ݳ��� 
		
		// ���η�ת��� 
//		while(m>10) {		// �õ��������λ��ÿһλ,��ת�����x�� 
//			x = x*10 + m%10;		// �õ���λ 
//			m /= 10;	// ������λ������ȥ��һλ
//			len++; 
//		}
//		if(x==0) printf("0\n");
//		else {
//			int first = 1;		// ǰ���� 
//			while(x>0) {		// �������
//				if(x%10!=0) {	// ���� 
//					printf("%d", x%10);
//					first = 0;		// ������㲻��ǰ���� 
//				} else if(!first) {	// ��ǰ���� 
//					printf("%d", x%10);		
//				} 
//				x /= 10;
//				len--;			// ���һλlen-1 
//			}
//			for(int i=0; i<len; i++) {	// �ѵ�λ0��� 
//				printf("0");
//			} 
//			printf("\n");
//		}

		// ȡ��
		int tmp = m;
		int k = 1;			// k��һ��10^f,fΪm��λ��-1 
		while(tmp>10) {
			tmp/=10;
			k *= 10;
		} 
		printf("%d\n", m%k);
		
	}

	return 0;
}

