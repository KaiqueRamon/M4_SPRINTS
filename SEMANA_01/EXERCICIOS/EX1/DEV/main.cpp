#include <iostream>
#include <string>
using namespace std;

// 1 -  Faça uma função que recebe uma certa medida e ajusta ela percentualmente 
// entre dois valores mínimo e máximo e retorna esse valor
int converteSensor(int medida, int min, int max) {
    return ((medida - min) * 100)/(max - min);
}

// 2 - Faça uma função que simule a leitura de um sensor lendo o 
// valor do teclado ao final a função retorna este valor
int leituraSensor() {
    int valor;
    printf("Digite um número inteiro: "); // em cpp: cout << "Digite"
    scanf("%d", &valor); // em cpp: cin >> valor
    return valor;
}

// 3 - Faça uma função que armazena uma medida inteira qualquer 
// em um vetor fornecido. Note que como C não possui vetores 
// nativos da linguagem, lembre-se que você precisa passar o 
// valor máximo do vetor assim como a última posição preenchida
// Evite também que, por acidente, um valor seja escrito em 
// uma área de memória fora do vetor
int armazenaVetor(int* medidas, int tamanho, int posicao, int medida) {
    if (posicao < tamanho) {
        medidas[posicao] = medida;
        return posicao + 1;
    } else {
        return posicao;
    }
}


// 4 - Faça uma função que recebe um vetor com 4 posições que contém 
// o valor da distância de um pequeno robô até cada um dos seus 4 lados.
// A função deve retornar duas informações: A primeira é a direção 
// de maior distância ("Direita", "Esquerda", "Frente", "Tras") e a 
// segunda é esta maior distância.
string direcaoMenorCaminho(int* distancias, int& maiorDistancia) {
    int tamanho = 4;
    int max = distancias[0];
    int iMax = 0;

    for (int i = 1; i < tamanho; i++) {
        if (distancias[i] > max) {
            max = distancias[i];
            iMax = i;
        }
    }

    maiorDistancia = max;

    string direcoes[] = {"Direita", "Esquerda", "Frente", "Tras"};

    return direcoes[iMax];
}



// 5 - Faça uma função que pergunta ao usuário se ele deseja continuar o mapeamento e 
// retorna verdadeiro ou falso
int leComando() {
    string resposta;
    cout << "Deseja continuar o mapeamento? Digite SIM ou NAO: "; // printf("Deseja...")
    cin >> resposta;  // scanf("%s", &resposta)

    if (resposta.compare("SIM") ==  0) {
        return 1;
    } else {
        return 0;
    }
}

// 6 - A função abaixo (que está incompleta) vai "dirigindo" virtualmente um robô 
// e através de 4 sensores em cada um dos 4 pontos do robo ("Direita", "Esquerda", 
// "Frente", "Tras"). 
//      A cada passo, ele verifica as distâncias aos objetos e vai mapeando o terreno 
// para uma movimentação futura. 
//      Ele vai armazenando estas distancias em um vetor fornecido como parâmetro 
// e retorna a ultima posicao preenchida do vetor.
//      Esta função deve ir lendo os 4 sensores até que um comando de pare seja enviado 
//
//      Para simular os sensores e os comandos de pare, use as funções já construídas 
// nos ítens anteriores e em um looping contínuo até que um pedido de parada seja 
// enviado pelo usuário. 
//
//      Complete a função com a chamada das funções já criadas
int dirige(int *v, int maxv) {
    int maxVetor = maxv;
    int *vetorMov = v;
    int posAtualVetor = 0;
    int dirigindo = 1;
    while (dirigindo) {
        int medida = leituraSensor(); //  Chame a função de de leitura da medida para a "Direita"
        medida = converteSensor(medida, 0, 830);
        posAtualVetor = armazenaVetor(vetorMov, maxVetor, posAtualVetor, medida);
        ///////////////////////////////////////////////////////////////////////////
        // Repita as chamadas acima para a "Esquerda", "Frente", "Tras"
        // ................
        ///////////////////////////////////////////////////////////////////////////
        dirigindo = leComando();
    }
    return posAtualVetor;
}


// O trecho abaixo irá utilizar as funções acima para ler os sensores e o movimento
// do robô e no final percorrer o vetor e mostrar o movimento a cada direção baseado 
// na maior distância a cada movimento
void percorre(int *v,int tamPercorrido){
    int *vetorMov = v;
    int maiorDir;

    for(int i = 0; i< tamPercorrido; i+=4){
        string direcao = direcaoMenorCaminho(&(vetorMov[i]), maiorDir);
        cout << "Movimentando para " + direcao + " distancia = " + std::to_string(maiorDir) + "\n";
    }
}

int main(int argc, char** argv) {
    int maxVetor = 100;
    int vetorMov[maxVetor*4];
    int posAtualVet = 0;

    posAtualVet = dirige(vetorMov,maxVetor);
    percorre(vetorMov,posAtualVet);

    return 0;
}

// int main(int argc, char** argv) {
    // printf("%d\n", converteSensor(8, 0, 10));
    
    // printf("%d\n", leituraSensor());
    
    // int maxVetor = 100;
    // int vetorMov[maxVetor*4];
    // printf("%d\n", armazenaVetor(vetorMov, maxVetor, 0, 10));
    // printf("%d\n", armazenaVetor(vetorMov, maxVetor, 100, 10));
    // printf("%d\n", vetorMov[0]);
 
    // vetorMov[1] = 20;
    // vetorMov[2] = 10;
    // vetorMov[3] = 0;
    // int maiorDir;
    // printf("%s\n", direcaoMenorCaminho(vetorMov, maiorDir));
    // cout << direcaoMenorCaminho(vetorMov, maiorDir);
    // cout << "\n";
    // printf("%d\n", maiorDir);

//     printf("%d\n", leComando());

//     return 0;
// }