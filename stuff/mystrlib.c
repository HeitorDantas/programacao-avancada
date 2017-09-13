#include <stdio.h>
#include <stdlib.h>

int strlen(char *str){
	int i=0;
	while(str[i]!=0){
		i++;
	}
	return i;
}


void mystrcat(char *s1,char* s2,char *sres){
	int i=0,len_s1,len_s2;
	len_s1 = strlen(s1);
	len_s2 = strlen(s2);
	sres = (char*) malloc(100);
	while(s1[i++]!=0){
		sres[i] = s1[i];
		i++;
	}
	
	while(s2[i-len_s1-2]!=0){
		sres[i] = s2[i-len_s1-2];
		i++;
	}
	sres[i] = '\0';
}


int main(){
	char *s1,*s2,*sres;
	int i=0;
	s1 = "hey";
	s2 = "you";
	mystrcat(s1,s2,sres);
	printf("%s\n",sres);
	return 0;
}