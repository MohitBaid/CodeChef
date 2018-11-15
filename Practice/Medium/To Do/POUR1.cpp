#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;	cin>>T;
	while(T--)
	{
			int a,b,c;	cin>>a>>b>>c;
			if(c==0)				cout<<"0"<<endl;
			else if(c==b || c==a)	cout<<"1"<<endl;
			else if(c==abs(b-a))	cout<<"2"<<endl;
			else					cout<<"-1"<<endl;
	}
}
