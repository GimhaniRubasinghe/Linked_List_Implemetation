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
		}printf("\b\b \n");
	}	
}
int main(){
	struct node *start1, *start2, *start3 ,*new_node , *p1 , *p2 ,*p3, *p4,*p5;
	start1 = create(start1);//create f1
	start2 = create(start2);//create f2
	printf("f1 = ");
	display(start1);
	printf("f2 = ");
	display(start2);
	
	//sum of f1 and f2
	p3 = start1;
	p4 = start2;
	start3 = NULL;
	
	if(p3->degree < p4->degree){
		p3 = start2;
		p4 = start1;
	}
	p1 = p3;
	while(p1 != NULL){
		p2 = p4;
		new_node = (struct node*)malloc(sizeof(struct node));
		new_node->lead = p1->lead;
		new_node->degree = p1->degree ;
		
		while(p2 != NULL){
			if(p1->degree == p2->degree){
				new_node->lead +=p2->lead;
				break;
			}
			p2 = p2->next;
		}
		new_node->next = NULL;
		if(start3 == NULL){
			start3 = new_node;
		}
		else{
			p5 = start3;
			while(p5->next != NULL){
				p5 = p5->next;
			}
			p5->next = new_node;
		}
		
		p1 = p1->next;
	}
	printf("f1 + f2 = ");
	display(start3);
	
}

