#include <stdio.h>
#define MAX 100

struct Aluno {
    float n_teorica;
    float n_pratica;
    int aulas_assistidas;
};

int menu () { // funcao que retorna o menu pedindo a opcao
    int opcao;

    // funcao que mostra o menu
    printf("\n--- MENU ---\n1 - Adicionar Notas\n2 - Visualizar Diagnostico\n3 - Registrar Evasao\n4 - Encerrar programa\n");

    printf("Digite uma opcao: ");
    scanf("%d", &opcao);

    return opcao;
}

int main () {

    int opcao;
    int qtd_aluno = 0;

    float maior_nota_pratica = 0, menor_nota_pratica = 11;
    float maior_nota_teorica = 0, menor_nota_teorica = 11;

    struct Aluno alunos[MAX];

    // tema, boas-vindas e integrantes do grupo
    printf("\n--- Sistema de Diagnostico de Turmas EPT ---\n");
    printf("Integrantes: Evangelista, Jailson, Julia, Mateus, Jociano e Guilherme\n");
    printf("Seja bem-vindo ao Sistema de Diagnostico de Turmas EPT!\n");

    opcao = menu();

    do {

        switch (opcao) {

        case 1:
            // caso da opcao 1, onde adiciona as notas
            printf("Digite a quantidade de alunos: ");
            scanf("%d", &qtd_aluno);
            
            // repete a solicitacao de notas de acordo com a quantidade de alunos
            for (int i = 0; i < qtd_aluno; i++) {

                float numero1;
                // solicita a nota teorica
                printf("Digite a nota de conhecimentos teoricos do aluno %d: ", i+1);
                scanf("%f", &numero1);
                // verifica se a nota esta entre 0 e 10
                while (numero1 < 0.0 || numero1 > 10.0) {
                
                    printf("Opcao invalida! Digite novamente.\n");
                    scanf("%f", &numero1);
                }
                
                if (numero1 >= 0.0 && numero1 <= 10.0) {
                    alunos[i].n_teorica = numero1;
                }
                else {
                    printf("Numero invalido!\n");
                    printf("Digite novamente o numero: \n");
                }
                // verifica se a nota eh maior que a ja armazenada
                if (alunos[i].n_teorica > maior_nota_teorica) {
                    maior_nota_teorica = alunos[i].n_teorica;
                }
                // verifica se a nota eh menor que a ja armazenada
                if (alunos[i].n_teorica < menor_nota_teorica) {
                    menor_nota_teorica = alunos[i].n_teorica;
                }
                // solicita a nota de atividades praticas do aluno
                printf("Digite a nota de habilidades praticas do aluno %d: ", i+1);
                scanf("%f", &alunos[i].n_pratica);
                // verifica se esta dentro de 0 e 10
                while (alunos[i].n_pratica < 0.0 || alunos[i].n_pratica > 10.0) {

                    printf("Opcao invalida! Digite novamente.\n");
                    scanf("%f", &alunos[i].n_pratica);
                }
                // verifica e armazena se a nota guardada eh maior que esta armazenada no programa
                if (alunos[i].n_pratica > maior_nota_pratica) {
                    maior_nota_pratica = alunos[i].n_pratica;
                }
                // verifica e armazena se a nota guardada eh menor que esta armazenada no programa
                if (alunos[i].n_pratica < menor_nota_pratica) {
                    menor_nota_pratica = alunos[i].n_pratica;
                }
                // solicita a quantidade de horas assistidas
                printf("Digite a quantidade de aulas assistidas do aluno %d: ", i+1);
                scanf("%d", &alunos[i].aulas_assistidas);
            }

            opcao = menu();
            break;

        case 2:
            // faz o diagnostico da turma

            // se tiver nenhum aluno
            if (qtd_aluno == 0) {
                printf("Nenhum aluno cadastrado\n");
                opcao = menu();
                break;
            }

            float soma = 0;
            int totalAulas = 0;

            // faz a media das horas assistidas
            for (int i = 0; i < qtd_aluno; i++) {

                float media = (alunos[i].n_teorica + alunos[i].n_pratica) / 2;

                soma += media;
                totalAulas += alunos[i].aulas_assistidas;
            }

            float mediaTurma = soma / qtd_aluno;

            int minutos = totalAulas * 45;
            int horas = minutos / 60;

            printf("\n--- DIAGNOSTICO ---\n");
            printf("Quantidade de alunos: %d\n", qtd_aluno);
            printf("Media da turma: %.2f\n", mediaTurma);
            // printa os valores de maior e menor noa de cada disciplina

            printf("Maior nota teorica: %.2f\n", maior_nota_teorica);
            printf("Menor nota teorica: %.2f\n", menor_nota_teorica);
            printf("Maior nota pratica: %.2f\n", maior_nota_pratica);
            printf("Menor nota pratica: %.2f\n", menor_nota_pratica);

            printf("Total de horas: %d\n", horas);
            
            // se estiver menor que 20 horas, retorna turma com defasagem
            if (horas < 20)
                printf("Turma com defasagem\n");

            // avalia a media da turma 
            if (mediaTurma >= 7)
                printf("Turma destaque\n");
            else
                printf("Turma com problemas\n");

            opcao = menu();
            break;

        case 3: {

            // faz o diagnostico de evasao e solicita o motivo 
            int dias, horas, minutos;
            int totalMin = 0;
            char motivo[100];

            printf("Motivo da evasao: ");
            scanf(" %[^\n]", motivo);

            printf("Digite dias, horas e minutos: ");
            scanf("%d %d %d", &dias, &horas, &minutos);

            while (dias > 0) {
                totalMin += 24 * 60;
                dias--;
            }

            while (horas > 0) {
                totalMin += 60;
                horas--;
            }

            totalMin += minutos;

            printf("Tempo total em minutos: %d\n", totalMin);

            opcao = menu();
            break;
        }

        }

    } while (opcao != 4); // se a opcao digitada for 4, o programa é fechado

    printf("Programa finalizado");
    return 0;
}
