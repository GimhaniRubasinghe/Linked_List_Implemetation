#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
};

int main(){
	struct node *start, *p , *new_node;
	start = NULL;
	printf("press -1 to stop to continue linked list\n");
	do{
		new_node = (struct node *)malloc(sizeof(struct node));
		printf("Enter the data : ");
		scanf("%d",&new_node->data);
		new_node->next = NULL;
		if(start == NULL){
			start = new_node;	
		}
		
		else{
		p = start;
		while(p->next != NULL)
	    { 
		   	p = p->next;  
			
		}
			p->next=new_node;	
		}
		
				
	}while(new_node->data != -1);
	
	printf("\nDisplay\n");
	p = start;
	while (p->data != -1){
		printf("%d\n",p->data);
		p = p->next;
	}
}
