#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL,"rus");

int rows,cols,k,temp;

cout<<"������� ����������� �������:\n";
cout<<"���������� �����: ";
cin>>rows;
cout<<"���������� ��������: ";
cin>>cols;

//cout<<"����� ������ ��� ����������: ";
//cin>>k;


int **mas = new int*[rows];

cout<<"�������� ������: "<<endl;
for (int i=0; i<rows; ++i)
mas[i] = new int[cols];

for (int i=0; i<rows; ++i)
{
    for (int j=0; j<cols; ++j)
    {
        cout<<"������� �������"<<i<<j<<": ";
        cin >> mas[i][j];
    }
cout<<endl;
}
for (int i=0; i<rows; ++i)
{
    for (int j=0; j<cols; ++j)
    {
        cout<<mas[i][j]<<"\t";
    }
cout<<endl;
}

//���������� �� ��������
for(int k = 0; k < rows; k++){
for (int i=0; i<rows; ++i)
{
    for (int j=0; j<rows-1; ++j)
    {
        if (mas[j][k]>mas[j+1][k])
        {
            temp=mas[j][k];
            mas[j][k]=mas[j+1][k];
            mas[j+1][k]=temp;
        }
    }
}
}

//���������� �� �������
for(int k = 0; k <cols; k++){
for (int i=0; i<cols; ++i)
{
    for (int j=0; j<cols-1; ++j)
    {
        if (mas[k][j]>mas[k][j+1])
        {
            temp=mas[k][j];
            mas[k][j]=mas[k][j+1];
            mas[k][j+1]=temp;
        }
    }
}
}

 for (int j=0; j<cols-1; ++j)
    {
        if (mas[j][cols - 1]>mas[j+1][0])
        {
            temp=mas[j][cols - 1];
            mas[j][cols - 1]=mas[j+1][0];
            mas[j+1][0]=temp;
        }
    }

for(int k = 0; k <cols; k++){
for (int i=0; i<cols; ++i)
{
    for (int j=0; j<cols-1; ++j)
    {
        if (mas[k][j]>mas[k][j+1])
        {
            temp=mas[k][j];
            mas[k][j]=mas[k][j+1];
            mas[k][j+1]=temp;
        }
    }
}
}


cout<<"����� ������: "<<endl;

for (int i=0; i<rows; ++i)
{
    for (int j=0; j<cols; ++j)
        cout<<mas[i][j]<<"\t";
cout<<endl;
}



for (int i=0; i<rows; ++i)
    delete [] mas[i];

delete [] mas;

system("pause");
return 0;
}
