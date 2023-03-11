#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//////////////////////////////////////////////////problem 1
// return index of minimum element of array
int min(int arr[], int n)
{
    int minInd = 0;
    int minVal = arr[0];
    int i;

    for (i = 1; i < n; i++) {

        // If a[i] < min value
        if (arr[i] < minVal) {
            minVal = arr[i];
            minInd = i;
        }
    }
    return minInd;
}
// sort the array
void insertionsort (int arr[], int n)
        {
             int key,j;
            for (int i = 1; i < n; i++)
          {
        key = arr[i];
        j = i-1;
         while( j >= 0 && arr[j] > key)
            {
           arr[j+1] = arr[j];
           j = j-1;
            }
        arr[j+1] = key;
            }
         }
// to max the minimum element of array and increment the array b m times

int maxiMin(int arr[], int N, int M)
{
    int minInd, l, r, i, j;
    for (i = 0; i < M; i++)
        {
          minInd = min(arr, N);
          arr[minInd]++;
          l = minInd - 1;
          r = minInd + 1;
        }
          return arr[minInd];
}

int main()
{
    int arr[] = { 3,5,1,2,8,4,9 };
    int N = sizeof(arr) / sizeof(arr[0]);
    insertionsort(arr,N);
    int M = 3;
    cout << maxiMin(arr, N, M);

    return 0;
}
