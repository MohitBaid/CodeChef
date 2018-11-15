#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long int a=1000,b=500,temp=1;;
	int M=27;
	for(int i=1;i<=a;i++)
	{
		temp=temp*i;
		temp=temp%M;
		cout<<temp%M<<" ";
	}
	
	cout<<"\n\n";
	temp=1;
	for(int i=1;i<=b;i++)
	{
		temp=temp*i;
		temp=temp%M;
		cout<<temp%M<<" ";
	}
	
	
	long long int ans=1;
	for(int i=1;i<=b;i++)
	{
		//cout<<"inv of:" <<i<<"mofule " << M<<":"<< inv(i,M)<<endl;
		ans=ans*(a-i+1)/i;
	}
	cout<<endl<<endl;
	cout<<ans<<endl;
	long long int an=(long long int)(ans)%M;
	cout<<endl<<endl;
	cout<<an<<endl;
}
