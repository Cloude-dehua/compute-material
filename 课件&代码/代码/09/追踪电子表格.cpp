#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;

const int maxn = 60;
int a[maxn][maxn];		// ���ӱ� 
int b[maxn][maxn];		// �����еı��ݱ� 
int op[maxn];			// op[i]==1��ʾ��i�У��У���Ҫ�����ɾ�� 
int r, c, n;

void Copy(int num1, int num2, int type) {
// 	��b���е� num2��(��) ������a�е�num1����(��)��type=='R'�������з��������
	if(type=='R') {
		for(int i=1; i<=c; i++) {	// ������һ�� 
			a[num1][i] = b[num2][i];
		}
	} else {
		for(int i=1; i<=r; i++) {	// ����һ�� 
			a[i][num1] = b[i][num2];
		} 
	} 
}


void insert(char type) {
// type=='R'��ʾ�����У����������
	memcpy(b, a, sizeof(a));		// ��a������b 
	int cnt2 = 0;					// ���������л����е����� 
	if(type=='R') {
		for(int i=1; i<=r; i++) {
			if(op[i]) {	// ����һ������ 
				Copy(++cnt2, 0, type);
			}
			Copy(++cnt2, i, type);		// ������i�� 
		}
	} else {	// ���в��� 
		for(int i=1; i<=c; i++) {
			if(op[i]) {	// ����һ������ 
				Copy(++cnt2, 0, type);
			}
			Copy(++cnt2, i, type);		// ������i�� 
		}
	} 
	if(type=='R') r = cnt2;				// ����������л����� 
	else c = cnt2; 
}

void del(char type) {
// type=='R'��ʾɾ���У�����ɾ����
	memcpy(b, a, sizeof(a));		// ��a������b 
	int cnt2 = 0;					// ���������л����е����� 
	if(type=='R') {
		for(int i=1; i<=r; i++) {
			if(!op[i]) {	// ����Ҫɾ�����оͿ�����ȥ 
				Copy(++cnt2, i, type);		// ������i��
			}
		}
	} else {	// ���в��� 
		for(int i=1; i<=c; i++) {
			if(!op[i]) {	// ����Ҫɾ�����оͿ�����ȥ 
				Copy(++cnt2, i, type);		// ������i��
			}
		}
	} 
	if(type=='R') r = cnt2;				// ����������л����� 
	else c = cnt2; 
}

int main(){
	int kase = 1;
	while(2==scanf("%d%d", &r, &c) && r && c) {
		scanf("%d", &n);
		 
		// ��λ����Ϣencode
		for(int i=1; i<=r; i++) {
			for(int j=1; j<=c; j++) {
				a[i][j] = i*100 + j;	// ǧ��λ�����У���ʮλ������ 
			}
		}
		char cmd[5];
		int x1, y1, x2, y2;
		while(n--) {	// n�β��� 
			scanf("%s", cmd);
			if(cmd[0]=='E') {	// ���� 
				scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
				swap(a[x1][y1], a[x2][y2]);
			} else {	// �������ɾ�� 
				int m;
				scanf("%d", &m);
				int x;
				memset(op, 0, sizeof(op));	// ��ʼ�� 
				for(int i=0; i<m; i++) {
					scanf("%d", &x);
					op[x]=1;
				}
				if(cmd[0]=='I') {	// ���� 
					insert(cmd[1]); 
				} else {	// ɾ������ 
					del(cmd[1]);
				} 
			}
		}
		
		int q;
		scanf("%d", &q);
		printf("Spreadsheet #%d\n", kase++);
		while(q--) {	// q�β�ѯ 
			int x, y, code;
			scanf("%d%d", &x, &y);
			code = x*100+y;
			int flag = 0;		// ����Ƿ��ڱ任��ı�����ҵ� 
			for(int i=1; i<=r && !flag; i++) {
				for(int j=1; j<=c; j++) {
					if(a[i][j]==code) {
						flag = 1;
						printf("Cell data in (%d,%d) moved to (%d,%d)\n", x, y, i, j);
						break;
					}
				}
			} 
			if(!flag) printf("Cell data in (%d,%d) GONE\n", x, y);	// û���ҵ� 
		}
		
	}

	return 0;
}

