#include <stdio.h>
 
int main() {
    unsigned long int codigo, cml = 0, cmv = 0;
    float pc, pv;
    int quantidade;
    
    int menor = 0;
    int meio = 0;
    int maior = 0;
    
    float maiorLucro = -1.0;
    int maiorQuantidadeVendida = -1;
    
    float totalCompras = 0.0, totalVendas = 0.0;
    
    float lucroUnitario, lucroPercentual, lucroTotal;
    
    while (1) {
        if (scanf("%d %f %f %d", &codigo, &pc, &pv, &quantidade) != 4) {
            break;
        }
        
        lucroUnitario = pv - pc;
        lucroPercentual = (lucroUnitario / pc) * 100.0;
        
        if (lucroPercentual < 10.0) {
            menor++;
        } else if (lucroPercentual <= 20.0) {
            meio++;
        } else {
            maior++;
        }
        
        if (lucroPercentual > maiorLucro) {
            maiorLucro = lucroPercentual;
            cml = codigo;
        }
        
        if (quantidade > maiorQuantidadeVendida) {
            maiorQuantidadeVendida = quantidade;
            cmv = codigo;
        }
        
        totalCompras += pc * quantidade;
        totalVendas += pv * quantidade;
    }
    
    lucroTotal = totalVendas - totalCompras;
    float percentualLucroTotal = (lucroTotal / totalCompras) * 100.0;
    
    printf("Quantidade de mercadorias que geraram lucro menor que 10%%: %d\n", menor);
    printf("Quantidade de mercadorias que geraram lucro maior ou igual a 10%% e menor ou igual a 20%%: %d\n", meio);
    printf("Quantidade de mercadorias que geraram lucro maior do que 20%%: %d\n", maior);
    printf("Codigo da mercadoria que gerou maior lucro: %lu\n", cml);
    printf("Codigo da mercadoria mais vendida: %lu\n", cmv);
    printf("Valor total de compras: %.2f, valor total de vendas: %.2f e percentual de lucro total: %.2f%%\n",
           totalCompras, totalVendas, percentualLucroTotal);
    
    return 0;
}