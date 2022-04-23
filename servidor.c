#include <stdio.h>
#include <string.h>
#include "servidor.h"
#include "veiculo.h"

/*ÁREA DE PROCESSAMENTO DE DADOS REFERENTE A SERVIDORES */

char cod[MAX][255]; // obrigatoria
char nome_serv[MAX][255]; // obrigatoria
char siape_serv[MAX][255];  // obrigatoria
char cpf_serv[MAX][255]; // obrigatoria

int ordenador_geral[255]; // print para todos os campos
int ordenador_professor[255]; // print para professor
int ordenador_tecnico[255]; // print para tecnicos

char nasci_serv[MAX][255];
char ende_serv[MAX][255];
char rg_serv[MAX][255];
char salario_serv[MAX][255];
char tipo_serv[MAX][255];

void criarServidor(char entrada[],char nome[],char siape[],char cpf[],char nasci[],char rg[],char salario[],char tipo[],char endereco[])
{
    int i,index = 0;

    for( i = 0 ;  i < MAX ; i++) // Verificando indices livres
    {
        if ( !(ocupados[i]))
        {
            if( i == 0 ) continue; // não quero cadastrar no indice 0

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
    int i,opcao = 0;
    char codigoServidorInformado[255];

    switch (op) {

        case 1: // printar tecnicos

            cabecalho();
            opcao = 1;
            ordenando(opcao);
            break;

        case 2: // printar professor

            cabecalho();
            opcao = 2;
            ordenando(opcao);
            break;

        case 3: // printar todos // printar em ordem

            cabecalho();
            opcao = 3;
            ordenando(opcao);
            break;

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
                            print_cod(i);
                        }
                    }
            }break;

        default:
            printf("Essa opção não existe \n");
            break;
    }
}

void print_cod(int index)
{
    printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t\t%s \t%s\n", cod[index], nome_serv[index], siape_serv[index],
                   cpf_serv[index], nasci_serv[index], rg_serv[index], salario_serv[index], tipo_serv[index],
                   ende_serv[index]);
}

void printar_all(vezes)
{
    int i;

    for(i = 0 ; i < vezes; ++i)
    {
        if( ordenador_geral[i] )
        {
            printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t\t%s \t%s\n",
                   cod[ordenador_geral[i]], nome_serv[ordenador_geral[i]],
                   siape_serv[ordenador_geral[i]],
                   cpf_serv[ordenador_geral[i]], nasci_serv[ordenador_geral[i]],
                   rg_serv[ordenador_geral[i]], salario_serv[ordenador_geral[i]],
                   tipo_serv[ordenador_geral[i]],ende_serv[ordenador_geral[i]]);
        }
    }
}

void printar_tec()
{
    int i;

    for(i = 0 ; i < MAX; ++i)
    {
        if( ordenador_tecnico[i] )
        {
            printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t\t%s \t%s\n",
                   cod[ordenador_tecnico[i]], nome_serv[ordenador_tecnico[i]],
                   siape_serv[ordenador_tecnico[i]],
                   cpf_serv[ordenador_tecnico[i]], nasci_serv[ordenador_tecnico[i]],
                   rg_serv[ordenador_tecnico[i]], salario_serv[ordenador_tecnico[i]],
                   tipo_serv[ordenador_tecnico[i]],ende_serv[ordenador_tecnico[i]]);
        }
    }
}

void printar_prof()
{
    int i;
    for(i = 0 ; i < MAX; ++i)
    {
        if( ordenador_professor[i] )
        {
            printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t\t%s \t%s\n",
                   cod[ordenador_professor[i]], nome_serv[ordenador_professor[i]],
                   siape_serv[ordenador_professor[i]],
                   cpf_serv[ordenador_professor[i]], nasci_serv[ordenador_professor[i]],
                   rg_serv[ordenador_professor[i]], salario_serv[ordenador_professor[i]],
                   tipo_serv[ordenador_professor[i]],ende_serv[ordenador_professor[i]]);
        }
    }
}

void ordenando(int opcao)
{
    int i,j,quantia = 0;
    char copy_nome[MAX][255], aux[255];

    iniciar_ordenados();

    for( i = 0 ; i < MAX ; ++i) // setando valores como zero para nao printar por cima
    {
        if(ocupados[i])
        {
            strcpy(copy_nome[i],nome_serv[i]); // inserir um low case aqui

        }else strcpy(copy_nome[i],"~");
    }

    // ordenando o vetor copy_nome com o método bubble sort

    for( i = 0 ; i < MAX; ++i)
    {
        for( j = 0 ; j < (MAX - i - 1) ; ++j)
        {
            if(  strcmp( copy_nome[j], copy_nome[j+1]) > 0 ) // troca o pedro pelo \0 ??
            {
                strcpy(aux,copy_nome[j]);
                strcpy(copy_nome[j],copy_nome[j+1]);
                strcpy(copy_nome[j+1],aux);
            }
        }
    }

    switch (opcao) {

        case 1: // tecnicos

            for( i = 0 ; i < MAX ; ++i)
            {
                for( j = 0 ; j < (MAX - i - 1) ; ++j)
                {
                    if( !strcmp(nome_serv[j],copy_nome[i]) && !strcmp("Tecnico",tipo_serv[j]))
                    {
                        ordenador_tecnico[i] = j;
                    }

                }
            }
            printar_tec();

            break;

        case 2: // professores

            for( i = 0 ; i < MAX ; ++i)
            {
                for( j = 0 ; j < (MAX - i - 1) ; ++j)
                {
                    if( !strcmp(nome_serv[j],copy_nome[i]) && !strcmp("Professor",tipo_serv[j]))
                    {
                        ordenador_professor[i] = j;
                    }
                }
            }
            printar_prof();
            break;

        case 3: // ordenando todos os valores

            for(i = 0 ; i < MAX ; ++i)
            {
                for(j = 0 ; j < (MAX - i - 1) ; ++j)
                {
                    if(!strcmp(nome_serv[j],copy_nome[i]))
                    {
                        ordenador_geral[i] = j;
                        quantia++;
                    }

                }
            }
            printar_all(quantia);
            break;

        default:
            // Erro interpretado, logo não vai rodar nada
            break;
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

void iniciar_ordenados()
{
    int i;
    for(i = 0 ; i < MAX ; ++i)
    {
        ordenador_geral[i] = 0;
        ordenador_professor[i] = 0;
        ordenador_tecnico[i] = 0;
    }
}

int  type_serv()
{
    int opcao;

    do {
        printf("Digite a categoria do Servidor : \n1-Professor\n2-Tecnico\n:");
        scanf("%d", &opcao);

        if (opcao == 1) {
            return 1; // professor

        } else if (opcao == 2) {
            return 2; // Tecnico

        } else {
            printf("\nDigite um valor valido para o servidor\n");
        }

    }while( opcao != 1 && opcao !=2 );

    return opcao;
}