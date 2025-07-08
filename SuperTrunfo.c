#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

// REVISAR O CODIGO

//  REVISAR CODIGO - MUITA COISA COPIADA DO CHAT GPT

// ENTENDER AS FUNÇÕES E O PORQUE DELAS

// ADICIONAR COMENTARIOS NO CODIGO

void MenuPrincipal();
void MenuAtributos();
void ConfigDaCarta();
void CriarCarta();
void MostrarCartaConfig();

struct Carta {
    
    char cidade[100];
    char estado[4]; // çembrar que: [] dentro tem q ter mais 1 espaço para o \n deixado
    
    int codigo;
    int populacao;
    int pturistico;

    float area;
    float pib;
    float pibpercapita;

};

void CartaPreConfig(struct Carta cartas[]) {
/*
    printf("----- Dados da carta 1 -----\n");
    printf("**Código: 01\n");
    printf("Estado: SP\n");
    printf("Cidade: São Paulo\n");
    printf("População: 123.000.000\n");
    printf("Número de Pontos Turísticos: 100\n");
    printf("Área (km²): 1.521\n");
    printf("PIB: R$2B\n");
    printf("PIB per capita: R$16.000\n");
    printf("-------------------------\n\n");
    
    printf("----- Dados da carta 2 -----\n");
    printf("**Código: 02\n");
    printf("Estado: PR\n");
    printf("Cidade: Curitiba\n");
    printf("População: 50.000.000\n");
    printf("Número de Pontos Turísticos: 43\n");
    printf("Área (km²): 954\n");
    printf("PIB: R$400M\n");
    printf("PIB per capita: R$8.000\n");
    printf("-------------------------\n");
*/

    cartas[0].codigo = 1;
    strcpy(cartas[0].estado, "SP");
    strcpy(cartas[0].cidade, "São Paulo");
    cartas[0].populacao = 123000000;
    cartas[0].pturistico = 100;
    cartas[0].area = 1521.0;
    cartas[0].pib = 2000.0; // em milhões

    // Carta 2
    cartas[1].codigo = 2;
    strcpy(cartas[1].estado, "PR");
    strcpy(cartas[1].cidade, "Curitiba");
    cartas[1].populacao = 50000000;
    cartas[1].pturistico = 43;
    cartas[1].area = 954.0;
    cartas[1].pib = 400.0; // em milhões
}

void LoopConfigDaCarta(struct Carta cartas[], int numero) {
    
    for (int i = 0; i < numero; i++){
        ConfigDaCarta(&cartas[i], i + 1);
    }
}

void ConfigDaCarta(struct Carta *carta, int numero) {

    printf("---- Insira os dados da carta %d ----\n\n", numero);
    printf("Código:");
    scanf("%d", &(carta->codigo)); 
    getchar(); // Limpa o buffer do teclado

    printf("Estado (sigla):");
    fgets(carta->estado, sizeof(carta->estado), stdin);
    carta->estado[strcspn(carta->estado, "\n")] = 0; // para remover a nova linha

    printf("Cidade:");
    fgets(carta->cidade, sizeof(carta->cidade), stdin);
    carta->cidade[strcspn(carta->cidade, "\n")] = 0; // para remover a nova linha

    printf("População:");
    scanf("%d", &(carta->populacao));
    getchar();

    printf("Número de Pontos Turísticos:");
    scanf("%d", &(carta->pturistico));
    getchar();
    
    printf("Área (km²):");
    scanf("%f", &(carta->area));
    getchar();

    printf("PIB (em Milhões):");
    scanf("%f", &(carta->pib));
    getchar();

}

void LoopMostrarCartaConfig(struct Carta *carta, int quantidade){

    for (int i = 0; i < quantidade; i++) {
        MostrarCartaConfig(&carta[i], i + 1);
    }
}

void MostrarCartaConfig(struct Carta *carta, int numerocarta) {

    printf("\n----- Dados da carta %d-----\n\n", numerocarta);
    printf("Código: %d\n", carta->codigo);
    printf("Estado: %s\n", carta->estado);
    printf("Cidade: %s\n", carta->cidade);
    printf("População: %d\n", carta->populacao);
    printf("Número de Pontos Turísticos: %d\n", carta->pturistico);
    printf("Área (km²): %.2f\n", carta->area);
    printf("PIB (em Milhões): %.2f\n", carta->pib);
    printf("-------------------------\n");
}

