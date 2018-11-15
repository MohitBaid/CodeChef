#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;	scanf("%d",&T);
	while(T--)
	{
		char s[500];	scanf("%s",s);
		int i,l,r=0;
		for(l=0;s[l]!='\0';l++);
		int A[500]={0};
		for(i=0;i<l;i++)
		{
			if(s[i]=='m')
			{
				if(i!=0 && s[i-1]=='s' && A[i-1]==0)						A[i-1]=1;
				else if(i!=l-1 && s[i+1]=='s' && A[i+1]==0)					A[i+1]=1;	
			}
		}
		for(i=0;i<l;i++)
		{
			if(s[i]=='m')					r++;
			if(s[i]=='s' && A[i]==0)		r--;
		}
		if(r>0)			printf("mongooses\n");	
		if(r==0)		printf("tie\n");
		if(r<0)			printf("snakes\n");
	}
}
