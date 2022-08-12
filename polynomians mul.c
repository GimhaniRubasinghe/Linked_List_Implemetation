#include <stdio.h>
#include <stdlib.h>

struct node {
	int lead;
	int degree;
	struct node *next;
};

struct node *create(struct node *start){
	start = NULL;
	struct node *new_node , *p;
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
		}printf("\b\b \n");
	}	
}

int main(){
	struct node *start1, *start2, *start3,*new_node, *p1 , *p2 ,*p3;
	start1 = create(start1);//create f1
	start2 = create(start2);//create f2
	printf("f1 = ");//print f1
	display(start1);
	printf("f2 = ");//print f2
	display(start2);
	
	//create f3 polinomian (f3 = f1*f2)
	p1 = start1;
	p3 = start3;
	start3 = NULL;
	
	while(p1 != NULL){
		p2 = start2;
		while(p2 != NULL){
			new_node = (struct node*)malloc(sizeof(struct node));
			new_node->lead = p1->lead * p2->lead; 
			new_node->degree = p1->degree + p2->degree;
			new_node->next = NULL;
			if(start3 == NULL){
				start3 = new_node;
			}
			else{
				p3 = start3;
				while(p3->next != NULL){
					p3 = p3->next;
				}
				p3->next = new_node;
			}
			p2 = p2->next;
		}
		p1=p1->next;
	}
	//to add nodes which have same degree
	p3 = start3;
	while(p3 != NULL){
		p2 = p3->next;
		while(p2 != NULL){
			if(p2->degree == p3->degree){
				p3->lead += p2->lead;
				p2->lead = 0;//to ignore in display 
			}
			p2 = p2->next;
		}
		p3 =p3->next;
		
	}
	printf("f1*f2 = ");//display f3
	display(start3);
	//p3 = start3;
	
}
