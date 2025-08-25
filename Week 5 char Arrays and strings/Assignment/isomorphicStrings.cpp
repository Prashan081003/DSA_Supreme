// leetcode 205. Isomorphic Strings

// Given two strings s and t, determine if they are isomorphic.

// Two strings s and t are isomorphic if the characters in s can be replaced to get t.

// All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.



----------->>>>>>>>>> New Method <<<<<<-----
bool isIsomorphic(string s, string t) {
    unordered_map<char, char> mapST, mapTS;
    for(int i = 0; i < s.length(); i++) {
        if(mapST.count(s[i]) && mapST[s[i]] != t[i]) return false;
        if(mapTS.count(t[i]) && mapTS[t[i]] != s[i]) return false;
        mapST[s[i]] = t[i];
        mapTS[t[i]] = s[i];
    }
    return true;
}

------------>>>>>> OLD Method <<<<<--------
#include<iostream>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()){
            return false;
        }
        int hash[256] = {0};
        bool istCharsMapped[256] = {0};
        for(int i=0; i<s.size(); i++){
            if(hash[s[i]] == 0 && istCharsMapped[t[i]] == 0){
                hash[s[i]] = t[i];
                istCharsMapped[t[i]] = true;
            }
        }
        for(int i=0; i<s.size(); i++){
            if(char(hash[s[i]]) != t[i]){
                return false;
            }
        }
        return true;
    }
};
