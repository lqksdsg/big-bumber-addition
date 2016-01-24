#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;
#define MIN(x,y) x < y ? x : y

string bigadd(string& num1,string& num2)
{
    char JW = 0; //进位
    stack<char> s1,s2,s3;
    for(string::iterator i = num1.begin();i!=num1.end();++i)
    {
        s1.push(*i);
    }
    for(string::iterator j = num2.begin();j!=num2.end();++j)
    {
        s2.push(*j);
    }
    size_t k = MIN(num1.length(),num2.length());
    for(size_t z = 0 ; z != k ;++z)
    {
        char x;
        x = s1.top() + s2.top() - 2*'0'+JW;
        s1.pop();
        s2.pop();
        if(x < 10)
        {
            s3.push(x%10);
            JW = 0;
        }
        else
        {
            s3.push(x%10);
            JW = 1;
        }
    }
    while(!s2.empty())
    {
        char x ;
        x = s2.top() + JW - '0';
        s2.pop();
        if(x < 10)
        {
            s3.push(x%10);
            JW = 0;
        }
        else
        {
            s3.push(x%10);
            JW = 1;
        }
    }
    while(!s1.empty())
    {
        char x ;
        x = s1.top() + JW - '0'; //注意要减去‘0’
        s1.pop();
        if(x < 10)
        {
            s3.push(x%10);
            JW = 0;
        }
        else
        {
            s3.push(x%10);
            JW = 1;
        }
    }
    if(JW == 1)
    {
        s3.push(JW);
    }
    string re;
    size_t q = s3.size();
    for(size_t u = 0; u != q;++u)
    {
        char c = s3.top()+'0';
        re = re + c;
        s3.pop();
    }
    return re;
}

int main(){
    string num,num1,num2,res;
    cin >> num >> num1;
    res = bigadd(num,num1);
    cout << res << endl;
    while(cin >> num2){
        res = bigadd(res,num2);
        cout << res;
        cout << endl;
    }
    return 0;
}
