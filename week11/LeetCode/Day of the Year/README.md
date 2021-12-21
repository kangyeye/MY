## 题目：
给你一个字符串 date ，按 YYYY-MM-DD 格式表示一个 现行公元纪年法 日期。请你计算并返回该日期是当年的第几天。

通常情况下，我们认为 1 月 1 日是每年的第 1 天，1 月 2 日是每年的第 2 天，依此类推。每个月的天数与现行公元纪年法（格里高利历）一致。

示例 1：

输入：date = "2019-01-09"

输出：9

---------------
冬至的每日一题
## Tips：
#### 1、to_string
包含在# include<string>。作用是把数值类型如int、double、long等转化为string。

int a = 4;
  
double b = 3.14;
  
string str1, str2;
  
str1 = to_string(a);
  
str2 = to_string(b);
  
cout << str1 << endl;
  
cout << str2 << endl;

#### 2、stoi和atoi

包含在#include<string>，不是c++11的可以在#include<cstring>。作用是将字符串转化为int型。
区别是stoi的形参是const string*，而atoi的形参是const char*。c_str()的作用是将const string*转化为const char*。

string s1("1234567");
  
char* s2 = "1234567";
  
int a = stoi(s1);
  
int b = atoi(s2);
  
int c = atoi(s1.c_str());
  
cout << a << endl;
  
cout << b << endl;
  
cout << c << endl;
