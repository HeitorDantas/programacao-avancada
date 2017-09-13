#include <stdio.h>

int main(){
	char xc[4];
	int xi[4];
	double xd[4];
	float xf[4];
	printf("char:\n\tx+1 = %X\n\tx+2 = %X\n\tx+3 = %X\n",xc+1,xc+2,xc+3);
	printf("int:\n\tx+1 = %X\n\tx+2 = %X\n\tx+3 = %X\n",xi+1,xi+2,xi+3);
	printf("float:\n\tx+1 = %X\n\tx+2 = %X\n\tx+3 = %X\n",xf+1,xf+2,xf+3);
	printf("double:\n\tx+1 = %d\n\tx+2 = %d\n\tx+3 = %d\n",xd+1,xd+2,xd+3);
	return 0;
}