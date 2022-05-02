#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "veiculo.h"
#include "servidor.h"

/*ÁREA DE PROCESSAMENTO DE DADOS REFERENTE A SERVIDORES */

int ocupados[MAX];

char cod[MAX][255]; // obrigatoria
char nome_serv[MAX][255]; // obrigatoria
char siape_serv[MAX][255];  // obrigatoria
char cpf_serv[MAX][255]; // obrigatoria

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
        if ( !(ocupados[i]) )
        {
            if( !i ) continue; // não quero cadastrar no indice 0
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
    int index = existe_cod(entrada);

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
}

void deletarServidor(char entrada[])
{
    entrada[strcspn(entrada,"\n")] = 0;
    int indice = existe_cod(entrada);
    int valor_posicao = ocupados[indice];

    if( indice && valor_posicao )
    {
        ocupados[indice] = 0;
        printf("\n##DELETADO##\n");
    }else {
        printf("\nDigite um codigo de servidor valido!\n");
    }
}

void menu_listar_server(int op)
{
    switch (op) {

        case 1: // printar tecnicos em ordem
            ordenando(op);
            break;

        case 2: // printar professor em ordem
            ordenando(op);
            break;

        case 3: // printar todos em ordem
            ordenando(op);
            break;

        case 4: // printar por cod
            print_serv_cod();
            break;

        default:
            printf("\n#Essa opcao nao existe !!#\n#Tente Novamente# \n");
            break;
    }
    return ;
}

void print_serv_cod()
{
    int control = 0;
    int  indice[255];
    char codigoServidor[255];

    do {
        printf("Digite o cod do servidor\n:");
        fflush(stdin);
        fgets(codigoServidor,255,stdin);
        codigoServidor[strcspn(codigoServidor,"\n")] = 0;
        control++;

        if(control == 2){
            printf("\n#Quantia de tentativas excedidas retornando para menu#\n");
            return;
        }
    }while( !existe_cod(codigoServidor) );

    indice[0] = existe_cod(codigoServidor);
    printar_serv(indice);
}

 void printar_serv( int ordenado[])
 {
    char aux[255];
    printf("\n##################LISTANDO###################\n");
    for( int i = 0 ; i < MAX ; ++i)
    {
        if( ordenado[i] )
        {
            strcpy( aux, caixa_correcao(nome_serv[ordenado[i]] ) );
            printf("Codigo: %s\n", cod[ordenado[i]] );
            printf("Nome: %s\n", aux );
            printf("Siape: %s\n", siape_serv[ordenado[i]] );
            printf("Salario: %s\n", salario_serv[ordenado[i]] );
            printf("Nascimento: %s\n", nasci_serv[ordenado[i]] );
            printf("Cpf: %s\n", cpf_serv[ordenado[i]] );
            printf("Rg: %s\n", rg_serv[ordenado[i]] );
            printf("Tipo de Servidor: %s\n", tipo_serv[ordenado[i]] );
            printf("Endereco: %s\n\n", ende_serv[ordenado[i]] );
        }

    }
    printf("###################FIM DA LISTAGEM####################\n\n");
 }

void ordenando(int opcao)
{
    int i,j,quantia = 0;
    char copy_nome[MAX][255], aux[255];
    int ordenador[255];

    for ( i = 0;  i < MAX ; ++i )
    {
        ordenador[i] = 0;
    }

    for( i = 0 ; i < MAX ; ++i)
    {
        if(ocupados[i]) strcpy(copy_nome[i],nome_serv[i]);
        else strcpy(copy_nome[i],"~");
    }

    for( i = 0 ; i < MAX; ++i)
    {
        for( j = 0 ; j < (MAX - i - 1) ; ++j)
        {
            if( (tolower(copy_nome[j][0]) > tolower(copy_nome[j+1][0]) ) || ( (tolower(copy_nome[j][0]) == tolower(copy_nome[j+1][0])) && (tolower(copy_nome[j][1]) > tolower(copy_nome[j+1][1])) ) )
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
                        ordenador[i] = j;
                        quantia++;
                    }
                }
            }
            verificador_quantia(quantia,ordenador);
            break;
        case 2: // professores

            for( i = 0 ; i < MAX ; ++i)
            {
                for( j = 0 ; j < (MAX - i - 1) ; ++j)
                {
                    if( !strcmp(nome_serv[j],copy_nome[i]) && !strcmp("Professor",tipo_serv[j]))
                    {
                        ordenador[i] = j;
                        quantia++;
                    }
                }
            }
            verificador_quantia(quantia,ordenador);
            break;
        case 3: // ordenando todos os valores

            for(i = 0 ; i < MAX ; ++i)
            {
                for(j = 0 ; j < MAX ; ++j)
                {
                    if(!strcmp(nome_serv[j],copy_nome[i]))
                    {
                        ordenador[i] = j;
                        quantia++;
                    }
                }
            }
            verificador_quantia(quantia,ordenador);
            break;

        default:
            break;
    }
}

