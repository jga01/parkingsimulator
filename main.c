//
// Created by pedro and tiago on 05/04/2022.
//

//Oi Pedro :)
//Olá Tiago ! :D

#include <stdio.h>
#include <string.h>

#define MAX 100

// Dados dos servidores
char flag_serv; // variável para indicar ocupação de um espaço na memoria // 1 - ocupado 0 - livre
int codigos_servidores[MAX];
char nomes_servidores[MAX][255];
int siape_servidores[MAX];
int cpf_serv[MAX];
int nascimento_servidores[MAX];
int rg_servidores[MAX];
char endereco_servidores[MAX][255];
int salario_servidores[MAX];
char tipo_servidores[MAX][255];

//Dados dos carros
int codigos_veiculos[MAX];
char descricao_veiculos[MAX][255];
char placa_veiculos[MAX][255];
char marca_veiculos[MAX][255];
char modelo_veiculos[MAX][255];

void criarServidor(int[], char[][255], int[], int[], int[], char[][255], int[], int[], char[][255]);
void atualizarServidor(int[], char[][255], int[], int[], int[], char[][255], int[], int[], char[][255]);
void deletarServidor(int);

void criarCarro(int[], char[][255], char[][255], char[][255], char[][255]);
void atualizarCarro(int[], char[][255], char[][255], char[][255], char[][255]);
void deletarCarro(int);

//Listar tudo
char listarDados(int);

int main()
{

    int input = 2929;

    while(input)
    {
        printf("\n");
        printf("  ___  ___  ___  ___   ___   _    ___  _  __ ___  _  _   ___ \n");
        printf(" |_ _|| __|/ __|| __| | _ \\ /_\\  | _ \\| |/ /|_ _|| \\| | / __|\n");
        printf("  | | | _|| (__ | _|  |  _// _ \\ |   /| ' <  | | | .` || (_ |\n");
        printf(" |___||_|  \\___||___| |_| /_/ \\_\\|_|_\\|_|\\_\\|___||_|\\_| \\___|\n\n");

        printf("1. Registrar servidor.\n");
        printf("2. Atualizar servidor.\n");
        printf("3. Deletar servidor.\n");
        printf("4. Registrar veiculo.\n");
        printf("5. Atualizar veiculo\n");
        printf("6. Deletar veiculo.\n");
        printf("7. Listar\n");
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
                break;
            case 2:
                printf("Digite o codigo do servidor: ");
                break;
            case 3:
                printf("Digite o codigo do servidor: ");
                break;
            case 4:
                printf("Digite o nome do carro: ");
                break;
            case 5:
                printf("Digite o codigo do carro: ");
                break;
            case 6:
                printf("Digite o codigo do carro: ");
                break;
            case 7:
                break;
            // tem que haver um default para caso eu digite 8
        }
    }

    return 0;
}

