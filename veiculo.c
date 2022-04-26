// ÁREA DE PROCESSAMENTO DE DADOS DOS VEICULOS

#include <stdio.h>
#include <string.h>
#include "veiculo.h"
#include "servidor.h"

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

int listar_veiculo_por_codigo(char cod_v[]) {
    cod_v[strcspn(cod_v, "\n")] = 0;
    int count = 0;

    for(int i = 0; i < MAX; i++) {
        if(!strcmp(cod_v, codigos_v[i])) {
            if(!count)
                printf("(%s)\n", codigos_serv_v[i]);
            printf("Codigo: %s\n", codigos_v[i]);
            printf("Marca: %s\n", marcas[i]);
            printf("Modelo: %s\n", modelos[i]);
            printf("Placa: %s\n", placas[i]);
            printf("Descricao: %s\n", descricoes[i]);
            count++;
        }
    }
    return count;
}

int listar_veiculo_por_servidor(char cod_serv_v[]) {
    cod_serv_v[strcspn(cod_serv_v, "\n")] = 0;
    int count = 0;

    for(int i = 0; i < MAX; i++) {
        if(!strcmp(cod_serv_v, codigos_serv_v[i])) {
            if(!count)
                    printf("(%s)\n", codigos_serv_v[i]);
            printf("Codigo: %s\n", codigos_v[i]);
            printf("Marca: %s\n", marcas[i]);
            printf("Modelo: %s\n", modelos[i]);
            printf("Placa: %s\n", placas[i]);
            printf("Descricao: %s\n", descricoes[i]);
            count++;
        }
    }
    return count;
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
