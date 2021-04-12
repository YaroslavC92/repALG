#include <iostream>
using namespace std;
unsigned long hasher(char *str);

int main()
{
    char *text = "Hello World";
    unsigned long temp = hasher(text);
    cout << temp;

    return 0;
}

unsigned long hasher(char *str)
{
    unsigned long hash = 5381;
    int c;

    while (c = *str++)
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash;
}
