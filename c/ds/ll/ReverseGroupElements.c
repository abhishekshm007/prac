#include<stdio.h>
#include<stdlib.h>

struct node {
  int data;
  struct node *next;
};

void reverse(struct node **, int );
void print(struct node *);
void push(struct node **, int );
struct node *group(struct node*);

int main(void){
  struct node *head;
  head = NULL;
  push(&head,1);
  push(&head,2);
  push(&head,3);
  push(&head,4);
  push(&head,5);
  push(&head,6);
  push(&head,7);
  push(&head,8);
  print(head);

  //  reverse(&head, 3);
  head = group(head);
  print(head);
  return 0;
}

void print(struct node* head){
  while(head != NULL){
    printf("%d\t",head->data);
    head = head->next;
  }
}

void push(struct node **head, int data){
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  temp->data = data;
  temp->next = NULL;
  if((*head) == NULL){
    (*head) = temp;
    return;
  }
  temp ->next = (*head);
  (*head) = temp;
  return;
}

void reverse(struct node **head, int nodes){
  if((*head) == NULL || (*head)->next == NULL){
    return;
  }
  struct node *prev = (*head), *current = (*head)->next , *temp;
  int counter = 1;
  while(counter < nodes && current != NULL){
    temp = current->next;
    current->next = *head;
    (prev)->next = temp;
    (*head) = current;
    counter++;
    current = temp;
  }
  reverse(&(prev->next), nodes);
}

struct node *group(struct node * head){
  if(head == NULL || head->next == NULL){
    return head;
  }
  struct node *prev, *current, *temp;
  struct node dummy;
  temp = &dummy;
  temp->next = head;
  prev = temp;
  current = head;
  head = &dummy;
  //temp = current->next;
  while(current != NULL){
    if((current->data) % 2 == 0){
      //      printf("true\t");
      head = current->next;
      prev->next = current->next;
      current->next = temp->next;
      temp->next = current;
      temp = temp->next;
      prev = current;
      current = head;
    }
    else{
      //      printf("fasle\t");
      prev = current;
      current = current->next;
    }
  }
  return dummy.next;
}
