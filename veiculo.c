// ÁREA DE PROCESSAMENTO DE DADOS DOS VEICULOS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "servidor.h"
#include "veiculo.h"

char cod_donos[MAX][255];
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

void inserirVeiculo(char dono[], char pcod[], char mod[], char desc[], char plac[], char marc[])
{
    strcpy(cod_donos[indice], dono);
    strcpy(codigos[indice], pcod);
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

void atualizarVeiculo(int ind, char pcod[], char mod[], char desc[], char plac[], char marc[])
{
    strcpy(codigos[ind], pcod);
    strcpy(modelos[ind], mod);
    strcpy(descricoes[ind], desc);
    strcpy(placas[indice], plac);
    strcpy(marcas[indice], marc);

    ocupados[ind] = 1;
}

void listarVeiculo()
{
    char listinp[256];
    printf("1. Mostrar por codigo do veiculo.\n");
    printf("2. Mostrar veiculos de um servidor.\n");
    printf("Opcao: ");
    fgets(listinp, sizeof(listinp), stdin);

    switch(atoi(listinp))
    {
        case 1:
            printf("Digite o codigo do veiculo: ");
            fgets(listinp, sizeof(listinp), stdin);
            listinp[strcspn(listinp, "\n")] = 0;

            for (int i = 0; i < MAX; i++)
            {
                if(ocupados[i])
                {
                    if(!strcmp(listinp, codigos[i]))
                    {
                        printf("Codigo\tPlaca\tMarca\tModelo\tDescricao\n\n");
                        printf("%s\t%s\t%s\t%s\t%s\n\n", codigos[i], placas[i], marcas[i], modelos[i], descricoes[i]);
                        return;
                    }
                }
            }
            printf("Nenhum veiculo com esse codigo.\n");
            break;
        case 2:
            printf("Digite o codigo do servidor: ");
            fgets(listinp, sizeof(listinp), stdin);
            listinp[strcspn(listinp, "\n")] = 0;

            printf("Codigo\tPlaca\tMarca\tModelo\tDescricao\n\n");

            int v_cont = 0;
            for (int i = 0; i < MAX; i++)
            {
                if(ocupados[i])
                {
                    if(!strcmp(listinp, cod_donos[i]))
                    {
                        v_cont++;
                        printf("%s\t%s\t%s\t%s\t%s\n\n", codigos[i], placas[i], marcas[i], modelos[i], descricoes[i]);
                    }
                }
            }
            if(!v_cont)
                printf("Nenhum servidor com esse codigo.\n");
            break;
        default:
            printf("Opcao invalida!\n");
            break;
    }
}

int checarCodigos(char t_cod[])
{
    for (int i = 0; i < MAX; ++i)
    {
        if(!strcmp(t_cod, codigos[i])) {
            return 1;
        }
    }
    return 0;
}

int checarDono(char t_cod[])
{
    for (int i = 0; i < MAX; ++i)
    {
        if(!strcmp(t_cod, cod[i])) {
            return 1;
        }
    }
    return 0;
}

int checarDesc(char t_desc[])
{
    for (int i = 0; i < MAX; ++i)
    {
        if(!strcmp(t_desc, descricoes[i])) {
            return 1;
        }
    }
    return 0;
}
