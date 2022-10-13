#include <bits/stdc++.h>
using namespace std;

int main() 
{
	// your code goes here
	int T,N,X,i,j,k;
	cin>>T;
	for(i=1;i<=T;i++)
	{
	    int sum=0;
	    cin>>N>>X;
	    int A[N];
	    for(j=0;j<N;j++)
	    {
            cin>>A[N];
            sum=sum+A[N];
	    }
	    if(sum<X)
	    cout<<"\n -1";
	    else
	    {
	        int count=0;
	        int summ=0;
		    sort(A,A+N);
			cout<<A[N];
		    for(k=N-1;k>=0;k--)
	        {
               summ+=A[N];
               count++;
	           if(summ>=X)
	           {
	               break;
	          }
	        }
	    cout<<endl<<count;
	    }
	}
	return 0;
}