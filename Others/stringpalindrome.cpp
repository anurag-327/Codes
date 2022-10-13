#include <bits/stdc++.h>
using namespace std;



/*int isPalindrome(string S)
{
	string P = S;
	reverse(P.begin(), P.end());
	if (S == P) 
		return 1;
	else 
		return 0;
}*/


int isPalindrome(string str)
{
    int i = 0;
    int j = str.length() - 1;
 
    while (i < j)
    {
        if (str[i] != str[j]) {
            return 0;
        }
 
        i++;
        j--;
    }
 
    return 1;
}
 

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    cout<<"Hello World!";
    string s[6];
    for(int i=0;i<=5;i++)
    {
         cin>>s[i];
    }

    for(int i=0;i<=5;i++)
    {
        string s1;
        for(int j=i+1;j<=5;j++)
        {
            
            s1=s[i]+s[j];
            if(isPalindrome(s1))
            {
                cout<<"\n PAlindrome of"<<s[i]<<"And "<<s[j];}
        }
    }
}