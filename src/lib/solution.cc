#include "solution.h"
#include <iostream>

TrieNode *getNode(void) 
{ 
    TrieNode *node =  new TrieNode; 
  
    node->endofword = false; 
  
    for (int i = 0; i < alphabets; i++) 
        node->child[i] = nullptr; 
  
    return node; 
} 

void insert(TrieNode* root, string key_word)
{
  TrieNode* travel=root;
  for(int i=0;i<key_word.length();i++)
  {
      int index=key_word[i]-'a';
      if(!travel->child[index]) //child not present
      {
        travel->child[index]=getNode();
      }

      travel=travel->child[index];
  }

  travel->endofword=true; //marks end of word
}

bool search(TrieNode *root, string key_word) 
{ 
    TrieNode *travel = root; 
  
    for (int i = 0; i < key_word.length(); i++) 
    { 
        int index = key_word[i] - 'a'; 
        if (!travel->child[index]) //next character not present
            return false; 
  
        travel = travel->child[index]; 
    } 
  
    return (travel != nullptr && travel->endofword); //last travelled character should be present and be the end 
} 


map<int,vector<vector<string>>> publication::title_search(vector<string>& v)
{
  map<int,vector<vector<string>>> m;
  vector<string> v1={"get","here"};
  vector<string> v2={"come","now"};
  vector<string> v3={"data","science"};
  vector<string> v4={"big","data"};
  store.push_back(v1);
  store.push_back(v2);
  store.push_back(v3);
  store.push_back(v4);
  vector<TrieNode*> vroots; //store root for eacht title
  for(int i=0;i<int(store.size());i++)
  {
    TrieNode *root = getNode();
    for(int j=0;j<int(store[i].size());j++)
      insert(root, store[i][j]);
    vroots.push_back(root);  
  }    
  
/*  TrieNode *root1 = getNode(); 
  for(int i = 0; i < v1.size(); i++) 
    insert(root1, v1[i]);

  TrieNode *root2 = getNode(); 
  for(int i = 0; i < v2.size(); i++) 
    insert(root2, v2[i]);
  
  TrieNode *root3 = getNode(); 
  for(int i = 0; i < v3.size(); i++) 
    insert(root3, v3[i]);    

  TrieNode *root4 = getNode(); 
  for(int i = 0; i < v4.size(); i++) 
    insert(root4, v4[i]); */

 // vector<TrieNode*> vroots={root1,root2,root3,root4};
  vector<int> count_freq(int(vroots.size()),0);
  for(int i=0;i<v.size();i++)
  {
    for(int j=0;j<vroots.size();j++)
    {
      if(search(vroots[j],v[i])) //search for each word of given title in each of my local titles 
        count_freq[j]++;  //how many words of given search title match with words of each local title
    }
  }
  for(int i=0;i<count_freq.size();i++)
  {
    if(count_freq[i]>0)
      m[count_freq[i]].push_back(store[i]);
  }
  return m;
}
