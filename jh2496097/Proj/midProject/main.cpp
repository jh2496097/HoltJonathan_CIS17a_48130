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
//struct Objects
//{
    //cant initialize in structures
    //int ob1 [2][2] = {1,1,1,1};
    //int ob2 [2][2] = {1,1,1,1};
//};
void outputBegin ();
int randObject ();
int **objectNum (int num);
void outputTbl(int **, int, int);
int **fillGrid (int , int);
bool isOver (int **tbl);
void destroy (int**, int);
void objtPlcmnt(int **tble, int spot);

int main(int argc, char** argv) {
    //making table
    int **table = fillGrid (ROWS, COLS);
    bool game;
    int spot;
    int count = 0;
    //suppose to be random num between 1 n 5
    int num = 1;
    //begin function
    outputBegin ();
    outputTbl(table, ROWS, COLS);
    do
    {
        int **object = objectNum (num);
        cout << "Pick a spot to place object (1 to 8): " ;
        cin >> spot;
    /*while (spot < 1 || spot > 8){//{v > 100 || v <= 0)
        cout << "Pick a spot between 1 and 8!!!" << endl;
        cin >> spot;
    }*/
    //IMPORTANT BOUNDS CHECKING AND PLACEMENT
    //first area checks spot choice compared to column size of object
    //rest makes sure number is 1 - 8
        while ((spot-1) + TWO > 8 || spot < 1 || spot > 8){
            cout << "Over Bounds will occur!!!!" << endl;
            cout << "Cannot place there please pick another:" << endl;
            cin >> spot;
        }
       objtPlcmnt(table, spot);
     //object for any spot 1 - 8 only
       /*for (int k = 1; k < 9; k++)
       {
        //int realSpot =0;
        //int rowCount =0, colCount =0;
        //object1 only spot 6 only
            if (spot == k)
            {
                for (int i=ROWS-1; i >= ROWS-TWO; i--){
                    for(int j=0; j < TWO; j++)  {
                        table [i][j+spot-1] = 1;
                    }
                }
            }  //this is full reverse but dont need full reverse
        /*for (int i = ROWS-1; i  >=0; i--)
        for(int j = COLS-1; j >= 0; j--)*/
        //}
    
        outputTbl(table, ROWS, COLS);
        destroy (object, TWO);
        //checking if lost
        game = isOver(table);
    }while(game == true);
    destroy(table, ROWS);
    
    
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
/*
 * Function fills a table with numbers by the set amount of ROWS n COLS
 * sets each one to 0 and then returns the 2D pointer
 */
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
/*
 * Deleting allocated memory for 2D arrys/ptrs
 */
void destroy(int **array,int rows)
{
    //Destroy in reverse order of creation
    for(int i=0;i<rows;i++)
    {
        delete []array[i];
    }
    delete []array;
}
/*
 * rand function getting a random number between 1 and 5 in respect to 5
 * diff objects
 */ 
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
        cout << "\tThis is your object : " << endl;
        for (int i=0; i <TWO; i++){//rows
            cout << "\t";
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
        cout << "\tThis is your object : " << endl  ;
        for (int i=0; i <ONE; i++){//rows
            cout << "\t";
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
        object = object1;
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
void spotChoice (int **tbl, int **obj, int spot, int col){
    cout << "Enter the column you wish to place the object:" << endl;
    cin >> spot;
    
    while (spot + col >= 8 ){
        cout << "Over Bounds will occur!!!!" << endl;
        cout << "Cannot place there please pick another:" << endl;
        cin >> spot;
    }
    //object1
    if (spot == 3)
    {
        for (int i=ROWS-1; i >= ROWS-TWO; i--){
            for(int j=0; j < TWO; j++){
                tbl [i][j+spot-1] = 1;
            }
        }
        /*for (int i = ROWS-1; i  >=0; i--)
        for(int j = COLS-1; j >= 0; j--)*/
    }
}
/*
 * check to see if a column is full and if it is then game over
 */
bool isOver (int **tbl)
{
    bool lose;
    //for (int i =0; i < ROWS; i++){ actually dont need to check columns
    int i = 0;
    for (int col=0; col < COLS;col++){
        //[0][j] because this would start from the top left of table
        if (tbl[i][col] == 1)
        {
            lose = false;
        }
        else
            lose = true;
    }
    return lose;
}
void objtPlcmnt(int **tble, int spot)
{
    int counter =0;
    //object for any spot 1 - 8 only
       //for (int k = 1; k < 9; k++)
       //{
        //object1 only spot 6 only
            //if (spot == k)
            int j = spot-1;
                //starting from bottom left to top
                for (int i =ROWS-1 ; i >= 0; i--){
                    //for (int j = spot-1; j < COLS; j++)
                    //{
                        
                    
                    if (tble [i][j] != 0){
                        counter++;
                        cout << "hi" << endl;
                    }
                }
            for (int i =ROWS-1 ; i >= 0; i--){
                    if (tble [i][j] != 1){
                         for (int i=ROWS-1; i >= ROWS-TWO; i--){
                              for(int j=0; j < TWO; j++)  {
                                   tble [i-counter][j+spot-1] = 1;
                              }
                         }
                    }
                        //else
                           // counter++;
                
                        
                        //else
                            //tble [i-TWO][j+spot-1] = 1;
                    
                }
              //this is full reverse but dont need full reverse
        /*for (int i = ROWS-1; i  >=0; i--)
        for(int j = COLS-1; j >= 0; j--)*/
            
       //}
}