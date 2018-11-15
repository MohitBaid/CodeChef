#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int y=0,x=1000;int L,B,H;
	string ch;
	int low=0,high=1000,mid;
	while(low<high)
	{
		mid=(low+high)/2;
		cout<<"? "<<mid<<" "<<y<<endl;
		fflush(stdout);
		cin>>ch;
		if(ch=="YES")
			low=mid+1;
		else
			high=mid-1;
	}
	low=low+5;
	if(low>1000)
		low=1000;
	while(1)
	{
		cout<<"? "<<low<<" "<<y<<endl;
		fflush(stdout);
		cin>>ch;
		if(ch=="NO")
			low--;
		else
			break;
	}
	L=(low)*2;
	y=L,x=1000;
	low=0;high=1000;
	while(low<high)
	{
		mid=(low+high)/2;
		cout<<"? "<<mid<<" "<<y<<endl;
		fflush(stdout);
		cin>>ch;
		if(ch=="YES")
			low=mid+1;
		else
			high=mid-1;	
	}
	low=low+5;
	if(low>1000)
		low=1000;
	while(1)
	{
		cout<<"? "<<low<<" "<<y<<endl;
		fflush(stdout);
		cin>>ch;
		if(ch=="NO")
			low--;
		else
			break;
	}
	B=(low)*2;
	y=0,x=0;
	low=0;high=1000;
	while(low<high)
	{
		mid=(low+high)/2;
		cout<<"? "<<x<<" "<<mid<<endl;
		fflush(stdout);
		cin>>ch;
		if(ch=="YES")
		{
			low=mid+1;
		}
		else
			high=mid-1;	
	}
	low=low+5;
	if(low>1000)
		low=1000;
	while(1)
	{
		cout<<"? "<<x<<" "<<low<<endl;
		fflush(stdout);
		cin>>ch;
		if(ch=="NO")
			low--;
		else
			break;
	}
	H=low-L;
	int ans=L*L+(B*H)/2;
	cout<<"! "<<ans<<endl;
}
