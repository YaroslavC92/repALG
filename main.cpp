#include <iostream>
#define SIZE 32
using namespace std;

int cursor = -1;
bool Stack[SIZE];

bool Push(int);
int Pop(void);
int main()
{
    int num;
    cout << "Enter number: ";
    cin >> num;
    while(num != 0){
        Push(num % 2);
        num /= 2;
    }
    while(cursor >=0)
        cout << Pop();

    return 0;
}

bool Push(int date){
    if(cursor < SIZE){
    Stack[++cursor] = date;
    return 1;
    }
    else{
        cout << "Stack overflow" << endl;
        return 0;
    }
}
int Pop(){
if(cursor != -1){
    return Stack[cursor--];
}
else{
    cout << "Stack is empty" << endl;
}
}
