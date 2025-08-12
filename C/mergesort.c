#include <stdio.h>
#include <stdlib.h>

// Função para intercalar duas metades ordenadas
void merge(int arr[], int inicio, int meio, int fim) {
   
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;

    // Criar arrays temporários
    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    // Copiar dados para os arrays temporários
    for (int i = 0; i < n1; i++) {
        L[i] = arr[inicio + i];
    }

    for (int j = 0; j < n2; j++) {
        R[j] = arr[meio + 1 + j];
    }

    // Intercalar os arrays temporários de volta ao array original
    int i = 0, j = 0, k = inicio;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    // Copiar os elementos restantes, se houver
    while (i < n1) {
        arr[k++] = L[i++];
    }

    while (j < n2) {
        arr[k++] = R[j++];
    }

    // Liberar memória
    free(L);
    free(R);
}

// Função principal do Merge Sort (recursiva)
void mergeSort(int arr[], int inicio, int fim) {
    if (inicio < fim) {
        int meio = (inicio + fim) / 2;

        // Ordenar as duas metades
        mergeSort(arr, inicio, meio);
        mergeSort(arr, meio + 1, fim);

        // Juntar as metades ordenadas
        merge(arr, inicio, meio, fim);
    }
}

int main() {
    int n;

    printf("Digite o tamanho do array: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));

    printf("Digite os %d elementos:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    mergeSort(arr, 0, n - 1);

    printf("Array ordenado:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}