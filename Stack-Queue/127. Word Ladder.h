//
// Created by Shinelon on 2017/10/17.
//

#ifndef ALGORITHM_INTERVIEW2_127_WORD_LADDER_H
#define ALGORITHM_INTERVIEW2_127_WORD_LADDER_H

#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string, int>> q;
        unordered_map<string, bool> map;
        for(auto wl : wordList){
            map[wl] = false;
        }
        q.push(make_pair(beginWord, 1));
        while(!q.empty()){
            string str = q.front().first;
            int level = q.front().second;
            q.pop();
            for(int i=0; i<str.size(); ++i){
                for(int j=0; j<26; ++j){
                    char iter = char('a'+j);
                    char tmp = str[i];
                    if(tmp == iter) continue;
                    str[i] = iter;

                    if(map.find(str)!=map.end() && !map[str]){
                        if(str == endWord) return level+1;

                        q.push( make_pair(str, level+1));
                        map.erase(str);
                    }
                    str[i] = tmp;
                }
            }
        }
        return 0;
    }
};

class Test{
public:
    void test(){
        string beginWord = "hit";
        string endWord = "cog";
        vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
        int res = Solution().ladderLength(beginWord, endWord, wordList);
        printf("%d \n", res);
    }
};

#endif //ALGORITHM_INTERVIEW2_127_WORD_LADDER_H
