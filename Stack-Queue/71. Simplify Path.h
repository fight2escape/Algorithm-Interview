//
// Created by Shinelon on 2017/9/24.
//

#ifndef ALGORITHM_INTERVIEW2_71_SIMPLIFY_PATH_H
#define ALGORITHM_INTERVIEW2_71_SIMPLIFY_PATH_H

#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    /**
     * Unix中的文件夹路径简化
     * @param path
     * @return
     */
    string simplifyPath(string path) {
        string dir = "/";
        stack<string> stk;
        path += "/";
        for(auto &s : path){
            if(s == '/'){
                if(dir == "." || dir.empty()){
                }else if(dir == ".."){
                    stk.pop();
                    if(stk.empty()){
                        stk.push("/");
                    }
                }else{
                    stk.push(dir);
                }
                dir = "";
            }else{
                dir += s;
            }
        }
        if(stk.top() == "/"){
            return "/";
        }else{
            dir = "";
            while(stk.top()!="/"){
                dir = '/' + stk.top() + dir;
                stk.pop();
            }
            return dir;
        }
    }
};

#endif //ALGORITHM_INTERVIEW2_71_SIMPLIFY_PATH_H
////    string s = "/home/a/../b/";
////    string s = "/..//b";
////    string s = "/...";
//string s = "/home/foo/./bar/";
//string res = Solution().simplifyPath(s);
//cout<<res<<endl;