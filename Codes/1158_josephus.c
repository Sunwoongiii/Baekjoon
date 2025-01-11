#include <stdlib.h>
#include <stdio.h>

typedef struct{
  int *arr;
  int front;
  int back;
  int size;
  int cnt;
}Queue;

void initQueue(Queue *q, int size);
int pop(Queue *q);
void push(Queue *q, int value);
void resize(Queue *Q);
void destroy(Queue *q);

void initQueue(Queue *q, int size){
  q->arr = (int*) malloc(size * sizeof(int));

  q->size = size;
  q->front = 0;
  q->back = -1;
  q->cnt = 0;
}

int pop(Queue *q){
  if(q->cnt == 0){
    return -1;
  }

  int value = q->arr[q->front];
  q->front = (q->front + 1) % q->size;
  q->cnt--;
  return value;
}

void push(Queue *q, int value){
  if(q->cnt == q->size)resize(q);

  q->back = (q->back + 1) % q->size;
  q->arr[q->back] = value;
  q->cnt++;
}

void resize(Queue *q){
  int newSize = q->size * 2;
  int *newArr = (int*)malloc(newSize * sizeof(int));

  for(int i  = 0; i < q->cnt; i++)newArr[i] = q->arr[(q->front + i) % q->size];
  free(q->arr);

  q->arr = newArr;
  q->front = 0;
  q->back = q->cnt -1;
  q->size = newSize;
}

void destroy(Queue *q){
  free(q->arr);
  q->arr = NULL;
  q->size = 0;
  q->front = 0;
  q->back = -1;
  q->cnt = 0;
}

int main(){
  int N,K;
  Queue q;
  initQueue(&q, 10);
  scanf("%d %d", &N, &K);

  for(int i = 1; i <= N; i++){
    push(&q, i);
  }

  printf("<");
  int cnt = 0;

  while(1){
    cnt++;

    if(cnt % K == 0){
      int temp = pop(&q);

      if(q.cnt == 0){
        printf("%d", temp);
        break;
      }
      else{
        printf("%d, ", temp);
      }
    }
    else{
      int temp = pop(&q);
      push(&q, temp);
    }
  }
  printf(">");
  destroy(&q);

}