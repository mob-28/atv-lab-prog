#include <stdio.h>

struct Aluno {
    float n_teorica;
    float n_pratica;
    int aulas_assistidas;
};

int menu () {
    int opcao;

    // funcao que mostra o menu
    printf("\n--- MENU ---\n1 - Adicionar Notas\n2 - Visualizar Diagnostico\n3 - Registrar Evasao\n4 - Encerrar programa\n");

    printf("Digite uma opcao: ");
    scanf("%d", &opcao);

    return opcao;
}

int main () {
    int opcao;
    int qtd_aluno;
    float maior_nota_pratica = 0, menor_nota_pratica = 11; 
    float maior_nota_teorica = 0, menor_nota_teorica = 11; 

    struct Aluno alunos[100];

    // tema, boas-vindas e integrantes do grupo
    printf("\n--- Sistema de Diagnostico de Turmas EPT ---\n");
    printf("Integrantes: Evangelista, Jailson, Julia, Mateus\n");
    printf("Seja bem-vindo ao Sistema de Diagnostico de Turmas EPT!\n");
    opcao = menu();

    do {
        switch (opcao) {

            case 1: 
                // primeira opcao e faz a soliticacao de cada dado: solicita a quantidade de alunos na turma, nota de conhecimentos teoricos, a nota de habilidades praticas e o total de aulas assistidas

                printf("Digite a quantidade de alunos: ");
                scanf("\n%d", &qtd_aluno);

                for (int i = 1; i <= qtd_aluno; i++) {
                    float numero1, numero2;

                    // pedido das infos de acordo com a quantidade de alunos
                    printf("Digite a nota de conhecimentos teoricos do aluno %d: ", i);
                    scanf("\n%f", numero1);

                    if (numero1 >= 0.0 && numero1 <= 10.0) {
                        alunos[i].n_teorica = numero1;
                    }
                    else {
                        printf("Numero invalido!\n");
                    }
                    
                    // se nota digitada for maior que a guardada, o valor de nota eh a nova maior nota
                    if (alunos[i].n_teorica > maior_nota_teorica) {
                        maior_nota_teorica = alunos[i].n_teorica;
                    }

                    // se nota digitada for menor que a guardada, o valor da nota eh a nova menor nota
                    if (alunos[i].n_teorica < menor_nota_teorica) {
                        menor_nota_teorica = alunos[i].n_teorica;
                    }

                    printf("Digite a nota de habilidades praticas do aluno %d: ", i);
                    scanf("\n%f", &alunos[i].n_pratica);

                    // se nota digitada for maior que a guardada, o valor de nota eh a nova maior nota
                    if (alunos[i].n_pratica > maior_nota_pratica) {
                        maior_nota_pratica = alunos[i].n_pratica;
                    }

                    // se nota digitada for menor que a guardada, o valor da nota eh a nova menor nota
                    if (alunos[i].n_pratica < menor_nota_pratica) {
                        menor_nota_pratica = alunos[i].n_teorica;
                    }

                    printf("Digite a quantidade de aulas assistidas do aluno %d: ", i);
                    scanf("\n%d", &alunos[i].aulas_assistidas);
                }
                
                opcao = menu();

        }
    } while (opcao != 4); // repete ate que a opcao 4 seja requisitada

    return 0;
}