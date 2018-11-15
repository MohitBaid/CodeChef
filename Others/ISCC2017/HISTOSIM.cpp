#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;	scanf("%d",&T);
	while(T--)
	{
		char P[1002],Q[1002];
		scanf("%s %s",P,Q);
		int A[1002]={0},B[1002]={0},i,d1=1,d2=1;
		map <char,int> mp1,mp2;
		map <char,int> :: iterator it;
		for(i=0;P[i]!='\0';i++)
		{
			it=mp1.find(P[i]);
			if(it==mp1.end())			mp1[P[i]]=d1++;
			A[i]=mp1[P[i]];
		}
		for(i=0;Q[i]!='\0';i++)
		{
			it=mp2.find(Q[i]);
			if(it==mp2.end())			mp2[Q[i]]=d2++;
			B[i]=mp2[Q[i]];
		}
		int flag=1;
		if(d1!=d2)		flag=0;
		else
		{
			if(d1 == 27)
			{
				if(strcmp(P,Q)==0)		flag=1;
				else					flag=0;
			}
			else
			{
				for(i=0;i<d1;i++)
				{
					if(A[i]!=B[i])
					{
						flag=0;
						break;		
					}
				}
			}
		}
		if(flag)	printf("YES\n");
		else		printf("NO\n");
	}
}
