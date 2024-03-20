//=======================
//Name: Alexander Thebolt
//Date: 04-05-2023
//Desc: Program 1
//=======================

#include <iostream>
#include "string"

using namespace std;

int multiplication(int, int, int);
int multiplication(int, int);

int numberSum(int, int);
int numberSum(int);

int triangleBlocks(int, int, int);
int triangleBlocks(int);

int power(int, int, int);
int power(int, int);

int countX(string, int, int);
int countX(string);

int main()
{
    cout << "GIVEN 0, 5 MULT: " << multiplication(0, 5) << endl;
    cout << "GIVEN 2080931 NUM-SUM: " << numberSum(2080931) << endl;
    cout << "GIVEN 1 TRI-BLOCKS: " << triangleBlocks(1) << endl;
    cout << "BASE 2 POWER 10 ANSWER: " << power(2, 10) << endl;
    cout << "GIVEN xyz NUM-Xs: " << countX("xyz") << endl;
}

//======================
//functions
//======================

int multiplication(int number, int times, int product)
{
    if (times == 0)
    {
        return product;
    }
    else
    {
        product = product + number;

        return multiplication(number, times-1, product);
    }
}

int numberSum(int number, int sum)
{
    if (number == 0)
    {
        return sum;
    }
    else
    {
        if (number % 10 != 0)
        {
            number = number - 1;
            sum++;
        }
        else
        {
            number = number / 10;
        }

        return numberSum(number, sum);
    }
}

int triangleBlocks(int rows, int rowSize, int total)
{
    if (rows == 0)
    {
        return total;
    }
    else
    {
        total = total + rowSize;
        
        return triangleBlocks(rows - 1, rowSize + 1, total);
    }
}

int power(int base, int exp, int product)
{
    if (exp == 0)
    {
        return product;
    }
    else
    {
        product = product * base;

        return power(base, exp - 1, product);
    }
}

int countX(string word, int count, int pos)
{
    if (pos == word.length())
    {
        return count;
    }
    else
    {
        if (word.at(pos) == 'x' || word.at(pos) == 'X')
        {
            count++;
        }
        
        return countX(word, count, pos + 1);
    }
}

//===============================
//Drivers
//===============================

int multiplication(int number, int times)
{
    return multiplication(number, times, 0);
}

int numberSum(int number)
{
    return numberSum(number, 0);
}

int triangleBlocks(int rows)
{
    //if there are no rows, then there are no blocks
    if (rows == 0)
    {
        return 0;
    }

    return triangleBlocks(rows, 1, 0);
}

int power(int base, int exp)
{
    //any number to the exp of 0 is 1.
    if (exp == 0)
    {
        return 1;
    }

    return power(base, exp, 1);
}

int countX(string word)
{
    return countX(word, 0, 0);
}