#ifndef SERVIDOR_H
#define SERVIDOR_H

#define MAX 100

int cod[MAX]; // obrigatoria
char nome_serv[MAX][255]; // obrigatoria
int siape[MAX];  // obrigatoria
int cpf[MAX]; // obrigatoria
char nascimento[MAX];
char end_serv[MAX][255];
int rg_serv[MAX];
int salario[MAX];
char tipo_serv[MAX][255];

//int cod[], char nome_serv[][255], int siape[], int cpf[], int nascimento[], char ende_serv[][255], int rg_serv[], int salario_serv[], char tipo_serv[][255]
void criarServidor();
void atualizarServidor(int cod[], char nome_serv[][255], int siape[], int cpf[], int nascimento[], char ende_serv[][255], int rg_serv[], int salario[], char tipo_serv[][255]);
void deletarServidor(int cod[]);


#endif //SERVIDOR_H