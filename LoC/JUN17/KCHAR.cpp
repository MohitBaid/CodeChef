#include<bits/stdc++.h>
using namespace std;
int main()
{
	char ch[]="aacaacc";
	long long int P[61],i;			P[0]=1;
	for(i=1;i<=60;i++)				P[i]=2*P[i-1];
	int T;	cin>>T;
	while(T--)
	{
		long long int n,diff,c=0;	cin>>n;
		while(n>7)
		{
			for(i=0;i<=60;i++)
				if(P[i]>n)
					break;
			i--;
			diff=n-P[i];
			n=P[i]-diff;
			c++;
			if(diff==0)			break;
		}
		//cout<<diff<<" "<<c<<endl;
		if(diff!=0)
		{
			char ct=ch[n-1];
			if(c%2==1)
			{
				if(ct=='a')		cout<<'c'<<endl;
				else			cout<<'a'<<endl;
			}
			else				cout<<ct<<endl;		
		}
		else
		{
			if(c%2)		cout<<'a'<<endl;
			else			cout<<'c'<<endl;
		}
	}
}
