#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;	cin>>T;
	while(T--)
	{
		set < pair < int , pair < int,int > > > s;
		set < pair < int , pair < int,int > > > ::iterator it;
		int k=3;
		while(k--)
		{
			int s1,s2,s3;
			cin>>s1>>s2>>s3;
			s.insert(make_pair(s1*-1,make_pair(s2*-1,s3*-1)));
		}
		int A[3][3];
		for(i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
			{
				
			}
		}
		else			cout<<"no"<<endl;
	}
}
