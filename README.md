# Bares

- Aluno: Noé Fernandes

# Descrição

O Projeto Bares é um avaliador de expressões. Ele recebe uma expressão numérica no formato de string, e devolve um resultado inteiro correto ou um erro. No processo de avaliação de erros é utilizado um parser, que tokeniza e ao mesmo tempo avalia se a expressão analisada é matematicamente correta ou não. No processo de cálculo do resultado da expressão há a trasformação da expressão do formato infixo para um tipo posfixo, que é não ambiguo. O uso de pilhas também é muito necessário para obter o resultado final.

# Erros tratados

- Integer constant out of range beginning at column (n)!: valor numérico não suportado pelo short.
- Missing <term> at column (n)!: A partir da coluna n está faltando o resto da
expressão.
- Extraneous symbol after valid expression found at column (n)!: Existe um sı́mbolo
qualquer (válido ou não) que foi encontrado depois que uma expressão completa foi
validada, na coluna n.
- Ill formed integer at column (n)!: Contante inteira iniciada na coluna n possui sı́mbolo
inválido em sua composição.
- Missing closing ”)”at column (n)!: Está faltando um parêntese de fechamento ‘)’
para um parêntese de abertura ‘(’ correspondente, na coluna n.
- Unexpected end of expression at column (n)!: Caso receba uma linha contendo
apenas espaços, cujo final é encontrado na coluna n.
- Division by zero!: Houve divisão cujo quociente é zero.
- Numeric overflow error!: Acontece quando uma operação dentro da expressão ou a
expressao inteira estoura o limite de short.

# Limitações
- Problemas na divisão por zero.
- Não Reclamar final inesperado numa expressão com um único parêntese. 

# How to run

- g++ -Wall -std=c++11 src/driver_parser.cpp src/parser.cpp src/bares.cpp -I include/ -o bares
- ./bares < entrada.txt > saida.txt

&copy; IMD/UFRN 2018-2019.
