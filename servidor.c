#include <stdio.h>
#include <string.h>
#include "servidor.h"
#include "veiculo.h" // para chamar a variavel ocupado

/*ÁREA DE PROCESSAMENTO DE DADOS REFERENTE A SERVIDORES */

void criarServidor()
{
    /*função com o objetivo de cadastrar novos funcionários no programa
     *
     * flag igual a 0 é vazio e 1 ocupado
     * siape é um numero de 7 digitos
     *
     * */

    int index = -7; // index vai funcionar como cod do dado
    int quantia_campos = 9;
    int i,j;
    char resp,n_obri;

    /*
    do {

        for( i = 0 ;  i < MAX ; i++)
        {
            if(ocupados[i] == 0)
            {
                index = i;
                break;
            }
        }

        printf("\nDigite o Codigo do Servidor : \n");
        scanf("%d\n", &cod[index]);
        printf("Digite o Nome do Servidor : \n");
        scanf("%s\n", &nome_serv[index]);
        printf("Digite o Siape do Servidor : \n");
        scanf("%d\n", &siape[index]);
        printf("Digite o Cpf do Servidor : \n");
        scanf("%d\n", &cpf[index]);

        // termino das obrigações
        printf("\nDeseja adicionar os campos nao obrigatorios ? [Y/N]\n");
        scanf("%d\n",&n_obri);

        if(n_obri == "N" || n_obri == "n") break;

        printf("Digite a data de nascimento do Servidor : \n");
        scanf("%s\n", &nascimento[index]);
        printf("Digite o endereco do Servidor : \n");
        scanf("%s\n", &end_serv[index]);
        printf("Digite o Rg do Servidor : \n");
        scanf("%d\n", &rg_serv[index]);
        printf("Digite o salario do servidor : \n");
        scanf("%d\n", &salario[index]);
        printf("Digite a categoria do Servidor : \nProfessor ou Tecnico\n");
        scanf("%s\n", &tipo_serv[index]);

        ocupados[index] = 1;

        printf("\nDeseja adicionar mais um cadastro ? [Y/N]\n");
        scanf("%c",&resp);

    }while(resp);
*/
    return ;
}
void atualizarServidor(int cod[], char nome_serv[][255], int siape[], int cpf[], int nascimento[], char ende_serv[][255], int rg_serv[], int salario[], char tipo_serv[][255])
{
    return ;
}
void deletarServidor(int cod[])
{
    return ;
}

int veri_duplic(char first,char second)
{
    return 0;
}
void listarServe()
{
    int i;

    for(i = 0 ; i < MAX ; i++) {

        if (ocupados[i] == 1)
        {
            printf("%d\t %s\t %d\t %d\t %d\t %s\t %d\t %d\t %s\t \n", cod[i], nome_serv[i], siape[i], cpf[i],
                   nascimento[i], end_serv[i], rg_serv[i], salario[i], tipo_serv[i]);
        }
    }
    return ;
}