#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int push(int value,int stack[],int top){ 	
	if( top == 3){ 
		return -1; 
	} 
	top++; 
	stack[top] = value; 
	return 1; 
}
int pop(int stack[],int top){ 
	int temp;
	
	if( top == -1 ){ //�P�_���|�O�_���Ū�
		return -1; 
	} 
	temp = stack[top]; 
	stack[top] = 0; 
	top--; 
	return temp;
}

	



void hanoi (int n, char from, char mid, char to,int ptr[]){   
// �b�h�ʲ�n�Ӷ�L�� 
	if(n==0) return ; 
//���N��n-1�Ӷ�L�h�졨������ 
	hanoi(n-1,from, to, mid,ptr); //?�N�ۤv�h�졨�ؼж� 
	printf("plate%2d from %c -> %c\n",n,from,to); 
	ptr[n-1]++;
	//�A�N��n-1�Ӷ�L�q�������𡨷h�^�� 
	hanoi(n-1,mid, from, to,ptr); 
}


int main() {
    int n,i;
    int topA = -1,topB = -1,topC = -1;
    
    
  //  printf("�п�J�L�ơG");
    scanf("%d", &n);
    int *towerA = malloc(n*sizeof(int));
    int *towerB = malloc(n*sizeof(int));
    int *towerC = malloc(n*sizeof(int));
    for(i =0;i<=2;i++){
    	push(3-i,towerA,topA);
    	printf("tower[%d] = %d\n",i,towerA[i]);
    	
	}
	
	
    
	for(i =0;i<=2;i++){
		push(3-i,towerA,topA);
	}
    hanoi(n, 'A', 'B', 'C',ptr);
    puts("");
    for(i=0;i<n;i++){
    	printf("plate %d = %d\n",i+1,ptr[i]);
	}
    return 0;
} 

