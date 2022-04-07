#ifndef VEICULO_H
#define VEICULO_H

#define MAX 100

extern int cod_veic[MAX];
extern int cod_serv[MAX];
extern char descricao[MAX][255];
extern char placa[MAX][255];
extern char marca[MAX][255];
extern char modelo[MAX][255];

void iniciar();
void inserir_veiculo(int cod_veic, int cod_serv, char descricao[], char placa[], char marca[], char modelo[]);
void excluir_veiculo(char cod_veic[]);
void listar_veiculo();

#endif //VEICULO_H
