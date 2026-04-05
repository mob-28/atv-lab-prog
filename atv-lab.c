#include <stdio.h>

typedef struct alunos {
    float n_teorico;
    float n_pratico;
    float aulas_assistidas;
    struct alunos *prox;
} aluno;

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
    int qtd_aluno, aula_total_astd; 
    float n_pratica, n_teorico;   

    // tema, boas-vindas e integrantes do grupo
    printf("\n--- Sistema de Diagnostico de Turmas EPT ---\n");
    printf("Integrantes: Evangelista, Jailson, Julia, Mateus\n");
    printf("Seja bem-vindo ao Sistema de Diagnostico de Turmas EPT!\n");
    opcao = menu();

    do {
        switch (opcao) {

            case 1: 
                // primeira opcao e faz a soliticacao de cada dado: solicita a quantidade de alunos na turma, nota de conhecimentos teóricos, a nota de habilidades práticas e o total de aulas assistidas

                printf("Digite a quantidade de alunos: ");
                scanf("\n%d", &qtd_aluno);

                for (int i = 1; i <= qtd_aluno; i++) {

                    // pedido das infos de acordo com a quantidade de alunos
                    printf("Digite a nota de conhecimentos teoricos do aluno %d: ", i);
                    scanf("\n%f", &n_teorico);

                    printf("Digite a nota de habilidades praticas do aluno %d: ", i);
                    scanf("\n%f", &n_pratica);

                    printf("Digite a quantidade de aulas assistidas do aluno %d: ", i);
                    scanf("\n%d", &aula_total_astd);
                }

                // pede novamente uma opcao
                menu();
                printf("Digite uma opcao: ");
                scanf("%d", &opcao);

        }
    } while (opcao != 4); // repete ate que a opcao 4 seja requisitada

    return 0;
}