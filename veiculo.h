#ifndef VEICULO_H
#define VEICULO_H

#define MAX_V 1000

extern char codigos_serv_v[MAX_V][255];
extern char codigos_v[MAX_V][255];
extern char modelos[MAX_V][255];
extern char descricoes[MAX_V][255];
extern char placas[MAX_V][255];
extern char marcas[MAX_V][255];
extern int ocupados_veiculos[MAX_V];

void iniciar_ocupados_veiculos();
int inserir_veiculo(char cod_serv_v[], char cod_v[], char mod[], char desc[], char plac[], char marc[]);
int alterar_veiculo(char cod_v[], char mod[], char desc[], char plac[], char marc[]);
int excluir_veiculo(char cod_v[]);
void excluir_veiculos_servidor(char cod_serv_v[]);
void listar_veiculo_por_codigo(char cod_v[]);
void listar_veiculo_por_servidor(char cod_serv_v[]);
void listar_veiculo_ordenado(char cod_serv_v[]);
int checar_servidor_veiculo(char cod_serv_v[]);
int checar_codigo_veiculo(char cod_v[]);
int checar_descricao_veiculo(char desc[]);
int checar_em_branco(char string[]);
char *busca_nome(char cod_serv_v[]);
int checar_cheio_veiculos();

#endif //VEICULO_H
