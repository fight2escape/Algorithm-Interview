//
// Created by Shinelon on 2017/10/18.
//

#ifndef ALGORITHM_INTERVIEW2_126_WORD_LADDER_II_H
#define ALGORITHM_INTERVIEW2_126_WORD_LADDER_II_H

#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord,const string& endWord, const vector<string>& wordList) {
        vector<vector<string>> res;
        unordered_set<string> set;
        unordered_map<string, unordered_set<string>> map;
        for(auto const &wl : wordList){
            set.insert(wl);
            map[wl] = unordered_set<string>{};
        }
        if(set.find(endWord) == set.end()) return res;

        queue< pair<string, int> > q;
        q.push( make_pair(beginWord, 1) );
        int length = beginWord.size();

        int endLevel = 0;
        int level = 1;
        vector<string> del;

        while(!q.empty()){
            string str = q.front().first;
            int com = q.front().second;
            q.pop();

            if(str == endWord){
                if(endLevel){
                    if(endLevel < com) break;
                }else{
                    endLevel = com;
                }
            }
            if(level < com){
                ++level;
                for(auto d : del){
                    set.erase(d);
                }
                del.clear();
            }

            string parent = str;
            for(int i=0; i<length; ++i){
                char tmp = str[i];
                for(char ch='a'; ch<='z'; ++ch){
                    if(ch == tmp) continue;
                    str[i] = ch;
                    if(set.find(str) != set.end()){
                        map[str].insert(parent);
                        q.push( make_pair(str, com+1) );
                        del.push_back(str);
                    }
                }
                str[i] = tmp;
            }
        }
        getPath(map, res, vector<string>{endWord}, beginWord, endWord);
        return res;
    }
private:
    void getPath(unordered_map<string, unordered_set<string>> &map,vector<vector<string>> &res,  vector<string> re, const string &beginWord, const string &endWord){
        for(auto str = map[endWord].begin(); str != map[endWord].end(); ++str){
            re.push_back(*str);
            if(*str == beginWord){
                reverse(re.begin(), re.end());
                res.push_back(re);
            }else{
                getPath(map, res, re,beginWord, *str);
            }
            re.pop_back();
        }
    }
};

class Test{
public:
    void test(){
        string beginWord = "hit";
        string endWord = "cog";
        vector<string> wordList = {"hot","dot","dog","lot","log","cog","dig"};
//        string beginWord = "red";
//        string endWord = "tax";
//        vector<string> wordList = {"ted","tex","red","tax","tad","den","rex","pee"};
        for(auto res : Solution().findLadders(beginWord, endWord, wordList)){
            printf("[ ");
            for(auto r : res){
                cout<<r<<" -> ";
            }
            printf(" null ]\n");
        }
    }
};

#endif //ALGORITHM_INTERVIEW2_126_WORD_LADDER_II_H
