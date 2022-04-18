#ifndef VEICULO_H
#define VEICULO_H

#define MAX 100

extern char codigos[MAX][255];
extern char modelos[MAX][255];
extern char descricoes[MAX][255];
extern char placas[MAX][255];
extern char marcas[MAX][255];
extern int ocupados[MAX];
extern int indice;

void iniciarVeiculo();
void inserirVeiculo(char dono[], char cod[], char mod[], char desc[], char plac[], char marc[]);
void excluirVeiculo(int ind);
void atualizarVeiculo(int ind, char cod[], char mod[], char desc[], char plac[], char marc[]);
void listarVeiculo();
int checarCodigos(char t_cod[]);
int checarDono(char t_dono[]);
int checarDesc(char t_desc[]);

#endif //VEICULO_H
