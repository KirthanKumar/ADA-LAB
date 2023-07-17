/*Sort a given set of N integer elements using Quick Sort technique and compute its time taken*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
clock_t start, end;
int partition(int a[], int low, int high);
void swap(int *x, int *y)
{
  int temp;
  temp = *x;
  *x = *y;
  *y = temp;
}

void quickSort(int a[], int low, int high){
    if(low < high){
        int pivot_pos = partition(a, low, high);
        quickSort(a, low, pivot_pos-1);
        quickSort(a,pivot_pos+1, high);
    }
}

int partition(int a[], int low, int high){
    int pivot = a[low];
    int i = low+1; int j = high;
    while(1){
        while(a[i]<=pivot && i<=high){
            i = i+1;
        }
        while(a[j]>pivot && j>=low){
            j = j-1;
        }
        if(i<j){
            swap(&a[i], &a[j]);
        }
        else{
            a[low] = a[j];
            a[j] = pivot;
            return j;
        }
    }
}

void printArray(int a[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int main(){
    int arr_size;
    printf("\nEnter number of elements: ");
    scanf("%d", &arr_size);
    int a[arr_size];
    
    for (int i = 0; i < arr_size; i++)
    {
        a[i] = rand();
    }
    start = clock();
    quickSort(a, 0, arr_size-1);
    end = clock();
    printf("Time taken is: %lf sec", (double)(end - start) / CLOCKS_PER_SEC);
    // printf("\nSorted array is \n");
    // printArray(a, arr_size);

    return 0;
}
