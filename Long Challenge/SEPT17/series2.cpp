#include<bits/stdc++.h>
using namespace std;
int main()
{
	int A2[100000],i;
	A[0]=0;
	A[1]=1;
	A[2]=4;
	for(i=3;i<=cycle;i++)
	{
		if(i>=A2[i-1])
		{
			A2[i]=A2[i-1]*2;
		}
		else	A2[i]=A2[i-1];
	}
	for(i=0;i<100;i++)	cout<<A[i]<<" ";	cout<<endl;
}
