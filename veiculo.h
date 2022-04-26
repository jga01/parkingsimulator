#ifndef VEICULO_H
#define VEICULO_H

#define MAX 100

extern char codigos_serv_v[MAX][255];
extern char codigos_v[MAX][255];
extern char modelos[MAX][255];
extern char descricoes[MAX][255];
extern char placas[MAX][255];
extern char marcas[MAX][255];
extern int ocupados_veiculos[MAX];

void iniciar_ocupados_veiculos();
int inserir_veiculo(char cod_serv_v[], char cod_v[], char mod[], char desc[], char plac[], char marc[]);
int alterar_veiculo(char cod_v[], char mod[], char desc[], char plac[], char marc[]);
int excluir_veiculo(char cod_v[]);
int listar_veiculo_por_codigo(char cod_v[]);
int listar_veiculo_por_servidor();
int checar_servidor_veiculo(char cod_serv_v[]);
int checar_codigo_veiculo(char cod_v[]);
int checar_descricao_veiculo(char desc[]);

#endif //VEICULO_H
