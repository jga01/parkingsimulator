#ifndef SERVIDOR_H
#define SERVIDOR_H

#define MAX 100

int cod[MAX]; // obrigatoria
char nome_serv[MAX][255]; // obrigatoria
char siape[MAX];  // obrigatoria
char cpf[MAX]; // obrigatoria
char nascimento[MAX];
char ende_serv[MAX][255];
char rg_serv[MAX];
char salario[MAX];
char tipo_serv[MAX][255];

//char cod[], char nome_serv[][255], char siape[], char cpf[], char nascimento[], char ende_serv[][255], char rg_serv[], char salario_serv[], char tipo_serv[][255]
//int cod[], char nome_serv[][255], int siape[], int cpf[], int nascimento[], char ende_serv[][255], int rg_serv[], int salario_serv[], char tipo_serv[][255]
void criarServidor();
void atualizarServidor(char entrada[255]); // entraa normals
void listarServer(char op[]);
void deletarServidor();
void printar_campos(int index);

#endif //SERVIDOR_H