// ÁREA DE PROCESSAMENTO DE DADOS DOS VEICULOS

#include <stdio.h>
#include <string.h>
#include "veiculo.h"

char codigos[MAX][255];
char modelos[MAX][255];
char descricoes[MAX][255];
char placas[MAX][255];
char marcas[MAX][255];
int ocupados[MAX];
int indice = 0;

void iniciarVeiculo()
{
    for (int i = 0; i < MAX; ++i)
    {
        ocupados[i] = 0;
    }
}

void inserirVeiculo(char cod[], char mod[], char desc[], char plac[], char marc[])
{
    strcpy(codigos[indice], cod);
    strcpy(modelos[indice], mod);
    strcpy(descricoes[indice], desc);
    strcpy(placas[indice], plac);
    strcpy(marcas[indice], marc);

    ocupados[indice] = 1;
    indice++;
}

void excluirVeiculo(int ind)
{
    ocupados[ind] = 0;
}

void atualizarVeiculo(int ind, char cod[], char mod[], char desc[], char plac[], char marc[])
{
    strcpy(codigos[ind], cod);
    strcpy(modelos[ind], mod);
    strcpy(descricoes[ind], desc);
    strcpy(placas[indice], plac);
    strcpy(marcas[indice], marc);

    ocupados[ind] = 1;
}

void listarVeiculo()
{
    printf("Indice\t\tCodigo\t\tPlaca\t\tMarca\t\tModelo\t\tDescricao\n\n");
    for (int i = 0; i < indice; ++i)
    {
        if(ocupados[i])
        {
            printf("%d.\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\n", (i+1), codigos[i], placas[i], marcas[i], modelos[i], descricoes[i]);
        }
    }
}

int checarCodigos(char cod[])
{
    for (int i = 0; i < indice; ++i)
    {
        if(!strcmp(cod, codigos[i])) {
            return 1;
        }
    }
    return 0;
}
