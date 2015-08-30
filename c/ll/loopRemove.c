#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct node {
  int data;
  struct node *next;
};

clock_t begin,end;
double t;

struct node *push(struct node *, int );
struct node *removeLoop(struct node *);
void print(struct node *);
struct node*makeLoop(struct node*);

int main(void){
  struct node *head;
  head = push(head, 1);
  head = push(head, 2);
  head = push(head, 3);
  head = push(head, 4);
  head = push(head, 5);
  head = push(head, 6);
  head = push(head, 7);
  head = push(head, 8);
  head = push(head, 9);
  head = push(head, 10);
  puts("original");
  print(head);
  head = makeLoop(head);
  puts("looped");
  //print(head);
  head = removeLoop(head);
  puts("loop removerd");
  print(head);
  return 0;
}

struct node*makeLoop(struct node*head){
  if(head == NULL || head->next == NULL){
    return head;
  }
  struct node *temp = head;
  while(head->next != NULL){
    head = head->next;
  }
  head->next = temp->next->next->next;
  return temp;
}

struct node *push(struct node *head, int data){
  struct node *new = (struct node*)malloc(sizeof(struct node));
  new->data = data;
  new ->next = NULL;
  if(head == NULL){
    return new;
  }
  new->next = head;
  head = new;
  return head;
}

void print(struct node *head){
  while(head != NULL){
    printf("%d\t", head->data);
    head = head->next;
  }
}

struct node* removeLoop(struct node *head){
  int counter = 1;
  struct node *slow = head, *fast = head;
  while(slow && fast && fast->next){
    fast = fast->next->next;
    slow = slow->next;
    if(slow == fast){
      break;
    }
  }
  if(slow == fast){
    while(fast->next != slow){
      fast = fast->next;
      counter++;
    }
    printf("\n\n\nvalue of counter %d\n\n\n",counter);
    if(fast->next == slow){
      fast = head;
      while(counter){
	fast = fast->next;
	counter--;
      }
      slow = head;
      struct node *temp;
      while(fast != slow){
	temp = fast;
	slow = slow->next;
	fast = fast->next;
      }
      printf("\n\nvalue of temp %d\n\n",temp->data);
      temp->next = NULL;
    }
  }
  return head;
}
