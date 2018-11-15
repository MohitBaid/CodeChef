#include<bits/stdc++.h>
using namespace std;
int main()
{
	char ch[22];
	while(scanf("%s",ch)!=EOF)
	{
		int a=0,b=0,s=0,ra=5,rb=5,i;
		bool result=false;
		for(i=0;i<10;i++)
		{
			if(ch[i]=='1')
			{
				if(i%2==0)		a++;
				else			b++;
			}
			s++;
			if(i%2==0)	ra--;
			else		rb--;
			if(a>b)
			{
				if(a-b>rb)	
				{
					result=true;
					break;
				}
			}	
			else if(b>a)
			{
				if(b-a>ra)
				{
					result=true;
					break;
				}
			}
		}
		if(a==b  && !result)
		{
			int f=10;
			for(i=0;i<5;i++)
			{
				s+=2;
				if(ch[f]==ch[f+1]);
				else
				{
					if(ch[f]=='1')	a++;
					else			b++;
					break;
				}
				f+=2;
			}
		}
		if(a>b)	 cout<<"TEAM-A "<<s<<endl;
		if(b>a)	 cout<<"TEAM-B "<<s<<endl;
		if(a==b) cout<<"TIE "<<endl;
	}
}
