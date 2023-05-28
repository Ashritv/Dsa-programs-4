#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubble_sort(int arr[], int n);
void swap(int *xp, int *yp);
void selectionSort(int arr[], int n);
void mergeSort(int arr[],int l, int r);
void merge(int arr[], int l,int m, int r);
void print(int arr[],int n);
void heapify(int arr[], int N, int i);
void heapSort(int arr[], int N);

int main() {
    int n, i,upper,lower;
    FILE *fp;

    printf("Enter the number of elements: \n");
     scanf("%d", &n);
    printf("enter the upper limit:\n");
    scanf("%d",&upper);
              printf("enter the lower limit:\n");
    scanf("%d",&lower);

    int arr[n];

fp=fopen("logs.txt","w");

    for (i=0; i<n; i++) {
        arr[i] = rand() % (upper - lower + 1) + lower;
        fprintf(fp,"%d\n",arr[i]);
    }

        int arr_size = sizeof(arr) / sizeof(arr[0]);
    printf("Unsorted array: ");
   print(arr,n);


           printf("Sorted array using bubble sort: ");
    bubble_sort(arr, n);
     print(arr,n);






    printf("Sorted array using selection sort: ");
    selectionSort(arr,n);
     print(arr,n);

 // to store the execution time of code
    double time_spent = 0.0;

    clock_t begin = clock();


    mergeSort(arr, 0, arr_size - 1);

      clock_t end = clock();

     time_spent += (double)(end - begin) / CLOCKS_PER_SEC;



     printf("Sorted array using merge sort: ");
      printf("The elapsed time is %f seconds\n", time_spent);
    fp=fopen("time.txt","a");
     fprintf(fp,"%f\n",time_spent);

      print(arr,n);


         printf("Sorted array using heap sort: ");
    heapSort(arr,arr_size);
      print(arr,n);




    return 0;
}

void bubble_sort(int arr[], int n)
{
    // to store the execution time of code
    double time_spent = 0.0;

    clock_t begin = clock();

    // do some stuff here




    int i, j, temp;

    FILE *fp;

    for (i=0; i<n-1; i++) {
        for (j=0; j<n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
      clock_t end = clock();

     time_spent += (double)(end - begin) / CLOCKS_PER_SEC;


    printf("The elapsed time is %f seconds\n", time_spent);
    fp=fopen("time.txt","a");

     fprintf(fp,"%f\n",time_spent);


}
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selectionSort(int arr[], int n)
{  double time_spent = 0.0;
   FILE *fp;
    clock_t begin = clock();
    int i, j, min_idx;


    for (i = 0; i < n-1; i++)
    {

        min_idx = i;
        for (j = i+1; j < n; j++)
          if (arr[j] < arr[min_idx])
            min_idx = j;
        swap(&arr[min_idx], &arr[i]);
    }

     clock_t end = clock();

     time_spent += (double)(end - begin) / CLOCKS_PER_SEC;


    printf("The elapsed time is %f seconds\n", time_spent);
    fp=fopen("time.txt","a");

     fprintf(fp,"%f\n",time_spent);

}
void merge(int arr[], int l,int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];


    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;


    j = 0;


    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }


    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }


    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}


void mergeSort(int arr[],int l, int r)
{
   FILE *fp;

    if (l < r)
    {

        int m = l + (r - l) / 2;


        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }


}
void heapify(int arr[], int N, int i)
{

    int largest = i;


    int left = 2 * i + 1;

    int right = 2 * i + 2;


    if (left < N && arr[left] > arr[largest])

        largest = left;

    if (right < N && arr[right] > arr[largest])

        largest = right;


    if (largest != i) {

        swap(&arr[i], &arr[largest]);


        heapify(arr, N, largest);
    }
}


void heapSort(int arr[], int N)
{
   double time_spent = 0.0;
      FILE *fp;
    clock_t begin = clock();

    for (int i = N / 2 - 1; i >= 0; i--)

        heapify(arr, N, i);


    for (int i = N - 1; i >= 0; i--) {

        swap(&arr[0], &arr[i]);


        heapify(arr, i, 0);
    }
    clock_t end = clock();

     time_spent += (double)(end - begin) / CLOCKS_PER_SEC;


    printf("The elapsed time is %f seconds\n", time_spent);
    fp=fopen("time.txt","a");

     fprintf(fp,"%f\n",time_spent);
}
void print(int arr[],int n)
{
     for (int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
