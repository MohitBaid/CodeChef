#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;	cin>>T;
	while(T--)
	{
		string s;	cin>>s;
		int p1=s.size()/2,p2=s.size()/2,f=0;
		if(s.size()%2==0)
				p1--;
		while(p1>=0)
		{
			if(s[p1]==s[p2])
			{
				p1--;
				p2++;
			}
			else	break;
		}
		if(p1== -1)			f=1;
		else
		{
			if(s[p1]<s[p2])		f=1;
			while(p1>=0)
			{
				s[p2]=s[p1];
				p1--;
				p2++;
			}
		}
		//cout<<s<<" "<<f<<endl;
		int msb=0,lsb=0;
		if(f==1)
		{
			p1=s.size()/2,p2=s.size()/2;
			if(s.size()%2==0)
				p1--;
			else
			{
				if(s[p1]=='9')	
				{
					s[p1]='0';
					if(p1==0)			lsb=1;
					if(p1 +1 ==s.size())	msb=1;
				}
				else		
				{
					s[p1]++;
					p1=0;
					p2=s.size();
				}
				p1--;
				p2++;
			}	
			while(p1>=0)
			{
				if(s[p1]=='9')
				{
					s[p1]='0';
					p1--;
					if(p1==-1)
						lsb=1;
				}
				else
				{
					s[p1]++;
					break;
				}
			}
			while(p2<s.size())
			{
				 if(s[p2]=='9')
				{
					s[p2]='0';
					p2++;
					if(p2==s.size())
						msb=1;
				}
				else
				{
					s[p2]++;
					break;
				} 
			}			
		}
		if(lsb==1 && msb==1)
		{
			//cout<<"afs ";
			cout<<lsb;
			for(int i=0;i<s.size()-1;i++)	cout<<s[i];
			cout<<msb<<endl;
		}
		else
		{
			cout<<s<<endl;
		}
	}
}
