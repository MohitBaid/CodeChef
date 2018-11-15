#include<bits/stdc++.h>
using namespace std;
map < long int ,long int > A;
long int sol(long int x)
{
	if(x==0)	return 0;
	if(A.find(x)!=A.end())	return A[x];
	if(x/2 + x/3 + x/4 <=x)	A[x]=x;
	else	A[x]=max(x,sol(x/2)+sol(x/3)+sol(x/4));
	return A[x];
}
int main()
{
	long int x;
	while(scanf("%ld",&x)==1)		printf("%ld\n",sol(x));
}
