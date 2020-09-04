#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>

// CodeCamp.c -- EE 312 Project 1

/* Student information for project:
 *
 * Angelina Ibarra
 *
 * On my honor, Angelina Ibarra, this programming project is my own work
 * and I have not provided this code to any other student.
 *
 * Name: Angelina Ibarra
 * email address: angelinasibarra@utexas.edu
 * UTEID: asi354
 * Section 5 digit ID: 16010
 *
 */



/* Determine the hamming distance between two int arrays.
   pre: aList != null, bList != null, aList.length == bList.length == len
   post: return hamming distance between the two arrays of ints.
   Neither parameter should be altered by this function.
*/

int hammingDistance(int aList[], int bList[], int len) {
    int i = 0;
    int hamDist = 0;
    while(i <len) {
        if (aList[i] == bList[i]) {
            i++;
        } else {
            hamDist++;
            i++;
        }
    }
    return(hamDist);
}



/* Determine if two ints have the same last digit.
   Note that the last digit of 0 is 0 and the last digit of -12 is 2. 
   post: return true if num1 and num2 have the same last digit, false otherwise.
*/

bool lastDigit(int num1, int num2) {
    if(num1 < 0){
        num1 *= -1;
    }
    if(num2 < 0){
        num1 *= -1;
    }
    if(num1%10 == num2%10){
        return(true);
    }else{
        return(false);
    }
}

/* Determine the sum of the positive integers less than 1000 that are multiples of 3 or 5 (or both).
   post: return the sum of the integers from 1 to 1000 that are multiples of 3 or 5 or both.
*/

int sum3or5Multiples() {
    int sum = 0;
    int i = 999;

    while(i >= 0){
        if(i%5 == 0 | i%3 == 0){
            sum = sum + i;
            i--;
        }else{
            i--;
        }
    }
    return(sum);
}

/* Reverse the digits of an integer. Return the reversed number if it is in the range of type int, 0 otherwise.
   post: return num with digits reversed if the reverse can be stored as an int, 0 otherwise.
*/

int reverseInt(int num) {
    //Find the length of the number
    int len = 0;
    int a = num;
    while(a != 0){
        len++;
        a = a/10;
    }

    //Store digits into numArray in reverse
    int numArray[len];
    int i = 0;
    while(num != 0){
        numArray[i] = num % 10;
        num = num/10;
        i++;
    }

    //Combine values to form reverse integer
    int power = 1;
    float sum = 0;
    i =  len - 1;
    while(i >=0){
        sum += (numArray[i] * power);
        power *= 10;
        i--;
    }

    //Check if new num is larger than int
    if(sum > 2147483647) {
        return(0);
    }else{
        num = sum;
        return(num);
    }
}
