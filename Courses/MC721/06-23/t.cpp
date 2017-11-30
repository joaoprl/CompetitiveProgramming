#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int main(){

    int entrada;
    while(scanf("%d", &entrada)){
        int soma = 0;
        int leitura;
        for (int i = 0; i < entrada; i++){
            scanf("%d", &leitura);
            soma += leitura;
        }
        int tempos;
        scanf("%d",&tempos);
        int tempoa, tempob;
        int possivel = 0;
        for (int i = 0; i < tempos; i++){
            scanf("%d %d", &tempoa, &tempob);
            if (soma <= tempob){
                if (tempoa>= soma)
                printf("%d\n", tempoa);
                else printf("%d\n", soma);
                possivel = 1;
                break;
            }
        }
        if (possivel == 0)
            printf("-1\n");

            break;
    }


    return 0;
}
// 1498251036304
