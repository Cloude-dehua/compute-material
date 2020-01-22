#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
int main(){
	FILE* rf = fopen("10.cpp", "r");		// 打开文件 
	FILE* wf = fopen("10-2.cpp", "w");
	
	// cope
	char buf[100];
//	scanf, gets, getchar==> fscanf, fgets, fgetchar
//  printf => fprintf
	while(fgets(buf, 100, rf)!=NULL) {		// 循环从rf文件里读取 
		fputs(buf, wf);						// 写人wf 
	}
	
//	fprintf(wf, "%s", buf);
	
	fclose(rf);		// 关闭文件 
	fclose(wf);
	return 0;
}

