int totalFunc = 0; 
typedef struct 
{
    int numero;
    char nome[80];
    float vencimento;
}tipoFunc;

tipoFunc *vetorDinFunc;
void escreveFunc (tipoFunc func){
    printf("Dados do funcionario\n");
    printf("Numero: %d\n", func.numero);
    printf("Numero: %s\n", func.nome);
    printf("Numero: %.2f\n", func.vencimento);
}
int main(int argc, char const *argv[])
{
    int totalFunc = 0;
    vetorDinFunc;
    return 0;
}
