/* 
 * Jonathan Holt
 * C++ objects
 * project
 * i certify this is my work
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cctype>
#include <cstring>
#include <ctime>
#include <fstream>

using namespace std;

//table
const int ROWS = 18;
const int COLS = 8;

enum ObSpots {ONE = 1 , TWO, THREE, FOUR, FIVE};
//diff objects to place on table
const int object1 [TWO][TWO] = {1,1,
                                1,1};
const int object2 [ONE][THREE] = {1,1,1};
const int object3 [FOUR][ONE] = {1,
                                 1,
                                 1,
                                 1};
const int object4 [TWO][THREE] = {1,1,1,
                                  1,1,1};
const int object5 [THREE][TWO] = {1,1,
                                  1,1,
                                  1,1};
struct UserObj
{
    int **ptr;
    int rows;
    int cols;
};
void outputBegin ();
int randObject ();
int **objectNum (int num);
int **objectNum1 (int num, int&, int&);
void outputTbl(int **, int, int);
int **fillGrid (int , int);
bool isOver (int **tbl);
void destroy (int**, int);
//void objtPlcmnt(int **tble, int spot);
void objtPlcmnt(int **tble, int spot, int rowOb, int colOb);
int **newTable (int **tble, int &pts);
void spotChoice (int &spot, int col);

int main(int argc, char** argv) {
    //making table
    int **table = fillGrid (ROWS, COLS);
    srand (time(NULL));
    int **object;
    bool game;
    int rowOb =0;
    int colOb =0;
    int spot;
    int points = 0;
    
    //begin function
    outputBegin ();
    outputTbl(table, ROWS, COLS);
    do
    {
        int num = randObject ();
        switch (num)
        {
            case 1:
                object = objectNum (num);
                spotChoice (spot, TWO);
                objtPlcmnt(table, spot, TWO, TWO);
                destroy (object, TWO);
                break;
            case 2:
                object = objectNum (num);
                spotChoice (spot, THREE);
                objtPlcmnt(table, spot, ONE, THREE);
                destroy (object, ONE);
                break;
            case 3:
                object = objectNum (num);
                spotChoice (spot, ONE);
                objtPlcmnt(table, spot, FOUR, ONE);
                destroy (object, FOUR);
                break;
            case 4:
                object = objectNum (num);
                spotChoice (spot, THREE);
                objtPlcmnt(table, spot, TWO, THREE);
                destroy (object, TWO);
                break;
            case 5:
                object = objectNum (num);
                spotChoice (spot, TWO);
                objtPlcmnt(table, spot, THREE, TWO);
                destroy (object, THREE);
                break;
            case 6:
                object = objectNum1 (num, rowOb, colOb);
                spotChoice (spot, colOb);
                objtPlcmnt(table, spot, rowOb, colOb);
                destroy (object, rowOb);
        }
        table = newTable (table, points);
        cout << " YOUR CURRENT POINTS ARE : " << points << " KEEP GOING!!\n\n";
        //int **object = objectNum (num);
        //spotChoice (spot, TWO);

        outputTbl(table, ROWS, COLS);
        
        //checking if lost
        game = isOver(table);

    }while(game != false);
    destroy(table, ROWS);
    
    cout << "GAME IS OVER !!!!!!" << endl;
    cout << "Here is your final point count: " << points << endl;
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
            "User then must pick a column in which to place that object."<< endl
            << "Filling a whole row with 1's will cause that row to be deleted"
            " and"<<endl << "points will be awarded. " << endl;
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
    num = rand()%6+1;
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
              // TRY AND FINE OUT THIS INDEX !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
              //cout << **(object+(i * COLS)+j)  << "  ";
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
    if (num == 3)
    {
        object=new int*[FOUR];//rows
        //creating 2D array
        for (int i=0; i < FOUR;i++)//rows
        {
            object[i]=new int[ONE];//cols
        }
        //once created filling and outputting
        cout << "\tThis is your object : " << endl  ;
        for (int i=0; i <FOUR; i++){//rows
            cout << "\t";
           for(int j=0; j <ONE; j++){//cols
              object[i][j]= 1;
              cout << object1[i][j]  << "  ";
              count++;
              if (count == ONE)
              {
                  cout <<  endl;
                  count = 0;
              }
           }
        }
    }
    if (num == 4)
    {
        object=new int*[TWO];//rows
        //creating 2D array
        for (int i=0; i < TWO;i++)//rows
        {
            object[i]=new int[THREE];//cols
        }
        //once created filling and outputting
        cout << "\tThis is your object : " << endl  ;
        for (int i=0; i < TWO; i++){//rows
            cout << "\t";
           for(int j=0; j < THREE; j++){//cols
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
    if (num == 5)
    {
        object=new int*[THREE];//rows
        //creating 2D array
        for (int i=0; i < THREE;i++)//rows
        {
            object[i]=new int[TWO];//cols
        }
        //once created filling and outputting
        cout << "\tThis is your object : " << endl  ;
        for (int i=0; i < THREE; i++){//rows
            cout << "\t";
           for(int j=0; j < TWO; j++){//cols
              object[i][j]= 1;
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
    
    return object;
}
int **objectNum1 (int num, int &rowOb, int &colOb)
{
    UserObj object ;//= new UserObj;
    if (num == 6)
    {
        cout << "This is a BONUS PLAY!" << endl << "User is allowed to enter"
                " an object of their own choice." << endl << "The max size" 
                " you may enter is a 5x5." << endl;
        
        cout << "Enter a row(s) number between 1 n 5" << endl;
    //for (int i = 0 ; i < 5; i ++)
        int count=0;
        cin >> object.rows;
        while (object.rows > 5 || object.rows < 1){
            cout << "ENTER a number !only! between 1 n 5" << endl;
            cin >> object.rows;
        }
    cout << "Enter a column(s) number between 1 n 5" << endl;
    //for (int i = 0 ; i < 5; i ++)
    
    cin >> object.cols;
        while (object.cols > 5 || object.cols < 1){
            cout << "ENTER a number !only! between 1 n 5" << endl;
            cin >> object.cols;
        }     
    //creating user object
    object.ptr = new int *[object.rows];//rows
    for (int i = 0; i < object.rows; i++)//rows
    {
        object.ptr[i] = new int [object.cols];//cols
    }
    //once created filling and outputting
        cout << "\tThis is your object : " << endl;
        for (int i=0; i <object.rows; i++){//rows
            cout << "\t";
           for(int j=0; j <object.cols; j++){//cols
              object.ptr[i][j]= 1;
              cout << object.ptr[i][j]  << "  ";
              count++;
              if (count == object.cols)
              {
                  cout <<  endl;
                  count = 0;
              }
           } 
        }
        rowOb = object.rows;
        colOb = object.cols;
        /*for(int i=0;i<object.rows;i++)
        {
            delete []object.ptr[i];
        }
            delete []object.ptr;*/
    //}
    return object.ptr;
    }
}
void spotChoice (int &spot, int col){
    cout << "Pick a spot to place object (1 to 8): " ;
        cin >> spot;
    //IMPORTANT BOUNDS CHECKING AND PLACEMENT
    //first area checks spot choice compared to column size of object
    //rest makes sure number is 1 - 8
        while ((spot-1) + col > 8 || spot < 1 || spot > 8){
            cout << "Over Bounds will occur!!!!" << endl;
            cout << "Cannot place there please pick another:" << endl;
            cin >> spot;
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
            break;
        }
        else
            lose = true;
    }
    return lose;
}
void objtPlcmnt(int **tble, int spot, int rowOb, int colOb)
{
    //columns
    int col = spot-1;
    int row = ROWS;
    //starting from bottom left to top
    for (int i = ROWS-1; i >= 0; i--){
       /* going to table then since object is size TWO looking at two spots to
        * check for a 1. If there is a one in either spot i set rows to that
        * spot to then tell me which row to start building from
        */
        for (int k = 0; k < colOb; k++)
        {
         if (tble[i][col+k] == 1 )//|| tble[i][col+1] == 1)//|| tble[i][col+1+1] == 1)// for three columns
         {
             //setting row
             row = i;
         }            
        }
     }
    /*
     * Going through with 2 loops to place a [TWO][TWO] object on the table
     * with the right row to start from and checking to make sure top row is not
     * a one or else i break from it to not cause bounds issues.
     */
     for (int i=row-1; i >= row-rowOb; i--){
          for(int j=0; j < colOb; j++)  {
              //checking if spot[col] top of table = 1 if so break from placing
              //one
              if (tble[0][col] == 1){
                  //breaking from loop cycle
                  break;
              }
              else
               tble [i][j+spot-1] = 1;                          
          }                
      }
}
/*
 * This is a point system function. Will check if an entire row is filled with
 * ones then if it is points will be awarded. then after rows is added for 
 * points the function will copy everything from the top of the rows and place 
 * it down a row. returns refilled table
 */
int **newTable (int **tble, int &pts){
    //int pts =0;
    int dstryRow =0;
    int **newTble = fillGrid (ROWS, COLS);
    //do{
    /*
     * copying table
     */
    for (int i =0; i < ROWS; i++){
        for (int j =0; j < COLS; j++){
            newTble[i][j] = tble[i][j];
        }
    }
    //for (int j =0; j < ROWS; j++){
        
        for (int i = 0; i < ROWS; i++)
        {
            if (tble[i][0] == 1 && tble[i][1] == 1 &&tble[i][2] == 1 &&
                    tble[i][3] == 1 &&tble[i][4] == 1 &&tble[i][5] == 1 &&
                    tble[i][6] == 1 &&tble[i][7] == 1)
            {
                pts += 10;
                for (int i = 0; i < ROWS-1; i++){
                   for (int j =0; j < COLS ; j++){
                     tble[i+1][j] = newTble[i][j];
                   }
                }
            }
        }
    //}
    destroy (newTble, ROWS);
    return tble;
    //}while(true);
}