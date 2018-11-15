#include<bits/stdc++.h>
using namespace std;
int main()
{
	char ch[100005];	scanf("%s",ch);
	int ans=0;
	int l;
	for(l=0;ch[l]!='\0';l++);
	int i=l;
	char flag='1';
	for(;i>=0;i--)
	{
		if(ch[i]==flag)
		{
			ans++;
			if(flag=='1')
				flag='0';
			else
				flag='1';	
		}
		
	}
	printf("%d\n",ans);
}
