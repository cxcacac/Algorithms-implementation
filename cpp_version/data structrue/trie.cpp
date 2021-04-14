/*
trie use node as unit
every unit has two attributes, including:
(1)26 children(use array to represent), indicating character at next index.
(2)a state ID(isEnd), indicating the location of current node, judging if it is the end of a word.
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Trie{
private:
    vector<Trie *> children;
    bool isEnd;
public:
    Trie() : children(26), isEnd(false){};
    void insert(const string s){
        Trie *node = this;
        for(const char& c: s){
            int num = c - 'a';
            if(node->children[num]==nullptr){
                node->children[num] = new Trie();
            }
            node = node->children[num];
        }
        node->isEnd = true;
    }
    Trie* searchPrefix(const string s){
        // start from current node
        Trie *node = this;
        for(const char& ch: s){
            int num = ch - 'a';
            if(node->children[num] == nullptr){
                return nullptr;
            }
            node = node->children[num];
        }
        return node;
    }
    bool searchWord(const string s){
        Trie* node = searchPrefix(s);
        return (node != nullptr) && (node->isEnd != false);
    }
    bool hasPrefix(const string s){
        Trie* node = searchPrefix(s);
        return node != nullptr;
    }
};
