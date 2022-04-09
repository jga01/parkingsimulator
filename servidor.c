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
    printf("\nDigite o Codigo do Servidor : \n");
    scanf("%d",&cod);
    printf("Digite o Nome do Servidor : \n");
    fgets(nome_serv[index],255,stdin);
    printf("Digite o Siape do Servidor : \n");
    fgets(&siape[index],10,stdin);
    printf("Digite o Cpf do Servidor : \n");
    fgets(&cpf[index],20,stdin);

    // termino das obrigações

    /*printf("\nDeseja adicionar os campos nao obrigatorios ? [Y/N]\n");
    fgets(&n_obri,2,stdin);*/

    printf("Digite a data de nascimento do Servidor : \n");
    fgets(&nascimento[index],255,stdin);
    printf("Digite o endereco do Servidor : \n");
    fgets(ende_serv[index],255,stdin);
    printf("Digite o Rg do Servidor : \n");
    fgets(&rg_serv[index],50,stdin);
    printf("Digite o salario do servidor : \n");
    fgets(&salario[index],15,stdin);
    printf("Digite a categoria do Servidor : \nProfessor ou Tecnico\n");
    fgets(tipo_serv[index],255,stdin);

    ocupados[index] = 1;
}

void criarServidor()
{
    int i,index = 0; // index vai funcionar como cod do dado

    for( i = 0 ;  i < MAX ; i++)
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

void listarServe(char op[])
{
    // criar os panoramas pedidos no projeto do professor
    // ou printa todos ou um caso específico
    int i;

    for(i = 0 ; i < MAX ; i++) {

        if (ocupados[i] == 1)
        {
            if(strcmp(op,"1")){// printar os Tecnicos

                if(!strcmp(tipo_serv[i],"tecnicos"));
                printar_campos(i);
            }
            else if(strcmp(op,"2")){// printar os Professores

                if(!strcmp(tipo_serv[i],"professor")){
                    printar_campos(i);
                }
            }
            else{
                printar_campos(i);
            }
        }
    }
    return ;
}
void printar_campos(int index){
    printf("%d\t %s\t %s\t %s\t %s\t %s\t %s\t %s\t %s\t \n", cod[index], nome_serv[index], siape[index], cpf[index],
           nascimento[index], ende_serv[index], rg_serv[index], salario[index], tipo_serv[index]);
}