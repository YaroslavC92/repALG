//#include <stdio.h>
//#include <stdlib.h>

void primeNum(int); // �������� ������� ����������� �������� �����

int main()
{
    int var;
    printf("Vvod number: ");
    scanf("%d", &var);
    primeNum(var);
    return 0;
}

void primeNum(int num){     // ������������ ��������
if(num > 1)
for(int i = 2; num > i; i++ ){
    if(!(num % i))
        return printf("Composite number\n");
}
return printf("Prime number\n");

}
