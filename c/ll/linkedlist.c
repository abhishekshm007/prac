#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define null NULL

struct node{
	int data;
	struct node *next;
};
typedef struct node *nodeptr;
typedef struct node node;

clock_t begin,end;
double time_used;

int is_palindrome(nodeptr);
void delete_using_node(nodeptr);
nodeptr insert_at_first(nodeptr , int);
nodeptr create(int *, int);
int recursion_len(nodeptr);
int iterative_len(nodeptr);
void print(nodeptr);
nodeptr search(nodeptr, int);
nodeptr reverse(nodeptr);
nodeptr recursive_reverse(nodeptr);


int main(int argc, char *argv[]){
	int ip;
	nodeptr temp, head = null;
	int len, arr[1000],i;

	while(1){
		printf("\t\t\t::LINKED LIST PROGRAM:::\n\
		1- create linked list\n\
		2- insert node\n\
		3- delete node\n\
		4- find recursive length\n\
		5- print linked list\n\
		6- find iterative length\n\
		7- search an item\n\
		8- delete node using node itself\n\
		9- reverse linked list\n\
		10-reverse usig recursion\n\
		11- check for palindrome\n\
		");
		printf("input: ");
		scanf("%d",&ip);	
	
		switch(ip){
			case 1:
				begin = clock();
				printf("Enter the no of nodes : ");
				scanf("%d",&len);
				printf("Enter the nodes : ");
				for(i=0; i<len; i++){
					scanf("%d",&arr[i]);
				}
				head = create(arr, len);
				printf(":: Linked list is created::\n");
				end = clock();
				time_used = ((double) end-begin)/CLOCKS_PER_SEC;
				printf("\ntime used is %f\n",time_used);
				break;
			case 5:
				print(head);
				break;
			case 3:
				printf("enter the element to be deleted\n");
				scanf("%d",&ip);
				delete(&head,ip);
				break;
			case 2:
				printf("enter the element to be inserted\n");
				scanf("%d",&ip);
				head = insert_at_first(head,ip);
				break;
			case 6: 
				begin = clock();
				len = iterative_len(head);
				printf("\nLength is %d\n",len);
				end = clock();
				time_used = (double)(end - begin) / CLOCKS_PER_SEC;
				printf("time used is %f",time_used);
				break;
			case 4:
				begin = clock();
				len = recursive_len(head);
				printf("\nLength is %d\n",len);
				end = clock();
				time_used = (double)(end - begin) / CLOCKS_PER_SEC;
				printf("time used is %f",time_used);
				break;
			case 7:
				begin = clock();
				printf("\nenter the element : \n");
				scanf("%d",&len);
				temp = search(head, len);
				if(temp != NULL)
				printf("\nelement found \n");
				else 
				printf("\nelement didnt find\n");
				end = clock();
				time_used = ((double) end-begin)/ CLOCKS_PER_SEC;
				printf("\ntime used is %f\n",time_used);
				break;
			case 8: 
				begin = clock();
				printf("\nenter the node no which you want delete : \n");
				scanf("%d",&len);
				temp = search(head, len);
				delete_using_node(temp);
				printf("\nNode deleted successfully\n");
				end = clock();
				time_used = ((double) end - begin)/ CLOCKS_PER_SEC;
				printf("\ntime used is %f\n",time_used);
				break;
			case 9:
				begin = clock();
				head = reverse(head);
				end = clock();
				printf("\nreverse linked list is : \n");
				print(head);
				time_used = ((double) end- begin)/ CLOCKS_PER_SEC;
				printf("\ntime used is %f\n",time_used);
				break;
			case 10:
				begin = clock();
				head = recursive_reverse(head);
				end = clock();
				print(head);
				time_used = ((double) end- begin)/ CLOCKS_PER_SEC;
				printf("\ntime used is %f\n",time_used);
				break;
			case 11:
				begin = clock();
				len = is_palindrome(head);
				end = clock();
				if(len)
					printf("\nit is palindrome\n");
				else 
					printf("\nit is not palindrome\n");
				time_used = ((double) end- begin)/ CLOCKS_PER_SEC;
				printf("\ntime used is %f\n",time_used);
				break;
			}
		}
				
}

nodeptr insert_at_first(nodeptr head, int data){
	struct node *new_node = (struct node *) malloc(sizeof(struct node));
	new_node->data = data;
	new_node->next = head;
	return new_node;	
}

int delete(struct node **head, int data){
	if((*head) == NULL){
		return 0;
	}
	if((*head)->data == data){
		(*head) = (*head)->next;
		return;
	}
	struct node *temp, *prev;
	temp = *head;
	prev = NULL;
	while(temp!=NULL){
		if((temp)->data == data){
			prev->next = (temp)->next;
		//	free(temp);
			return 1;
		}
		else
		{
			(prev) = temp;
			(temp)= (temp)->next; 
		}
	}
	
}

void print(struct node *head){
	printf("Linked list is :\t");
	while(head != NULL){
		printf("%d\t",head->data);
		head = head->next;
	}
	puts("\n");
}

struct node *create(int *arr, int len){
	struct node *head = (struct node *)malloc(sizeof(struct node));
	struct node *prev = (struct node *)malloc(sizeof(struct node));
	head = prev;
	int i =1;
	while(len){
		struct node *temp = (struct node *)malloc(sizeof(struct node));
		temp->data = *arr++;
		prev->next = temp;
		if(i){
			head = temp;
			i--;
		}
		temp->next = NULL;
		prev = temp;
		len--;
	}
	return head;
}

int iterative_len(nodeptr head){
	int count = 0;
	while(head != NULL){
		count++;
		head = head->next;
	}
	return count;
}

int recursive_len(nodeptr head){
	if(head== NULL)
	return 0;
	else return (1 + recursive_len(head->next));

}

nodeptr search(nodeptr head, int key){
	if(head == NULL)
	return NULL;
	else {
		if(head->data == key)
		return head;
		else search(head->next, key);
		
	}
}

void delete_using_node(nodeptr delNode){
	delNode->data = delNode->next->data;
	delNode->next = delNode->next->next;
	free(delNode->next);
	return;
	
}
nodeptr reverse(nodeptr head){
	nodeptr prev = NULL, next = head->next;
	while(head->next != NULL){
		head->next = prev;
		prev = head;
		head = next;
		next = next->next;
	}
	head->next = prev;
	return head;

}

nodeptr recursive_reverse(nodeptr head){
	if(head == NULL){
		return NULL;
	}

	if(head->next == NULL){
		return head;
	}

	nodeptr rest;
	nodeptr first = head;
	rest = recursive_reverse(head->next);
	first->next->next = first;
	first->next = NULL;
	return rest;
}

int is_palindrome(nodeptr head){
	nodeptr a , b , temp, prev;
	a = b = temp = head;
	while(b!= NULL && b->next != NULL){
		prev = a;
		a = a->next;
		b = b->next->next;
	}
	a =	b = reverse(a);
	
	while(temp != NULL && b != NULL){
		if(temp->data != b->data){
			b = reverse(a);
			prev->next = b;
			return 0;
		}
		temp = temp->next;
		b = b->next;
	}
	b = reverse(a);
	prev -> next = b ;
	return 1;

	
}

