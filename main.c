//
// Created by pedro and tiago on 05/04/2022.
//

//Oi Pedro :)
//Olá Tiago ! :D

#include <stdio.h>
#include <string.h>

#define MAX

// Dados dos servidores
int codigos_servidores[MAX];
char nomes_servidores[MAX][255];
int siape_servidores[MAX];
int rg_servidores[MAX];
int cpf_servidores[MAX];
char endereço_servidores[MAX][255];
int salario_servidores[MAX];
int nascimento_servidores[MAX];
char tipo_servidores[MAX][255];

//Dados dos carros
int codigos_veiculos[MAX];
char descrição_veiculos[MAX][255];
char placa_veiculos[MAX][255];
char marca_veiculos[MAX][255];
char modelo_veiculos[MAX][255];

void criarServidor(int[], char[][], int[], int[], int[], char[][], int[], int[], char[][]);
void atualizarServidor(int[], char[][], int[], int[], int[], char[][], int[], int[], char[][]);
void deletarCarro(int[], char[][], int[], int[], int[], char[][], int[], int[], char[][]);

void criarCarro(int[], char[][], char[][], char[][], char[][]);
void atualizarCarro(int[], char[][], char[][], char[][], char[][]);
void deletarCarro(int);

//Listar tudo
char listarDados(int);

int main()
{
    printf("Ola Mundo!!");

    return 0;
}

