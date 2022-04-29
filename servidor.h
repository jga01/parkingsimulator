#ifndef SERVIDOR_H
#define SERVIDOR_H

#define MAX 100

extern int ocupados[MAX];
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
void menu_listar_server(int op);
void deletarServidor(char entrada[]);
void print_serv_cod();
void ordenando(int opcao);
int type_serv();
void printar_serv(int ordenado[]);
void verificador_quantia(int quantia, int ordenador[]);
int checarCodigos(char temp_cod[]);
int checa_repeti(char codigo[],char nome[], char siape[],char cpf[], char iden[] );
int existe_cod(char codigo[]);
void iniciar_ocupados();
int checa_branco(char codigo[],char nome[], char siape[],char cpf[], char indentficador[]);
char *caixa_baixa(char nome[]);

#endif //SERVIDOR_H