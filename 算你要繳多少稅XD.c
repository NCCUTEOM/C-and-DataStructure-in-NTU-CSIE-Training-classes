#include<stdio.h>

int main(){
int income,discount,taxrate;

scanf("%d",&income);




if(0<income && income<=370000){
	taxrate = 6;
	discount = 0;
	
	printf("income %d\ntax rate %d%%\ntax %d\ndiscount %d\ntaxpay %d\n",income,taxrate,income*taxrate/100,discount,taxrate*income/100-discount);
	
}
else if(370000<income && income<=990000){
	taxrate = 13;
	discount = 25900;
	
	printf("income %d\ntax rate %d%%\ntax %d\ndiscount %d\ntaxpay %d\n",income,taxrate,income*taxrate/100,discount,taxrate*income/100-discount);
	
}
else if(990000<income && income<=1980000){
	taxrate = 21;
	discount = 105100;
	
	printf("income %d\ntax rate %d%%\ntax %d\ndiscount %d\ntaxpay %d\n",income,taxrate,income*taxrate/100,discount,taxrate*income/100-discount);
}
else if(1980000<income && income<=3720000){
	taxrate = 30;
	discount = 283300;
	
	printf("income %d\ntax rate %d%%\ntax %d\ndiscount %d\ntaxpay %d\n",income,taxrate,income*taxrate/100,discount,taxrate*income/100-discount);
}
else{

	taxrate = 40;
	discount = 655300;
	
	printf("income %d\ntax rate %d%%\ntax %d\ndiscount %d\ntaxpay %d\n",income,taxrate,income*taxrate/100,discount,taxrate*income/100-discount);
}
return 0;
}
