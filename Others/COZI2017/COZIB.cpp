#include<stdio.h>
int main()
{
		int n,t;	scanf("%d %d",&n,&t);
		int A[n][n];
		int i,j;
		char ch[n+2];
		for(i=0;i<n;i++)
		{
				scanf("%s",ch);
				for(j=0;j<n;j++)
				{
					if(ch[j]=='1')
						A[i][j]=1;
					else
						A[i][j]=0;
				}
		}
		int f[n];
		int b[n];
		for(i=0;i<n;i++)		
		{
				f[i]=0;
				b[i]=0;
		}
		for(i=0;i<n;i++)
		{
				for(j=0;j<n;j++)
				{
						f[j]+=A[i][j];
						b[i]+=A[i][j];
				}
		}
		/*for(i=0;i<n;i++)
		{
				printf("%d    %d\n",f[i],b[i]);
		}*/
		long long int ans=b[0];		t--;	//first phase
		if(t)
		{
			for(i=0;i<n;i++)				//second phase
			{
				if(A[0][i]==0)
						ans+=(2*b[i]);
				else
						ans+=b[i];
			}
			t--;
			if(t)
			{
				for(i=0;i<n;i++)
				{
					if(f[i]%2==0)
						ans+=(t*b[i]*2);
					else
						ans+=(t*b[i]);	
				}	
			} 
		}
		printf("%lld\n",ans);
}
