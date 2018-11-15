#include<stdio.h>
int main()
{
		int T;	scanf("%d",&T);
		while(T--)
		{
				int n,i;
				char ch[1002];			scanf("%s",ch);
				int A[26],flag=1;
				for(i=0;i<26;i++)		A[i]=0;
				for(n=0;ch[n]!='\0';n++);	
				for(i=0;i<n/2;i++)
						A[(int)ch[i]-97]++;
				//for(i=0;i<26;i++)	printf("%d ",A[i]);		printf("\n");		
				for(i=n-1;i>=(n+1)/2;i--)
						A[(int)ch[i]-97]--;
				//for(i=0;i<26;i++)	printf("%d ",A[i]);		printf("\n");
				for(i=0;i<26;i++)
					if(A[i]!=0)
					{
							flag=0;
							break;
					}			
				if(flag)
					printf("YES\n");
				else
					printf("NO\n");		
		}
}
