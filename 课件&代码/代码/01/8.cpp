#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
int Jie(int n) {
	if(n==0) return 1;
	return n*Jie(n-1);		// µÝ¹éµ÷ÓÃ 
} 
int main(){
	printf("%d", Jie(4)); 

	return 0;
}

