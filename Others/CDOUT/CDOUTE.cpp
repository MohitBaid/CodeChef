#include<bits/stdc++.h>
using namespace std;
int ls( int arr[], int n )
{
    int ls[n], i, j, max = 0;
    for (i = 0; i < n; i++ )
        ls[i] = 1;
    for (i = 1; i < n; i++ )
        for (j = 0; j < i; j++ ) 
            if ( arr[i] <=arr[j] && ls[i] < ls[j] + 1)
                ls[i] = ls[j] + 1;
    for (i = 0; i < n; i++ )
        if (max < ls[i])
            max = ls[i];
    return max;
}
int main()
{
  	int n,i;	cin>>n;
  	int A[n];
  	for(i=0;i<n;i++)
  		cin>>A[i];
  	int t=ls(A,n);
	printf("%d",5*(t-1));  	
}
