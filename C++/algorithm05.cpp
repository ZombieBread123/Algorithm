#include <stdio.h>
#include <iostream>
#define MAX_SIZE 1000
using namespace std;
void bubbleSort(int a[], int n);
void bubbleSortImproved1(int a[], int n);
void bubbleSortImproved2(int a[], int n);
void copyArray(int a[], int b[], int n);
int main()
{
 int numTestCases;
 scanf("%d", &numTestCases);
 for (int i = 0; i < numTestCases; ++i)
 {
 int num;
 int a[MAX_SIZE], b[MAX_SIZE];
 scanf("%d", &num);
 for (int j = 0; j < num; j++)
 scanf("%d", &b[j]);
 copyArray(a, b, num);
 bubbleSort(a, num);
 copyArray(a, b, num);
 bubbleSortImproved1(a, num);
 copyArray(a, b, num);
 bubbleSortImproved2(a, num);
 printf("\n");
 }
 return 0;
}
void swap(int* a, int* b)
{
 int tmp = *a;
 *a = *b;
 *b = tmp;
}
/* BubbleSort 함수 */
void bubbleSort(int a[], int n)
{
 int countCmpOps = 0; // 비교 연산자 실행 횟수
 int countSwaps = 0; // swap 함수 실행 횟수
 // bubble sort 알고리즘 구현
    for (int i = 0; i < n - 1; i++) {
        for (int j = 1; j < n - i; j++) {
            if(a[j-1] > a[j]){
                swap(&a[j-1], &a[j]);
                countSwaps++;
            }
            countCmpOps++;
        }
    }
 cout << countCmpOps << " " << countSwaps << " ";
}
/* BubbleSort 함수 - Improved Version 1 */
void bubbleSortImproved1(int a[], int n)
{
 int countCmpOps = 0; // 비교 연산자 실행 횟수
 int countSwaps = 0; // swap 함수 실행 횟수
 // bubble sort의 개선된 알고리즘 (1) 구현
    for (int i = 0; i < n - 1; i++) {
        bool isSwapped = false;
        for (int j = 1; j < n - i; j++) {
            if(a[j-1] > a[j]){
                swap(&a[j-1], &a[j]);
                countSwaps++;
                isSwapped = true;
            }
            countCmpOps++;
        }
        if(!isSwapped) break;
    }
 cout << countCmpOps << " " << countSwaps << " ";
}
/* BubbleSort 함수 - Improved Version 2 */
void bubbleSortImproved2(int a[], int n)
{
 int countCmpOps = 0; // 비교 연산자 실행 횟수
 int countSwaps = 0; // swap 함수 실행 횟수
 // bubble sort의 개선된 알고리즘 (2) 구현
    int lastSwappedPos = n;
    while(lastSwappedPos > 0){
        int swappedPos = 0;
        for(int i = 1; i < lastSwappedPos; i++){
            if(a[i-1] > a[i]){
                swap(&a[i-1], &a[i]);
                countSwaps++;
                swappedPos = i;
            }
            countCmpOps++;
        }
        lastSwappedPos = swappedPos;
    }
 cout << countCmpOps << " " << countSwaps << " ";
}
void copyArray(int a[], int b[], int n)
{
 for (int i = 0; i < n; i++)
 a[i] = b[i];
}