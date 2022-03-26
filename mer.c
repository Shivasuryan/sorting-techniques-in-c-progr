#include <stdio.h>

void merge(int arr[], int p, int q, int h)
{

  int n1 = q - p + 1;
  int n2 = h - q;

  int L[n1], M[n2];

  for (int i = 0; i < n1; i++)
    L[i] = arr[p + i];
  for (int j = 0; j < n2; j++)
    M[j] = arr[q + 1 + j];


  int i, j, k;
  i = 0;
  j = 0;
  k = p;

  while (i < n1 && j < n2) {
    if (L[i] <= M[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = M[j];
      j++;
    }
    k++;
  }

  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = M[j];
    j++;
    k++;
  }
}

void mergeSort(int arr[], int l, int h)
{
  if (l < h)
  {


    int m = l + (h - l) / 2;

    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, h);

    merge(arr, l, m, h);
  }
}


void printArray(int arr[], int n) {
  for (int i = 0; i < n; i++)
    printf("%d ", arr[i]);
  printf("\n");
}

int main() {
    printf("enter the size of array\n");
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
    scanf("%d",&arr[i]);
    mergeSort(arr, 0, n- 1);

  printf("Sorted array: \n");
  printArray(arr, n);
}
