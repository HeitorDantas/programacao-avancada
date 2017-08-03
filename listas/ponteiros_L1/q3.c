
/*

}

int i=5, *p;

p = &i;//p guarda o endereco de i

printf("%x %d %d %d %d", p,*p+2,**&p,3**p,**&p+4);
p : endereco de i = 4094
*p+2 : i+2 == 7
**&p == i == 5
3**p : *p == i , 3*i == 15
**&p+4 : i+4 == 9

out: 4094 7 5 15 9

}
*/