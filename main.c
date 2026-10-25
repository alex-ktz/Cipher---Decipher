#include <stdio.h>
#include <stdlib.h>
#include "cipher.h"
#include "tests.h"
#include <string.h>
#include <stdbool.h>

#define ARG_NUM_ERR "The program receives 1 or 4 arguments only!\n"
#define TEST_ERR "Usage: cipher test\n"
#define COMMAND_ERR "The given command is invalid.\n"
#define K_ERR "The given shift value is invalid.\n"
#define FILE_ERR "The given file is invalid.\n"
#define MAX_SIZE 1024
#define ZERO 0
#define ONE 1
#define TWO 2
#define THREE 3
#define FOUR 4
#define FIVE 5
#define TEN 10

int run_all_tests(void)
{
  if (test_cipher_non_cyclic_lower_case_positive_k() != ZERO) {return ONE;}
  if (test_cipher_cyclic_lower_case_special_char_positive_k() != ZERO) {return ONE;}
  if (test_cipher_non_cyclic_lower_case_special_char_negative_k() != ZERO) {return ONE;}
  if (test_cipher_cyclic_lower_case_negative_k() != ZERO) {return ONE;}
  if (test_cipher_cyclic_upper_case_positive_k() != ZERO) {return ONE;}
  if (test_decipher_non_cyclic_lower_case_positive_k() != ZERO) {return ONE;}
  if (test_decipher_cyclic_lower_case_special_char_positive_k() != ZERO) {return ONE;}
  if (test_decipher_non_cyclic_lower_case_special_char_negative_k() != ZERO) {return ONE;}
  if (test_decipher_cyclic_lower_case_negative_k() != ZERO) {return ONE;}
  if (test_decipher_cyclic_upper_case_positive_k() != ZERO) {return ONE;}

  return ZERO;
}

//bool is_number(const char *str) {
//  if ((str == NULL) || (*str == '\0')) {
//    return false;
//  }
//  char *check;
//  strtol(str, &check, TEN);
//  return (*check == '\0') && (check != str);
//}
int is_number(const char *str) {
  if ((str == NULL) || (*str == '\0')) {
    return ZERO;
  }
  char *check;
  strtol(str, &check, TEN);
  return ((*check == '\0') && (check != str)) ? ONE : ZERO;
}

int main (int argc, char *argv[]) {
  if (argc != TWO && argc != FIVE){
    fprintf(stderr,ARG_NUM_ERR);
    return EXIT_FAILURE;
  }
  else if (argc == TWO && strcmp(argv[ONE],"test") != ZERO){
    fprintf(stderr, TEST_ERR);
    return EXIT_FAILURE;
  }
  else if (argc == TWO){
    if (run_all_tests() != ZERO) {
      return EXIT_FAILURE;
    }
    else  {
      return EXIT_SUCCESS;
    }
  }
  else if (strcmp(argv[ONE],"cipher") != ZERO && strcmp(argv[ONE],"decipher") != ZERO){
    fprintf(stderr, COMMAND_ERR);
    return EXIT_FAILURE;
  }
  else if (is_number(argv[TWO]) == ZERO){
  //else if (!is_number(argv[TWO])) {
    fprintf(stderr, K_ERR);
    return EXIT_FAILURE;
  }
  else {
    FILE *input = fopen(argv[THREE], "r");
    FILE *output = fopen(argv[FOUR], "w");
    if ((input == NULL) || (output == NULL)){
      fprintf(stderr, FILE_ERR);
      return EXIT_FAILURE;
    }
    char *numstr = argv[TWO];
    long k = strtol(numstr, NULL, TEN);
    char buffer[MAX_SIZE];
    while (fgets(buffer, sizeof(buffer), input) != NULL){
      if (strcmp(argv[ONE],"cipher") == ZERO){
        cipher(buffer,k);
        fputs(buffer, output);
      }
      else if (strcmp(argv[ONE],"decipher") == ZERO){
        decipher(buffer,k);
        fputs(buffer, output);
      }
}
    fclose(input);
    fclose(output);
    return EXIT_SUCCESS;
  }
}


