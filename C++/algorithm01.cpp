#include <stdio.h>
#include <iostream>
#define MAX_SIZE 1000
using namespace std;
void selectionSort(int a[], int n);
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
 selectionSort(a, num);
 }
 return 0;
}
/* Selection Sort �Լ� */
void selectionSort(int a[], int n)
{
 int countCmpOps = 0; // �� ������ ���� Ƚ��
 int countSwaps = 0; // swap �Լ� ���� Ƚ��
 // selection sort �˰��� ����
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i+1; j < n; j++) {
            countCmpOps++;
            if (a[j] < a[min]) {
                min = j;
            }
        }
        if (min != i) {
            int temp = a[i];
            a[i] = a[min];
            a[min] = temp;
            countSwaps++;
        }
    }
 cout << countCmpOps << " " << countSwaps << endl;
}