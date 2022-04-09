//
// Created by Pedro and Tiago on 05/04/2022.
//

#include <stdio.h>
#include "servidor.c"
#include "servidor.h"
#include "veiculo.h"
#include "veiculo.c"

void limparBuffer(char cod[]);

int ind;
char codigo[255], modelo [255], descricao[255], placa[255], marca[255];
char entrada[255];
int op;


int main()
{
    iniciarVeiculo();

    int input = 2929;

    printf("\n");
    printf("  ___  ___  ___  ___   ___   _    ___  _  __ ___  _  _   ___ \n");
    printf(" |_ _|| __|/ __|| __| | _ \\ /_\\  | _ \\| |/ /|_ _|| \\| | / __|\n");
    printf("  | | | _|| (__ | _|  |  _// _ \\ |   /| ' <  | | | .` || (_ |\n");
    printf(" |___||_|  \\___||___| |_| /_/ \\_\\|_|_\\|_|\\_\\|___||_|\\_| \\___|\n\n");

    while(input)
    {
        printf("Area de Servidores: \n");
        printf("1. Registrar servidor.\n");
        printf("2. Atualizar servidor.\n");
        printf("3. Deletar servidor.\n");
        printf("4. Listar servidores.\n\n");

        printf("Area de Veiculos: \n");
        printf("5. Registrar veiculo.\n");
        printf("6. Atualizar veiculo\n");
        printf("7. Deletar veiculo.\n");
        printf("8. Listar veiculos.\n\n");

        printf("0. Sair do programa.\n\n");

        printf("Opcao: ");
        scanf("%d%*c", &input);

        printf("\n");

        switch(input)
        {
            case 0:

                printf("Encerrando o programa...");
                return 0;

            case 1: // criar servidor

                criarServidor();
                break;

            case 2:// atualizar servidor

                printf("Digite o cod do servidor :");
                scanf("%s",&entrada);

                atualizarServidor(entrada);
                break;

            case 3: // deletar servidor

                printf("Digite o codigo do servidor: ");
                scanf("%s", &entrada);
                deletarServidor(entrada);
                break;

            case 4: // printar servidor

                printf("Digite a forma como deseja printar os servidores\n\n");
                printf("1. Printar apenas os Tecnicos \n");
                printf("2. Printar apenas os professores \n");
                printf("3. Printar Todos \n");
                printf("4.Printar um servidor pelo cod dele.\n");

                scanf("%d",&op);

                listarServer(op);

                break;
            case 5:
                printf("Insira o codigo do veiculo: ");
                fgets(codigo, 255, stdin);

                codigo[strcspn(codigo, "\n")] = 0;

                while(checarCodigos(codigo))
                {
                    printf("Esse codigo ja existe, insira outro: ");
                    fgets(codigo, 255, stdin);
                    codigo[strcspn(codigo, "\n")] = 0;
                }

                printf("Insira o modelo: ");
                fgets(modelo, 255, stdin);
                printf("Insira a descricao: ");
                fgets(descricao, 255, stdin);
                printf("Insira a placa: ");
                fgets(placa, 255, stdin);
                printf("Insira a marca: ");
                fgets(marca, 255, stdin);

                //codigo[strcspn(codigo, "\n")] = 0;
                modelo[strcspn(modelo, "\n")] = 0;
                descricao[strcspn(descricao, "\n")] = 0;
                placa[strcspn(placa, "\n")] = 0;
                marca[strcspn(marca, "\n")] = 0;

                inserirVeiculo(codigo, modelo, descricao, placa, marca);
                printf("\n");
                break;
            case 6:
                printf("Insira o indice: ");
                scanf("%d%*c", &ind);
                printf("Insira o novo codigo: ");
                fgets(codigo, 255, stdin);
                printf("Insira o novo modelo: ");
                fgets(modelo, 255, stdin);
                printf("Insira a nova descricao: ");
                fgets(descricao, 255, stdin);
                printf("Insira a nova placa: ");
                fgets(placa, 7, stdin);
                printf("Insira a nova marca: ");
                fgets(marca, 255, stdin);

                codigo[strcspn(codigo, "\n")] = 0;
                modelo[strcspn(modelo, "\n")] = 0;
                descricao[strcspn(descricao, "\n")] = 0;
                placa[strcspn(placa, "\n")] = 0;
                marca[strcspn(marca, "\n")] = 0;

                atualizarVeiculo(ind-1, codigo, modelo, descricao, placa, marca);

                printf("\n");

                break;
            case 7:
                printf("Insira o indice: ");
                scanf("\n%d", &ind);

                excluirVeiculo(ind-1);

                printf("\n");
                break;
            case 8:
                if (codigos[0][0])
                {
                    listarVeiculo();

                    printf("\n");
                    break;
                }
                else
                    printf("Nao existem veiculos registrados.\n\n");
                break;
            default:
                printf("Essa opcao nao existe.\n");
                break;
        }
    }
    return 0;
}

/*void limparBuffer(char cod[])
{
    cod[strcspn(cod, "\n")] = 0;
    strcpy(codigo, cod);
}*/


