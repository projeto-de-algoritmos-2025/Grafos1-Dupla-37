#include <stdbool.h>
#include <stdlib.h>

int direcoes[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};


bool dfs(int** grid, bool** visitado, int row, int col, int i, int j) {
    if (i < 0 || i >= row || j < 0 || j >= col) return false;
    if (grid[i][j] == 1 || visitado[i][j]) return false;
    if (i == row - 1) return true;

    visitado[i][j] = true;

    for (int d = 0; d < 4; d++) {
        int ni = i + direcoes[d][0];
        int nj = j + direcoes[d][1];
        if (dfs(grid, visitado, row, col, ni, nj)) return true;
    }

    return false;
}

bool podeCruzar(int row, int col, int** cells, int dia) {
 
    int** grid = (int**)calloc(row, sizeof(int*));
    bool** visitado = (bool**)calloc(row, sizeof(bool*));
    for (int i = 0; i < row; i++) {
        grid[i] = (int*)calloc(col, sizeof(int));
        visitado[i] = (bool*)calloc(col, sizeof(bool));
    }

    for (int i = 0; i < dia; i++) {
        int r = cells[i][0] - 1;
        int c = cells[i][1] - 1;
        grid[r][c] = 1;
    }

    bool cruzou = false;
    for (int j = 0; j < col; j++) {
        if (grid[0][j] == 0 && !visitado[0][j]) {
            if (dfs(grid, visitado, row, col, 0, j)) {
                cruzou = true;
                break;
            }
        }
    }

  
    for (int i = 0; i < row; i++) {
        free(grid[i]);
        free(visitado[i]);
    }
    free(grid);
    free(visitado);

    return cruzou;
}


int latestDayToCross(int row, int col, int** cells, int cellsSize, int* cellsColSize) {
    int esquerda = 1, direita = cellsSize, resposta = 0;

    while (esquerda <= direita) {
        int meio = (esquerda + direita) / 2;
        if (podeCruzar(row, col, cells, meio)) {
            resposta = meio;
            esquerda = meio + 1;
        } else {
            direita = meio - 1;
        }
    }

    return resposta;
}