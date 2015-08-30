#include<stdio.h>
#include<stdlib.h>

struct node {
  int data;
  struct node *next;
};

struct node *push(struct node *,int data);
void print(struct node *);
struct node *mergesort(struct node*);
struct node *merge(struct node*, struct node*);
void divide(struct node* , struct node **, struct node **);
int main(void){
  struct node *head;
  head = push(head, 2);
  head = push(head, 4);
  head = push(head, 6);
  head = push(head, 1);
  head = push(head, 9);
  head = push(head, 3);
  print(head);
  head = mergesort(head);
  printf("\n\n\n sotrted:\n\n");
  print(head);
  return 0;
}

struct node *push(struct node *head, int data){
  struct node *temp = (struct node *) malloc((sizeof(struct node)));
  temp->data = data;
  if(head == NULL){
    return temp;
  }

  temp->next = head;
  temp->data = data;
  return temp;
}

void print(struct node *head){
  while(head != NULL){
    printf("%d\t",head->data);
    head = head->next;
  }
}

struct node* mergesort(struct node *head){
  if(head->next == NULL){
    return head;
  }
  struct node *a, *b;

  divide(head, &a, &b);

  a = mergesort(a);
  b = mergesort(b);

  return merge(a,b);
}

void divide(struct node *head, struct node **a, struct node **b){
  if(head->next == NULL){
    (*a) = head;
    return;
  }
  struct node *t1,*t2, *prev;
  
  prev = (struct node*)malloc(sizeof(struct node));
  t1 = head;
  t2 = head;
  
  while(t1 != NULL && t2 != NULL && t2->next != NULL){
    prev = t1;
    t1 = t1->next;
    t2 = t2->next->next;
  }
  prev->next = NULL;
  printf("%d hjhj\t",prev->data);
    printf("%d aaa\t",head->data);
  (*a) = head;
  (*b) = t1;
  printf("%d a",(*a)->data);
  printf("%d b",(*b)->data);
}

/* struct node *merge(struct node *a, struct node *b){
  struct node head, *current;
  current = &head;
  current = current->next;
  if(a == NULL){
    return b;
  }
  if(b == NULL){
    return a;
  }
  if(a->data <= b->data){
    current = a;
    a = a->next;
    current->next = merge(a,b);
  }
  else{
    current = b;
    b = b->next;
    current->next = merge(a,b);
  }
  printf("asdfa");
  return head.next;
}
*/

struct node* merge(struct node* a, struct node* b)
{
  struct node* result = NULL;

  /* Base cases */
  if (a == NULL)
    return(b);
  else if (b==NULL)
    return(a);

  /* Pick either a or b, and recur */
  if (a->data <= b->data)
    {
      result = a;
      result->next = merge(a->next, b);
    }
  else
    {
      result = b;
      result->next = merge(a, b->next);
    }
  return(result);
}
