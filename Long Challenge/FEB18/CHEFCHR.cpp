#include<bits/stdc++.h>
using namespace std;
map < char , int > mp;
int check()
{
	if(mp['c']==1 && mp['h']==1 && mp['e']==1 && mp['f']==1)	return 1;
	else	return 0;
}
int main()
{
	int T;	cin>>T;
	while(T--)
	{
		mp.clear();
		string a;	cin>>a;
		int ans=0,i;
		mp[a[0]]++;
		mp[a[1]]++;
		mp[a[2]]++;
		mp[a[3]]++;
		for(i=4;i<a.size();i++)
		{
			if(check())		ans++;
			mp[a[i-4]]--;
			mp[a[i]]++;
		}
		if(check())	ans++;
		if(ans)		cout<<"lovely "<<ans<<endl;
		else		cout<<"normal\n";
	}
}
