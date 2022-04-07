//
// Created by Pedro and Tiago on 05/04/2022.
//

#include <stdio.h>
#include <string.h>
#include "servidor.c"
#include "veiculo.c"

int main()
{

    int input = 2929;
    int sec_input = 2929;

    while(input)
    {
        printf("\n");
        printf("  ___  ___  ___  ___   ___   _    ___  _  __ ___  _  _   ___ \n");
        printf(" |_ _|| __|/ __|| __| | _ \\ /_\\  | _ \\| |/ /|_ _|| \\| | / __|\n");
        printf("  | | | _|| (__ | _|  |  _// _ \\ |   /| ' <  | | | .` || (_ |\n");
        printf(" |___||_|  \\___||___| |_| /_/ \\_\\|_|_\\|_|\\_\\|___||_|\\_| \\___|\n\n");

        printf("Area de Servidores: \n")
        printf("1. Registrar servidor.\n");
        printf("2. Atualizar servidor.\n");
        printf("3. Deletar servidor.\n");
        printf("4. Listar servidores.\n\n");

        printf("Area de Veiculos: \n")
        printf("5. Registrar veiculo.\n");
        printf("6. Atualizar veiculo\n");
        printf("7. Deletar veiculo.\n");
        printf("8. Listar veiculos.\n\n");
        printf("0. Sair do programa.\n\n");
        printf("Input: ");

        scanf("%d", &input);

        switch(input)
        {
            case 0:
                printf("Good bye!!");
                return 0;
            case 1:
                printf("Digite o nome do servidor: ");
                //criarServidor();
                break;
            case 2:
                printf("Digite o codigo do servidor: ");
                //atualizarServidor();
                break;
            case 3:
                printf("Digite o codigo do servidor: ");
                //deletarServidor();
                break;
            case 4:
                //listarServidor();
                break;
            case 5:
                //inserir_veiculo();
                break;
            case 6:
                //inserir_veiculo();
                break;
            case 7:
                //excluir_veiculo();
                break;
            case 8:
                //listar_veiculo();
            /*case 7:
                printf("\n1. Listar Servidor. \n");
                printf("2. Listar Carros. \n");

                scanf("%d", &sec_input);

                switch (sec_input) // se digitar algum valor fora dos case cai no while.
                {
                    case 1:
                        //imprimir dados de um servidor em específico
                        //imprimir todos os servidores
                        // imprimir servidor E prof E Tec pela ordem alfabetica
                        break;

                    case 2:
                        // imprimir dados de um veiculo de um cod especifico
                        // imprimir todos os veiculos de um servidor
                        // imprimir todos os veiculos de um servidor por ordem alfabetica
                        break;
                }

                break;*/
        }
    }

    return 0;
}

