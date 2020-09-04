#include<stdio.h>
#include<stdbool.h>


// CodeCampTester.c -- EE 312 Project 1 -- Tester class

/* Student information for assignment:
 * 
 * Name: Angelina Ibarra
 * email address: angelinasibarra@gmail.com
 * UTEID: asi354
 * Section 5 digit ID: 16010
 *  
 */

//function prototypes. These will be completed in CodeCamp.c
int sum3or5Multiples();
//****************************

int main() {
  
 int expected;
 int actual;

  // test 7, sum of multiples of 3 or 5
  expected = 233168;
  actual = sum3or5Multiples();
  printf("Test 7 sum of multiples: expected value: %d, actual value: %d\n", expected, actual);

  if(expected == actual)  
     printf("passed test 7, sum of multiples of 3 or 5\n\n");
  else 
     printf("**** FAILED **** test 7, sum of multiples of 3 or 5\n\n");

}

