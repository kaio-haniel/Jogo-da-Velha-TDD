// Copyright 2026 Kaio Haniel

/**
 * \file  velha.cpp
*/

#include "./velha.hpp"

/** 
 * @brief verifica situacao do jogo da velha  
 * @author Programador 
 * @param  velha descreve o parametro
 * 
 *  Descrever o que a funcao faz
 */

int VerificaVelha(int velha[3][3]) {
int cont_x = 0;
int cont_o = 0;
int cont_vazio = 0;
for (int i = 0; i < 3; ++i) {
for (int j = 0; j < 3; ++j) {
if (velha[i][j] == 1) {
cont_x++;
} else if (velha[i][j] == 2) {
cont_o++;
} else if (velha[i][j] == 0) {
cont_vazio++;
} else {
return -2;
}
}
}
// Regra basica de turnos: X comeca jogando
if (cont_o > cont_x || (cont_x - cont_o) > 1) {
return -2;
}
bool vitoria_x = false;
bool vitoria_o = false;
// Checa linhas horizontais
for (int i = 0; i < 3; ++i) {
if (velha[i][0] != 0 &&
velha[i][0] == velha[i][1] &&
velha[i][1] == velha[i][2]) {
if (velha[i][0] == 1) vitoria_x = true;
if (velha[i][0] == 2) vitoria_o = true;
}
}
// Checa colunas verticais
for (int j = 0; j < 3; ++j) {
if (velha[0][j] != 0 &&
velha[0][j] == velha[1][j] &&
velha[1][j] == velha[2][j]) {
if (velha[0][j] == 1) vitoria_x = true;
if (velha[0][j] == 2) vitoria_o = true;
}
}
// Checa diagonal principal
if (velha[0][0] != 0 &&
velha[0][0] == velha[1][1] &&
velha[1][1] == velha[2][2]) {
if (velha[0][0] == 1) vitoria_x = true;
if (velha[0][0] == 2) vitoria_o = true;
}
// Checa diagonal secundaria
if (velha[0][2] != 0 &&
velha[0][2] == velha[1][1] &&
velha[1][1] == velha[2][0]) {
if (velha[0][2] == 1) vitoria_x = true;
if (velha[0][2] == 2) vitoria_o = true;
}

// Casos impossiveis por violacao de vitoria
if (vitoria_x && vitoria_o) {
return -2;
}
if (vitoria_x && (cont_x != cont_o + 1)) {
return -2;
}
if (vitoria_o && (cont_x != cont_o)) {
return -2;
}
if (vitoria_x) return 1;
if (vitoria_o) return 2;
// Casas disponiveis sem vencedor
if (cont_vazio > 0) {
return -1;
}
return 0;
}
