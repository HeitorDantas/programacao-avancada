#include <stdio.h>

void atobits(int vet[],unsigned char *pchar){
	*pchar = 0;
	for(int i=0;i<8;i++){
		*pchar += vet[i];
		if(i<7) *pchar<<=1;
	}
}

void printbyte(unsigned char *pchar){

	for(int i=0;i<8;i++){
		printf("%d",!!(0x80 & *pchar));
		*pchar<<=1;
	}
	printf("\n");
}
//00001010
//00000001

int main(){
	int i,vet[8] = {1,1,1,1,1,1,0,0};
	unsigned char *pc,c = 2;
	
	pc = &c;
	atobits(vet,pc);
	printbyte(pc);
	
	//10000010
	//i = 7

	return 0;
}