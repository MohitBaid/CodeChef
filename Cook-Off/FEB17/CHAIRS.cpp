#include<stdio.h>
#include<bits/stdc++.h>
int main()
{
	int T;	scanf("%d",&T);
	while(T--)
	{
		int n,i,k=0,j;	scanf("%d",&n);
		int ans=0,temp,sum=0,max=-1,p,ans1=0,ans2=0;
		char ch[n+2];
		scanf("%s",ch);
		for(i=0;ch[i]!='\0';i++)
			if(ch[i]=='1')
				k++;
			else
			{
				if(k>max)
				{
					max=k;
					p=i-k+((k+1)/2);
				}
			}	
		k=0;	
		char ch1[n/2];
		char ch2[n-n/2];
		for(i=p,j=0;j<n/2;j++,i=(i+1)%n)
			ch1[j]=ch[i];
		for(;j<n;j++,i=(i+1)%n)
			ch2[j-n/2]=ch[i];		
		int k1=0,k2=0;
		for(i=0;i<n/2;i++)
		{
			if(ch1[i]=='0')
 				 k1++;
  			else
   				ans1+=k1;
   				
   			if(ch1[n/2-1-i]=='0')
 				 k2++;
  			else
   				ans2+=k2;	
		}	
		k1=0,k2=0;
		int ans3=0,ans4=0;
		for(i=0;i<n-n/2;i++)
		{
			if(ch2[i]=='0')
 				 k1++;
  			else
   				ans3+=k1;
			if(ch2[n-n/2-1-i]=='0')
 				 k2++;
  			else
   				ans4+=k2;
		}
		if(ans1+ans2<ans2+ans3)	
			printf("%d\n",ans1+ans4);
		else
			printf("%d\n",ans2+ans3);		
		
	}
}
