#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;		cin>>T;	
	while(T--)
	{
		float n,v1,v2;	cin>>n>>v1>>v2;
		double l1=1.414*n;
		double l2=2.0*n;
		double t1=l1/v1;
		double t2=l2/v2;
		//cout<<l1<<" "<<l2<<" "<<t1<<" "<<t2<<endl;
		if(t1<t2)		cout<<"Stairs"<<endl;
		else			cout<<"Elevator"<<endl;
	}
}
