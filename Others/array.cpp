#include<bits/stdc++.h>
using namespace std;
void Display(int a[],int size)
{
     for(int i=0;i<size;i++)
     {
         cout<<"\n Element "<<i+1<<": "<<a[i];
     }
}

int Insert(int capacity,int element, int index,int a[],int &size)
{
    if(size>=capacity)
    {
    cout<<"\n Not Possible to insert Element ::";
    return(-1);
    }
    for(int i=size-1;i>=index;i--)
    {
        a[i+1]=a[i];
    }
    a[index]=element;
    size+=1;
    return (1);
}

int Delete(int index,int a[],int &size)
{
    for(int j=index-1;j<=size-1;j++)
    {
        a[j]=a[j+1];
    }
    size-=1;
}

void LinearS(int a[],int size)
{
   int element,i;
   cout<<"\n Enter Element to be searched : ";
   cin>>element;
   for(i=0;i<size;i++)
   {
       if(a[i]==element)
       {
           cout<<"\n Element found at "<<i+1<<"position";
       }
   }


}
int main()
{
    int a[100];
    int i,size;
    cout<<"\n Enter size of array(max 100) ::";
    cin>>size;
    cout<<" Enter Data of the array";
    for(i=0;i<size;i++)
    {
       cout<<"\n Enter "<<i+1<<" Element::";
       cin>>a[i];
    }
    Insert(100,44,5,a,size);
    cout<<"\n Updated Array:";
    Display(a,size);
    Delete(3,a,size);
    cout<<"\n Updated Array After Deletion :";
    Display(a,size);
    cout<<"\n        Search Mechanism";
    LinearS(a,size);
    return 0;
}