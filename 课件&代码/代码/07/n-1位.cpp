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
//		scanf("%1d%d",&f, &m);		// %1d表示只接受一位即最高位放在f中，剩余放入m中
//		printf("%d\n", m); 
		
		scanf("%d", &m);
		int x = 0;
		int len =0;			// 计算数据长度 
		
		// 两次反转输出 
//		while(m>10) {		// 拿到除了最高位的每一位,反转后放入x中 
//			x = x*10 + m%10;		// 拿到个位 
//			m /= 10;	// 擦除个位，方便去下一位
//			len++; 
//		}
//		if(x==0) printf("0\n");
//		else {
//			int first = 1;		// 前导零 
//			while(x>0) {		// 倒序输出
//				if(x%10!=0) {	// 非零 
//					printf("%d", x%10);
//					first = 0;		// 后面的零不是前导零 
//				} else if(!first) {	// 非前导零 
//					printf("%d", x%10);		
//				} 
//				x /= 10;
//				len--;			// 输出一位len-1 
//			}
//			for(int i=0; i<len; i++) {	// 把低位0输出 
//				printf("0");
//			} 
//			printf("\n");
//		}

		// 取余
		int tmp = m;
		int k = 1;			// k是一个10^f,f为m的位数-1 
		while(tmp>10) {
			tmp/=10;
			k *= 10;
		} 
		printf("%d\n", m%k);
		
	}

	return 0;
}

