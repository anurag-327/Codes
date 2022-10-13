#include<bits/stdc++.h>
using namespace std;
void print(multiset<string> &s)
{
//     //array 1
//    for(int i=0;i<v.size();i++)
//    {
//        cout<<v[i]<<endl;
//    }


//     //array 2
//    //    vector<int> ::iterator it=v.begin();
//    auto it=v.begin();
//    for(it=v.begin();it!=v.end();it++)
//    {
//        cout<<endl<<(*it);
//    }


        //    array 3
    // for(int &value:v)
    // {
    //    cout<<endl<<value;
    // }
 

    //   MAP 1

    // auto it=m.begin();
    // for(it=m.begin();it!=m.end();it++)
    // {  
    //     cout<<(*it).first<<"  "<<(*it).second<<endl;
    // }

    // for(auto &value:m)
    // {
    //    cout<<value.first<<" "<<value.second<<endl;
    // }

    for(auto &value:s)
    {
        cout<<value<<endl;
    }

}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

             //    VECTORS

    // vector<int> v;
    // int n;
    // cin>>n;
    // for(int i=0;i<n;i++)
    // {
    //     int a;
    //     cin>>a;
    //     v.push_back(a);
    // }
    // print(v);

             // MAP

    //  map<int,string> m;
    //  m[1]="Anurag";
    //  m[11]="Anand";
    //  m[5]="Pavnesh";
    //  m[3]="Akshat";
    //  m.insert({23,"Rachit"});
    //  m.insert({66,"Suyash"});
    //  print(m);

    //  auto it=m.find(5);
    //  if(it!=m.end())
    //  cout<<endl<<it->first<<" " <<it->second<<endl;
    //  cout<<endl<<"size="<<m.size()<<endl;
     
    //  m.erase(it);
    //  m.erase(66);
    //  print(m);
    //  m.clear();
    //  print(m);
    //  cout<<endl<<"size="<<m.size()<<endl;

    // unordered_map<int,string> m;
    //  m[1]="Anurag";
    //  m[11]="Anand";
    //  m[11]="Pavnesh";
    //  m[3]="Akshat";
    //  m.insert({23,"Rachit"});
    //  m.insert({66,"Suyash"});
    //  print(m);

    //  auto it=m.find(5);
    //  if(it!=m.end())
    //  cout<<endl<<it->first<<" " <<it->second<<endl;
    //  cout<<endl<<"size="<<m.size()<<endl;
     
    //  m.erase(it);
    //  m.erase(66);
    //  print(m);
    //  m.clear();
    //  print(m);
    //  cout<<endl<<"size="<<m.size()<<endl;
     
    // multimap<int,string> m;
    // //  m[1]="Anurag";
    // //  m[11]="Anand";
    // //  m[11]="Pavnesh";
    // //  m[3]="Akshat";
    //  m.insert({23,"Rachit"});
    //  m.insert({66,"Suyash"});
    //  print(m);

    //  auto it=m.find(5);
    //  if(it!=m.end())
    //  cout<<endl<<it->first<<" " <<it->second<<endl;
    //  cout<<endl<<"size="<<m.size()<<endl;
     
    //  m.erase(it);
    //  m.erase(66);
    //  print(m);
    //  m.clear();
    //  print(m);
    //  cout<<endl<<"size="<<m.size()<<endl;
     
       //  SET
    
    // 
    

    // unordered_set<string> s;
    // s.insert("Anurag");
    // s.insert("Akshat");
    // int n;
    // cin>>n;
    // while(n--)
    // {
    //     string k;
    //     cin>>k;
    //     s.insert(k);
    // }
    // print(s);
    // auto it=s.find("Anurag");
    // s.erase(it);
    // print(s);


    multiset<string> s;
    // s.insert("hello");
    // s.insert("Akshat");
    int n;
    cin>>n;
    while(n--)
    {
        string k;
        cin>>k;
        s.insert(k);
    }
    // print(s);
    auto it=s.find("Ani");
    s.erase(it);
    print(s);

     return 0;        
}