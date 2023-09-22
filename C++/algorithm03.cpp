#include <stdio.h>
#include <iostream>
#define MAX_SIZE 1000
using namespace std;
void ShellSort(int a[], int n);
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
 ShellSort(a, num);
 }
 return 0;
}
void swap(int* a, int* b)
{
 int tmp = *a;
 *a = *b;
 *b = tmp;
}
/* Shell Sort �Լ� */
void ShellSort(int a[], int n)
{
 int countCmpOps = 0; // �� ������ ���� Ƚ��
 int countSwaps = 0; // swap �Լ� ���� Ƚ��
 // Shell sort �˰��� ����
    int gap = n / 2;
    while (gap > 0) {
        for (int i = 0; i < n - gap; i++) {
            int j = i + gap;
            int tmp = a[j];
            while (j >= gap) {
                if(tmp < a[j-gap]){
                    a[j] = a[j - gap];
                    j -= gap;
                    countSwaps++;
                    countCmpOps++;
                }else{
                    countCmpOps++;
                    break;
                }
            }
            a[j] = tmp;
        }
        gap /= 2;
    }
 cout << countCmpOps << " " << countSwaps << endl;
}