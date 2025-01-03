#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void *b){
  int x = *(int*)a;
  int y = *(int*)b;
  return (x>y) - (x<y);
}

int main(){
  int a,b,cnt,sum = 0;

  scanf("%d %d", &a, &b);

  int *A = (int*)malloc(a * sizeof(int));
  int *B = (int*)malloc(b * sizeof(int));

  for(int i = 0; i < a; i++)scanf("%d", &A[i]);
  for(int i = 0; i < b; i++)scanf("%d", &B[i]);

  qsort(A, a, sizeof(int), compare);
  qsort(B, b, sizeof(int), compare);

  int i = 0, j = 0;

  while(i < a && j < b){
    if(A[i] < B[j]){
      sum++;
      i++;
    }

    else if(A[i] > B[j]){
      sum++;
      j++;
    }
    else{
      i++;
      j++;
    }
  }

  sum += a-i+b-j;

  printf("%d", sum);

  free(A); free(B);
  return 0;
}