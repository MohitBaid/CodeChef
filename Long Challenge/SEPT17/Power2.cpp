#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,i,j;	cin>>n;
	int A2[200002]={0};
	A2[0]=0;
	for(i=1;i<=200000;i++)
	{
		if(i%2==1)
		{
			A2[i]=A2[i-1];
		}
		else
		{
			int temp=i;
			int c=0;
			while(temp%2==0)
			{
				c++;
				temp/=2;
			}
			A2[i]=A2[i-1]+c;
		}
	}
	for(i=0;i<=15;i++)
	{
		for(j=0;j<=i;j++)
		{
			//cout<<i<<" "<<j<<" "<<A2[i]<<" "<<A2[j]<<" "<<A2[j-i]<<endl;
			if(A2[i]<=A2[j]+A2[i-j])
			{
				cout<<"1 ";
			}
			else	cout<<"0 ";
		}
		cout<<endl;
	}
	//cout<<A2[200000]<<endl;
}
