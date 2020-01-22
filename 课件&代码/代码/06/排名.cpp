#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn = 1000 + 10;
struct Stu{
	char num[25];	// 考号 
	int score;		// 分数 
} ss[maxn];			// ss结构体数组，保存进入复试的同学信息 
int total;			// 总共进入复试的人数 

bool cmp(Stu a, Stu b) {
	if(a.score != b.score) return a.score > b.score;		// 第一规则：分数降序
	return strcmp(a.num, b.num) < 0;						// 第二规则：考号升序 
}

int main(){
	int n, m, g;
	int score[15];
	while(scanf("%d%d%d", &n, &m, &g)==3 && n) {
		for(int i=1; i<=m; i++) {	// 输入每道考题分数 
			scanf("%d", &score[i]);
		}
		char num[25];
		int cnt, x, sum;
		total = 0;
		for(int i=0; i<n; i++) {	// 处理n个同学 
			scanf("%s %d", num, &cnt);
			sum = 0;	// 总分 
			for(int j=0; j<cnt; j++) {
				scanf("%d", &x);
				sum += score[x];
			}
			if(sum >= g) {	// 该生进入复试 
				ss[total].score = sum;		// 记录相关信息 
				strcpy(ss[total].num, num);
				total++;	// 进入复试人数加一 
			}
		}
		
		sort(ss, ss+total, cmp);	// 根据cmp比较规则排序ss[0, total) 
		
		printf("%d\n", total);
		for(int i=0; i<total; i++) {
			printf("%s %d\n", ss[i].num, ss[i].score);
		}
	}

	return 0;
}

