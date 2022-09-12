#include <iostream>
#include <string>
using namespace std;

struct free_throws
{
    string name;
    int made;
    int attempts;
    float percent;
};
/*传递结构体饮用，const---引用的值不能被改变*/
void display(const free_throws & ft);
void set_pc(free_throws & ft);
//返回值为结构体引用
free_throws & accumulate(free_throws & target, const free_throws & source);

int main()
{
    free_throws one = {"Ifelsa Branch", 13, 14};
    free_throws team = {"Throwgoods", 0, 0};

    free_throws dup;
    dup = accumulate(team,one);

    cout << "Displaying value:\n";
    display(team);
    cout << "Displaying dup after assignment:\n";
    display(dup);
    
    return 0;
}

void display(const free_throws & ft)
{
    cout << "Name: " << ft.name << '\n';
    cout << "Made: " << ft.made << '\t';
    cout << "Attempts: " << ft.attempts << '\t';
    cout << "Percent: " << ft.percent << '\n';
}

void set_pc(free_throws & ft)
{
    //attempts和precent的联系
    if (ft.attempts != 0)
    {
        ft.percent = 100.0f *float(ft.made)/float(ft.attempts);
    }
    else
    {
        ft.percent = 0;
    }
    
}

free_throws & accumulate(free_throws & target, const free_throws & source)
{
    //复制free_throws中的值进入target
    target.attempts += source.attempts;//attempts复制
    target.made += source.made;//source复制
    set_pc(target);

    return target;  //返回结构体引用
}

