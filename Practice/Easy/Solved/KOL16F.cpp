#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T,i;	scanf("%d",&T);
	char ch[100005];
	int f=T;
	while(T--)
	{
		int A[100005]={0},B[100005]={0};
		int m=0,temp=0;
		scanf("%s",ch);
		char c=ch[0];
		for(i=0;ch[i]!='\0';i++)
		{
			if(ch[i]==c)	temp++;
			else
			{
				c=ch[i];
				B[m]=temp;
				A[m++]=temp;
				temp=1;
			}
		}
		B[m]=temp;
		A[m++]=temp;
		if(ch[0]==ch[i-1]&&m>2)
		{
			A[0]+=A[m-1];
			B[0]+=B[m-1];
			m--;
		}
		sort(A,A+m);
		if(A[m-1]==1)		
		{
			if(m==1)			cout<<"Case "<<f-T<<": 1"<<endl;
			else if(m==2)		cout<<"Case "<<f-T<<": 2"<<endl;
			else				cout<<"Case "<<f-T<<": 3"<<endl;
		}	
		else if(A[m-1]==2)
		{
			if(m==1)			cout<<"Case "<<f-T<<": 1"<<endl;
			else
			{
				int min=3;
				for(i=0;i<m;i++)
				{
					if(B[i]==2)
					{
						if(i!=0 && B[i-1]<min)					min=B[i-1];
						else if(i!=m-1 && B[i+1]<min)			min=B[i+1];	
					}
				}
				cout<<"Case "<<f-T<<": "<<min+1<<endl;
			}
		}
		else
		{	
			if(m==1)			cout<<"Case "<<f-T<<": "<<A[m-1]-1<<endl;
			else
			{
				int q=A[m-1]/2;
				if(A[m-1]%2==1)
				{	
					A[m-1]=q;
					A[m]=q;
					A[m+1]=1;
				}
				else
				{
					A[m-1]=q;
					A[m]=q-1;
					A[m+1]=1;
				}
				sort(A,A+m+2);
				cout<<"Case "<<f-T<<": "<<A[m+1]<<endl;
			}	
		}
	}
}
