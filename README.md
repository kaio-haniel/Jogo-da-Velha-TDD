# Trabalho 1 - Verificador de Jogo da Velha com TDD
Disciplina: Tecnicas de Programacao 2

Instrucoes de Compilacao e Execucao:

1. Compilar e executar os testes unitarios (Catch):
   make all
   ./testa_velha

2. Verificacao estatica de estilo (cpplint):
   make cpplint
   ou
   cpplint --exclude=catch.hpp *.cpp *.hpp

3. Verificacao de analise estatica de codigo (cppcheck):
   make cppcheck

4. Verificacao de gerenciamento de memoria (Valgrind):
   valgrind --leak-check=full ./testa_velha

5. Verificacao de cobertura de testes (gcov):
   g++ -std=c++11 -Wall -fprofile-arcs -ftest-coverage testa_velha.cpp velha.cpp -o testa_velha
   ./testa_velha
   gcov velha.cpp
