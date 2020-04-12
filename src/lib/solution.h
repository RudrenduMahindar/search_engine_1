#ifndef TEMPLATE_SOLUTION_H
#define TEMPLATE_SOLUTION_H

#include <string>
#include <vector>
#include <map>
using namespace std;

const int alphabets=26;

struct TrieNode{
    TrieNode *child[alphabets];
    bool endofword;
};

class publication {
public:
    string paper_title;
    vector<vector<string>> store;
    map<int,vector<vector<string>>> title_search(vector<string>&);

};

class author{
public:
    string paper_title;
    string author_name;
};

class conference{
public:
    string paper_title;
    string conf_name;
    int year;
};

class journal{
public:
    string paper_title;
    string jour_name;
    int year;
};

#endif