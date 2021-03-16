//#include <stdio.h>
//#include <stdlib.h>

int pow(int num, int rank);
int powToo(int num, int rank);
int main()
{
    int a, b, c;
    printf("Vvedite chislo: ");
    scanf("%d", &a);
    printf("Vvedite stepen: ");
    scanf("%d", &b);
    c = pow(a, b);
    printf("Rezultat: %d\n", c);
    c = powToo(a, b);
    printf("Rezultat: %d", c);
    return 0;
}

int pow(int num, int rank){
if(rank > 0)
    return num * pow(num, rank - 1);
else return 1;
}

int powToo(int num, int rank){
if(rank > 0){
    return 1 * powToo(num * num, rank/2);
}
else return 1;
}
