#include "cmp.hpp"

int main(int argc, char *argv[]) 
{
    if (argc < 2)
    {
        printf("Недостаточно параметров\n");
        return PARAMETRS_ERROR;
    }

    FILE* original_file;
    FILE* compressed_file;

    char* compressed_name = create_compressed_name(argv[1]);
    alphabetic* array = (alphabetic*)malloc(sizeof(alphabetic) * 256);
    // long long* alphabet = new long long[256];
    if (array == NULL) return ALLOCATION_ERROR;

    for (int i = 0; i < 256; i++)
    {
        array[i].amount = 0;
        array[i].char_num = 0;
    }

    if ((original_file = fopen(argv[1], "r")) == NULL)
    {
        printf("Cannot open file.\n");
        return FILE_OPENING_ERROR;
    }

    if ((compressed_file = fopen(compressed_name, "w")) == NULL)
    {
        printf("Cannot open file.\n");
        return FILE_OPENING_ERROR;
    }

    while (!feof(original_file))
    {
        int ind = (int) fgetc(original_file);
        array[ind].amount++;
        array[ind].char_num = ind;
    }

    qsort(array, 256, sizeof(alphabetic), (int(*) (const void *, const void *)) comp);

    for (int i = 0; i < 256; i++)
    {
        fprintf(compressed_file, "%d: %d\n", array[i].char_num, array[i].amount);
    }

    fclose(original_file);

    free(array);
    
    return 0;
}