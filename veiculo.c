// ÁREA DE PROCESSAMENTO DE DADOS DOS VEICULOS

#include "veiculo.h"

void iniciar()
{
    for (int i = 0; i < MAX; ++i)
    {
        ocupados[i] = 0;
    }
}

void inserir_veiculo(int cod_veic, int cod_serv, char descricao[], char placa[], char marca[], char modelo[])
{
    int index = -1;

    for (int i = 0; i < MAX; ++i)
    {
        if(ocupados[i] == 0)
        {
            index = i;
            break;
        }
    }
    //cod_veic[index] = cod_veic;
    //strcpy()
}
