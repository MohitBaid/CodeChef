#include<bits/stdc++.h>
using namespace std;
int main()
{
	char ch[100005];
	scanf("%s",ch);
	int c=0,h=0,e=0,f=0,i;
	for(i=0;ch[i]!='\0';i++)
	{
		if(ch[i]=='C')				c++;
		if(ch[i]=='H' && h<c)		h++;
		if(ch[i]=='E' && e<h)		e++;
		if(ch[i]=='F' && f<e)		f++;
	}
	printf("%d\n",f);
}
