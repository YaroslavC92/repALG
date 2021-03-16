#include <stdio.h>
#include <stdlib.h>

int mass[32] = {0};
int count = 0;

int decTObin(int);
int main()
{
    int var;
    printf("Vvedite chislo: ");
    scanf("%d", &var);
    decTObin(var);
    for(int i = 31; i >= 0; i--){
        printf("%d", mass[i]);
    }
    return 0;
}

int decTObin(int dec){
    mass[count] = dec % 2;
    count++;
    dec /= 2;
    if(dec <= 1){
        mass[count] = dec;
        return dec;
    }
    else decTObin(dec);

}
