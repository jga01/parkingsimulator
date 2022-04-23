#ifndef SERVIDOR_H
#define SERVIDOR_H

#define MAX 100

extern char cod[MAX][255]; // obrigatoria
extern char nome_serv[MAX][255]; // obrigatoria
extern char siape_serv[MAX][255];  // obrigatoria
extern char cpf_serv[MAX][255]; // obrigatoria
extern char nasci_serv[MAX][255];
extern char ende_serv[MAX][255];
extern char rg_serv[MAX][255];
extern char salario_serv[MAX][255];
extern char tipo_serv[MAX][255];

void criarServidor(char identificador[],char nome[],char siape[],char cpf[],char nasci[],char rg[],char salario[],char tipo[],char endereco[]);
void atualizarServidor(char entrada[255],char nome[255],char siape[255],char cpf[255],char nasci[255],char rg[255],char salario[255],char tipo[255],char endereco[255]); // entrada normal
void listarServer(int op);
void deletarServidor(char entrada[]);
void print_cod(int index);
void printar_all(int vezes);
void printar_prof();
void printar_tec();
void cabecalho();
void ordenando(int opcao);
void iniciar_ordenados();
int type_serv();

#endif //SERVIDOR_H