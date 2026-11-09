#include <algorithm>
#include <cctype>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

struct Funcionario {
    std::string nome;
    double salarioAtual{};
    int anosDeEmpresa{};
};

constexpr double DESCONTO_DIDATICO = 0.08;
constexpr double LIMITE_SALARIO_DESTAQUE = 10000.00;

double calcularPercentualReajuste(int anosDeEmpresa) {
    if (anosDeEmpresa < 1) return 0.05;
    if (anosDeEmpresa < 5) return 0.10;
    return 0.15;
}

bool converterDouble(const std::string& texto, double& valor) {
    std::istringstream entrada(texto);
    if (!(entrada >> valor)) return false;
    entrada >> std::ws;
    return entrada.eof() && std::isfinite(valor);
}

bool converterInteiro(const std::string& texto, int& valor) {
    std::istringstream entrada(texto);
    if (!(entrada >> valor)) return false;
    entrada >> std::ws;
    return entrada.eof();
}

std::string lerTexto(const std::string& mensagem) {
    std::string texto;

    while (true) {
        std::cout << mensagem;
        if (!std::getline(std::cin, texto)) return "";

        const auto primeiro = texto.find_first_not_of(" \t\r\n");
        if (primeiro != std::string::npos) {
            const auto ultimo = texto.find_last_not_of(" \t\r\n");
            return texto.substr(primeiro, ultimo - primeiro + 1);
        }

        std::cout << "O campo nao pode ficar vazio. Tente novamente.\n";
    }
}

double lerSalario() {
    std::string texto;
    double salario = 0.0;

    while (true) {
        std::cout << "Salario atual (use ponto para casas decimais): R$ ";
        if (!std::getline(std::cin, texto)) return -1.0;

        if (converterDouble(texto, salario) && salario >= 0.0) return salario;
        std::cout << "Valor invalido. Informe um salario numerico maior ou igual a zero.\n";
    }
}

int lerTempoDeEmpresa() {
    std::string texto;
    int anos = 0;

    while (true) {
        std::cout << "Tempo de empresa (anos completos): ";
        if (!std::getline(std::cin, texto)) return -1;

        if (converterInteiro(texto, anos) && anos >= 0) return anos;
        std::cout << "Valor invalido. Informe um numero inteiro maior ou igual a zero.\n";
    }
}

Funcionario lerFuncionario() {
    Funcionario funcionario;
    funcionario.nome = lerTexto("Nome do funcionario: ");
    funcionario.salarioAtual = lerSalario();
    funcionario.anosDeEmpresa = lerTempoDeEmpresa();
    return funcionario;
}

void exibirResultado(const Funcionario& funcionario) {
    const double percentual = calcularPercentualReajuste(funcionario.anosDeEmpresa);
    const double aumento = funcionario.salarioAtual * percentual;
    const double novoSalario = funcionario.salarioAtual + aumento;
    const double desconto = novoSalario * DESCONTO_DIDATICO;
    const double salarioFinal = novoSalario - desconto;

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "\n========== RESULTADO DO REAJUSTE ==========\n";
    std::cout << "Funcionario: " << funcionario.nome << '\n';
    std::cout << "Tempo de empresa: " << funcionario.anosDeEmpresa << " ano(s)\n";
    std::cout << "Salario anterior: R$ " << funcionario.salarioAtual << '\n';
    std::cout << "Percentual aplicado: " << percentual * 100.0 << "%\n";
    std::cout << "Valor do aumento: R$ " << aumento << '\n';
    std::cout << "Novo salario (antes do desconto): R$ " << novoSalario << '\n';
    std::cout << "Desconto didatico (8%): R$ " << desconto << '\n';
    std::cout << "Salario final estimado: R$ " << salarioFinal << '\n';

    if (novoSalario > LIMITE_SALARIO_DESTAQUE) {
        std::cout << "ATENCAO: o novo salario ultrapassa R$ 10.000,00.\n";
    }

    std::cout << "===========================================\n";
}

std::string normalizarResposta(std::string resposta) {
    std::transform(resposta.begin(), resposta.end(), resposta.begin(),
                   [](unsigned char caractere) {
                       return static_cast<char>(std::tolower(caractere));
                   });
    return resposta;
}

bool desejaContinuar() {
    while (true) {
        std::string resposta = normalizarResposta(
            lerTexto("\nDeseja calcular outro funcionario? (sim/nao): ")
        );

        if (resposta == "sim") return true;
        if (resposta == "nao" || resposta == "não") return false;

        std::cout << "Resposta invalida. Digite sim ou nao.\n";
    }
}

int main() {
    std::cout << "=====================================\n";
    std::cout << "       SISTEMA DE REAJUSTE SALARIAL\n";
    std::cout << "=====================================\n";

    do {
        Funcionario funcionario = lerFuncionario();

        if (!std::cin) {
            std::cerr << "\nEntrada encerrada antes da conclusao do cadastro.\n";
            return 1;
        }

        exibirResultado(funcionario);
    } while (desejaContinuar());

    std::cout << "\nSistema encerrado. Obrigado!\n";
    return 0;
}
