#include<bits/stdc++.h>
using namespace std;
int main()
{
	long int n,h,i,pen;	cin>>n>>h;
	int p[h],r[h],w[h],c[h],l[h],d[h];
	for(i=0;i<h;i++)
	{
		cin>>p[i]>>r[i]>>w[i]>>c[i];
		l[i]=c[i];
		d[i]=1;
	}
	cin>>pen;
	map <int,int > mp1,mp2;
	for(i=0;i<h;i++)
	{
		cout<<"p b "<<i<<endl;
	}
	while(n--)
	{
		fflush(stdout);
		cout<<"g"<<endl;
		int c2;	cin>>c2;
		if(c2==0)
		{
			int cid,q;	cin>>cid>>q;
			int flag=1;
			for(i=0;i<h;i++)
			{
				if(d[i]==1)
				{
					if(l[i]>=q)
					{
						mp1[cid]=c[i]-l[i];
						mp2[cid]=i;
						l[i]-=q;
						cout<<"p s "<<i<<" "<<mp1[cid]<<endl;
						flag=0;
						break;
					}
				}
			}
			if(flag)		cout<<"p s -1 -1\n";
		}
		if(c2==1)
		{
			int cid,p;	cin>>cid>>p;
			if(d[mp2[cid]]==1)
				cout<<"p i "<<mp2[cid]<<" "<<mp1[cid]+p<<endl;
			else
				cout<<"p i -1 -1\n";
		}
		if(c2==2)
		{
			int hid;	cin>>hid;
			d[hid]=0;
		}
	}
	cout<<"end\n";
}
