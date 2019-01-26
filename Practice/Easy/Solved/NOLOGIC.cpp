#include<bits/stdc++.h>
using namespace std;
int main()
{
	string str;
	int T;	cin>>T;
	cin.get();
	while(T--)
	{
		getline(cin,str);
		set < char > let;
		for(char ch='a' ; ch<='z' ; ch++)
			let.insert(ch);
		for(int i=0 ; i<str.size() ;i++)
		{
			if(str[i]>='a' && str[i]<='z')
			{
				if(let.find(str[i])!=let.end())
					let.erase(str[i]);	
			}
			if(str[i]>='A' && str[i]<='Z')
			{
				if(let.find(str[i]+32)!=let.end())
					let.erase(str[i]+32);	
			}	
		}
		if(let.size()==0)	cout<<"~";
		else  				cout<<(*(let.begin()));
		cout<<endl;	
	}
}
