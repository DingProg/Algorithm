
#include <iostream>
#include <cstring>

using namespace std;

//带回溯的模式匹配
int match(string a,string b){
    for(int i = 0;i< a.length();i++){
        int j = 0;
        for(;j< b.length() && i + j< a.length();j++){
            if(a[i + j] != b[j]){
                break;
            }
        }
        if(j == b.length()){
            return i;
        }
    }
    return -1;
}


//next数组
void getNext(int *next,string p){
    int k = -1;
    int j = 0;
    next[0] = -1;
    
    while(j < p.length() -1){
        if(k == -1 || p[k] == p[j]){
            next[++j] = ++k;
        }else{
            k = next[k];
        }
    }
}

//不带回溯的模式匹配
int matchNoBack(int *next,string p,string sub){

    int i = 0,j = 0;
    while(i < p.length() && j < (int)sub.length()){
        cout<<"pre "<<"i="<<i<<"j="<<j<<endl;
        if(j == -1 || p[i] == sub[j]){
            i++;
            j++;
        }else{
            j = next[j];
        }
    }
    if(j == sub.length()){
        return i - j;
    }
    return -1;
}


int main()
{
    cout<<"hello"<<endl;
    string a ="abdcabcfg" ,b = "abc";
    
    cout<<match(a,b)<<endl;
    
    int next[b.length()];
    getNext(next,b);
//    cout<<"{";
//    for(int i =0;i< b.length();i++){
//        cout<<next[i]<<" ";
//    }
//    cout<<"}";
    cout<<matchNoBack(next, a,b)<<endl;
    return 0;
}
