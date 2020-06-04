#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>

// CodeCamp.c -- EE 312 Project 1

/* Student information for project:
 *
 * Replace <NAME> with your name.
 *
 * On my honor, Eduardo Saul Ruiz> this programming project is my own work
 * and I have not provided this code to any other student.
 *
 * Name: Eduardo Saul Ruiz
 * email address: esruiz39@utexas.edu
 * UTEID: esr668
 * Section 5 digit ID: 16020
 *
 */



/* Determine the hamming distance between two int arrays.
   pre: aList != null, bList != null, aList.length == bList.length == len
   post: return hamming distance between the two arrays of ints.
   Neither parameter should be altered by this function.
*/

int hammingDistance(int aList[], int bList[], int len){

    int hamDis = 0;
    int i=0;

    while ( i < len ){
        if (aList[i] != bList[i]){
            hamDis++;
        }
        i++;
    }
    return hamDis;
}


/* Determine if two ints have the same last digit.
   Note that the last digit of 0 is 0 and the last digit of -12 is 2. 
   post: return true if num1 and num2 have the same last digit, false otherwise.

   Personal Note:
        Checks if num1 or num2 is a positive or negative number.
        If negative, turns it into a positive number.
        Goal is to make num1 & num2 fall in the boundary of 0 < x < 9,
            to do so, we subtract 10 to retain the last digit

*/

bool lastDigit(int num1, int num2) {

    int maxBound = 9;
    int minBound = 0;
    int singleDigit = 10;
    int neg = -1;

    while (num1 < minBound){
        num1 = num1 * neg;
    }
    while (num1 > maxBound){
        num1 = num1 - singleDigit;
    }
    while (num2 < minBound){
        num2 = num2 * neg;
    }
    while (num2 > maxBound){
        num2 = num2 - singleDigit;
    }
    if (num1 == num2){
        return true;
    }
    else {
        return false;
    }
}

/* Determine the sum of the positive integers less than 1000 that are multiples of 3 or 5 (or both).
   post: return the sum of the integers from 1 to 1000 that are multiples of 3 or 5 or both.
*/

int sum3or5Multiples(){

    int max = 1000;
    int start = 1;
    int mult3 = 3;
    int mult5 = 5;
    int add3 = 3;
    int add5 = 5;
    int sum = 0;

    while(start < max){
        if (mult3 == mult5){
            sum = sum + mult3;
            mult3 = mult3 + add3;
            mult5 = mult5 + add5;
        }
        if (start == mult3){
            sum = sum + mult3;
            mult3 = mult3 + add3;
        }
        if (start == mult5){
            sum = sum + mult5;
            mult5 = mult5 + add5;
        }
        start++;
    }
    return sum;


}

/* Reverse the digits of an integer. Return the reversed number if it is in the range of type int, 0 otherwise.
   post: return num with digits reversed if the reverse can be stored as an int, 0 otherwise.
*/

int reverseInt(int num){

    int digits = 0;
    int i = 0;
    int neg = -1;
    int negFlag = 0;
    int testNum = num;
    int decPart;
    int multiple;
    int newValue;
    int minBound = 0;
    int maxBound = 9;
    int findPlaceValue = 10;

    if (testNum < minBound){
        testNum = testNum * neg;
        negFlag = 1;
    }
    if (testNum > maxBound){
        while (testNum != 0) {
            testNum = testNum / findPlaceValue;
            digits++;
        }
        int reverse[digits];
        if (negFlag == 1){
            num = num * neg;
        }
        while (i < digits){
            decPart = num % findPlaceValue;
            num = num / findPlaceValue;
            reverse[i] = decPart;
            i++;
        }
        num = 0;
        i = 0;
        while (digits > 0){
            multiple = digits - 1;
            newValue = reverse[i];
            while (multiple > 0) {
                newValue = newValue * findPlaceValue;
                multiple--;
            }
            digits--;
            i++;
            num = num + newValue;
        }
        if (negFlag == 1){
            num = num * neg;
        }
        if (num > 2147483647){
            return 0;
        }
        if (num < -2147483648){
            return 0;
        }
        return num;
    }
    return num;
}

  

