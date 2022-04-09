#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "servidor.h"
#include "veiculo.h"

/*ÁREA DE PROCESSAMENTO DE DADOS REFERENTE A SERVIDORES */

void cadastro(int index)
{
    /*
     * função que irá ficando cadastrando e inserindo atualizações
     * */
    printf("Digite o Codigo do Servidor : \n:");
    scanf("%d",&cod[index]);
    printf("Digite o Nome do Servidor : \n:");
    scanf("%s",&nome_serv[index]);
    printf("Digite o Siape do Servidor : \n:");
    scanf("%s",&siape[index]);
    printf("Digite o Cpf do Servidor : \n:");
    scanf("%s",&cpf[index]);

    // termino das obrigações

    /*printf("\nDeseja adicionar os campos nao obrigatorios ? [Y/N]\n");
    fgets(&n_obri,2,stdin);*/

    printf("Digite a data de nascimento do Servidor : \n:");
    scanf("%s",&nascimento[index]);
    printf("Digite o Rg do Servidor : \n:");
    scanf("%s",&rg_serv[index]);
    printf("Digite o salario do servidor : \n:");
    scanf("%s",&salario[index]);
    printf("Digite a categoria do Servidor : \nProfessor ou Tecnico\n:");
    scanf("%s",&tipo_serv[index]);

    printf("Digite o endereco do Servidor : \n:"); // usar a ideia da concatenação ?
    scanf("%s",&ende_serv[index]);
    ocupados[index] = 1;
}

void criarServidor()
{
    int i,index = 0; // index vai funcionar como cod do dado

    for( i = 0 ;  i < MAX ; i++) // Verificando indices livres
    {
        if(!(ocupados[i]))
        {
            index = i;
            break;
        }
    }
        cadastro(index);

}
void atualizarServidor(char input[]) //
{
    int  i,index = 0;
    int cod_fornecido = atoi(input);

    for( i = 0; i < MAX ; i++)
    {
        if(cod_fornecido == cod[i]) // essa gambiarra é tudo pra não mexer com strcmp
        {
            index = i;
            break;
        }
    }
    if(!index)
    {
        printf("Não foi possivel atualizar o dado porque ele não existe\n");
        return ;
    }
        cadastro(index);

}
void deletarServidor()
{
    return ;
}

void listarServer(int op)
{
    // criar os panoramas pedidos no projeto do professor
    // ou printa todos ou um caso específico
    int i,j;
    int codigoServidorInformado;

    switch (op) {

        case 1:
            for (i = 0; i < MAX; i++)
            {
                if (!strncmp(tipo_serv[i], "tecnicos", 5))
                {
                    printar_campos(i);
                }
            }break;

        case 2:
            for(i = 0; i< MAX; i++)
            {
                if(!strncmp(tipo_serv[i],"professor",5))
                {
                    printar_campos(i);
                }
            }break;

        case 3:
            for(i = 0; i < MAX ; i++)
            {
                printar_campos(i);
            }break;

        case 4:

            for(i = 0 ; i < MAX ; i++)
            {
                printf("Digite o cod do servidor : \n");
                scanf("%d",&codigoServidorInformado);

                for( j = 0 ; j < MAX ; j++)
                {
                    if(codigoServidorInformado == cod[j])
                    {
                        printar_campos(j);

                    }else printf("O capo Informado não existe \n");
                }
            }break;

        default:
            printf("Essa opção não existe \n");
            break;
    }
}


int printar_campos(int index)
{
    printf("COD\tNome\tSiape\tCpf\tNascimento\tEndereco\tRg\tSalario\tTipo\n");
    printf("%d\t %s\t%s \t%s \t%s \t%s \t%s \t%s \t%s\n", cod[index], nome_serv[index], siape[index], cpf[index],nascimento[index], ende_serv[index], rg_serv[index], salario[index], tipo_serv[index]);
    return 0;
}