#include <iostream>

using namespace std;

void dateINmass(int *arr, int lnum);
void dateOUTmass(int *arr, int lnum);
void swap(int *arr_1, int *arr_2);
void qs(int *arr, int first, int last);
void insertionSort(int *arr, int length);
void upqs(int *arr, int first, int last, int length);
void blokSort(int *arr, int length);
int main()
{
    int razmer, firstel, lastel;
    cout << "Vvod razmera massiva: ";
    cin >> razmer;
    cout << "Vvod nomera 1 elementa: ";
    cin >> firstel;
    lastel = razmer - 1;
    int *mass = new int[razmer];
    dateINmass(mass, razmer);
    dateOUTmass(mass, razmer);
    //qs(mass, firstel, lastel);
    //insertionSort(mass, razmer);
    upqs(mass, firstel, lastel, razmer);
    dateOUTmass(mass, razmer);
    cout << "Vvod razmera massiva: ";
    cin >> razmer;
    dateINmass(mass, razmer);
    dateOUTmass(mass, razmer);
    blokSort(mass, razmer);
    dateOUTmass(mass, razmer);

    return 0;
}

void dateINmass(int *arr, int lnum){
    for(int i = 0; i < lnum; i++){
        cout << "element [" << i << "]: ";
            cin >> arr[i];
    }
}

void dateOUTmass(int *arr, int lnum){
    for(int i = 0; i < lnum; i++)
        cout << arr[i] << "\t";
        cout << endl;
}

void swap(int *arr_1, int *arr_2){
    int temp = *arr_1;
    *arr_1 = *arr_2;
    *arr_2 = temp;
}

void qs(int *arr, int first, int last){
    int i = first, j = last, x = arr[(first + last) / 2];

    do {
        while (arr[i] < x) i++;
        while (arr[j] > x) j--;

        if(i <= j) {
            if (arr[i] > arr[j]) swap(&arr[i], &arr[j]);
            i++;
            j--;
        }
    } while (i <= j);

    if (i < last)
        qs(arr, i, last);
    if (first < j)
        qs(arr, first, j);
}

void insertionSort(int *arr, int length){
    int temp,item;
    for (int counter = 1; counter < length; counter++)
    {
        temp = arr[counter];
        item = counter-1;
        while(item >= 0 && arr[item] > temp){
            arr[item + 1] = arr[item];
            arr[item] = temp;
            item--;
        }
    }
}

void upqs(int *arr, int first, int last, int length){
    cout << " UP QUICK SORT\n ";
    int i,j;
    if(length <= 10){
        cout << "insertionSort\n";
        insertionSort(arr, length);
        return;
    }
      i = length / 2;
      j = i + (i/2);
      swap(&arr[i], &arr[j]);
      qs(arr, first, last);
      return;
}

void blokSort(int *arr, int length){
    cout << " Blocky sort\n ";
    const int max = length;
    const int b = 10;

    int blokmas[b][max+1];
    for(int i = 0; i < b; i++){
        blokmas[i][max] = 0;
    }

    for(int digit = 1; digit < 1000000000; digit *= 10){
        for(int i = 0; i < max; i++){
            if(arr[i] % 2) continue;
            int d = (arr[i] / digit) % b;
            blokmas[d][blokmas[d][max]++] = arr[i];

        }

        int idx = 0;
        for(int i = 0; i < b; i++){
            for(int j = 0; j < blokmas[i][max]; j++){
                    if (arr[idx] % 2 == 0)
                arr[idx++] = blokmas[i][j];
            }
            blokmas[i][max] = 0;
        }
    }
}
