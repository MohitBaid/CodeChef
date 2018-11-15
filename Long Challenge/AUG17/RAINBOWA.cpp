#include<bits/stdc++.h>
using namespace std;
int isascen(int A[],int n)
{
	int i;
	for(i=1;i<n;i++)
		if(A[i]<A[i-1])
			return 0;
	return 1;		
}
int isequal(int A[],int B[],int n)
{
	int i;
	for(i=0;i<n;i++)
		if(A[i]!=B[i])
			return 0;
	return 1;		
}
int check(int A[])
{
	int i;
	for(i=1;i<=7;i++)
		if(A[i]==0)
			return 0;
	return 1;		
}
int main()
{
	int T;	cin>>T;
	while(T--)
	{
		int n,i,flag=1;		cin>>n;
		int A[n],B[n],C[8]={0};
		for(i=0;i<n;i++)	
		{
			cin>>A[i];
			B[n-i-1]=A[i];
			if(A[i]>7)	flag=0;
			else		C[A[i]]++;
		}
		if(flag && isequal(A,B,n) && isascen(A,n/2) && check(C))			cout<<"yes\n";
		else																cout<<"no\n";		
	}
}
