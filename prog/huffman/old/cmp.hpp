#ifndef CMP_HPP
# define CMP_HPP

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <algorithm>
#include <fstream>

/**
 * @brief Структура для хранения количества каждого символа, встречающегося в файле.
 * 
 */
typedef struct alphabetic
{
    int char_num;
    int amount;
} alphabetic;

/**
 * @brief Коды ошибок
 * 
 */
enum {
    FILE_OPENING_ERROR = -3,
    ALLOCATION_ERROR,
    PARAMETRS_ERROR
};

/**
 * @brief компаратор для сортировки массива символов (алфавита файла)
 * 
 * @param v1 - первый сортируемый символ
 * @param v2 - второй сортируемый символ
 * @return int 1, если второй больше первого, -1 если первый больше второго
 */
int         comp(const alphabetic* v1, const alphabetic* v2);

/**
 * @brief Создает имя для сжатого файла.
 * 
 * @param original_name - имя исходного файла, 
 * @return char* - строка, с именем сжатого файла
 */
char*       create_compressed_name(char* original_name);

void        decompress();

void        compress();


#endif