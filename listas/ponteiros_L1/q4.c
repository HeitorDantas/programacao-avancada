/*
int i,j;

p = i; invalida, p nao pode guardar o valor i, mas sim o endereco.
q = &j;
p = &*&i;
i = (*&)j; invalida,a expressao dentro do parentesis nao se aplica a nenhuma variavel
i = *&j;
i = *&*&j;
q = *p; invalido, q nao pode receber o valor pra qual p aponta a menos que esse seja um endereco
i = (*p)++ + *q;

*/