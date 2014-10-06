/* 
 * Jonathan Holt
 * C++ objects
 * midterm
 * i certify this is my work
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cctype>
#include <cstring>
#include <ctime>

using namespace std;

//table
const int ROWS = 18;
const int COLS = 8;

enum ObSpots {ONE = 1 , TWO = 2, THREE = 3, FOUR = 4, FIVE = 5};
//diff objects to place on table
const int object1 [TWO][TWO] = {1,1,1,1};
const int object2 [ONE][THREE] = {1,1,1};
const int object3 [FOUR][ONE] = {1,1,1,1};
const int object4 [TWO][THREE] = {1,1,1,1,1,1};
const int object5 [THREE][TWO] = {1,1,1,1,1,1};
struct Objects
{
    //int ob1 [2][2] = {1,1,1,1};
    //int ob2 [2][2] = {1,1,1,1};
};
void outputBegin ();
int randObject ();
int **objectNum (int num);
void outputTbl(int **, int, int);
int **fillGrid (int , int);

void destroy (int**, int);

int main(int argc, char** argv) {
    //making table
    int **table = fillGrid (ROWS, COLS);
    
    int spot;
    int count = 0;
    
    for (int i=0; i < TWO;i++)
    {
        for(int j=0; j<TWO; j++)
        {
           cout << object1[i][j]  << "  ";
           count++;
           if (count == TWO)
           {
               cout <<  endl;
               count = 0;
           }
        }
    }
    int num = 1;
    //int **object = **objectNum (num);
    outputBegin ();
    outputTbl(table, ROWS, COLS);
    int **object = objectNum (num);
    cout << "Pick a spot to place object: " ;
    cin >> spot;
    //object1
    if (spot == 3)
    {
        for (int i=ROWS-1; i >= ROWS-TWO; i--)
        {
            for(int j=0; j < TWO; j++)
            {
                table [i][j+spot-1] = 1;
            }
        }
        /*for (int i = ROWS-1; i  >=0; i--)
        for(int j = COLS-1; j >= 0; j--)*/
    }
    
    outputTbl(table, ROWS, COLS);
    
    destroy(table, ROWS);
    destroy (object, TWO);
    return 0;
}
void outputTbl(int **ptr, int rows, int cols)
{
    int count = 0;
    for (int i = 0; i < ROWS; i++)
    {
        cout << "\t\t";
        for(int j = 0; j < COLS; j++)
        {
            cout << ptr[i][j] << "   ";
            count++;
            if (count == COLS)
            {
                cout << endl;
                count = 0; 
            }
        }
    }
    cout << "\t    -------------------------------------" << endl;
    cout << "Columns \t1   2   3   4   5   6   7   8     "<< endl;
}
int **fillGrid (int ROWS, int COLS)
{
    int **array=new int*[ROWS];
    //creating 2D array
    for(int i=0;i<ROWS;i++)
    {
        array[i]=new int[COLS];
    }
    //setting to 0
    for (int row = 0; row < ROWS; row++)
    {
        for (int col = 0; col < COLS; col++)
        {
            array[row][col] = 0;
        }
    }
    return array;
}
/*
 * Information of beginning of game
 */
void outputBegin ()
{
    cout << "    /---------- /|" << endl;
    cout << "  /___________ / | " << endl;
    cout << " |            |  | " << endl;
    cout << " |            |  /             __ " << endl;
    cout << " |----    ----| /          ___|  |____          ( )" << endl;
    cout << "     |    | |   /------\\  |          |  ______   __ " << endl;
    cout << "     |    | |  |   ___ |  |          | |   ___| |  |   /------|\n"; 
    cout << "     |    | |  |  |___|    ---|  |---  |  /     |  |  /   /_--|\n"; 
    cout << "     |    | |  \\  \\______     |  |     |  |     |  |  |_____ \\\n"; 
    cout << "     |    | |   \\________/    |  |     |  |     |  |  _____/ |\n"; 
    cout << "     |____|/                   __      |__|     |__| |______/\n"; 
    cout << endl << endl;
    
    cout << "This is a console based tetris game." << endl << "The console is"
            " going to constantly output a table at the user" << endl << "and"
            " the user will be promtped with an object/tetris block." << endl <<
            "User then must pick a column in which to place that item." << endl
            << "Filling a whole row will cause that row to be deleted and "
            <<endl << "points will be awarded. " << endl;
}
void destroy(int **array,int rows)
{
    //Destroy in reverse order of creation
    for(int i=0;i<rows;i++)
    {
        delete []array[i];
    }
    delete []array;
}
int randObject ()
{
    int num;
    num = rand()%5+1;
    return num;
}
/*
 * Creating diff object to be placed in the table similiar to objects at 
 * top with const creation using dynamic allocation here
 */
int **objectNum (int num)
{
    int count =0;
    int **object;
    if (num == 1)
    {
        object=new int*[TWO];//rows
        //creating 2D array
        for (int i=0; i < TWO;i++)//rows
        {
            object[i]=new int[TWO];//cols
        }
        //once created filling and outputting
        for (int i=0; i <TWO; i++){//rows
           for(int j=0; j <TWO; j++){//cols
              object[i][j]= 1;
              cout << object[i][j]  << "  ";
              count++;
              if (count == TWO)
              {
                  cout <<  endl;
                  count = 0;
              }
           }
        }
    }
    if (num == 2)
    {
        object=new int*[ONE];//rows
        //creating 2D array
        for (int i=0; i < THREE;i++)//rows
        {
            object[i]=new int[THREE];//cols
        }
        //once created filling and outputting
        for (int i=0; i <ONE; i++){//rows
           for(int j=0; j <THREE; j++){//cols
              object[i][j]= 1;
              cout << object1[i][j]  << "  ";
              count++;
              if (count == THREE)
              {
                  cout <<  endl;
                  count = 0;
              }
           }
        }
    }
    /*if (num == 3)
    {
        objectNum = object3;
        for (int i=0; i < TWO;i++)
        {
           for(int j=0; j<TWO; j++)
           {
              cout << object1[i][j]  << "  ";
              count++;
              if (count == TWO)
              {
                  cout <<  endl;
                  count = 0;
              }
           }
        }
    }
    if (num == 4)
    {
        objectNum = object4;
        for (int i=0; i < TWO;i++)
        {
           for(int j=0; j<TWO; j++)
           {
              cout << object1[i][j]  << "  ";
              count++;
              if (count == TWO)
              {
                  cout <<  endl;
                  count = 0;
              }
           }
        }
    }
    if (num == 5)
    {
        objectNum = object5;
        for (int i=0; i < TWO;i++)
        {
           for(int j=0; j<TWO; j++)
           {
              cout << object1[i][j]  << "  ";
              count++;
              if (count == TWO)
              {
                  cout <<  endl;
                  count = 0;
              }
           }
        }
    }*/
    return object;
}
