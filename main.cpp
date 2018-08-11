//
//  main.cpp
//  Recursion
//
//  Created by Evan Matoske on 10/21/15.
//  Copyright © 2015 Evan Matoske. All rights reserved.
//

#include <iostream>
#include <string>

/*****************************************************************
 * Author: Evan Matoske                                          *
 * Date: 10/22/15                                                *
 * Description: This program has 3 functions that use recursion  *
 * The functions are: reverse, sum, and triangle.                *
 * The reverse function reverses a word that the user enter.     *
 * The sum function add together the numbers the user enters.    *
 * The triangle function calculates the triangle number from the *
 * number of rows the user enters                                *
 ****************************************************************/



 /*******************************************************
 *                    Reverse Function                  *
 * Reverses the word the user enters recursively. Takes *
 * as a parameterer a string. The function prints the   *
 * last letter of the word and then deletes it and then *
 * passes the new string into the function until there  *
 * is one character left in the string.                 *
 *******************************************************/

void reverse(std::string input)
{
    
    if (input.length() < 1)
        std::cout << input << std::endl;
    else
    {
        std::cout << input.substr(input.length()-1);
        std::string temp = input.erase(input.length()-1);
        reverse(temp);
        
    }
    
}
/**************************************************************
 *                    Sum Function                            *
 * Adds the numbers in an array recursively. Takes an array   *
 * and integer as a parameter. Starts with the last number in *
 * the array and adds it to the next one until there is       *
 * no more numbers to add. The integer passed is used as      *
 * the number of elements in the array.                       *
 *************************************************************/

int sum(int nums[], int num)
{
    
    if (num == -1)
        return 1;
    else
    {
        return nums[num] + sum(nums, num - 1);
    }
}
/*******************************************************************
 *                      Triangle Function                          *
 * The user enters a number which is considered the number         *
 * of rows in the equal lateral triangle. The fuction              *
 * recursively adds the together the number elements in the row    *
 * where row n = n elements. It adds the last number to the number *
 * before it until it gets to the second to last number where it   *
 * will add three. For 1 and 2 rows it will simply return 1 or 3.  *
 ******************************************************************/
 
int triangle (int num)
{
    int num2 = num;
    if (num == 1)
        return 1;
    
    if (num == 2)
        return 3;
    
    else
        return num2 + triangle (num -1);
}

int main()
{
    std::cout << "This program will run three different functions." << std::endl;
    std::cout << "The First function will reverse any word you would like." << std::endl;
    std::cout << "The Second function will add together as many numbers as " << std::endl;
    std::cout << "you like up to 100 numbers." << std::endl;
    std::cout << "The Third function will calculate the triangle number " << std::endl;
    std::cout << "of the number you enter." << std::endl;
    std::cout << std::endl;
    
    int choice;
    // It will run a do while loop until the user enters 4 to exit program
    do
    {
    std::cout << "Enter '1' to reverse your word " << std::endl;
    std::cout << "Enter '2' to add an array of numbers " << std::endl;
    std::cout << "Enter '3' for the triangle method  " << std::endl;
    std::cout << "Enter '4' to end the program " << std::endl;
    std::cin >> choice;
    std::cout << std::endl;
        
    // Input verification.
    while ((choice < 1) || (choice > 4))
    {
        std::cout << "Please enter 1, 2, 3, or 4 : ";
        std::cin >> choice;
    }
    
    //Reverse Function
    if (choice == 1)
    
        {
            std::cout << "Enter a string " << std::endl;
            std::string input;
            std::cin >> input;
            reverse(input);
            
        }
    //Sum Function
    else if (choice == 2)
    {
            int num;
            int count = 0;
            int arrSize = 100;
            int array[arrSize];
            std::cout << "Enter a number or -1 to quit" << std::endl;
            std::cin >> num;
            while (num != -1 && num < arrSize)
            {
                array[count] = num;
                count++;
                std::cout << "Enter a number or -1 to quit" << std::endl;
                std::cin >> num;
		array[count] = num;
            }
            std::cout << sum(array, count) << std::endl;
    }
    //Triangle Function
    else if (choice == 3)
    {
            int num;
            std::cout << "Enter a number" << std::endl;
            std::cin >> num;
            std::cout << triangle(num) << std::endl;
        
    }
    
    } while (choice != 4);
    
    
    return 0;
}
