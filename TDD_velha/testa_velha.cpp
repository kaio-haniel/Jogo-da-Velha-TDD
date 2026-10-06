// Copyright 2026 Kaio Haniel

/**
* \file testa_velha.cpp
*/

#define CATCH_CONFIG_MAIN
#include "./catch.hpp"
#include "./velha.hpp"

TEST_CASE("Verifica jogo impossivel por contagem de pecas", "[velha]") {
int jogo_invalido[3][3] = {
{1, 1, 1},
{1, 1, 1},
{0, 0, 0}
};
REQUIRE(VerificaVelha(jogo_invalido) == -2);
}

TEST_CASE("Verifica jogo indefinido", "[velha]") {
  int jogo_indefinido[3][3] = {
    {1, 0, 0},
    {0, 2, 0},
    {0, 0, 0}
  };
  REQUIRE(VerificaVelha(jogo_indefinido) == -1);
}

TEST_CASE("Verifica vitoria de X em linha horizontal", "[velha]") {
  int vitoria_x[3][3] = {
    {1, 1, 1},
    {2, 2, 0},
    {0, 0, 0}
  };
  REQUIRE(VerificaVelha(vitoria_x) == 1);
}

TEST_CASE("Verifica vitoria de O em linha horizontal", "[velha]") {
  int vitoria_o[3][3] = {
    {2, 2, 2},
    {1, 1, 0},
    {1, 0, 0}
  };
  REQUIRE(VerificaVelha(vitoria_o) == 2);
}

TEST_CASE("Verifica vitoria de X em coluna vertical", "[velha]") {
  int vitoria_coluna[3][3] = {
    {1, 2, 0},
    {1, 2, 0},
    {1, 0, 0}
  };
  REQUIRE(VerificaVelha(vitoria_coluna) == 1);
}

TEST_CASE("Verifica vitoria de X na diagonal principal", "[velha]") {
  int vitoria_diag_principal[3][3] = {
    {1, 2, 0},
    {0, 1, 2},
    {0, 0, 1}
  };
  REQUIRE(VerificaVelha(vitoria_diag_principal) == 1);
}

TEST_CASE("Verifica vitoria de O na diagonal secundaria", "[velha]") {
  int vitoria_diag_secundaria[3][3] = {
    {1, 1, 2},
    {1, 2, 0},
    {2, 0, 0}
  };
  REQUIRE(VerificaVelha(vitoria_diag_secundaria) == 2);
}

TEST_CASE("Verifica empate (velha)", "[velha]") {
  int jogo_empate[3][3] = {
    {1, 2, 1},
    {1, 1, 2},
    {2, 1, 2}
  };
  REQUIRE(VerificaVelha(jogo_empate) == 0);
}

TEST_CASE("jogo impossivel, dois vencedores simultaneos", "[velha]") {
  int dois_vencedores[3][3] = {
    {1, 1, 1},
    {2, 2, 2},
    {0, 0, 0}
  };
  REQUIRE(VerificaVelha(dois_vencedores) == -2);
}

TEST_CASE("Verifica jogo impossivel com jogada apos vitoria de X", "[velha]") {
  int jogo_pos_vitoria[3][3] = {
    {1, 1, 1},
    {2, 2, 2},
    {0, 0, 0}
  };
  REQUIRE(VerificaVelha(jogo_pos_vitoria) == -2);
}

TEST_CASE("jogo impossivel, X vence mas pecas estao iguais", "[velha]") {
  int x_vence_mas_o_jogou_depois[3][3] = {
    {1, 1, 1},
    {2, 2, 0},
    {0, 0, 2}
  };
  REQUIRE(VerificaVelha(x_vence_mas_o_jogou_depois) == -2);
}
