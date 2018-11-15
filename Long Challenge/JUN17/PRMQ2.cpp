#include<bits/stdc++.h>
using namespace std;
const long long MAX_SIZE = 1000001;
int isprime[MAX_SIZE];
int prime[MAX_SIZE];
int SPF[MAX_SIZE];
int m;
int mp[100000][100];
int F[100000][2];
int pos[100000];
int R[100000];
int sum[100000];
map<int,int> ind;
int C[MAX_SIZE];
void seive()
{
    isprime[0] = isprime[1] = 1 ;
    for (int i=2; i<MAX_SIZE ; i++)
    {
	    if (!isprime[i])
        {
            prime[m++]=i;
            SPF[i] = i;
        }
        for (int j=0;j<m && i*prime[j]<MAX_SIZE && prime[j] <= SPF[i];j++)
        {
            isprime[i*prime[j]]=1;
            SPF[i*prime[j]] = prime[j] ;
        }
    }
    for(int i=0;i<m;i++)
    	ind[prime[i]]=i;
    int k=0;
	int j=prime[k];	
    for(int i=0;i<MAX_SIZE;i++)
	{
		C[i]=ind[j];
		if(j==i)
		{
			k++;
			j=prime[k];
		}
	}	
}
int main()
{
	seive();
	int n,q,i,d=0,j,k;	scanf("%d",&n);
	int A[n];
	for(i=0;i<n;i++)		scanf("%d",&A[i]);
	for(i=0;i<100000;i++)		F[i][0]=F[i][1]=-1;
	for(i=0;i<n;i++)
	{
		int num=A[i];
		int ctr=0;
		while(num!=1)
		{
			if(ctr==0)
			{
				mp[i][ctr]=SPF[num];
				mp[i][ctr+1]++;
				ctr=ctr+2;
			}
			else
			{
				if(mp[i][ctr-2]==SPF[num])
					mp[i][ctr-1]++;
				else
				{
					mp[i][ctr]=SPF[num];
					mp[i][ctr+1]++;
					ctr=ctr+2;
				}	
			}
			num=num/SPF[num];
		}
		pos[i]=ctr;
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<pos[i];j=j+2)
		{
			int x=ind[mp[i][j]];
			sum[x]+=mp[i][j+1];
			mp[i][j+1]=sum[x];
			F[x][R[x]]=i;
			if(R[x]==0)
			{
				R[x]=1;
				F[x][R[x]]=i;
			}
		}
	}
	scanf("%d",&q);
	while(q--)
	{
		/*int x,y,l,r;	scanf("%d %d %d %d",&l,&r,&x,&y);
		int px=0,py=m-1,ans=0;
		l--;				r--;
		px=C[x];			py=C[y];
		if(y==prime[py]);
		else	py--;
		for(i=px;i<=py;i++)
		{
			if(F[px][0]!=-1)
			{
				if(F[i][1]<l);
				else if(F[i][0]>r);
				else if(F[i][0]>=l && F[i][1]<=r)		ans+=sum[i];
				else if(F[i][0]<l &&  F[i][1]<=r)
				{
					for(j=l;j>=0;j--)
					{
						/*int flag=0,tem;
						for(k=0;k<pos[j];j=j+2)
							if(mp[j][k]==prime[i])
							{
									tem=mp[j][k+1];
									flag=1;
									break;
							}
						if(flag)
						{
							ans+=(sum[i]-tem);
							break;	
						}*/
						//printf("0\n");
		/*			}	
				}
				else if(F[i][0]>=l &&  F[i][1]>r)
				{
					/*for(j=r;j>=0;j--)
					{
						int flag=0,tem;
						for(k=0;k<pos[j];j=j+2)
							if(mp[j][k]==prime[i])
							{
									tem=mp[j][k+1];
									flag=1;
									break;
							}
						if(flag)
						{
							ans+=(sum[i]-tem);
							break;	
						}
					}*/
					//printf("0\n");
		/*		}	
			}
			//printf("%d %d\n",prime[i],ans);
		}
		printf("%d\n",ans);*/
		printf("0\n");
	}
	return 0;
}
