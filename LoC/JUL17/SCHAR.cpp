#include<bits/stdc++.h>
using namespace std;
int P[26][100005];
int pos[26];
int finddis(char ch[],int ans.int l)
{
	
}
int main()
{
	int T;	scanf("%d",&T);
	while(T--)
	{
		char ch[100005];
		scanf("%s",ch);
		long long int A[100005]={0};
		int i,B[100005]={0},C[100005]={0};
		for(i=0;i<26;i++)
			P[i]=-1;
		int l=strlen(ch);	
		for(i=l-1;i>=0;i--)
		{
			P[ch[i]-'a'][pos[ch[i]-'a']++]=i;
		}
		B[0]=0,C[0]=0;
		for(i=1;i<l;i++)		B[i]=abs((ch[i]-'a')-(ch[i-1]-'a'));
		for(i=1;i<l;i++)		C[i]=C[i-1]+B[i];
		for(i=0;ch[i]!='\0';i++)
		{
			char c=ch[i];
			A[i]=C[i];
			int j=0;
			while(j<l)
			{
				j=P[c-'a'];
				j++;
				A[i]+=B[j];
				c=ch[j];
			}
		}
		sort(A,A+l);
		cout<<A[0]<<endl;
	}
}
