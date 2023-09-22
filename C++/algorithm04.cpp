#include <stdio.h>
#include <iostream>
#define MAX_SIZE 1000
using namespace std;
void combSort(int a[], int n);
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
 combSort(a, num);
 }
 return 0;
}
void swap(int* a, int* b)
{
 int tmp = *a;
 *a = *b;
 *b = tmp;
}
/* comb sort �Լ� */
void combSort(int a[], int n)
{
 int countCmpOps = 0; // �� ������ ���� Ƚ��
 int countSwaps = 0; // swap �Լ� ���� Ƚ��
 // comb sort �˰��� ����
    int gap = n;
    float shrink = 1.3;
    bool sorted = false;
    while (!sorted) {
        gap = gap / shrink;
        if (gap <= 1) {
            gap = 1;
            sorted = true;
        }
        for (int i = 0; i + gap < n; i++) {
            if (a[i] > a[i + gap]) {
                swap(a[i], a[i + gap]);
                sorted = false;
                countSwaps++;
            }
            countCmpOps++;
        }
    }
 cout << countCmpOps << " " << countSwaps << endl;
}