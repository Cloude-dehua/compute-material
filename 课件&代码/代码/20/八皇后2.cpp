/**
�ǵǿ����Ŷ�
*/
#include <cstdio>
int vis[9];
int n = 8; 
int kase = 1;
int a[9];
// dfs��������� 
void dfs(int cur) {
	if(cur==n+1) {	// �ݹ�߽磬�Ѿ�ȫ�����кã�û�г��ֳ�ͻ 
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
		// ���Խ�i��ֵ��a[cur] 
		for(int i=1; i<=8; i++) {
			if(vis[i] == 0) 	// i֮ǰû��ʹ�ù� 
			{
				a[cur] = i;	// ��ʱ���ʺ����(cur, a[cur]) -->(cur, i)
				int ok = true;
				for(int j=1; j<cur; j++) {	// ��鵱ǰҪ�ŵ�λ���Ƿ��ǰ��Ļʺ��ͳ�ͻ 
					if(cur-j == a[cur]-a[j] || cur-j == a[j] - a[cur]) {
						ok = false;	
						break;
					}
				}
				if(ok) {	//��֦ 
					vis[i] = 1;
					dfs(cur+1);
					vis[i] = 0;	// ���� 
				}
			}
		}
	}
}

int main() {
	dfs(1);
	return 0;
}

