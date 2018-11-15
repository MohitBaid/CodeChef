#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;	cin>>T;
	while(T--)
	{
		int no,k,i;	cin>>no>>k;
		long long int n=1,j;
		for(i=0;i<no;i++)	n=n*2;
		int A[n],B[n];
		for(i=0;i<n;i++)	A[i]=i;
		for(i=1;i<=no;i++)
		{
			long long int f=pow(2,i-1);
			long long int d=n/f;
			long long int a=0;
			while(f--)
			{
				long long int p1=a;
				long long int p2=a+1;
				//cout<<"p1 = "<<p1<<" "<<p2<<" "<<a<<" "<<d<<endl;
				for(j=a;j<a+d;j++)
				{
					//cout<<"B["<<j<<"]=";
					if(j<((a+a+d)/2))
							B[j]=A[p1],p1+=2;//,cout<<"A["<<p1-2<<"]"<<endl;
					else
							B[j]=A[p2],p2+=2;//,cout<<"A["<<p2-2<<"]"<<endl;			
				}
				a=a+d;
				//for(j=0;j<n;j++)	cout<<B[j]<<" ";
				//cout<<endl;
			}
			for(j=0;j<n;j++)	A[j]=B[j];//,cout<<A[j]<<" ";
			//cout<<endl;
		}
		for(j=0;j<n;j++)	cout<<B[j]<<" ";
				cout<<endl;
		for(i=0;i<n;i++)
			if(k==B[i])
			{
				cout<<i<<endl;
				break;
			}
		
			
	}
}
