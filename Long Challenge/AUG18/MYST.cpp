#include<bits/stdc++.h>
using namespace std;
int B[50000][10];
int b=0;
void populate(int A[],int n,int p,int C[],int P[])
{
	int i,j;
	if(p==n)
	{
		for(i=0;i<n;i++)
			B[b][i]=C[i];
		b++;	
	}
	else
	{
		for(i=0;i<n;i++)
		{
			C[p] = A[i];
			P[p] = i;
			int valid = true;
			for(j=0;j<p;j++)
			{
				if(P[j]==i)
				{
					valid = false;
					break;
				}
			} 
			if(valid)
			{
				populate(A,n,p+1,C,P);
			}
		}
	}
}
int main()
{
	int T;	cin>>T;
	while(T--)
	{
		int n,p,i,j;	cin>>n>>p;
		int A[n],C[10]={0},P[10]={0};
		for(i=0;i<n;i++)	cin>>A[i];
		populate(A,n,0,C,P);
		/*cout<<b<<endl;
		for(i=0;i<b;i++)
		{
			for(j=0;j<n;j++)	cout<<B[i][j]<<" ";	cout<<endl;
		}*/
		for(i=0;i<n;i++)
		{
			int ansf = n+1,pos = -1;
			for(j=0;j<b;j++)
			{
				int temp = p;
				int ans = 0,k;
				for(k=i;k>=0;k--)
				{
					if(temp>B[j][k])
					{
						temp-=B[j][k];
					}
					else	break;
				}
				ans += (i-k);
				
				temp = p;
				for(k=i;k<n;k++)
				{
					if(temp>B[j][k])
					{
						temp-=B[j][k];
					}
					else	break;
				}
				ans +=(k-i);
				
				if(B[j][i]<p)	ans--;
				//ansf = min(ansf,ans);
				if(ansf>ans)
				{
					ansf = ans;
					pos = j;
				}
			}
			cout<<n-ansf<<" "<<pos<<":";
			for(j=0;j<n;j++)	cout<<B[pos][j]<<" ";	cout<<endl;
		}
		cout<<endl;
		/*for(i=0;i<b;i++)
		{
			for(j=0;j<n;j++)	cout<<B[i][j]<<" ";		cout<<endl;
		}*/
		b=0;
	}
}
