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


using namespace std;

/*
 * 
 */
const int ROWS = 18;
const int COLS = 8;
void outputBegin ();
void outputTbl(int **, int, int);
int **fillGrid (int , int);
void destroy (int**, int);

int main(int argc, char** argv) {
    outputBegin ();
    int **table = fillGrid (ROWS, COLS);
    //fillGrid (table, ROWS);
    
    outputTbl(table, ROWS, COLS);
    int object [2][2] = {1,1,1,1};
    int spot;
    cout << "Pick a spot to place object: " ;
    cin >> spot;
    if (spot == 5)
    {
        for (int i=0; i < 2;i++)
        for(int j=0; j<2; j++)
        table [i][spot+j] = 1;
    }
    for (int i=0; i < 2;i++)
        for(int j=0; j<2; j++)
        cout << object[i][j]  << "  " << endl;
    outputTbl(table, ROWS, COLS);
    
    destroy(table, ROWS);
    
    return 0;
}
void outputTbl(int **ptr, int rows, int cols)
{
    int count = 0;
    for (int i = 0 ; i <rows; i++)
    {
        cout << "\t\t";
        for(int j = 0; j < cols; j++)
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