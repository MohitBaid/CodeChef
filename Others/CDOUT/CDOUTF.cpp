#include<bits/stdc++.h>
using namespace std;
int  main()
{
		int n,k;	scanf("%d",&n);
		while(n--)
		{
			char ch[100001];
			cin>>ch;
			cin>>k;
			k=k%26;
			int i;
			for(i=0;ch[i]!='\0';i++)
			{
				int d=ch[i]-65;
				d=d-k-(i+1);
				d=d%26;
				if(d<0)
					d+=26;
				printf("%c",d+65);
			}
			printf("\n");
		}	
	}
