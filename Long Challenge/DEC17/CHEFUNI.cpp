#include<bits/stdc++.h>
using namespace std;
int calmov(int F[])
{
	int mov=0;
	if(F[1]!=F[2])
	{
		int diff=min(F[0],F[2]-F[1]);
		mov=diff;
		F[0]-=diff;
		F[2]-=diff;
	}
	if(F[0]>0)
	{
		int d=F[0]/2;
		mov+=2*d;
		F[0]-=d*2;
		F[1]-=d;
		F[2]-=d;
	}
	mov+=F[1];
	F[2]-=F[1];
	F[1]=0;
	return mov;
}
long long int compute(int F[],int s[],int a,int b,int c)
{
	long long int ans=0;
	if(s[0]==1)
	{
		ans+=(F[0]+F[1]+F[2])*a;
		return ans;
	}
	else
	{
		if(s[0]==2)
		{
			bool flag=true;
			if(F[0]+F[1]<=F[2])	flag=false;
			int mov=calmov(F);
			sort(F,F+3);
			int mov1=mov;
			ans+=mov*b;
			if(s[1]==1)
			{
				ans+=(F[2])*a;
				return ans;
			}
			else
			{
				long long int ans1=ans,ans2=ans;
				if(F[2]>=1 && flag)
				{
					int diff=min(F[2],mov1);
					ans1+=(diff*c+(F[2]-diff)*a -diff*b);
					ans2+=F[2]*a;
					return min(ans1,ans2);
				}
				else
				{
					ans+=F[2]*a;
					return ans;
				}
			}
		}
		else
		{
			int mov=F[0];
			ans+=(mov*c);
			F[1]-=F[0];
			F[2]-=F[0];
			F[0]=0;
			sort(F,F+3);
			//cout<<ans<<endl;
			if(s[1]==1)
			{
				ans+=(F[2]+F[1])*a;
				return ans;
			}
			else
			{
				long long int ans1=ans,ans2=ans+((F[1]*b) + (F[2]-F[1])*a);;
				if(F[2]-F[1]>=1)
				{
					int diff=min(F[2]-F[1],mov);
					ans1-=diff*c;
					F[0]+=diff;
					F[1]+=diff;
					F[2]+=diff;
					int mov=calmov(F);
					ans1+=mov*b;
					//cout<<mov<<" "<<b<<endl;
					ans1+=(F[2]*a);
					return min(ans1,ans2);
				}
				else
				{
					return ans2;
				}
			}
		}
	}
}
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out1.txt","w",stdout);
	int T;	cin>>T;
	while(T--)
	{
		int xi,y,z,a,b,c,i,j;
		cin>>xi>>y>>z>>a>>b>>c;
		//cout<<xi<<" "<<y<<" "<<z<<" "<<a<<" "<<b<<" "<<c<<":";
		int s[3]={1,2,3};
		double x[3];
		x[0]=1.0*a/1.0;
		x[1]=1.0*b/2.0;
		x[2]=1.0*c/3.0;
		for(i=0;i<3;i++)
		{
			for(j=0;j<3-i-1;j++)
			{
				if(x[j]>x[j+1])
				{
					int temp=x[j];
					x[j]=x[j+1];
					x[j+1]=temp;
					
					temp=s[j];
					s[j]=s[j+1];
					s[j+1]=temp;
				}
			}
		}
		//cout<<"assaf";
		int F[3];
		F[0]=xi;
		F[1]=y;
		F[2]=z;
		sort(F,F+3);
		if(F[0]==0)
		{
			if(F[1]==0)
			{
				s[0]=1;
				s[1]=2;
				s[2]=3;
			}
			else
			{
				if(s[0]==3)
				{
					swap(s[0],s[1]);
					swap(s[1],s[2]);
				}
				if(s[1]==3)
				{
					swap(s[1],s[2]);
				}
			}
		}
		cout<<compute(F,s,a,b,c)<<endl;
	}
}
