#include <iostream>
using namespace std;

//  -- recursion --
/*
    type function(parameters){
        if(Base condition){
        do it;
        }
        function(parameters);
        do it;
    }

void fun(int n)
{
    if (n > 0)
    {
        cout << n << endl;
        fun(n - 1);
    }
    return;
}
void func(int n)
{
    if (n > 0)
    {
        fun(n - 1);
        cout << n << endl;
    }
    return;
}
void print(int n)
{
    if (n-- > 0)
    {
        cout << "I love Recursion" << endl;
        print(n);
    }
    return;
}
    */

int maxNum(int [] array , int n){
    if(n > 0){
        maxNum(array , (n-1));
    }
}
int main()
{
    fun(3);
    func(3);
    print(3);
}