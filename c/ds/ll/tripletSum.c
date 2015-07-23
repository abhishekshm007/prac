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
int checkTriplet(struct node* , int *, int *, int*);

int main(void){
  struct node *head1, *head2, *head3;
  head1 = push(head1, 2);
  head1 = push(head1, 4);
  head1 = push(head1, 6);
  head1 = push(head1, 1);
  head1 = push(head1, 9);
  head1 = push(head1, 3);
  /*
  head2 = push(head2, 2);
  head2 = push(head2, 4);
  head2 = push(head2, 6);
  head2 = push(head2, 1);
  head2 = push(head2, 9);
  head2 = push(head2, 3);

  head3 = push(head3, 2);
  head3 = push(head3, 4);
  head3 = push(head3, 6);
  head3 = push(head3, 1);
  head3 = push(head3, 9);
  head3 = push(head3, 3);
  */
  puts("hello");
  print(head1);
  puts("hello");
  //print(head2);
  //  print(head3);
  int i =0 ,n1,n2,n3;
  //  i = checkTriplet(head, &n1,&n2,&n3);
  if(i){
    printf("triplet exist\n");
    printf("no are %d %d %d\n",n1,n2,n3);
  }
  return 0;
}

struct node *push(struct node *head, int data){
  struct node *temp = (struct node *) malloc((sizeof(struct node)));
  temp->data = data;
  temp->next = NULL;
  if(head == NULL){
    return temp;
  }

  temp->next = head;
  head = temp;
  return head;
}

void print(struct node *head){
  while(head != NULL && puts("adadasdadasdasd")){
    printf("%d\t",head->data);
    head = head->next;
    puts("adad");
  }
  puts("hellosdfsf");
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
  //  printf("%d hjhj\t",prev->data);
  //  printf("%d aaa\t",head->data);
  (*a) = head;
  (*b) = t1;
  //  printf("%d a",(*a)->data);
  //  printf("%d b",(*b)->data);
}


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
