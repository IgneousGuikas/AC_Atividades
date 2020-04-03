#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <windows.h>
#include <time.h>

using namespace std;

void quicksort1(int* arr, int start, int end);
void quicksort2(int* arr, int start, int end);
void bubblesort(int* arr, int n);



int main(int argc, char **argv) {
  srand(time(0));

  LARGE_INTEGER StartingTime, EndingTime, ElapsedMicroseconds;
  LARGE_INTEGER Frequency;

  QueryPerformanceFrequency(&Frequency);

  int n = 10000;
  int arr1[10000];
  int arr2[10000];
  int arr3[10000];

  ifstream myfile ("arr10000.txt");
  try {
    if (myfile.is_open()) {
      int number, i = 0;
      printf("Carregando\n");
      while (myfile >> number) {
        arr1[i] = number;
        arr2[i] = number;
        arr3[i] = number;
        i++;
      }
      printf("Carregado\n");
      myfile.close();
    } else {
      printf("Não Carregado\n");
      return 0;
    }
  } catch(...) {
    printf("Erro\n");
    return 0;
  }


  // printf("arr: [\n");
  // for(int i=0; i<n; i++) {
  //   printf("%d ", arr1[i]);
  //   if(i%20 == 0) {
  //     printf("\n       ");
  //   }
  // }
  // printf("]\n");


  QueryPerformanceCounter(&StartingTime);

  quicksort1(arr1, 0, n-1);

  QueryPerformanceCounter(&EndingTime);

  ElapsedMicroseconds.QuadPart = EndingTime.QuadPart - StartingTime.QuadPart;
  ElapsedMicroseconds.QuadPart *= 1000000000;
  ElapsedMicroseconds.QuadPart /= Frequency.QuadPart;

  std::cout << "Enlapsed time quicksort1: " << ElapsedMicroseconds.QuadPart << "ns" << std::endl;

  QueryPerformanceCounter(&StartingTime);

  quicksort2(arr2, 0, n-1);

  QueryPerformanceCounter(&EndingTime);

  ElapsedMicroseconds.QuadPart = EndingTime.QuadPart - StartingTime.QuadPart;
  ElapsedMicroseconds.QuadPart *= 1000000000;
  ElapsedMicroseconds.QuadPart /= Frequency.QuadPart;

  std::cout << "Enlapsed time quicksort2: " << ElapsedMicroseconds.QuadPart << "ns" << std::endl;

  QueryPerformanceCounter(&StartingTime);

  bubblesort(arr3, n);

  QueryPerformanceCounter(&EndingTime);

  ElapsedMicroseconds.QuadPart = EndingTime.QuadPart - StartingTime.QuadPart;
  ElapsedMicroseconds.QuadPart *= 1000000000;
  ElapsedMicroseconds.QuadPart /= Frequency.QuadPart;

  std::cout << "Enlapsed time bubblesort: " << ElapsedMicroseconds.QuadPart << "ns" << std::endl;

  // printf("\narr sorted: [\n");
  // for(int i=0; i<n; i++) {
  //   printf("%d ", arr1[i]);
  //   if(i%20 == 0) {
  //     printf("\n              ");
  //   }
  // }
  // printf("]\n");

}

void quicksort1(int* arr, int start, int end) {
  if(start < end) {
    int temp;

    temp = arr[end];
    arr[end] = arr[start];
    arr[start] = temp;

    int pivot = arr[end];

    int j = start;
    for(int i=start; i<end; i++) {
      if(arr[i] <= pivot) {
        temp = arr[j];
        arr[j] = arr[i];
        arr[i] = temp;
        j++;
      }
    }
    temp = arr[j];
    arr[j] = pivot;
    arr[end] = temp;

    quicksort1(arr, start, j-1);
    quicksort1(arr, j+1, end);
  }
}


void quicksort2(int* arr, int start, int end) {
  if(start < end) {
    int temp;

    int pivot_idx = rand()%( end-start ) + start;
    temp = arr[end];
    arr[end] = arr[pivot_idx];
    arr[pivot_idx] = temp;

    int pivot = arr[end];

    int j = start;
    for(int i=start; i<end; i++) {
      if(arr[i] <= pivot) {
        temp = arr[j];
        arr[j] = arr[i];
        arr[i] = temp;
        j++;
      }
    }
    temp = arr[j];
    arr[j] = pivot;
    arr[end] = temp;

    quicksort2(arr, start, j-1);
    quicksort2(arr, j+1, end);
  }
}


void bubblesort(int* arr, int n) {
  bool swaped = false;
  int temp;
  for(int i=0; i<n-1; i++) {
    if(arr[i] > arr[i+1]) {
      temp = arr[i];
      arr[i] = arr[i+1];
      arr[i+1] = temp;
      swaped = true;
    }
  }

  if(swaped) {
    bubblesort(arr, n);
  }
}
