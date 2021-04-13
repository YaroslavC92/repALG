#include <iostream>
using namespace std;

char *cesar(char *, unsigned char, bool);

int main()
{
    char massage[] = "hello";
    cout << cesar(massage, 2, true) << endl;
    cout << cesar(massage, 2, false) << endl;
    return 0;
}

char *cesar(char *text, unsigned char key, bool d){
    if(d){
        int i = 0;
        while(*(text + i)){
           text[i] += key;
            i++;
        }
    }
    else {
        int i = 0;
        while(*(text + i)){
            *(text + i) -= key;
            i++;
        }
    }
    return text;
}
