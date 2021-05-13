void imprime (char **matChar, int **matCabecalho, int **matLinha2, int linhas, int colunas, int maiorAgL, int maiorArgC);

void preencher (char*** mat, int nLinha, int nColuna, char linha, char coluna, int** matLinha2, int** matCabecalho, char** matChar, int maiorArgL, int maiorArgC);

void marcar (char*** mat, int nLinha, int nColuna, char linha, char coluna, int** matLinha2, int** matCabecalho, char** matChar, int maiorArgL, int maiorArgC);

void limpar (char*** mat, int nLinha, int nColuna, char linha, char coluna, int** matLinha2, int** matCabecalho, char** matChar, int maiorArgL, int maiorArgC);

void salvar (int linhas, int colunas, int* argsLinha, int* argsColuna, int** matLinha, int** matColuna, char** matChar, char* doc);

void copiaMat (char*** matChar, char** matChar2, int linhas, int colunas); 
