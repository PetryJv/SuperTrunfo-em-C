#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

// REVISAR O CODIGO

// ENTENDER AS FUNÇÕES E O PORQUE DELAS e comentar

// ADICIONAR COMENTARIOS NO CODIGO


// Protótipo das funções
void MenuPrincipal();
void MenuAtributos();
void ConfigDaCarta();
void CriarCarta();
void MostrarCartaConfig();

// estrutura da carta
struct Carta {
    
    char cidade[100];
    char estado[4]; // lembrar q espaço para o \n
    
    int codigo;
    int populacao;
    int pturistico;

    float area;
    float pib;
    float pibpercapita;
};

// Carta pré-configurada
void CartaPreConfig(struct Carta cartas[]) {

    // Carta 1
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

// loop para criação de quantidade de cartas
void LoopConfigDaCarta(struct Carta cartas[], int numero) {
    
    for (int i = 0; i < numero; i++){
        ConfigDaCarta(&cartas[i], i + 1);
    }
}

// Configurando a carta manualmente - Usuário / Jogador
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
// loop de 'X'vezes para mostrar as cartas, conforme quantidade de cartas
void LoopMostrarCartaConfig(struct Carta *carta, int quantidade){

    for (int i = 0; i < quantidade; i++) {
        MostrarCartaConfig(&carta[i], i + 1);
    }
}

// Estrutura da mostragem da carta 
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

// switch para comparar os atributos 
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

// condição 'if-else' para determinar o vencedor da comparação de atributos 
void MostrarVencedor(int resultado, int numeroCarta1, int numeroCarta2) {
    if (resultado == 1) { // retornou 1 no int Atributos()
        printf("Carta %d venceu!\n", numeroCarta1);
    } else if (resultado == 2) { // retornou 2 na função int Atributos
        printf("Carta %d venceu!\n", numeroCarta2);
    } else if (resultado == 0) {// retornou 0 na função int Atributos
        printf("Empate entre as cartas %d e %d!\n", numeroCarta1, numeroCarta2);
    } else {
        printf("Resultado inválido!\n");
    }
}

// Estrutura do Menu dos Atributos
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

// estrutura do Menu de Cartas  
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
    } while (opcaocarta <= 0 || opcaocarta >= 4); // caso digite um numero inválido, repete operação toda

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

// Estrutura do Menu Principal do Jogo
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