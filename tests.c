#include <stdio.h>
#include <string.h>
#include "tests.h"
#include "cipher.h"

#define K_1 3
#define K_2 2
#define K_3 (-1)
#define K_4 (-3)
#define K_5 29
#define ZERO 0

// See full documentation in header file
int test_cipher_non_cyclic_lower_case_positive_k ()
{
  char in[] = "abc";
  char out[] = "def";
  cipher (in, K_1);
  return strcmp (in, out) != ZERO;
}

// See full documentation in header file
int test_cipher_cyclic_lower_case_special_char_positive_k ()
{
  char in[] = "z, b.";
  char out[] = "b, d.";
  cipher(in, K_2);
  return strcmp(in, out) != ZERO;
}

// See full documentation in header file
int test_cipher_non_cyclic_lower_case_special_char_negative_k ()
{
  char in[] = "cbt!";
  char out[] = "bas!";
  cipher(in, K_3);
  return strcmp(in, out) != ZERO;
}
// See full documentation in header file
int test_cipher_cyclic_lower_case_negative_k ()
{
  char in[] = "abc";
  char out[] = "xyz";
  cipher(in, K_4);
  return strcmp(in, out) != ZERO;
}

// See full documentation in header file
int test_cipher_cyclic_upper_case_positive_k ()
{
  char in[] = "XYZ";
  char out[] = "ABC";
  cipher(in, K_5);
  return strcmp(in, out) != ZERO;
}

// See full documentation in header file
int test_decipher_non_cyclic_lower_case_positive_k ()
{
  char in[] = "def";
  char out[] = "abc";
  decipher (in, K_1);
  return strcmp (in, out) != ZERO;
}

// See full documentation in header file
int test_decipher_cyclic_lower_case_special_char_positive_k ()
{
  char in[] = "a, d.";
  char out[] = "y, b.";
  decipher(in, K_2);
  return strcmp(in, out) != ZERO;
}

// See full documentation in header file
int test_decipher_non_cyclic_lower_case_special_char_negative_k ()
{
  char in[] = "c, d.";
  char out[] = "d, e.";
  decipher(in,K_3);
  return strcmp(in, out) != ZERO;
}
// See full documentation in header file
int test_decipher_cyclic_lower_case_negative_k ()
{
  char in[] = "xyz";
  char out[] = "abc";
  decipher(in, K_4);
  return strcmp(in, out) != ZERO;
}

// See full documentation in header file
int test_decipher_cyclic_upper_case_positive_k ()
{
  char in[] = "ABC";
  char out[] = "XYZ";
  decipher(in, K_5);
  return strcmp(in, out) != ZERO;
}
