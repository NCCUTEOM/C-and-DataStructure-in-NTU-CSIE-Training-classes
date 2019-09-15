#include<stdio.h>
#include<stdlib.h>
#include <string.h>


void swap(char *a, char *b)
{
 char temp[128];

    strcpy(temp, a);
  	strcpy(a, b);
    strcpy(b, temp);
    memset(temp, '\0', sizeof(temp));

}
void print(int n, char data[][128])
{
    int i;

    for(i=0; i<n; i++)
    {
        printf("%s\n", data[i]);
    }
    printf("\n");
}
int selesort(char data[][128],int n){
 //   int data[5] = {34,12,5,66,1};  // 欲排序的資料
    int i, j, pos;  // pos: 紀錄目前最小值位置
  //  int n=5;
    for(i=0; i<n-1; i++)
    {
        pos = i;
        for(j=i+1; j<n; j++) // 找出最小值
        {
            if(strcmp(data[j],data[pos]) <0)
                pos = j; 
        }
        // 把最小值跟第 i 個做交換
        swap(data[i], data[pos]);
        print(n, data);
    }
    print(n, data);
    return 0;
}	
	
	
	
	
	

int bubblesort(char data[][128],int n){


//int data[5] = {34,12,5,66,1}; // 欲排序的資料
int i, j;
//int n;
for(i=n; i>1; i--){
	for(j=0; j<i-1; j++){
		if(strcmp(data[j+1] ,data[j])<0){
		
			swap(data[j+1], data[j]);	
		
		}		
	}
		print(n,data);
}
// print(n, data);
return 0;
} 
	
	
	
	
	
	

int isort(char data[][128],int n){
	
   // int data[5] = {34,12,5,66,10};  // 欲排序的資料
    int i, j; 
   	char key[128];  // 紀錄要被插入的值
  //  int n=5;
    for( i=1; i<n; i++) 
    {
		strcpy(key, data[i]);
        for(j=i-1; j>=0 && strcmp(data[j], key)>0; j--)
        {
            strcpy(data[j+1] ,data[j]);
        }
        strcpy(data[j+1],key);  //將key插入
        print(n, data);
    }
   // print(n, data);
    return 0;
}

int main(){

char data[10][128];
int n =10,row=0;
int op;
while(1){
	int i;
	for(i = 0;i<10;i++){
	
	scanf(" %s",data[i]);
	
	}
	scanf(" %d",&op);
	switch(op){
		case 3:
			isort(data,n);
			break;
		case 1:
			bubblesort(data,n);
			break;
		case 2:
			selesort(data,n);
			break;
		
	}

	
}






return 0;

}
	
	
	
	
	

