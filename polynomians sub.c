#include <stdio.h>
#include <stdlib.h>

struct node{
	int lead;
	int degree;
	struct node *next;
};

struct node *create(struct node* start){
	struct node *p, *new_node;
	start = NULL;
	printf("\nEnter value decrese order of degree.(when there is no x0 the value enter it as 0)\n");
	do{
		new_node = (struct node*)malloc(sizeof(struct node));
		printf("power of x: ");
		scanf("%d",&new_node->degree);
		printf("Enter the leading value of x%d : ",new_node->degree);
		scanf("%d",&new_node->lead);
		
		new_node->next = NULL;
		if(start == NULL){
			start = new_node;
		}
		else{
			p = start;
			while(p->next != NULL){
				p = p->next;
			}
			p->next = new_node;
		}
		
	}while(new_node->degree != 0);
	return start;
}

struct node *display(struct node *start){
	struct node *p;
	p = start;
	if(start == NULL){
		printf("there is no polynomian");//if there is not polimonian to show it
	}
	else{
		while(p != NULL){
			if(p->lead != 0){//ignore whethere lead is 0
				printf("%dx%d + ",p->lead,p->degree);	
			}
			p = p->next;
		}printf("\b\b ");
	}	
}
int main(){
	struct node *start1, *start2, *p1 , *p2 ,*p3, *p4;
	start1 = create(start1);//create f1
	start2 = create(start2);//create f2
	printf("\nf1 = ");
	display(start1);
	printf("\nf2 = ");
	display(start2);
	
	//substraction of f1 and f2
	p3 = start1;
	p4 = start2;
	
	if(p3->degree < p4->degree){
		p3 = start2;
		p4 = start1;
	}
	p1 = p3;
	while(p1 != NULL){
		p2 = p4;
		while(p2 != NULL){
			if(p1->degree == p2->degree){
				p1->lead -=p2->lead;
				break;
			}
			p2 = p2->next;
		}
		p1 = p1->next;
	}
	printf("\nf1 - f2 = ");
	if(p3==start2){
		printf("-(");
		display(p3);
		printf(")\n");	
	}else{
		display(p3);
	}
	
	
	
}

