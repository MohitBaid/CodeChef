//https://www.geeksforgeeks.org/divide-and-conquer-maximum-sum-subarray/
#include<bits/stdc++.h>
using namespace std;
long long int max(long long int a, long long int b) { return (a > b)? a : b; }
long long int max3(long long int a, long long int b,long long int c){	return max(max(a,b),c);	}
long long int maxCrossingSum(long long int arr[], long long int l, long long int m, long long int h)
{
    long long int sum = 0;
    long long int left_sum = 0;
    for (long long int i = m; i >= l; i--)
    {
        sum = sum + arr[i];
        if (sum > left_sum)
          left_sum = sum;
    }
    sum = 0;
    long long int right_sum = 0;
    for (long long int i = m+1; i <= h; i++)
    {
        sum = sum + arr[i];
        if (sum > right_sum)
          right_sum = sum;
    }
    return left_sum + right_sum;
}
long long int maxSubArraySum(long long int a[], long long int size)
{
    long long int max_so_far = 0, max_ending_here = 0;
 
    for (long long int i = 0; i < size; i++)
    {
        max_ending_here = max_ending_here + a[i];
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;
 
        if (max_ending_here < 0)
            max_ending_here = 0;
    }
    return max_so_far;
}
int main()
{
	int T;	cin>>T;
	while(T--)
	{
		long long int n,k,i;	cin>>n>>k;
		long long int s=0,A[n],s1=-9999999999999999;
		for(i=0;i<n;i++)
		{
			cin>>A[i];
			s+=A[i];
			s1=max(A[i],s1);
		}
		if(s1<0)	
		{
			cout<<s1<<endl;
		}
		else if(k==1)
		{
			long long int ans=maxSubArraySum(A,n);
			cout<<ans<<endl;
		}
		else
		{
			long long int B[2*n];
			for(i=0;i<2*n;i++)
				B[i]=A[i%n];	
			long long int ans=maxSubArraySum(B,2*n);
			if(s>0)		ans+=1LL*s*(k-2);
			cout<<ans<<endl;
		}
	}
}
