
#include <iostream>
using namespace std;

/**
 ASCII码排序 （http://acm.nyist.edu.cn/JudgeOnline/problem.php?pid=4）
 描述
 输入三个字符（可以重复）后，按各字符的ASCII码从小到大的顺序输出这三个字符。
 输入
 第一行输入一个数N,表示有N组测试数据。后面的N行输入多组数据，每组输入数据都是占一行，有三个字符组成，之间无空格。
 输出
 对于每组输入数据，输出一行，字符中间用一个空格分开。
 样例输入
 2
 qwe
 asd
 样例输出
 e q w
 a d s
 **/
int main()
{
    int n;
    cin>>n;
    char str[4];
    while(n > 0){
        cin>>str;
        char min1 = (str[0] > str[1] ? str[1]:str[0]);
        char min2 = (min1 > str[2] ? str[2] :min1);
        char max1 = (str[0] > str[1] ? str[0]:str[1]);
        char max2 = (max1 < str[2] ? str[2] :max1);
        cout<<min2<<" ";
        cout<<(char)(str[0] + str[1] + str[2] - max2 -min2)<<" ";
        cout<<max2<<endl;
        n--;
    }
    return 0;
}
