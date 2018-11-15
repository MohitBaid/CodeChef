//http://www.geeksforgeeks.org/searching-for-patterns-set-2-kmp-algorithm/
#include<bits/stdc++.h>
using namespace std;
void computeLPSArray(char *pat, int M, int *lps);
int KMPSearch(char *pat, char *txt)
{
    int M = strlen(pat);
    int N = strlen(txt);
    int lps[M];
    computeLPSArray(pat, M, lps);
    int i = 0;  
    int j  = 0;  
    int ans=-1;
    int pos=-1;
    while (i < N)
    {
        if (pat[j] == txt[i])
        {
            j++;
            i++;
        }
        if (j == M)
        {           
		    return i-j;
            j = lps[j-1];
        }
        else if (i < N && pat[j] != txt[i])
        {
         	if(ans<j)
         	{
         		ans=j;
         		pos=i-j;
         	}
            if (j != 0)
                j = lps[j-1];
            else
                i = i+1;
        }
    }
    return pos;
}
void computeLPSArray(char *pat, int M, int *lps)
{
    int len = 0;
    lps[0] = 0; // lps[0] is always 0
    int i = 1;
    while (i < M)
    {
        if (pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else 
        {
            if (len != 0)
            {
                len = lps[len-1];
            }
            else 
            {
                lps[i] = 0;
                i++;
            }
        }
    }
} 
int main()
{
	int n,i;	cin>>n;
	string a,b;		cin>>a>>b;
	for(i=0;i<n-1;i++)	b+=b[i];
	char A[n+1],B[2*n];
	for(i=0;i<n;i++)	A[i]=a[i];		A[i]=a[i];
	for(i=0;i<n+n-1;i++)	B[i]=b[i];		B[i]=b[i];
	int ans=KMPSearch(A,B);
	if(ans==-1)	ans++;
	cout<<ans<<endl;
}
