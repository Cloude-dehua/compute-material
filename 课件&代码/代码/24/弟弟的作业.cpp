/**
�ǵǿ����Ŷ�
*/
#include <cstdio>

int main() {
	int a, b, c;
	char s[50];
	int cnt = 0;	// ���Ե���Ŀ���� 
	while(scanf("%s", s)==1) {
		if(sscanf(s,"%d+%d=%d", &a, &b, &c)==3 && a+b==c) cnt++;	// �ӷ����Ƿ���ȷ 
		else if(sscanf(s,"%d-%d=%d", &a, &b, &c)==3 && a-b==c) cnt++;	//�������Ƿ���ȷ 
	} 
	printf("%d\n", cnt);
	return 0;
}

