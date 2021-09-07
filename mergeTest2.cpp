#include <stdio.h>
void merge2(int *S, int low, int mid, int high);
void mergesort2(int *S, int low, int high);
int count = 0;
int main()
{
static int S[8] = {27, 10, 12, 20, 25, 13, 15, 22};
int i;
printf("before : ");
for(i = 0; i <8; i++)
printf("%d ", S[i]);
printf("\n");
mergesort2(S, 0, 7);
printf("\nafter : ");

for(i = 0; i <8; i++)
printf("%d ", S[i]);
printf("\n");
}

void mergesort2(int *S, int low, int high)
{
int mid;
if(low < high) {
mid = (low + high) / 2;
printf("[%d] low : %d, mid : %d, high %d\n", count, low, mid, high);
count++;
mergesort2(S, low, mid);
mergesort2(S, mid + 1, high);
merge2(S, low, mid, high);
}
}

void merge2(int *S, int low, int mid, int high)
{
int i, j, k;
int U[high - low];
i = low;
j = mid + 1;
k = 0;
while(i <= mid && j <= high) {
if(S[i] < S[j]) {
U[k] = S[i];
i++;
}
else {
U[k] = S[j];
j++;
}
k++;
}
if(i > mid)
for(; j <= high; j++) {
U[k] = S[j];
k++;
}
else {
for(; i <= mid; i++) {
U[k] = S[i];
k++;
}
}
 for(i = 0; i <8; i++)
 printf("U[k] = %d\n", U[i]);
 printf("\n");
k = 0;
for(i = low; i <= high; i++) {
S[i] = U[k];
k++;
}
}
