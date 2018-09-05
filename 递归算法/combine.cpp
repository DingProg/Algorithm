
#include <iostream>
#include <vector>

using namespace std;

//组合问题C(n,m):n个元素中取m个
void combine(int data[],int n,int m,int temp[],const int M,vector<vector<int>> &vec_res)
{
    for(int i=n; i>=m; i--)   // 注意这里的循环范围
    {
        temp[m-1] = i - 1;
        if (m > 1)
            combine(data,i-1,m-1,temp,M,vec_res);
        else                     // m == 1, 输出一个组合
        {
            vector<int> vec_temp;
            for(int j=M-1; j>=0; j--){
                vec_temp.push_back(data[temp[j]]);
            }
            vec_res.push_back(vec_temp);
        }
    }
}


int main()
{
    int n=10,m=3;
    vector<vector<int> > vec_res;
    int *data=new int[n];
    int *temp=new int[m];
    for(int i=0;i<n;i++){
        data[i]=i+1;//测试数据为1...n
    }
    combine(data,n,m,temp,m,vec_res);
    for(auto temp:vec_res){
        for(auto e:temp){
            cout<<e<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}
