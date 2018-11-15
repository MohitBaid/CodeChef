#include<bits/stdc++.h>
using namespace std;
long long arr[1000000],brr[1000000],crr[1000000];
long long int binarySearch(long long int arr[], long long int l, long long int r, long long int x)

{
   if (r >= l)
   {
        long long  mid = l + (r - l)/2;
 
        // If the element is present at the middle itself
        if (arr[mid] == x)  return mid;
 
        // If element is smaller than mid, then it can only be present
        // in left subarray
        if (arr[mid] > x) return binarySearch(arr, l, mid-1, x);
 
        // Else the element can only be present in right subar:ray
        return binarySearch(arr, mid+1, r, x);
   }
 
   // We reach here when element is not present in array
   return r;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long int p,q,r,i,j,k,mod=1000000007;
		cin>>p>>q>>r;
		long long int sum=0,sumx[p],sumz[r],temp=0;
		for(i=0;i<p;i++)
		{
			cin>>arr[i];
			//sumx[i]=temp+arr[i];
			//temp=sumx[i];
		}
		for(i=0;i<q;i++)
                {
                        cin>>brr[i];
                }
		for(i=0;i<r;i++)
                {
                        cin>>crr[i];
		//	sumz[i]=temp+crr[i];
		//	temp=sumz[i];
                }
		sort(arr,arr+p);
		sort(brr,brr+q);
		sort(crr,crr+r);
		for(i=0;i<p;i++)
		{
			sumx[i]=(temp+arr[i])%mod;
			temp=sumx[i];
		//	cout<<arr[i]<<"\t"<<sumx[i]<<endl;
		}temp=0;
		for(i=0;i<r;i++)
		{
			sumz[i]=(temp+crr[i])%mod;
			temp=sumz[i];
		}
	//	int lx=binarySearch(arr,0,p-1,0);
	//	int lz=binarySearch(crr,0,r-1,15);
//		cout<<"lx : "<<lx<<"\t ly : "<<lz<<endl;
		for(i=0;i<q;i++)
		{
			long long lx,lz;
			if(brr[i]<arr[0] || brr[i]<crr[0])
			{
			//	cout<<"0"<<endl;
				break;
			}
			else
			{
			
				if(brr[i]>arr[p-1] && brr[i]<crr[r-1])
				{
					lx=p-1;
					lz=binarySearch(crr,0,r-1,brr[i]);
				}
				else if(brr[i]<arr[p-1] && brr[i]>crr[r-1])
                {
             	   	 lz=r-1;
                    lx=binarySearch(arr,0,p-1,brr[i]);
            	}
				else if(brr[i]>arr[p-1] && brr[i]>crr[r-1])
                {
                      lx=p-1;
                      lz=r-1;
        	    }
				else
				{
					lx=binarySearch(arr,0,p-1,brr[i]);
					lz=binarySearch(crr,0,r-1,brr[i]);
				}
				long long sum1,sum2,sum3,sum4;
				sum1=((sumx[lx])%mod * (brr[i] * (lz+1))%mod)%mod;
         		sum2=(((lx+1)*brr[i])%mod * ( sumz[lz])%mod)%mod;
         		sum3=(((lx+1)*(lz+1))%mod * (brr[i]*brr[i])%mod)%mod;
         		sum4=(sumx[lx]*sumz[lz]) % mod;
         		sum+=((sum1+sum2)%mod+(sum3+sum4)%mod)%mod;
//				cout<<sum1<<" "<<sum2<<" "<<sum3<<" "<<sum4<<endl;
			}//cout<<sum<<endl;
		}cout<<sum<<endl;
	//	cout<<sum%mod<<endl;
	}
}
