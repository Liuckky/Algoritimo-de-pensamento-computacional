#include <studio.h>

int main()  {
    int sala [3][3];
    int livres = 0, ocupados = 0;
    for (int i 0; i < 3; i++)  {
        printf("Poltrona[%d][%d] (0 ou 1): ", i, j);
        scanf("%d", &sala[i][j]);
        if (sala[i][j] ==0)
            livres++;
        else
            ocupadas++;
        }
}
printf("\nSituacao da silva:\n")
for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++)
         printf("%d ", sala[i][j]);
    printf("\n");
}
printf("\nSituacao da sala:\n", livres);
printf("Ocupadas: %d\n", ocupadas);

return 0;
}