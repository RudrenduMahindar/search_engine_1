#include <iostream>
#include "src/lib/solution.h"
#include <algorithm>
using namespace std;

vector<string> format_input(string& s)
{
    vector<string> v;
    transform(s.begin(),s.end(),s.begin(),::tolower);
    string word = ""; 
    for (auto& x : s) 
    { 
       if (x ==' ') 
       { 
           v.push_back(word); //words before last word
           word = ""; 
       } 
       else {
           word = word + x;} 
   }  
   v.push_back(word); //last word
   return v;
}

int main()
{
    cout<<"Enter title:==>>"<<endl;
    string title;
    getline(cin,title);    
    vector<string> paper_title=format_input(title); //convert to lower case vector of strings
    publication p;
    map<int,vector<vector<string>>> m1=p.title_search(paper_title);
    cout<<"Search results:==>>"<<endl;
    if(m1.empty())
        cout<<"No results"<<endl;
    else
    {    
        for(auto it=m1.rbegin();it!=m1.rend();it++) //highest frequency match displayed first
        {
            for(auto& it1:(*it).second)
            {
                for(auto& it2:it1)
                    cout<<it2<<" ";
                cout<<endl;    
            }
            if(((*it).first)==int(paper_title.size())) //perfect frequency match found, only display that title
                break;
        }
    }    
    return EXIT_SUCCESS;
}