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
	
	if( top == -1 ){ //判斷堆疊是否為空的
		return -1; 
	} 
	temp = stack[top]; 
	stack[top] = 0; 
	top--; 
	return temp;
}

	



void hanoi (int n, char from, char mid, char to,int ptr[]){   
// 在搬動第n個圓盤時 
	if(n==0) return ; 
//先將第n-1個圓盤搬到”中間塔” 
	hanoi(n-1,from, to, mid,ptr); //?將自己搬到”目標塔” 
	printf("plate%2d from %c -> %c\n",n,from,to); 
	ptr[n-1]++;
	//再將第n-1個圓盤從”中間塔”搬回來 
	hanoi(n-1,mid, from, to,ptr); 
}


int main() {
    int n,i;
    int topA = -1,topB = -1,topC = -1;
    
    
  //  printf("請輸入盤數：");
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

