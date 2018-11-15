#include<bits/stdc++.h>
using namespace std;
void search_asc(int v,int n)
{
	int i=1,j=n,u;
	bool ans = false;
	
	while(1)
	{
		cout<<"1 "<<i<<" "<<j<<endl;
		cin>>u;
		if(v==u)
		{
			ans = true;
			break;
		}
		else if(u == -1)	break;
		else
		{
			if(u>v)		j--;
			else		i++;
		}
	}
	
	if(ans)	cout<<"2 "<<i<<" "<<j<<endl;
	else	cout<<"2 -1 -1"<<endl;
}

void search_dsc(int v,int n)
{
	int i=n,j=1,u;
	bool ans = false;
	
	while(1)
	{
		cout<<"1 "<<i<<" "<<j<<endl;
		cin>>u;
		if(v==u)
		{
			ans = true;
			break;
		}
		else if(u == -1)	break;
		else
		{
			if(u>v)		j++;
			else		i--;
		}
	}
	
	if(ans)	cout<<"2 "<<i<<" "<<j<<endl;
	else	cout<<"2 -1 -1"<<endl;
}
int search(int v,int n)
{
	int a,b;
	cout<<"1 1 1"<<endl;
	fflush(stdout);
	cin>>a;
	cout<<"1 1 2"<<endl;
	fflush(stdout);
	cin>>b;
	if(a>b)	search_dsc(v,n);
	else	
	{
		search_asc(v,n);
		//cout<<"2 -1 -1"<<endl;
	}
}
int main()
{
	int n,k,v;
	cin>>n>>k>>v;
	search(v,n);
}
