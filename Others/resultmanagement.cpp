#include<iostream>
#include<string.h>
using namespace std;
class result
{
    char name[30];
    int roll;
    public:
    float phy;
    float chem;
    float math;
    float eng;
    float cs;
    float total;
    float per;
    result();
    void input();
    void display();
}   ;
void result :: input(void)
{
    cout<<"\n Enter name of student";
    gets(name);
    cout<<"\n Enter Roll No of student";
    cin>>roll;
    cout<<"\n Enter marks in physics";
    cin>>phy;
    cout<<"\n Enter marks in chemistry";
    cin>>chem;
    cout<<"\n Enter marks in maths";
    cin>>math;
    cout<<"\n Enter marks in english";
    cin>>eng;
    cout<<"\n Enter marks in computer science";
    cin>>cs;  
}
void result :: display(void)
{
    cout<<"Name of student ::"<<name;
    cout<<"Roll No. ::"<<roll;
    cout<<" Marks in Physics ::"<<phy;
    cout<<" Marks in Chemistry ::"<<chem;
    cout<<" Marks in Maths ::"<<math;
    cout<<" Marks in English ::"<<eng;
    cout<<" Marks in Computer Science ::"<<cs; 
    total=phy+chem+math+eng+cs;
    per=total/5.0;
    cout<<" TOTAL MARKS ::"<<total;
    cout<<" PERCENTAGE ::"<<per;
}
 result :: result()
{
    strcpy(name,"Nil");
    roll=0;
    phy=0;
    chem=0;
    math=0;
    eng=0;
    cs=0;
    total=0;
    per=0;
}
int main()
{
    result stu[2];
    int i,j;
    for(i=0;i<2;i++)
    {
         cout<<"Enter Detail of Student "<<i+1;
        stu[i].input();
    }
    for(j=0;j<2;j++)
    {
        cout<<"\n\n Detail of Student "<<j+1;
        stu[j].display();
    }
    return 0;
}