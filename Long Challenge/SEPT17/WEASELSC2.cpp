//http://www.geeksforgeeks.org/largest-rectangle-under-histogram/
// C++ program to find maximum rectangular area in linear time
#include<iostream>
#include<stack>
using namespace std;
int getMaxArea(long long int hist[], int n)
{
    stack<int> s;
    long long int max_area = 0; // Initalize max area
    long long int tp;  // To store top of stack
    long long int area_with_top; // To store area with top bar as the smallest bar
    long long int i = 0;
    while (i < n)
    {
        // If this bar is higher than the bar on top stack, push it to stack
        if (s.empty() || hist[s.top()] <= hist[i])
            s.push(i++);
        else
        {
            tp = s.top();  // store the top index
            s.pop();  // pop the top
 			 area_with_top = hist[tp] * (s.empty() ? i : i - s.top() - 1);
			if (max_area < area_with_top)
                max_area = area_with_top;
        }
    }
    while (s.empty() == false)
    {
        tp = s.top();
        s.pop();
        area_with_top = hist[tp] * (s.empty() ? i : i - s.top() - 1);
 
        if (max_area < area_with_top)
            max_area = area_with_top;
    }
 
    return max_area;
}
int main()
{
    int T;	cin>>T;
    while(T--)
    {
		long long int n,i,k;	cin>>n>>k;
		long long int A[n];
		for(i=0;i<n;i++)	cin>>A[i];    	
    	cout<<getMaxArea(A, n)<<endl;
	}
}
