# Sistema de Reajuste Salarial

Aplicacao de console em C++ que calcula o reajuste salarial de funcionarios conforme o tempo de empresa. Projeto academico com foco em funcoes, estruturas, validacao de entradas e organizacao de codigo.

## Regras do exercicio

| Tempo de empresa | Reajuste |
| --- | ---: |
| Menos de 1 ano | 5% |
| De 1 a menos de 5 anos | 10% |
| 5 anos ou mais | 15% |

A aplicacao tambem demonstra um desconto fixo de 8% sobre o salario reajustado. **Esse percentual e uma regra didatica do exercicio, nao representa o calculo oficial do INSS.** O calculo real de contribuicoes depende das regras e faixas vigentes.

## Funcionalidades

- Leitura do nome, salario atual e tempo de empresa.
- Validacao de campos vazios, salario negativo e tempo negativo ou nao inteiro.
- Calculo automatico do percentual e do valor do reajuste.
- Demonstracao do desconto didatico de 8%.
- Processamento de mais de um funcionario na mesma execucao.
- Aceita respostas como `sim`, `SIM`, `Sim`, `nao` e `NAO`.

## Estrutura

```text
ReajusteSal/
├── src/
│   └── main.cpp
├── .gitignore
├── Makefile
└── README.md
```

## Requisitos

- Compilador C++ com suporte a C++17 (GCC, Clang ou MSVC).
- No Windows, pode usar MinGW-w64 ou WSL.

## Compilar

Com g++:

```bash
g++ -std=c++17 -Wall -Wextra -Wpedantic -O2 src/main.cpp -o ReajusteSal
```

Ou, se tiver GNU Make instalado:

```bash
make
```

## Executar

Linux/macOS:

```bash
./ReajusteSal
```

Windows (MinGW):

```powershell
.\ReajusteSal.exe
```

## Exemplo de calculo

Para salario de R$ 2.000,00 e 3 anos completos de empresa:

- Reajuste: 10% (R$ 200,00).
- Novo salario antes do desconto didatico: R$ 2.200,00.
- Desconto didatico de 8%: R$ 176,00.
- Resultado apos o desconto didatico: R$ 2.024,00.

## Casos importantes para testar

1. 0 anos: deve aplicar 5%.
2. 1 ano: deve aplicar 10%.
3. 4 anos: deve aplicar 10%.
4. 5 anos: deve aplicar 15%.
5. Salario negativo ou texto no campo numerico: deve solicitar novamente.
6. Nome vazio: deve solicitar novamente.
7. Resposta `SIM` para continuar e `NAO` para encerrar.

## Observacao sobre valores monetarios

O projeto utiliza `double` para manter o exemplo simples e didatico. Em sistemas financeiros de producao, prefira representar dinheiro em centavos com inteiros ou usar uma biblioteca decimal apropriada, alem de regras tributarias atualizadas.

## Autoria

Taina do Amaral Melo

Projeto academico de Analise e Desenvolvimento de Sistemas.
