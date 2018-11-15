#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;		cin>>T;
	while(T--)
	{
		int n,i;	cin>>n;
		int A[n],diff[n],d=0;
		for(i=0;i<n;i++)
		{
			cin>>A[i];
		}
		for(i=0;i<n-1;i++)
		{
			diff[i]=A[i+1]-A[i];
		}
		for(i=0;i<n-1;i++)	cout<<diff[i]<<" ";	cout<<endl;
		int flag=0;
		int c=1;
		//cout<<"dsg";
		for(i=0;i<n-1;i++)
		{
			if(diff[i]!=0)	
			{
				d++;
			}
		}
		cout<<d<<endl;

	}
}
