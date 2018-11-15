#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,i,j;	cin>>n;
	for(j=0;j<n;j++)
	{
		int t=0,temp;
		for(i=0;i<5;i++)
		{
			cin>>temp;
			t+=temp;
		}
			if(t==0)	cout<<"Beginner\n";
			if(t==1)	cout<<"Junior Developer\n";
			if(t==2)	cout<<"Middle Developer\n";
			if(t==3)	cout<<"Senior Developer\n";
			if(t==4)	cout<<"Hacker\n";
			if(t==5)	cout<<"Jeff Dean\n";
	}
}
