/*
  Katie Bourque
  Assignment 8
  Computer Organizations
*/
#include <stdio.h>

int rmult (int i, int j) { //computes product of i and j by repeated addition
  if (j == 1){
    return i;
  }
  else{
    return i + rmult (i, --j); //return product
  }
}

int bmult(int i, int j) { //computes product using bit representation and doubles
  int sum = 0;
  int mult = i;
  int bit = 1;

  while (bit <= j){
    if (j & bit){
      sum = sum + mult;
    }
    bit += bit; //double bit
    mult += mult; //double mult 
  }
  return sum;
}

int main() {
  int fac1;
  int fac2;

  for(fac1 = 9; fac1 <= 12; ++fac1){
    printf("***********************************\n");
    for(fac2 = 1; fac2 <= 7; fac2 += 2){
      printf("%2d *%2d = %2d  0x%08x  0x%08x\n", fac1, fac2, fac1*fac2, rmult(fac1, fac2), bmult(fac1, fac2));
    }
  }
  printf("***********************************");
}
