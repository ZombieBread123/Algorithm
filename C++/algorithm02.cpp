#include <stdio.h>
#include <iostream>
#define MAX_SIZE 1000
using namespace std;
void insertionSort(int a[], int n);
int main()
{
 int numTestCases;
 scanf("%d", &numTestCases);
 for (int i = 0; i < numTestCases; ++i)
 {
 int num;
 int a[MAX_SIZE];
 scanf("%d", &num);
 for (int j = 0; j < num; j++)
 scanf("%d", &a[j]);
 insertionSort(a, num);
 }
 return 0;
}
/* Insertion Sort �Լ� */
void insertionSort(int a[], int n)
{
 int countCmpOps = 0; // �� ������ ���� Ƚ��
 int countSwaps = 0; // swap �Լ� ���� Ƚ��
 // insertion sort �˰���
    for (int i = 1; i < n; i++) {
        int j = i;
        while (j > 0) {
            if(a[j-1] < a[j]){
                countCmpOps++;
                break;
            }
            if(a[j-1] > a[j]){
            int temp = a[j];
            a[j] = a[j-1];
            a[j-1] = temp;
            countSwaps++;
            countCmpOps++;
            j--;
            }
        }
    }
 cout << countCmpOps << " " << countSwaps << endl;
}