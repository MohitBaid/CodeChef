#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;	cin>>T;
	while(T--)
	{
		string s;	cin>>s;
		char pre='.';int pos=-1,dir=1,moves=0;
		for(int i=0;i<s.size();i++)
		{
			if(s[i]!='.')
			{
				pre = s[i];
				pos = i;
				break;
			}
		}
		int ma=0,mb=0,pair=0;
		set < int > gt;
		for(int i=pos+1;i<s.size();i++)
		{
			if(s[i]!='.')
			{
				if(pre == '.')
				{
					pre = s[i];
					pos = i;
				}
				else
				{
					if(pre == s[i])
					{
						int moves = (i-pos-1);
						if(pre == 'A')
							ma += moves;
						else
							mb += moves;	
					}
					else	
					{
						if(i-pos > 1)
						{
							pair++;
							if(gt.find(i-pos)==gt.end())
								gt.insert(i-pos);
							else 	gt.erase(i-pos);	
						}
					}
					pre = '.';
					pos = -1;
				}
			}
		}
		if(pre != '.')
		{
			if(pre == 'A')
				ma += s.size()-pos-1;
			else
				mb += s.size()-pos-1;	
		}
		if(pair%2==0)
		{
			if(gt.size()==0)
			{
				mb++;
			}
			else
			{
				ma++;
			}
		}
		else ma++;	
		//cout<<ma<<" "<<mb<<endl;
		if(mb>=ma)	cout<<"B"<<endl;
		else		cout<<"A"<<endl;	
	}
}
