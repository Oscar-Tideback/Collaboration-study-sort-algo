#include <stdio.h>
#include <stdlib.h>
#include "heapsort.h"
#include "quicksort.h"
#include "menu.h"
#include "main.h"
#include "randomizers.h"
#include "bubblesort.h"
#include "qsort_std.h"


static void test_sortingalgorithm() {
        unsigned* (*randomizer)(size_t);
        void (*algorithm)(unsigned*, size_t);

        printf("Test soring algorithm\n");
        printf("\n");        
        printf("Choose randomizer\n");
        printf("1: Sorted\n");
        printf("2: Unsorted\n");
        printf("3: Almost sorted\n");
        printf("4: Reversed sorted\n");//
        printf("5: Unikly numberd usorted\n");//

        int choice2;
        scanf("%d", &choice2);
        getc(stdin);
        switch (choice2) 
        {
            case 1: 
            randomizer = sorted;
                break;
            case 2: 
            randomizer = random_;
                break;
            case 3: 
            randomizer = almostsorted;
                break;  
            case 4: 
            randomizer = reversed_sorted;
                break; 
            case 5: 
            randomizer = unique_random;
                break;          
        }

        printf("Choose algorithm\n");
        printf("1: Bubblesort\n");
        printf("2: Quicksort\n");
        printf("3: Heapsort\n");
        printf("4: Qsort STD\n");

        int choice1;
        scanf("%d", &choice1);
        getc(stdin);
        switch (choice1) 
        {
        case 1: 
        algorithm = bubblesort;
            break;
        case 2: 
        algorithm = quicksort;
            break;
        case 3: 
        algorithm = heapsort;
            break;       
        case 4: 
        algorithm = qsort_std;
            break; 
    }

    printf("Enter number of tests: ");
        size_t num_of_tests; 
        scanf("%zu", &num_of_tests); 

        printf("Number of elements of first test: ");
        size_t size_of_first_test;
        scanf("%zu", &size_of_first_test);
        
        printf("Linear increase of number of elements: ");
        size_t size_increase;
        scanf("%zu", &size_increase);

        sorting_test(randomizer, algorithm, num_of_tests , size_of_first_test , size_increase);
}

void the_menu() {
    menu:
    printf("\n ****MENU**** \n");
    printf("\n");
    printf("Choices\n");
    printf("\n");
    printf("1: Test sorting algorithm\n");
    printf("2: Quit\n");
    printf("\n");
    printf("Choice: \n");
    int choice;
    scanf("%d", &choice);
    getc(stdin);
    switch (choice) 
    {
    case 1: 
        test_sortingalgorithm();
        break;  
    case 2: 
        exit(0);
    }
    goto menu; 
}