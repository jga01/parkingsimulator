#include <stdio.h>
#include <string.h>
#include "servidor.h"
#include "veiculo.h"

int op;
char iden[255],entrada[255],nome[255],siape[255],cpf[255],nasci[255],rg[255],tipo[255],salario[255],endereco[255];


int main()
{
    iniciar_ocupados();
    iniciar_ocupados_veiculos();

    char temp_cod_s_v[256];
    char temp_cod_v[256];
    char temp_marca[256];
    char temp_mdl[256];
    char temp_placa[256];
    char temp_desc[256];

    char input = '-';

    printf("\n");
    printf("  ___  ___  ___  ___   ___   _    ___  _  __ ___  _  _   ___ \n");
    printf(" |_ _|| __|/ __|| __| | _ \\ /_\\  | _ \\| |/ /|_ _|| \\| | / __|\n");
    printf("  | | | _|| (__ | _|  |  _// _ \\ |   /| ' <  | | | .` || (_ |\n");
    printf(" |___||_|  \\___||___| |_| /_/ \\_\\|_|_\\|_|\\_\\|___||_|\\_| \\___|\n\n");

    do
    {
        printf("\n");
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
        fflush(stdin);
        scanf("%c", &input);

        printf("\n");

        switch(input)
        {
            case '0':

                printf("Encerrando o programa...");
                return 0;

            case '1': // criar servidor
                do {

                    fflush(stdin);
                    printf("Digite o codigo do Servidor : \n:");
                    fgets(entrada,255,stdin);
                    fflush(stdin);
                    printf("Digite o nome do Servidor : \n:");
                    fgets(nome,255,stdin);
                    fflush(stdin);
                    printf("Digite o siape do Servidor : \n:");
                    fgets(siape,255,stdin);
                    fflush(stdin);
                    printf("Digite o cpf do Servidor : \n:");
                    fgets(cpf,255,stdin);
                    strcpy(iden,"1");

                }while(checaEntrada(entrada,nome,siape,cpf,iden));

                fflush(stdin);
                printf("Digite a data de nascimento do Servidor : \n:");
                fgets(nasci,255,stdin);
                fflush(stdin);
                printf("Digite o rg do Servidor : \n:");
                fgets(rg,255,stdin);
                fflush(stdin);
                printf("Digite o salario do servidor : \n:");
                fgets(salario,255,stdin);
                fflush(stdin);
                printf("Digite o endereco do Servidor : \n:");
                fgets(endereco,255,stdin);

                op = type_serv();
                if(op == 1)
                    strcpy(tipo,"Professor");
                else
                    strcpy(tipo,"Tecnico");

                criarServidor(entrada,nome,siape,cpf,nasci,rg,salario,tipo,endereco);
                break;

            case '2':// atualizar servidor

                printf("Digite o COD do servidor\n:");
                scanf("%s",&entrada);
                fflush(stdin);

                while(existe_cod(entrada))
                {
                    printf("Esse cod nao faz referencia a nenhum servidor\n");
                    printf("Digite um cod valido\n:");
                    scanf("%s",&entrada);
                }

                do {
                    fflush(stdin);
                    printf("Digite o NOVO Nome do Servidor : \n:");
                    fgets(nome,255,stdin);
                    printf("Digite o NOVO Siape do Servidor : \n:");
                    fflush(stdin);
                    fgets(siape,255,stdin);
                    printf("Digite o NOVO Cpf do Servidor : \n:");
                    fflush(stdin);
                    fgets(cpf,255,stdin);
                    strcpy(iden, "2");

                }while( checaEntrada(entrada,nome,siape,cpf,iden) );

                //codigo[strcspn(codigo,"\n")] = 0;

                printf("Digite a NOVA data de nascimento do Servidor : \n:");
                fflush(stdin);
                fgets(nasci,255,stdin);
                printf("Digite o NOVO Rg do Servidor : \n:");
                fflush(stdin);
                fgets(rg,255,stdin);
                printf("Digite o NOVO salario do servidor : \n:");
                fflush(stdin);
                fgets(salario,255,stdin);
                printf("Digite o NOVO endereco do Servidor : \n:"); // usar a ideia da concatenação ?
                fflush(stdin);
                fgets(endereco,255,stdin);

                op = type_serv();
                if(op == 1)
                    strcpy(tipo,"Professor");
                else
                    strcpy(tipo,"Tecnico");

                // a diferença é que vai manter o mesmo codigo
                atualizarServidor(entrada,nome,siape,cpf,nasci,rg,salario,tipo,endereco);
                break;

            case '3': // deletar servidor

                printf("Digite o codigo do servidor: ");
                fflush(stdin);
                fgets(entrada,255,stdin);

                deletarServidor(entrada);
                break;

            case '4': // listar servidor

                printf("Digite a forma como deseja printar os servidores\n\n");
                printf("1. Printar apenas os Tecnicos \n");
                printf("2. Printar apenas os professores \n");
                printf("3. Printar Todos \n");
                printf("4.Printar um servidor pelo cod dele.\n");

                scanf("%d",&op);
                fflush(stdin);

                listarServer(op);
                break;

            case '5': //inserir veiculo
                do {
                    printf("Digite o codigo do proprietario: ");
                    fgets(temp_cod_s_v, sizeof(temp_cod_s_v), stdin);
                    if(!checar_servidor_veiculo((temp_cod_s_v)))
                        printf("Nenhum servidor com esse codigo.\n");
                } while(!checar_servidor_veiculo(temp_cod_s_v));
                do {
                    printf("Digite o codigo do veiculo: ");
                    fgets(temp_cod_v, sizeof(temp_cod_v), stdin);
                    if(checar_codigo_veiculo(temp_cod_v))
                        printf("Esse codigo esta em uso!\n");
                } while(checar_codigo_veiculo((temp_cod_v)));
                do {
                    printf("Digite a descricao do veiculo: ");
                    fgets(temp_desc, sizeof(temp_desc), stdin);
                    if(checar_descricao_veiculo(temp_desc))
                        printf("Essa descricao esta em uso!\n");
                } while(checar_descricao_veiculo(temp_desc));
                printf("Digite a marca do veiculo: ");
                fgets(temp_marca, sizeof(temp_marca), stdin);
                printf("Digite o modelo do veiculo: ");
                fgets(temp_mdl, sizeof(temp_mdl), stdin);
                printf("Digite a placa do veiculo: ");
                fgets(temp_placa, sizeof(temp_placa), stdin);
                inserir_veiculo(temp_cod_s_v, temp_cod_v, temp_mdl, temp_desc, temp_placa, temp_marca);
                break;
            case '6': //alterar veiculo
                do {
                    printf("Digite o codigo do proprietario: ");
                    fgets(temp_cod_s_v, sizeof(temp_cod_s_v), stdin);
                    if(!checar_servidor_veiculo((temp_cod_s_v)))
                        printf("Nenhum servidor com esse codigo.\n");
                } while(!checar_servidor_veiculo(temp_cod_s_v));
                do {
                    printf("Digite o codigo do veiculo: ");
                    fgets(temp_cod_v, sizeof(temp_cod_v), stdin);
                    if(checar_codigo_veiculo(temp_cod_v))
                        printf("Esse codigo esta em uso!\n");
                } while(checar_codigo_veiculo((temp_cod_v)));
                do {
                    printf("Digite a descricao do veiculo: ");
                    fgets(temp_desc, sizeof(temp_desc), stdin);
                    if(checar_descricao_veiculo(temp_desc))
                        printf("Essa descricao esta em uso!\n");
                } while(checar_descricao_veiculo(temp_desc));
                printf("Digite a marca do veiculo: ");
                fgets(temp_marca, sizeof(temp_marca), stdin);
                printf("Digite o modelo do veiculo: ");
                fgets(temp_mdl, sizeof(temp_mdl), stdin);
                printf("Digite a placa do veiculo: ");
                fgets(temp_placa, sizeof(temp_placa), stdin);
                alterar_veiculo(temp_cod_v, temp_mdl, temp_desc, temp_placa, temp_marca);
                break;
            case '7': //deletar veiculo
                printf("Digite o codigo do veiculo: ");
                fgets(temp_cod_v, sizeof(temp_cod_v), stdin);
                excluir_veiculo(temp_cod_v);
                break;
            case '8': //listar veiculo
                printf("1. Listar veiculo por codigo\n");
                printf("2. Listar veiculos de um servidor\n");
                scanf("%c", &input);
                fflush(stdin);
                switch(input) {
                    case '1':
                        printf("Digite o codigo do veiculo: ");
                        fgets(temp_cod_v, sizeof(temp_cod_v), stdin);
                        listar_veiculo_por_codigo(temp_cod_v);
                        break;
                    case '2':
                        printf("Digite o codigo do servidor: ");
                        fgets(temp_cod_s_v, sizeof(temp_cod_s_v), stdin);
                        listar_veiculo_por_servidor(temp_cod_s_v);
                        break;
                    default:
                        printf("Invalida!\n");
                        break;
                }
                break;
            default:
                printf("Essa opcao nao existe.\n");
                break;
        }
    } while(input != '0');
    return 0;
}


