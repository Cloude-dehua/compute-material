#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn = 1000 + 10;
struct Stu{		// 定义一个学生结构体 
	int score[5];	// 分数 
	char name[20];	// 姓名 
}ss[maxn];		// 结构体数组 
int cnt = 0;	// 参加复试的人 

bool cmp(Stu a, Stu b) {		// 根据总分降序排序 
	if(a.score[4] != b.score[4]) return a.score[4] > b.score[4];	// 第一规则：根据分数降序
	return strcmp(a.name, b.name) < 0;		// 第二规则：根据姓名升序 
}

int main(){
	int n;
	scanf("%d", &n);
	int line[5];
	for(int i=0; i<5; i++) scanf("%d", &line[i]);
	for(int i=0; i<n; i++) {
		char name[20];
		int a[5];
		scanf("%s %d %d %d %d", name, &a[0], &a[1], &a[2], &a[3]);
		a[4] = a[0] + a[1] + a[2] + a[3];
		bool ok = 1;
		for(int j=0; j<5; j++) {
			if(a[j]<line[j]) {
				ok = 0;
				break;
			}
		}
		if(ok) {	// 进入复试，copy相关信息放入ss 
			strcpy(ss[cnt].name, name);
			for(int j=0; j<5; j++) {
				ss[cnt].score[j] = a[j];
			}
			cnt++;	// 进入复试人数加一 
		}
	}
	sort(ss, ss+cnt, cmp);		// 更加cmp规则进行结构体排序 
	for(int i=0; i<cnt; i++) {	// 输出 
		printf("%s", ss[i].name);
		for(int j=0; j<5; j++) printf(" %d", ss[i].score[j]);
		printf("\n");
	} 
	return 0;
}

