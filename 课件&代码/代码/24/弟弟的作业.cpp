/**
登登考研团队
*/
#include <cstdio>

int main() {
	int a, b, c;
	char s[50];
	int cnt = 0;	// 做对的题目数量 
	while(scanf("%s", s)==1) {
		if(sscanf(s,"%d+%d=%d", &a, &b, &c)==3 && a+b==c) cnt++;	// 加法题是否正确 
		else if(sscanf(s,"%d-%d=%d", &a, &b, &c)==3 && a-b==c) cnt++;	//减法题是否正确 
	} 
	printf("%d\n", cnt);
	return 0;
}