int Atributos(struct Carta *carta1, struct Carta *carta2, int atributo){

    switch (atributo) {
        case 1:
            if (carta1->populacao > carta2->populacao) return 1;
            else if (carta1->populacao < carta2->populacao) return 2;
            else return 0; 
        case 2:
            if (carta1->area > carta2->area) return 1;
            else if (carta1->area < carta2->area) return 2;
            else return 0;
        default:
            return -1;
    }
}

void MostrarVencedor(int resultado, int numeroCarta1, int numeroCarta2) {
    if (resultado == 1) {
        printf("Carta %d venceu!\n", numeroCarta1);
    } else if (resultado == 2) {
        printf("Carta %d venceu!\n", numeroCarta2);
    } else if (resultado == 0) {
        printf("Empate entre as cartas %d e %d!\n", numeroCarta1, numeroCarta2);
    } else {
        printf("Resultado inválido!\n");
    }
}

void MenuAtributos(struct Carta carta[], int quantidade){

    int atributo;

    do {
        printf("\n------ Você deseja comparar qual Atributo? ------\n");
        printf("1. População\n");
        printf("2. Área (km²)\n");
        printf("3. Número de Pontos Turísticos\n");
        printf("4. PIB\n");
        printf("5. Densidade demográfica\n");
        printf("6. PIB per capita\n");
        printf("-------------------------------------------------\n");
        printf("Insira a opção desejada:");
        scanf("%d", &atributo);
        getchar();
        if (atributo <= 0 || atributo >= 7) {
            printf ("\n**Digite uma opção válida!**\n\n");
        }
    } while (atributo <= 0 || atributo >= 7);

    int resultado = Atributos(&carta[0], &carta[1], atributo);

    MostrarVencedor(resultado, 1, 2);
}

void MenuCartas() {

    int opcaocarta;
    struct Carta carta[2];

    do{
        printf("\n----- Voce Deseja -----\n");
        printf("1. Configurar as Cartas\n");
        printf("2. Usar as Cartas Pré-Configuradas\n");
        printf("3. Voltar ao Menu Principal\n");
        printf("-------------------------\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcaocarta);
        getchar();
        if (opcaocarta <= 0 || opcaocarta >= 4) {
            printf("\n**Digite uma opção válida!**\n\n");
        }
    } while (opcaocarta <= 0 || opcaocarta >= 4);

    switch (opcaocarta){
        case 1:
            LoopConfigDaCarta(carta, 2);
            LoopMostrarCartaConfig(carta, 2);
            MenuAtributos(carta, 2);
            break;
        case 2:
            CartaPreConfig(carta);
            int cartasConfiguradas = 2;
            LoopMostrarCartaConfig(carta, 2);
            MenuAtributos(carta, 2);

            break;
        case 3:
            MenuPrincipal();
            break;        
        default:
            break;
        }
}

void MenuPrincipal() {

    int opcao;
    int menu;
    struct Carta *carta;

    do {
        printf("----- Menu Principal -----\n");
        printf("1. Iniciar jogo\n");
        printf("2. Regras\n");
        printf("3. Sair\n");
        printf("-------------------------\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar(); // Limpa o buffer do teclado
        if (opcao <= 0 || opcao >= 4) {
            printf("\n**Digite uma opção válida!**\n\n");
        }
    } while (opcao <= 0 || opcao >= 4);

    switch (opcao){

        case 1:
            MenuCartas();
            break;

        case 2:
            printf("\n\n----------- Regras do jogo ------------\n");
            printf("Super Trunfo é um jogo de cartas em que    \n");
            printf("cada carta tem atributos numéricos         \n");
            printf("Os jogadores comparam um atributo escolhido\n");
            printf("Quem tiver o maior valor vence a rodada    \n");
            printf("-------------------------------------------\n");

            // utilizar o do - while para criar uma repetição onde 'menu' tem que ser == 1 para sair
            do {
                printf("Digite o número '1' para voltar ao Menu Principal:");
                scanf("%d", &menu);
                getchar();
                
                if (menu == 1) {
                    MenuPrincipal();
                }
                else {
                    printf("\n**Digite uma opção válida!**\n\n");
                }
            } while (menu != 1); 

        case 3:
            printf("Saindo do jogo....\n");
            system("cls");
            break;        
        default:
            break;
        }
    }

int main() {
    struct Carta Carta;
    MenuPrincipal();

}