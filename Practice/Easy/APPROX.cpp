#include<bits/stdc++.h>
using namespace std;
int main()
{
	char dec_dig[1000000 +1];
	int num = 103993;
	int den = 33102;
	int rem = num%den,i;
	for(i=1;i<=1000000;i++)
	{
		rem = rem*10;
		dec_dig[i] = (char)(rem/den + '0');
		rem = rem % den;
	}
	int T;	cin>>T;
	while(T--)
	{
		int k;	cin>>k;
		cout<<"3";
		//k--;
		if(k>0)
		{
			cout<<".";
			for(i=1;i<=k;i++)
				cout<<dec_dig[i];
		}
		cout<<endl;
	}
}