#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
};
struct node *getnode();
struct node *create(struct node *start);
struct node *display(struct node *start);
struct node *insertbegin(struct node *start);
struct node *insertend(struct node *start);
struct node *deletebegin(struct node *start);
struct node *deleteend(struct node *start);
struct node *countnodes(struct node *start);
struct node *searchnode(struct node *start,int value);
int main(){
	int option,value;
	struct node *start;
	while(option != 9){
		printf("\n*******MENU********\n");
		printf("1)Create linked list\n");
		printf("2)Dispaly linked list\n");
		printf("3)Insert a node begin of the linked list\n");
		printf("4)Insert a node end of the linked list\n");
		printf("5)Delete a node from begin of the linked list\n");
		printf("6)Delete a node from end of the linked list\n");
		printf("7)count number of nodes in linked list\n");
		printf("8)Search a node if it is in linked list\n");
		printf("9)Exit\n");
		
		printf("\nEnter the number : ");
		scanf("%d",&option);
		
		switch(option){
			case 1 : start = create(start); printf("Linked list created\n");break;
			case 2 : display(start); break;
			case 3 : start = insertbegin(start); printf("A node inserted begin of the linked list\n");break;
			case 4 : start = insertend(start); printf("A node inserted begin of the linked list\n");break;
			case 5 : start = deletebegin(start);
					 printf("first node is deleted\n");break;
			case 6 : start = deleteend(start);		 
					 printf("Last node is deleted\n");break;
			case 7: countnodes(start);break;		 
			case 8: printf("Enter the node value you want to search: ");
					 scanf("%d",&value);
					 searchnode(start,value);break;		 
			case 9: printf("Exit");break;
			default: printf("Invalid input try again\n");
					
		}
	}
	
}

struct node *getnode(){
	struct node *new_node;
	new_node = (struct node *)malloc(sizeof(struct node));
	printf("Enter the value : ");
	scanf("%d",&new_node->data);
	return new_node;
}

//create circular linked list
struct node *create(struct node *start){
	struct node *new_node,*p;
	int option = 1;
	start = NULL;
	
	while(option == 1){
		new_node = getnode();
		new_node->next = NULL;		
		if(start == NULL){
			start = new_node;	
		}
		
		else{
			p = start;
			while(p->next != NULL)
	    	{ 
				p = p->next;  
			
			};
				p->next=new_node;	
		}
		printf("Do you want to continue creating list. (yes => press 1, no => press 0)");
		scanf("%d",&option);		
	}
	new_node->next = start;
	return start;
}

//display circular linked list
struct node *display(struct node *start){
	struct node *p;
	p = start;
	if(p == NULL){
		printf("there is no values");//if there is not values to show it
	}else{
		do{
			printf("%d, ",p->data);
			p = p->next;
		}while(p != start);
		printf("\b\b \n");	
	}
	
}

//insert node begin
struct node *insertbegin(struct node *start){
	struct node *new_node ,*p;
	new_node = getnode();
	if(start == NULL){
			start = new_node;	
		}
	else{
		p = start;
		while(p->next != start){ 
			p = p->next;  
			}
		p->next=new_node;
		new_node->next = start;
		start = new_node;	
		}
	
	return start;
}

//insert node end
struct node *insertend(struct node *start){
	struct node *new_node,*p;
	new_node = getnode();
	if(start == NULL){
			start = new_node;	
		}
	else{
		p = start;
		while(p->next != start){ 
			p = p->next;  
			}
		p->next=new_node;
		new_node->next = start;	
		}
	
	return start;
}

//detlete node begin
struct node *deletebegin(struct node *start){
	struct node *p;
	if(start == NULL){
		printf("There is no data in linked list");
	}
	else{
		p = start;
		while(p->next != start){ 
			p = p->next;  
			}
		p->next = start->next;
		start = p->next;
		}
	return start;
}

//delete node end
struct node *deleteend(struct node *start){
	struct node *pre,*p;
	if(start == NULL){
		printf("There is no data in linked list");
	}
	else{
		p = start;
		while(p->next != start){ 
			pre = p;
			p = p->next;  
			}
		pre->next = start;	
		}
	return start;
}

//count nodes
struct node *countnodes(struct node *start){
	struct node *p;
	int count;
	p = start;
	do{
		p = p->next;
		count++;
	}while(p != start);
	printf("There is %d nodes in linked list\n",count);	
}

//search node
struct node *searchnode(struct node *start,int value){
	struct node *p;
	int yes;
	p = start;
	do{
		if(p->data == value){
			yes = 1;
			break;
		}
		p = p->next;
	}while(p != start);
	if(yes){
		printf("There is %d in the linked list\n",value);
	}
	else{
		printf("There is no %d in the linked list\n",value);
	}
}



