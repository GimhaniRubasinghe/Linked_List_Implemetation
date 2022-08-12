#include <stdio.h>
#include <stdlib.h>
//A C program to perform addition and multiplication operation on two polynomials using linked list
struct node{
	int lead;
	int degree;
	struct node *next;
};
struct node *create(struct node* start);
struct node *pol_add(struct node* start1,struct node* start2);
struct node *pol_mul(struct node* start1,struct node* start2);
struct node *display(struct node *start);

int main(){
	struct node *start1, *start2,*p1;
	int option;
	printf("\n*****ADDITION AND MULTIPLICATION ON TWO POLYNOMIALS*****\n");
	start1 = create(start1);//create f1
	start2 = create(start2);//create f2
	printf("\nf1 = ");
	display(start1);
	printf("f2 = ");
	display(start2);

	printf("\nAddition of f1 and f2\n");
	p1 = pol_add(start1,start2);
	printf("f1 + f2 = ");
	display(p1);
	free(p1);

	printf("\nMultiplication of f1 and f2\n");
	p1 = pol_mul(start1,start2);
	printf("f1*f2 = ");
	display(p1);
	free(p1);

}
//Function to create a polynomian in a linked list
struct node *create(struct node* start){
	struct node *p, *new_node;
	start = NULL;
	printf("\nEnter value decrese order of degree.\n(when 3 is the highest digree of polynimiyan and 2 and 0 is no there,you should enter value as 0)\nDon't skip them\n\n");
	do{
		new_node = (struct node*)malloc(sizeof(struct node));//mamory allocation
		printf("power of x: ");
		scanf("%d",&new_node->degree);//to get degree
		printf("Enter the leading value of x%d : ",new_node->degree);
		scanf("%d",&new_node->lead);//to get lead value of it
		new_node->next = NULL;

		if(start == NULL){
			start = new_node;//start the linked list
		}
		else{
			p = start;//to add new element from second node
			while(p->next != NULL){
				p = p->next;
			}
			p->next = new_node;
		}

	}while(new_node->degree != 0);
	return start;
}
//Function to display a polinomian
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
//Function to add two polinomians
struct node *pol_add(struct node* start1,struct node* start2){
	struct node *start3 ,*new_node , *p1 , *p2 ,*p3, *p4,*p5;
	p3 = start1;
	p4 = start2;
	start3 = NULL;//create new list to add adding values

	if(p3->degree < p4->degree){//if second polynomian first degree is greater than first one
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
	return start3;
}
//Function to multiply two polynomians
struct node *pol_mul(struct node* start1,struct node* start2){
	struct node *start3,*new_node, *p1 , *p2 ,*p3;
	p1 = start1;
	p3 = start3;
	start3 = NULL;//create a new list to add mulypying values

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
	return start3;
}


