#include <iostream>
#include <stack>
#include <map>

using namespace std;

/**
 括号配对问题 （http://acm.nyist.edu.cn/JudgeOnline/problem.php?pid=2）
 描述
 现在，有一行括号序列，请你检查这行括号是否配对。
 输入
 第一行输入一个数N（0<N<=100）,表示有N组测试数据。后面的N行输入多组输入数据，每组输入数据都是一个字符串S(S的长度小于10000，且S不是空串），测试数据组数少于5组。数据保证S中只含有"[", "]", "(", ")" 四种字符
 输出
 每组输入数据的输出占一行，如果该字符串中所含的括号是配对的，则输出Yes,如果不配对则输出No
 样例输入
 3
 [(])
 (])
 ([[]()])
 样例输出
 No
 No
 Yes
 **/
string leftStr="([{";
string rightStr=")]}";
map<char,char> strMap;

bool checkLeftAndRight(bool isLeft,char sChar){
    string checkStr = (isLeft ? leftStr:rightStr);
    for(int i = 0 ;i<checkStr.length();i++){
        if(checkStr[i] == sChar){
            return true;
        }
    }
    return false;
}

bool checkRule(string str){
    stack<char> strStack;
    
    int count = 0;
    for(int i=0;i<str.length();i++){
        if(checkLeftAndRight(true,str[i])){
            count++;
            strStack.push(str[i]);
        }
        if(checkLeftAndRight(false,str[i])){
            count++;
            if(!strStack.empty()){
                if(strMap[strStack.top()] == str[i]){
                    strStack.pop();
                }else{
                    strStack.push(str[i]);
                }
            }else{
                return false;
            }
        }
    }
    if(strStack.empty() && count % 2 == 0){
        return true;
    }
    return false;
}

int main()
{
    strMap['('] = ')';
    strMap['['] = ']';
    strMap['{'] = '}';
    int n;
    cin>>n;
    while(n > 0){
        string str;
        cin>>str;
        cout<<(checkRule(str)?"Yes":"No")<<endl;
        n--;
    }
    return 0;
}
