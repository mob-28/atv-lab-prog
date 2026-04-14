#include <stdio.h>
#include <string.h>
#define MAX 100
 
struct Aluno {
    float n_teorica;
    float n_pratica;
    int aulas_assistidas;
};
 
int menu() {
    int opcao;
 
    printf("\n--- MENU ---\n");
    printf("1 - Adicionar Notas\n");
    printf("2 - Visualizar Diagnostico\n");
    printf("3 - Registrar Evasao\n");
    printf("4 - Encerrar programa\n");
    printf("Digite uma opcao: ");
    scanf("%d", &opcao);
 
    // valida opcao do menu
    while (opcao < 1 || opcao > 4) {
        printf("Opcao invalida! Digite novamente: ");
        scanf("%d", &opcao);
    }
 
    return opcao;
}
 
int main() {
 
    int opcao;
    int qtd_aluno = 0;
 
    float maior_nota_pratica = 0, menor_nota_pratica = 11;
    float maior_nota_teorica = 0, menor_nota_teorica = 11;
 
    // indices para identificar qual aluno tem maior/menor nota
    int idx_maior_teorica = 0, idx_menor_teorica = 0;
    int idx_maior_pratica = 0, idx_menor_pratica = 0;
 
    struct Aluno alunos[MAX];
 
    // variaveis para acumular evasoes
    int qtd_evasoes = 0;
    int total_min_evasao = 0;
    char motivos[MAX][100];
 
    printf("\n--- Sistema de Diagnostico de Turmas EPT ---\n");
    printf("Integrantes: Evangelista, Jailson, Julia, Mateus, Jociano e Guilherme\n");
    printf("Seja bem-vindo ao Sistema de Diagnostico de Turmas EPT!\n");
 
    opcao = menu();
 
    do {
 
        switch (opcao) {
 
        case 1:
            printf("Digite a quantidade de alunos: ");
            scanf("%d", &qtd_aluno);
 
            // valida quantidade de alunos
            while (qtd_aluno <= 0 || qtd_aluno > MAX) {
                printf("Quantidade invalida! Digite um valor entre 1 e %d: ", MAX);
                scanf("%d", &qtd_aluno);
            }
 
            for (int i = 0; i < qtd_aluno; i++) {
 
                // --- Nota teorica ---
                float numero1;
                printf("Digite a nota de conhecimentos teoricos do aluno %d: ", i + 1);
                scanf("%f", &numero1);
 
                while (numero1 < 0.0 || numero1 > 10.0) {
                    printf("Nota invalida! Digite um valor entre 0.0 e 10.0: ");
                    scanf("%f", &numero1);
                }
 
                alunos[i].n_teorica = numero1;
 
                if (alunos[i].n_teorica > maior_nota_teorica) {
                    maior_nota_teorica = alunos[i].n_teorica;
                    idx_maior_teorica = i; // guarda o indice do aluno
                }
                if (alunos[i].n_teorica < menor_nota_teorica) {
                    menor_nota_teorica = alunos[i].n_teorica;
                    idx_menor_teorica = i; // guarda o indice do aluno
                }
 
                // --- Nota pratica ---
                printf("Digite a nota de habilidades praticas do aluno %d: ", i + 1);
                scanf("%f", &alunos[i].n_pratica);
 
                while (alunos[i].n_pratica < 0.0 || alunos[i].n_pratica > 10.0) {
                    printf("Nota invalida! Digite um valor entre 0.0 e 10.0: ");
                    scanf("%f", &alunos[i].n_pratica);
                }
 
                if (alunos[i].n_pratica > maior_nota_pratica) {
                    maior_nota_pratica = alunos[i].n_pratica;
                    idx_maior_pratica = i; // guarda o indice do aluno
                }
                if (alunos[i].n_pratica < menor_nota_pratica) {
                    menor_nota_pratica = alunos[i].n_pratica;
                    idx_menor_pratica = i; // guarda o indice do aluno
                }
 
                // --- Aulas assistidas ---
                printf("Digite a quantidade de aulas assistidas do aluno %d: ", i + 1);
                scanf("%d", &alunos[i].aulas_assistidas);
 
                // valida aulas assistidas (nao pode ser negativo)
                while (alunos[i].aulas_assistidas < 0) {
                    printf("Valor invalido! Digite um numero positivo: ");
                    scanf("%d", &alunos[i].aulas_assistidas);
                }
            }
 
            opcao = menu();
            break;
 
        case 2:
            if (qtd_aluno == 0) {
                printf("Nenhum aluno cadastrado!\n");
                opcao = menu();
                break;
            }
 
            float soma = 0;
            int totalAulas = 0;
 
            for (int i = 0; i < qtd_aluno; i++) {
 
                float media_individual = (alunos[i].n_teorica + alunos[i].n_pratica) / 2;
 
                soma += media_individual;
                totalAulas += alunos[i].aulas_assistidas;
 
                // verifica media individual de cada aluno
                printf("\nAluno %d | Teorica: %.2f | Pratica: %.2f | Media: %.2f",
                       i + 1,
                       alunos[i].n_teorica,
                       alunos[i].n_pratica,
                       media_individual);
 
                if (media_individual >= 7.0)
                    printf(" -> Aluno aprovado");
                else
                    printf(" -> Aluno com dificuldades");
            }
 
            float mediaTurma = soma / qtd_aluno;
 
            int minutos = totalAulas * 45;
            int horas = minutos / 60;
 
            printf("\n\n--- DIAGNOSTICO DA TURMA ---\n");
            printf("Quantidade de alunos: %d\n", qtd_aluno);
            printf("Media da turma: %.2f\n", mediaTurma);
 
            printf("\nNotas Teoricas:\n");
            printf("  Maior nota: %.2f (Aluno %d)\n", maior_nota_teorica, idx_maior_teorica + 1);
            printf("  Menor nota: %.2f (Aluno %d)\n", menor_nota_teorica, idx_menor_teorica + 1);
 
            printf("\nNotas Praticas:\n");
            printf("  Maior nota: %.2f (Aluno %d)\n", maior_nota_pratica, idx_maior_pratica + 1);
            printf("  Menor nota: %.2f (Aluno %d)\n", menor_nota_pratica, idx_menor_pratica + 1);
 
            // Conversao int -> double para exibir horas com precisao
            double horasDouble = (double)minutos / 60.0;
            printf("\nTotal de aulas: %d (%.2f horas)\n", totalAulas, horasDouble);
 
            if (horas < 20)
                printf("Status de frequencia: Turma com defasagem\n");
            else
                printf("Status de frequencia: Frequencia adequada\n");
 
            if (mediaTurma >= 7.0)
                printf("Status de desempenho: Turma destaque\n");
            else
                printf("Status de desempenho: Turma com problemas\n");
 
            // exibe registros de evasao acumulados
            printf("\n--- EVASOES REGISTRADAS ---\n");
            if (qtd_evasoes == 0) {
                printf("Nenhuma evasao registrada.\n");
            } else {
                printf("Total de evasoes: %d\n", qtd_evasoes);
                for (int i = 0; i < qtd_evasoes; i++) {
                    printf("  Evasao %d: %s\n", i + 1, motivos[i]);
                }
                double totalHorasEvasao = (double)total_min_evasao / 60.0;
                printf("Tempo total de ausencias: %d minutos (%.2f horas)\n",
                       total_min_evasao, totalHorasEvasao);
            }
 
            opcao = menu();
            break;
 
        case 3: {
 
            int dias, horas_ev, minutos_ev;
            int totalMin = 0;
            char motivo[100];
 
            printf("Motivo da evasao: ");
            scanf(" %[^\n]", motivo);
 
            printf("Digite dias, horas e minutos da ausencia: ");
            scanf("%d %d %d", &dias, &horas_ev, &minutos_ev);
 
            // valida entradas negativas
            while (dias < 0 || horas_ev < 0 || minutos_ev < 0) {
                printf("Valores invalidos! Nao pode ser negativo. Digite novamente (dias horas minutos): ");
                scanf("%d %d %d", &dias, &horas_ev, &minutos_ev);
            }
 
            // Conversao usando laco while conforme exigido pelo projeto
            int diasTemp = dias;
            while (diasTemp > 0) {
                totalMin += 24 * 60;
                diasTemp--;
            }
 
            int horasTemp = horas_ev;
            while (horasTemp > 0) {
                totalMin += 60;
                horasTemp--;
            }
 
            totalMin += minutos_ev;
 
            // Conversao int -> double e double -> int conforme requisito
            double totalMinDouble = (double)totalMin;
            int totalMinInt = (int)totalMinDouble;
 
            // salva evasao para exibir no diagnostico
            strncpy(motivos[qtd_evasoes], motivo, 99);
            motivos[qtd_evasoes][99] = '\0';
            total_min_evasao += totalMin;
            qtd_evasoes++;
 
            printf("\nEvasao registrada!\n");
            printf("Motivo: %s\n", motivo);
            printf("Tempo total de ausencia: %d minutos\n", totalMinInt);
            printf("Equivalente a: %.2f horas\n", totalMinDouble / 60.0);
 
            opcao = menu();
            break;
        }
 
        }
 
    } while (opcao != 4);
 
    printf("\nPrograma finalizado.\n");
    return 0;
}