#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "servidor.h"
#include "veiculo.h"

/*ÁREA DE PROCESSAMENTO DE DADOS REFERENTE A SERVIDORES */

char cod[MAX][255]; // obrigatoria
char nome_serv[MAX][255]; // obrigatoria
char siape_serv[MAX][255];  // obrigatoria
char cpf_serv[MAX][255]; // obrigatoria

char nasci_serv[MAX][255];
char ende_serv[MAX][255];
char rg_serv[MAX][255];
char salario_serv[MAX][255];
char tipo_serv[MAX][255];

void criarServidor(char identificador[],char nome[],char siape[],char cpf[],char nasci[],char rg[],char salario[],char tipo[],char endereco[])
{
    int i,index =0;

    for( i = 0 ;  i < MAX ; i++) // Verificando indices livres
    {
        if (!(ocupados[i])) {
            index = i;
            break;
        }
    }
    strcpy(cod[index], identificador);
    //strcpy(cod[index], identificador);
    strcpy(nome_serv[index], nome);
    strcpy(siape_serv[index],siape);
    strcpy(cpf_serv[index], cpf);
    strcpy(nasci_serv[index], nasci);
    strcpy(rg_serv[index], rg);
    strcpy(salario_serv[index], salario);
    strcpy(tipo_serv[index], tipo);
    strcpy(ende_serv[index],endereco);
    ocupados[index] = 1;

}

void atualizarServidor(char entrada[255],char nome[255],char siape[255],char cpf[255],char nasci[255],char rg[255],char salario[255],char tipo[255],char endereco[255])
{
    int  i,index = 0;

    for( i = 0; i < MAX ; i++)
    {
        if(!strncmp(entrada,cod[i],3))
        {
            index = i;
            break;
        }
    }
    // entrada de valores nos vetores globais.
    //strcpy(cod[index], identificador);
    strcpy(nome_serv[index], nome);
    strcpy(siape_serv[index],siape);
    strcpy(cpf_serv[index], cpf);
    strcpy(nasci_serv[index], nasci);
    strcpy(rg_serv[index], rg);
    strcpy(salario_serv[index], salario);
    strcpy(tipo_serv[index], tipo);
    strcpy(ende_serv[index],endereco);
    /*Ocupados já é 1*/

}
void deletarServidor(char entrada[])
{
    int i;
    char input[255];

    for(i = 0 ; i<MAX ; ++i)
    {
        itoa(ocupados[i],input,10);
        if(!strcmp(input,entrada))
            ocupados[i] = 0;
    }

}

void listarServer(int op)
{
    // criar os panoramas pedidos no projeto do professor
    // ou printa todos ou um caso específico
    int i;
    char codigoServidorInformado[255];

    switch (op) {

        case 1: // printar tecnicos

            cabecalho();

            for (i = 0; i < MAX; i++)
            {
                if (!strncmp(tipo_serv[i], "tecnicos", 5))
                {
                    printar_campos(i);
                }
            }
            break;

        case 2: // printar professor

            cabecalho();

            for(i = 0; i< MAX; i++)
            {
                if(!strncmp(tipo_serv[i],"professor",5))
                {
                    printar_campos(i);
                }
            }break;

        case 3: // printar todos

            cabecalho();
            for(i = 0; i < MAX ; i++)
            {
                if(ocupados[i])
                {
                    printar_campos(i);
                }
            }break;

        case 4: // printar por cod

            do {

                printf("Digite o cod do servidor : \n");
                scanf("%s", &codigoServidorInformado);


            }while(checarCodigos(codigoServidorInformado));

            if(!strcmp(codigoServidorInformado,"0")) break;

            cabecalho();

            for(i = 0 ; i < MAX ; i++)
            {
                if(ocupados[i])
                    {
                        if(!strcmp(codigoServidorInformado,cod[i]))
                        {
                            printar_campos(i);
                        }
                    }
            }break;

        default:
            printf("Essa opção não existe \n");
            break;
    }
}


int printar_campos(int index) {

    // imprimir o campo nome em ordem alfabetica
    // tenho que pegar o nome e julgar com base nos proximos valores
    // vou supor que a primeira palavra é a menor valor ordem alfabetica

    int i;

    for(i = 0 ; i < MAX ; ++i) {

        if (ocupados[i]) {
            printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n", cod[index], nome_serv[index], siape_serv[index],
                   cpf_serv[index], nasci_serv[index], rg_serv[index], salario_serv[index], tipo_serv[index],
                   ende_serv[index]);
        }
    }
    /*
     *
    strcpy(menor, nome_serv[0]); // supondo que esse seja o menor
    função para printar em ordem alfabetica tem que ser feita a parte
    for( i = 1; i < MAX ; ++i)
    {
        if(ocupados[i])
        {
            printf("%s\t%s\t%s\t%s\t\t%s\t%s\t%s\t%s\t%s\n",cod[index],nome_serv[index],siape_serv[index], cpf_serv[index],nasci_serv[index], rg_serv[index], salario_serv[index], tipo_serv[index], ende_serv[index]);
            if(strncmp(menor,nome_serv[i],3) > 0)
            {
                strcpy(menor,nome_serv[i]);// se a condição for sastifeita menor recebe outro valor

            }

        }
    }
     */


    return 0;
}
int existe_cod(char codigo[])
{
    int i;

    if(!strcmp(codigo,"0")) return 0 ;

    for( i = 0 ; i < MAX ; ++i)
    {
        if(!strcmp(codigo,cod[i])) return 1;
    }
    return 0;
}

int checaEntrada(char codigo[],char nome[], char siape[],char cpf[])
{
    int input1,input2,input3,input4;

    input1 = strcmp(codigo,"\n");
    input2 = strcmp(siape,"\n");
    input3 = strcmp(cpf,"\n");
    input4 = strcmp(nome,"\n");

    // se algum for igual a um enter == "\n" ele vai ter valor zero e tornar verdadeira a condição
    if(!(input1 && input2 && input3 && input4)) {

        printf("Digite Valores validos para entrada\n");
        return 1;

    }else return 0;
}
void cabecalho()
{
    printf("\nCod\tNome\tSiape\tCpf\t\tNascimento\tRg\t\tSalario\tTipo\t\tEndereco\n\n");
}