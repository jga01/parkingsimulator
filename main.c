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

    int done = 1;
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
        scanf("%c", &input);
        fflush(stdin);

        printf("\n");

        switch(input)
        {
            case '0':

                printf("Encerrando o programa...");
                return 0;

            case '1': // criar servidor

                if(checar_cheio_servidores() >= MAX-1){
                    printf("Armazenamento cheio!\n");
                    done = 0;
                }
                if(!done) {done = 1; break;}

                do {

                    printf("Digite o codigo do Servidor : \n:");
                    fgets(entrada,sizeof(entrada),stdin);
                    fflush(stdin);
                    printf("Digite o nome do Servidor : \n:");
                    fgets(nome,sizeof(nome),stdin);
                    fflush(stdin);
                    printf("Digite o siape do Servidor : \n:");
                    fgets(siape,sizeof(siape),stdin);
                    fflush(stdin);
                    printf("Digite o cpf do Servidor : \n:");
                    fgets(cpf,sizeof(cpf),stdin);
                    fflush(stdin);
                    strcpy(iden,"1");

                }while( checa_branco(entrada,nome,siape,cpf,iden) );

                printf("Digite a data de nascimento do Servidor : \n:");
                fgets(nasci,sizeof(nasci),stdin);
                fflush(stdin);
                printf("Digite o rg do Servidor : \n:");
                fgets(rg,sizeof(rg),stdin);
                fflush(stdin);
                printf("Digite o salario do servidor : \n:");
                fgets(salario,sizeof(salario),stdin);
                fflush(stdin);
                printf("Digite o endereco do Servidor : \n:");
                fgets(endereco,sizeof(endereco),stdin);
                fflush(stdin);

                op = type_serv();
                if(op == 1)
                    strcpy(tipo,"Professor");
                else
                    strcpy(tipo,"Tecnico");

                criarServidor(entrada,nome,siape,cpf,nasci,rg,salario,tipo,endereco);
                break;

            case '2':// atualizar servidor
                do {
                    printf("Digite o cod do servidor\n:");
                    fgets(entrada,sizeof(entrada),stdin);
                    fflush(stdin);
                    entrada[strcspn(entrada,"\n")] = 0;

                    if(!existe_cod(entrada)){
                        printf("\n#Esse codigo nao existe digite um valido!#\n");
                    }
                }while( !existe_cod(entrada) );

                do {
                    printf("Digite o NOVO Nome do Servidor : \n:");
                    fgets(nome,sizeof(nome),stdin);
                    fflush(stdin);
                    printf("Digite o NOVO Siape do Servidor : \n:");
                    fgets(siape,sizeof(siape),stdin);
                    fflush(stdin);
                    printf("Digite o NOVO Cpf do Servidor : \n:");
                    fgets(cpf,sizeof(cpf),stdin);
                    fflush(stdin);
                    strcpy(iden, "2");

                }while( checa_branco(entrada,nome,siape,cpf,iden) );

                printf("Digite a NOVA data de nascimento do Servidor : \n:");
                fgets(nasci,sizeof(nasci),stdin);
                fflush(stdin);
                printf("Digite o NOVO Rg do Servidor : \n:");
                fgets(rg,sizeof(rg),stdin);
                fflush(stdin);
                printf("Digite o NOVO salario do servidor : \n:");
                fgets(salario,sizeof(salario),stdin);
                fflush(stdin);
                printf("Digite o NOVO endereco do Servidor : \n:");
                fgets(endereco,sizeof(endereco),stdin);
                fflush(stdin);

                op = type_serv();
                if(op == 1) strcpy(tipo,"Professor");
                else strcpy(tipo,"Tecnico");

                atualizarServidor(entrada,nome,siape,cpf,nasci,rg,salario,tipo,endereco);
                break;

            case '3': // deletar servidor
                do {
                    printf("Digite o cod do servidor\n:");
                    fgets(entrada,sizeof(entrada),stdin);
                    fflush(stdin);
                    entrada[strcspn(entrada,"\n")] = 0;

                    if(!existe_cod(entrada)){
                        printf("\n#Esse codigo nao existe digite um valido!#\n");
                    }
                }while( !existe_cod(entrada) );

                deletarServidor(entrada);
                excluir_veiculos_servidor(entrada);
                break;

            case '4': // listar servidor

                printf("Digite a forma como deseja printar os servidores\n\n");
                printf("1. Printar apenas os Tecnicos \n");
                printf("2. Printar apenas os professores \n");
                printf("3. Printar Todos \n");
                printf("4.Printar um servidor pelo cod dele.\n");

                scanf("%c",&input);
                fflush(stdin);

                menu_listar_server(input);
                break;

            case '5': //inserir veiculo
                if(checar_cheio_veiculos() >= MAX_V){
                    printf("Armazenamento cheio!\n");
                    done = 0;
                }
                if(!done) {done = 1; break;}
                do {
                    printf("Digite o codigo do proprietario: ");
                    fgets(temp_cod_s_v, sizeof(temp_cod_s_v), stdin);
                    if(!checar_servidor_veiculo((temp_cod_s_v))) {
                        printf("Nenhum servidor com esse codigo.\n");
                        done = 0;
                    }
                } while(checar_em_branco(temp_cod_s_v));
                if(!done) {done=1;break;}
                do {
                    printf("Digite o codigo do veiculo: ");
                    fgets(temp_cod_v, sizeof(temp_cod_v), stdin);
                    if(checar_codigo_veiculo(temp_cod_v))
                        printf("Esse codigo esta em uso ou nenhum codigo foi inserido!\n");
                } while(checar_codigo_veiculo((temp_cod_v)) || checar_em_branco(temp_cod_v));
                do {
                    printf("Digite a descricao do veiculo: ");
                    fgets(temp_desc, sizeof(temp_desc), stdin);
                    if(checar_descricao_veiculo(temp_desc))
                        printf("Essa descricao esta em uso ou nenhuma descricao foi inserida!\n");
                } while(checar_descricao_veiculo(temp_desc) || checar_em_branco(temp_desc));
                do {
                    printf("Digite a marca do veiculo: ");
                    fgets(temp_marca, sizeof(temp_marca), stdin);
                } while(checar_em_branco(temp_marca));
                do {
                    printf("Digite o modelo do veiculo: ");
                    fgets(temp_mdl, sizeof(temp_mdl), stdin);
                } while(checar_em_branco(temp_mdl));
                do {
                    printf("Digite a placa do veiculo: ");
                    fgets(temp_placa, sizeof(temp_placa), stdin);
                } while(checar_em_branco(temp_placa));
                inserir_veiculo(temp_cod_s_v, temp_cod_v, temp_mdl, temp_desc, temp_placa, temp_marca);
                break;
            case '6': //alterar veiculo
                do {
                    printf("Digite o codigo do veiculo: ");
                    fgets(temp_cod_v, sizeof(temp_cod_v), stdin);
                    if(!checar_codigo_veiculo(temp_cod_v)) {
                        printf("Esse codigo nao existe\n");
                        done = 0;
                    }
                } while(checar_em_branco(temp_cod_v));
                if(!done) {done=1;break;}
                do {
                    printf("Digite a descricao do veiculo: ");
                    fgets(temp_desc, sizeof(temp_desc), stdin);
                    if(checar_descricao_veiculo(temp_desc))
                        printf("Essa descricao esta em uso!\n");
                } while(checar_descricao_veiculo(temp_desc) || checar_em_branco(temp_desc));
                do {
                    printf("Digite a marca do veiculo: ");
                    fgets(temp_marca, sizeof(temp_marca), stdin);
                } while(checar_em_branco(temp_marca));
                do {
                    printf("Digite o modelo do veiculo: ");
                    fgets(temp_mdl, sizeof(temp_mdl), stdin);
                } while(checar_em_branco(temp_mdl));
                do {
                    printf("Digite a placa do veiculo: ");
                    fgets(temp_placa, sizeof(temp_placa), stdin);
                } while(checar_em_branco(temp_placa));
                alterar_veiculo(temp_cod_v, temp_mdl, temp_desc, temp_placa, temp_marca);
                break;
            case '7': //deletar veiculo
                printf("Digite o codigo do veiculo: ");
                fgets(temp_cod_v, sizeof(temp_cod_v), stdin);
                if(checar_em_branco(temp_cod_v) || !checar_codigo_veiculo(temp_cod_v)) {
                    printf("Digite um codigo valido e existente.\n");
                    done = 0;
                } if(!done) {done=1;break;}
                printf("Veiculo deletado!\n");
                excluir_veiculo(temp_cod_v);
                break;
            case '8': //listar veiculo
                printf("1. Listar veiculo por codigo\n");
                printf("2. Listar veiculos de um servidor\n");
                printf("3. Listar veiculos por ordem alfabetica\n");
                printf("Opcao: ");
                scanf("%c", &input);
                fflush(stdin);
                switch(input) {
                    case '1':
                        printf("Digite o codigo do veiculo: ");
                        fgets(temp_cod_v, sizeof(temp_cod_v), stdin);
                        if(checar_em_branco(temp_cod_v) || !checar_codigo_veiculo(temp_cod_v)) {
                            printf("Digite um codigo valido e existente.\n");
                            done = 0;
                        } if(!done) {done=1;break;}
                        listar_veiculo_por_codigo(temp_cod_v);
                        break;
                    case '2':
                        printf("Digite o codigo do servidor: ");
                        fgets(temp_cod_s_v, sizeof(temp_cod_s_v), stdin);
                        if(checar_em_branco(temp_cod_s_v) || !checar_servidor_veiculo(temp_cod_s_v)) {
                            printf("Digite um codigo valido e existente.\n");
                            done = 0;
                        } if(!done) {done=1;break;}
                        listar_veiculo_por_servidor(temp_cod_s_v);
                        break;
                    case '3':
                        printf("Digite o codigo do servidor: ");
                        fgets(temp_cod_s_v, sizeof(temp_cod_s_v), stdin);
                        if(checar_em_branco(temp_cod_s_v) || !checar_servidor_veiculo(temp_cod_s_v)) {
                            printf("Digite um codigo valido e existente.\n");
                            done = 0;
                        } if(!done) {done=1;break;}
                        listar_veiculo_ordenado(temp_cod_s_v);
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


