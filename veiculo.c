// ÁREA DE PROCESSAMENTO DE DADOS DOS VEICULOS

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "veiculo.h"
#include "servidor.h"

char nomes_serv_v[MAX][255];
char codigos_serv_v[MAX][255];
char codigos_v[MAX][255];
char modelos[MAX][255];
char descricoes[MAX][255];
char placas[MAX][255];
char marcas[MAX][255];
int ocupados_veiculos[MAX];

void iniciar_ocupados_veiculos() {
    for (int i = 0; i < MAX; ++i) {
        ocupados_veiculos[i] = 0;
    }
}

int inserir_veiculo(char cod_serv_v[], char cod_v[], char mod[], char desc[], char plac[], char marc[]) {
    cod_serv_v[strcspn(cod_serv_v, "\n")] = 0;
    cod_v[strcspn(cod_v, "\n")] = 0;
    mod[strcspn(mod, "\n")] = 0;
    desc[strcspn(desc, "\n")] = 0;
    plac[strcspn(plac, "\n")] = 0;
    marc[strcspn(marc, "\n")] = 0;

    for(int i = 0; i < MAX; i++) {
        if(!ocupados_veiculos[i]) {
            for(int j = 0; j < MAX; j++) {
                if(!strcmp(cod_serv_v, cod[j]))
                    strcpy(nomes_serv_v[i], nome_serv[j]);
            }
            strcpy(codigos_serv_v[i], cod_serv_v);
            strcpy(codigos_v[i], cod_v);
            strcpy(modelos[i], mod);
            strcpy(descricoes[i], desc);
            strcpy(placas[i], plac);
            strcpy(marcas[i], marc);
            ocupados_veiculos[i] = 1;
            return 1;
        }
    }
    return 0;
}

int alterar_veiculo(char cod_v[], char mod[], char desc[], char plac[], char marc[]) {
    cod_v[strcspn(cod_v, "\n")] = 0;
    mod[strcspn(mod, "\n")] = 0;
    desc[strcspn(desc, "\n")] = 0;
    plac[strcspn(plac, "\n")] = 0;
    marc[strcspn(marc, "\n")] = 0;

    for(int i = 0; i < MAX; i++) {
        if(!ocupados_veiculos[i] && !strcmp(cod_v, codigos_v[i])) {
            strcpy(codigos_v[i], cod_v);
            strcpy(modelos[i], mod);
            strcpy(descricoes[i], desc);
            strcpy(placas[i], plac);
            strcpy(marcas[i], marc);
            return 1;
        }
    }
    return 0;
}

int excluir_veiculo(char cod_v[]) {
    cod_v[strcspn(cod_v, "\n")] = 0;

    for(int i = 0; i < MAX; i++) {
        if(!strcmp(cod_v, codigos_v[i])) {
            for(int j = 0; j < 255; j++) {
                codigos_v[i][j] = '\0';
            }
            ocupados_veiculos[i] = 0;
            return 1;
        }
    }
    return 0;
}

void listar_veiculo_por_codigo(char cod_v[]) {
    cod_v[strcspn(cod_v, "\n")] = 0;
    int count = 0;

    for(int i = 0; i < MAX; i++) {
        if(!strcmp(cod_v, codigos_v[i])) {
            if(!count)
                printf("(%s)\n", nomes_serv_v[i]);
            printf("Codigo: %s\n", codigos_v[i]);
            printf("Marca: %s\n", marcas[i]);
            printf("Modelo: %s\n", modelos[i]);
            printf("Placa: %s\n", placas[i]);
            printf("Descricao: %s\n", descricoes[i]);
            count++;
        }
    }
    if(!count)
        printf("Esse veiculo nao existe\n");
}

void listar_veiculo_por_servidor(char cod_serv_v[]) {
    cod_serv_v[strcspn(cod_serv_v, "\n")] = 0;
    int count = 0;

    for(int i = 0; i < MAX; i++) {
        if(!strcmp(cod_serv_v, codigos_serv_v[i])) {
            if(!count)
                    printf("(%s)\n", nomes_serv_v[i]);
            printf("Codigo: %s\n", codigos_v[i]);
            printf("Marca: %s\n", marcas[i]);
            printf("Modelo: %s\n", modelos[i]);
            printf("Placa: %s\n", placas[i]);
            printf("Descricao: %s\n\n", descricoes[i]);
            count++;
        }
    }
    if(!count)
        printf("Servidor nao existe ou nao possui veiculos\n");
}

void listar_veiculo_ordenado(char cod_serv_v[]) {
    cod_serv_v[strcspn(cod_serv_v, "\n")] = 0;
    int SIZE = 0;
    int count = 0;

    for(int i = 0; i < MAX; i++) {
        if(!strcmp(cod_serv_v, codigos_serv_v[i])) {
            SIZE++;
        }
    }

    char veiculos_ordenados[SIZE][256];

    for(int i = 0; i < SIZE; i ++) {
        for(int j = 0; j < 256; j++) {
            veiculos_ordenados[i][j] = 0;
        }
    }

    int k = 0;
    for(int i = 0; i < MAX; i++) {
        if(!strcmp(cod_serv_v, codigos_serv_v[i])) {
            strcpy(veiculos_ordenados[k], marcas[i]);
            k++;
        }
    }

    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE-1; j++) {
            char aux[256];
            if(tolower(veiculos_ordenados[j][0]) > tolower(veiculos_ordenados[j+1][0])) {
                strcpy(aux, veiculos_ordenados[j]);
                strcpy(veiculos_ordenados[j], veiculos_ordenados[j+1]);
                strcpy(veiculos_ordenados[j+1], aux);
            }
        }
    }

    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < MAX; j++) {
            if(!strcmp(veiculos_ordenados[i], marcas[j]) && !strcmp(cod_serv_v, codigos_serv_v[j])) {
                if(!count)
                    printf("(%s)\n", nomes_serv_v[j]);
                printf("Codigo: %s\n", codigos_v[j]);
                printf("Marca: %s\n", marcas[j]);
                printf("Modelo: %s\n", modelos[j]);
                printf("Placa: %s\n", placas[j]);
                printf("Descricao: %s\n\n", descricoes[j]);
                count++;
            }
        }
    }
}

int checar_servidor_veiculo(char cod_serv_v[]) {
    cod_serv_v[strcspn(cod_serv_v, "\n")] = 0;

    for(int i = 0; i < MAX; i ++) {
        if(!strcmp(cod_serv_v, cod[i]))
            return 1;
    }
    return 0;
}

int checar_codigo_veiculo(char cod_v[]) {
    cod_v[strcspn(cod_v, "\n")] = 0;

    for(int i = 0; i < MAX; i ++) {
        if(!strcmp(cod_v, codigos_v[i]))
            return 1;
    }
    return 0;
}

int checar_descricao_veiculo(char desc[]) {
    desc[strcspn(desc, "\n")] = 0;

    for(int i = 0; i < MAX; i ++) {
        if(!strcmp(desc, descricoes[i]))
            return 1;
    }
    return 0;
}
