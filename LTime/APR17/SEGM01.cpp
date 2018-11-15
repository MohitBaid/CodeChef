#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		char ch[100005];	scanf("%s",ch);
		int n1=0,i;
		int n2=0;
		int max=0;
		for(i=0;ch[i]!='\0';i++)
		{
			if(ch[i]=='1')
			{
				n1++;
				n2++;
			}
			else
			{
				if(max<n2)
					max=n2;
				n2=0;
			}
		}
		if(max<n2)
			max=n2;
		n2=0;
		if( (max==n1 ||n1==i) &&n1!=0 )
			printf("YES\n");
		else
			printf("NO\n");	
	}
}
