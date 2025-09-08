
int maiorProfundidade = 0;
int soma = 0;

void buscaProfundidade(struct TreeNode* no, int profundidade) {
    if (no == NULL) return;

    if (no->left == NULL && no->right == NULL) {
        if (profundidade > maiorProfundidade) {
            maiorProfundidade = profundidade;
            soma = no->val;
        } else if (profundidade == maiorProfundidade) {
            soma += no->val;
        }
    }

    buscaProfundidade(no->left, profundidade + 1);
    buscaProfundidade(no->right, profundidade + 1);
}


int deepestLeavesSum(struct TreeNode* raiz) {
    maiorProfundidade = 0;
    soma = 0;
    buscaProfundidade(raiz, 0);
    return soma;
}
