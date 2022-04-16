#include <stdio.h>
#include <string.h>
#include "servidor.h"
#include "veiculo.h"

/*ÁREA DE PROCESSAMENTO DE DADOS REFERENTE A SERVIDORES */

char cod[MAX][255]; // obrigatoria
char nome_serv[MAX][255]; // obrigatoria
char siape_serv[MAX][255];  // obrigatoria
char cpf_serv[MAX][255]; // obrigatoria

int ordenador[255];
char nasci_serv[MAX][255];
char ende_serv[MAX][255];
char rg_serv[MAX][255];
char salario_serv[MAX][255];
char tipo_serv[MAX][255];

void criarServidor(char entrada[],char nome[],char siape[],char cpf[],char nasci[],char rg[],char salario[],char tipo[],char endereco[])
{
    int i,index =0;

    for( i = 0 ;  i < MAX ; i++) // Verificando indices livres
    {
        if (!(ocupados[i]))
        {
            index = i;
            break;
        }
    }

    entrada[strcspn(entrada,"\n")] = 0;
    nome[strcspn(nome, "\n")] = 0;
    siape[strcspn(siape,"\n")] = 0;
    cpf[strcspn(cpf,"\n")] = 0;
    nasci[strcspn(nasci,"\n")] = 0;
    rg[strcspn(rg, "\n")] = 0;
    salario[strcspn(salario,"\n")] = 0;
    tipo[strcspn(tipo,"\n")] = 0;
    endereco[strcspn(endereco,"\n")] = 0;

    strcpy(cod[index], entrada);
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

    nome[strcspn(nome, "\n")] = 0;
    siape[strcspn(siape,"\n")] = 0;
    cpf[strcspn(cpf,"\n")] = 0;
    nasci[strcspn(nasci,"\n")] = 0;
    rg[strcspn(rg, "\n")] = 0;
    salario[strcspn(salario,"\n")] = 0;
    tipo[strcspn(tipo,"\n")] = 0;
    endereco[strcspn(endereco,"\n")] = 0;


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

    entrada[strcspn(entrada,"\n")] = 0;
    // entrada == cod do servidor

    for(i = 0 ; i<MAX ; ++i)
    {
        if(!strcmp(cod[i],entrada))
        {
            ocupados[i] = 0;
            printf("\nDELETADO\n");
        }
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

                if (!strncmp(tipo_serv[i], "tecnico", 5))
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
            for(i= 0 ; i < MAX ; ++i)
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

    int i;
    ordenando();

    for(i = 0 ; i < MAX ; ++i) {

        if (ocupados[i]) {

            printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t\t%s \t%s\n", cod[ordenador[i]], nome_serv[ordenador[i]], siape_serv[ordenador[i]],
                   cpf_serv[ordenador[i]], nasci_serv[ordenador[i]], rg_serv[ordenador[i]], salario_serv[ordenador[i]], tipo_serv[ordenador[i]],
                   ende_serv[ordenador[i]]);
        }
    }

    return 0;
}
void ordenando()
{
    int i,j,aux;
    // strcmp se retornar maior que 0 == o primeiro valor é maior que o segundo
    // strcmp se retornar menor que 0 == o primeiro valor é menor que o segundo
    // strcmp se retornar igual a 0 == mesmo tamanho

    for( i = 0; i < MAX - 1 ; ++i)
    {
        for(j = 0 ; j < MAX - 1 ; ++j)
        {
            if(strcmp(nome_serv[j], nome_serv[j+1]) > 0)
            {
                 // método bubble sort
                 ordenador[j] = j+1;
                 ordenador[j+1] = j;

                /* nome_serv[i] é maior que nome_sev[j] ? se for ::
                 *
                 * auxiliar = numero[i];
                 * numero[i] = numeros[i+1];
                 * numeros[i+1] = aux;
                 *
                 * */
            }
        }
    }
}

int existe_cod(char codigo[])
{
    int i;

    for( i = 0 ; i < MAX ; ++i)
    {
        if(!strcmp(cod[i],codigo)) return 0;
    }
    return 1;
}

int checaEntrada(char codigo[],char nome[], char siape[],char cpf[], char iden[] )
{
    int input1,input2,input3,input4,i;
    int teste;

    codigo[strcspn(codigo,"\n")] = 0;
    nome[strcspn(nome, "\n")] = 0;
    siape[strcspn(siape,"\n")] = 0;
    cpf[strcspn(cpf,"\n")] = 0;
    iden[strcspn(iden,"\n")] = 0;

    input1 = strcmp(codigo,"\n"); // nao pode repetir
    input2 = strcmp(siape,"\n"); // nao pode repetir
    input3 = strcmp(cpf,"\n"); // nao pode repetir
    input4 = strcmp(nome,"\n");

    for (i = 0; i < MAX; ++i) {
        // se o teste for 1 é pq ao menos um dos valores é repetido
        //teste = (strcmp(cod[i],codigo) && strcmp(siape_serv[i],siape) && strcmp(cpf_serv[i],cpf));

        if(!strcmp(iden,"1"))
        {
            // aqui ele trata o cod
            teste = ( (!strcmp(cod[i], codigo) || !strcmp(siape_serv[i], siape)) || !strcmp(cpf_serv[i], cpf) );
        }
        else{
            // aqui ele nao trata o cod
            teste = ( !strcmp(siape_serv[i], siape) || !strcmp(cpf_serv[i], cpf) );
        }

        if (teste) // se pelo menos algum for repetido ele retorna 1 pedindo para reescrever
        {
                printf("\nAlguns dos dados estao repetidos\nTente Novamente\n\n");
                return 1;
        }
    }

    // se algum for igual a um enter == "\n" ele vai ter valor zero e tornar verdadeira a condição
    if(!(input1 && input2 && input3 && input4)) {

        printf("\nDigite Valores validos para entrada\nNao digite espacos\n\n");
        return 1;

    }else return 0;
}

void cabecalho()
{
    printf("\nCod\tNome\tSiape\tCpf\t\tNascimento\tRg\t\tSalario\t\tTipo\t\tEndereco\n\n");
}