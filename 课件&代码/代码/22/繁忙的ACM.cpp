#include <cstdio>
#include <algorithm>
using namespace std; 
const int maxn=1000+10;
int kase=1;
struct renwu{
	int jd;
	int zx;
}rw[maxn];
bool cmp(renwu a,renwu b)
{
	return a.zx>b.zx;
}
int max(int x,int y)
{
	return x>y?x:y; 
}
int main()
{
	int n;
	while(scanf("%d",&n)==1 && n)
	{
		for(int i=0;i<n;i++)
		{
			scanf("%d%d",&rw[i].jd,&rw[i].zx);
		}
		sort(rw,rw+n,cmp);
		int ans=0;
		int jdsum=0;
		for(int i=0;i<n;i++)
		{
			jdsum+=rw[i].jd;
			ans=max(jdsum+rw[i].zx,ans);
		}
		printf("Case %d: %d\n",kase++,ans);
		 
	}
	return 0;
}
