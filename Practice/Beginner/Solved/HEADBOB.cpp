#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;	cin>>T;
	while(T--)
	{
		int n;	cin>>n;
		char ch[n+3];	cin>>ch;
		int flag=0,flag2=0,i;
		for(i=0;ch[i]!='\0';i++)
		{
			if(ch[i]=='I')
			{
				flag=1;
				printf("INDIAN\n");
				break;
			}
			if(ch[i]=='Y')
				flag2=1;
		}
		if(!flag)
		{
			if(flag2)
				printf("NOT INDIAN\n");
			else
				printf("NOT SURE\n");	
		}
	}
}