int existe_cod(char codigo[])
{
    for(int i = 0 ; i < MAX ; ++i)
    {
        if(!strcmp(cod[i],codigo)) return i;
    }
    return 0; // o cod não existe no vetor
}

int checa_repeti(char codigo[],char nome[], char siape[],char cpf[], char iden[] )
{
    int teste, indice = existe_cod(codigo);

    codigo[strcspn(codigo,"\n")] = 0; // não pode repetir
    nome[strcspn(nome, "\n")] = 0;
    siape[strcspn(siape,"\n")] = 0; // não pode repetir
    cpf[strcspn(cpf,"\n")] = 0; // não pode repetir
    iden[strcspn(iden,"\n")] = 0;

    for (int i = 1; i < MAX; ++i) {

        if( ocupados[i] && ( i != indice ) )
        {
            if(!strcmp(iden,"1")){   // aqui ele trata o cod
                teste = ( (strcmp(cod[i], codigo) && strcmp(siape_serv[i], siape)) && strcmp(cpf_serv[i], cpf) );
            }
            else{   // aqui ele nao trata o cod
                teste = ( strcmp(siape_serv[i], siape) && strcmp(cpf_serv[i], cpf) );
            }

            if (!teste){
                printf("\nAlguns dos dados estao repetidos\nTente Novamente\n\n");
                return 1;
            }
        }
    }
   return 0;
}

int checa_branco(char codigo[],char nome[], char siape[],char cpf[], char indentificador[])
{
    int input1,input2,input3,input4;

    input1 = strcmp(codigo,"\n"); // nao pode ficar em branco
    input2 = strcmp(siape,"\n"); // nao pode ficar em branco
    input3 = strcmp(cpf,"\n"); // nao pode ficar em branco
    input4 = strcmp(nome,"\n"); // não pode ficar em branco

    if( !(input1 && input2 && input3 && input4) ) {
        printf("\nDigite Valores validos para entrada\nNao digite espacos\n\n");
        return 1;

    }else return checa_repeti(codigo,nome,siape,cpf,indentificador);
}

int  type_serv()
{
    int opcao;

    do {
        printf("Digite a categoria do Servidor : \n1-Professor  2-Tecnico\n:");
        scanf("%d", &opcao);
        fflush(stdin);

        if (opcao == 1) return 1; // professor
        else if (opcao == 2) return 2; // Tecnico
        else printf("\nDigite um valor valido para o servidor\n");

    }while( opcao != 1 && opcao !=2 );

    return opcao;
}

void verificador_quantia(int quantia, int ordenador[])
{
    if (!quantia) printf("\nSem registros!!\nCadastre um novo Servidor!!\n");
    else printar_serv(ordenador);
}

int checarCodigos(char temp_cod[])
{
    for (int i = 0; i < MAX; ++i)
    {
        if(!strcmp(temp_cod, codigos_v[i])) {
            return 1;
        }
    }
    return 0;
}

void iniciar_ocupados()
{
    for(int i = 0; i < MAX; i++)
    {
        ocupados[i] = 0;
    }
}

char *caixa_correcao(char nome[])
{
    for(int i = 0 ; i < 255 ; ++i)
    {
        nome[0] = toupper(nome[0]);
        if(nome[i] == ' ') {nome[i+1] = toupper(nome[i+1]);}
    }
    return nome;
}

int checar_cheio_servidores(){
    int count = 0;
    for(int i = 0; i < MAX; i++) {
        if(ocupados[i]) {
            count++;
        }
    }
    return count;
}