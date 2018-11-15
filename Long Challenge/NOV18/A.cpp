#include<bits/stdc++.h>
#define int long long int
using namespace std;
main()
{
	int T=1;
	while(T--)
	{
		int n,q,k;	cin>>n>>q>>k;
		int s[n];
		for(int i = 0;i<n;i++)
		{
			cin>>s[i];
		}
		vector < int > v;
		int c[2]={0,0},flag = s[0];
		for(int i=0;i<n;i++)
		{
			if(s[i] == flag)
			{
				c[flag]++;
			}
			else
			{
				if(flag==1)		v.push_back(c[flag]);
				else			v.push_back(c[flag]*-1);	
				
				c[flag]=0;
				
				flag = (flag+1)%2;
				c[flag]=1;
			}
		}
		if(flag==1)			v.push_back(c[flag]);
		else				v.push_back(c[flag]*-1);	
		
		deque < int > dq;
	
		multiset < int > ms;
		for(int i=0;i<v.size();i++)
		{
			dq.push_back(v[i]);
			ms.insert(v[i]);
		}
		
		while(q--)
		{
			char ch;	cin>>ch;
			if(v.size() == 1)
			{
				if(ch=='!')		continue;
				else
				{
					cout<<min(k,max(0*1LL,v[0]))<<endl;	
				}	
			}
			else
			{
				if(ch=='!')
				{
					int x = dq.back();
					int y = dq.front();
					
					if(x*y>0)
					{	
						if(x>0)
						{
							dq.pop_front();
							dq.pop_back();
							ms.erase(ms.find(x));
							ms.erase(ms.find(y));
							
						
							if(x-1!=0)	dq.push_back(x-1);
							if(y+1!=0)	dq.push_front(y+1);
						
							if(x-1!=0)	ms.insert(x-1);
							if(y+1!=0)	ms.insert(y+1);
						}
						else
						{
								dq.pop_front();
								dq.pop_back();
								ms.erase(ms.find(x));
								ms.erase(ms.find(y));
								
							
								if(x+1!=0)	dq.push_back(x+1);
								if(y-1!=0)	dq.push_front(y-1);
							
								if(x+1!=0)	ms.insert(x+1);
								if(y-1!=0)	ms.insert(y-1);
						}
					}
					else
					{
						if(x<0)
						{
							dq.pop_back();
							ms.erase(ms.find(x));
							
							if(x+1!=0)	dq.push_back(x+1);
							dq.push_front(-1);
						
							if(x+1!=0)	ms.insert(x+1);
							ms.insert(-1);	
						}
						else
						{
							dq.pop_back();
							ms.erase(ms.find(x));
							
							if(x-1!=0)	dq.push_back(x-1);
							dq.push_front(1);
						
							if(x-1!=0)	ms.insert(x-1);
							ms.insert(1);
						}
					}
				}
				else
				{
					multiset < int > :: iterator mt;
					mt = ms.end();
					mt--;
					cout<<min(k,max(0*1LL,(*mt)))<<endl;
				}
			}
		}
	}
}
