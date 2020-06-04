/* mathStuff_xxxxxx.c

Roger Priebe and (you)
cs1428 10/15/2007 (updated 3/24/09)
EE312  10/3/2018

Finish comments here
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>


//**********  Function Prototypes  ******************

//function isPrime
//input parameter - positive integer
//returns true if the number is prime, otherwise false
//

bool isPrime (int number);



//function printPrimes
//input parameter - positive integer
//Uses the isPrime method to print a list of prime numbers between 1 and n. 

void printPrimes (int n);


//function findFibo
//input parameter - positive integer
//returns the nth fibonacci number where
//Fib(0) -> 0 
//Fib(1) -> 1 
//Fib(N) -> Fib(N-2) + Fib(N-1)

int findFibo (int n);


//function findFactors
//input parameter - positive integer
//prints the prime factors of the given number to standard output (count)
//example output: 52=2*2*13 (or 52=1*2*2*13) or 13=prime

void findFactors (int number);


//******************  MAIN  *****************************

int main () {


    int testNum;

    //test for the isPrime function
    printf("Enter a test number - ");
    scanf("%d", &testNum);

    if (isPrime(testNum))
        printf("%d is prime\n", testNum);
    else
        printf("%d is not prime.", testNum);

    printf("\n");

    //test for printing primes
    printf("Enter n to print the prime numbers between 1 and n: ");
    scanf("%d", &testNum);

    printPrimes(testNum);

    printf("\n");

    //test for Fibonacci number finder
    printf("Which Fibonacci number? ");
    scanf("%d", &testNum);

    printf("The %d Fibonacci number is : %d \n", testNum, findFibo(testNum));

    printf("\n");

    //test for prime factors
    printf("Factor what number? ");
    scanf("%d",&testNum);
    
    findFactors(testNum);
    
    return 0;
}


//function helperPrime
//input parameter - 2 positive integers
//helper function to determine if a number is prime by incrementing n, the divisor

int helperPrime(int number, int n){

    if (n > sqrt(number)){                  //if n exceeds the square root of number, no more factors
        return true;
    }
    else if (n == sqrt(number)){            //if number is a square, then not prime
        return false;
    }
    else if ((number % n) > 0){             //recursion loop
        n = n+1;
        helperPrime(number, n);
    }
    else {                                  //divided evenly, so not prime
        return false;
    }
}

int helperPrint(int n, int count){
    if (count <= n) {
        if (isPrime(count)) {
            printf(", %d", count);
            count++;
            helperPrint(n, count);
        } else {
            count++;
            helperPrint(n, count);
        }
    }
}

int helperFactors(int number, int n, int orig, int flag) {
    if (n <= number) {
        if ((number % n) > 0) {                     //recursion loop
            n++;
            helperFactors(number, n, orig, flag);
        }
        else if ((number % n) == 0) {               //Finds factors through recursion
            flag++;
            if (orig != number) {                   //prints * before factor, except first for first factor
                printf("*");
            }
            number = (number / n);                //decrease number by dividing the factor it found
            printf(" %d ", n);
            n = 2;
            helperFactors(number, n, orig, flag);
        }
    }
    else if (flag == 1){                            //checks if the number was divided by itself
        printf("= prime");
        return true;
    }

}




//function isPrime
//input parameter - positive integer
//returns true if the number is prime, otherwise false
//

bool isPrime (int number) {
   const int START_DIVISOR = 2; //HINT: You may want a helper function
   int n = START_DIVISOR;

   if (number < START_DIVISOR){               //takes care if input is 1
       return false;
   }
   else {
       helperPrime(number, n);
   }
}


//function printPrimes
//input parameter - positive integer
//Uses the isPrime method to print a list of prime numbers between 1 and n. 

void printPrimes (int n) {

    int count = 1;                              //initial start

    if (n < count) {                            //takes care if input is 1
        printf("invalid");
    }
    else {
        printf("%d", count);
        count++;
        if (isPrime(count)) {                   //
            helperPrint(n, count);
        }
    }
} 



//function findFibo
//input parameter - positive integer
//returns the nth fibonacci number where
//Fib(0) -> 0 
//Fib(1) -> 1 
//Fib(N) -> Fib(N-2) + Fib(N-1)

int findFibo (int n) {
    if (n == 0){                //Fib of 0 is 0
        return 0;
    }
    else if (n == 1){           //Fib of 1 is 1
        return 1;
    }
    else {                      //Use 1 and 0 known fib sequence as a basis for recursion
        int fib = findFibo(n-2) + findFibo(n-1);
        return fib;
    }
    
}


//function findFactors
//input parameter - positive integer
//prints the prime factors of the given number to standard output (cout)
//example output: 52=2*2*13 (or 52=1*2*2*13) or 13=prime

void findFactors (int number) {
    const int START_DIVISOR = 2; //HINT: You may want a helper function

    int n = START_DIVISOR;
    int orig = number;
    int flag = 0;                              //checks how many factors were found

    if (number < START_DIVISOR){               //takes care if input is 1
        printf("invalid");
    }
    else if (number == START_DIVISOR){         //takes care if input is 1
        printf("1 * 2");
    }
    else {
        helperFactors(number, n, orig, flag);
    }

}
    
