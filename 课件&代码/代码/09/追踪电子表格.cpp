#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;

const int maxn = 60;
int a[maxn][maxn];		// 电子表 
int b[maxn][maxn];		// 操作中的备份表 
int op[maxn];			// op[i]==1表示第i行（列）需要插入或删除 
int r, c, n;

void Copy(int num1, int num2, int type) {
// 	将b表中的 num2行(列) 拷贝到a中的num1行中(列)，type=='R'，操作行否则操作列
	if(type=='R') {
		for(int i=1; i<=c; i++) {	// 拷贝这一行 
			a[num1][i] = b[num2][i];
		}
	} else {
		for(int i=1; i<=r; i++) {	// 拷贝一列 
			a[i][num1] = b[i][num2];
		} 
	} 
}


void insert(char type) {
// type=='R'表示插入行，否则插入列
	memcpy(b, a, sizeof(a));		// 将a表拷贝找b 
	int cnt2 = 0;					// 操作后表的行或者列的数量 
	if(type=='R') {
		for(int i=1; i<=r; i++) {
			if(op[i]) {	// 拷贝一个空行 
				Copy(++cnt2, 0, type);
			}
			Copy(++cnt2, i, type);		// 拷贝第i列 
		}
	} else {	// 对列操作 
		for(int i=1; i<=c; i++) {
			if(op[i]) {	// 拷贝一个空列 
				Copy(++cnt2, 0, type);
			}
			Copy(++cnt2, i, type);		// 拷贝第i列 
		}
	} 
	if(type=='R') r = cnt2;				// 表操作完后的行或者列 
	else c = cnt2; 
}

void del(char type) {
// type=='R'表示删除行，否则删除列
	memcpy(b, a, sizeof(a));		// 将a表拷贝找b 
	int cnt2 = 0;					// 操作后表的行或者列的数量 
	if(type=='R') {
		for(int i=1; i<=r; i++) {
			if(!op[i]) {	// 不需要删除的行就拷贝回去 
				Copy(++cnt2, i, type);		// 拷贝第i列
			}
		}
	} else {	// 对列操作 
		for(int i=1; i<=c; i++) {
			if(!op[i]) {	// 不需要删除的行就拷贝回去 
				Copy(++cnt2, i, type);		// 拷贝第i列
			}
		}
	} 
	if(type=='R') r = cnt2;				// 表操作完后的行或者列 
	else c = cnt2; 
}

int main(){
	int kase = 1;
	while(2==scanf("%d%d", &r, &c) && r && c) {
		scanf("%d", &n);
		 
		// 将位置信息encode
		for(int i=1; i<=r; i++) {
			for(int j=1; j<=c; j++) {
				a[i][j] = i*100 + j;	// 千百位保存行，个十位保存列 
			}
		}
		char cmd[5];
		int x1, y1, x2, y2;
		while(n--) {	// n次操作 
			scanf("%s", cmd);
			if(cmd[0]=='E') {	// 交换 
				scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
				swap(a[x1][y1], a[x2][y2]);
			} else {	// 插入或者删除 
				int m;
				scanf("%d", &m);
				int x;
				memset(op, 0, sizeof(op));	// 初始化 
				for(int i=0; i<m; i++) {
					scanf("%d", &x);
					op[x]=1;
				}
				if(cmd[0]=='I') {	// 插入 
					insert(cmd[1]); 
				} else {	// 删除操作 
					del(cmd[1]);
				} 
			}
		}
		
		int q;
		scanf("%d", &q);
		printf("Spreadsheet #%d\n", kase++);
		while(q--) {	// q次查询 
			int x, y, code;
			scanf("%d%d", &x, &y);
			code = x*100+y;
			int flag = 0;		// 标记是否在变换后的表格中找到 
			for(int i=1; i<=r && !flag; i++) {
				for(int j=1; j<=c; j++) {
					if(a[i][j]==code) {
						flag = 1;
						printf("Cell data in (%d,%d) moved to (%d,%d)\n", x, y, i, j);
						break;
					}
				}
			} 
			if(!flag) printf("Cell data in (%d,%d) GONE\n", x, y);	// 没有找到 
		}
		
	}

	return 0;
}

