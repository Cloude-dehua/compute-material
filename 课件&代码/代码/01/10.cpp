#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
int main(){
	FILE* rf = fopen("10.cpp", "r");		// ���ļ� 
	FILE* wf = fopen("10-2.cpp", "w");
	
	// cope
	char buf[100];
//	scanf, gets, getchar==> fscanf, fgets, fgetchar
//  printf => fprintf
	while(fgets(buf, 100, rf)!=NULL) {		// ѭ����rf�ļ����ȡ 
		fputs(buf, wf);						// д��wf 
	}
	
//	fprintf(wf, "%s", buf);
	
	fclose(rf);		// �ر��ļ� 
	fclose(wf);
	return 0;
}

