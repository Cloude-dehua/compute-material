/**
登登考研团队
*/
#include <cstdio>
int vis[9];
int n = 8; 
int kase = 1;
int a[9];
// dfs搜索解答数 
void dfs(int cur) {
	if(cur==n+1) {	// 递归边界，已经全部排列好，没有出现冲突 
		printf("Case %d:\n", kase++);
		for(int i=1; i<=n ; i++) {
			for(int j=1; j<a[i]; j++) {
				printf("#");
			}
			printf("@");
			for(int j=a[i]+1; j<=n; j++) {
				printf("#");
			}
			printf("\n");
		}
	} else {
		// 尝试讲i赋值给a[cur] 
		for(int i=1; i<=8; i++) {
			if(vis[i] == 0) 	// i之前没有使用过 
			{
				a[cur] = i;	// 暂时将皇后放在(cur, a[cur]) -->(cur, i)
				int ok = true;
				for(int j=1; j<cur; j++) {	// 检查当前要放的位置是否和前面的皇后发送冲突 
					if(cur-j == a[cur]-a[j] || cur-j == a[j] - a[cur]) {
						ok = false;	
						break;
					}
				}
				if(ok) {	//截枝 
					vis[i] = 1;
					dfs(cur+1);
					vis[i] = 0;	// 回溯 
				}
			}
		}
	}
}

int main() {
	dfs(1);
	return 0;
}

