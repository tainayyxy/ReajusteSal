#include <stdio.h>
#include <string.h>
//Aluna: Tainá do Amaral Melo
//ADS 3° Semestre noturno A 
int main() {
    
    char nome[100];
    float salario, novoSalario, aumento, percentual, salarioFinal;
    int tempo;
    char continuar[10];

    do {

        // ===== Entrada de Dados =====
        printf("\n Digite o nome do funcionario: ");
        scanf(" %[^\n]", nome);  // nome com espaço

        printf("Digite o salario atual: ");
        scanf("%f", &salario);

        printf("Digite o tempo de empresa (anos): ");
        scanf("%d", &tempo);

        // ===== Percentual de Reajuste =====
        if (tempo < 1) {
            percentual = 0.05;   // 5%
        } 
        else if (tempo >= 1 && tempo < 5) {
            percentual = 0.10;   // 10%
        } 
        else {
            percentual = 0.15;   // 15%
        }

        // ===== Cálculos =====
        aumento = salario * percentual;     // valor do aumento
        novoSalario = salario + aumento;    // salario com reajuste

        // Desafio extra: desconto INSS 8%
        salarioFinal = novoSalario - (novoSalario * 0.08);

        // ===== Saída de Dados =====
        printf("\n===== RESULTADO =====\n");
        printf("Funcionario: %s\n", nome);
        printf("Salario antigo: R$ %.2f\n", salario);
        printf("Percentual aplicado: %.0f%%\n", percentual * 100);
        printf("Valor do aumento: R$ %.2f\n", aumento);
        printf("Novo salario (antes INSS): R$ %.2f\n", novoSalario);
        printf("Salario final (apos INSS): R$ %.2f\n", salarioFinal);

        // Mensagem caso se ultrapasse 10.000
        if (novoSalario > 10000) {
            printf(">>> Salario acima de R$ 10.000! Funcionario em alto nivel salarial!\n");
        }

        // Aqui calcula para outros funcionários
        printf("\nDeseja calcular para outro funcionario? (Sim/Nao): ");
        scanf(" %s", continuar);
        getchar(); 

    } while (strcmp(continuar, "Sim") == 0);

    return 0;
}
