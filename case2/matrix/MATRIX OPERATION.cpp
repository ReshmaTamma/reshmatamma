/*FILE NAME:MATRIX OPERATION.cpp
 *PURPOSE  :To process the given matrix in row wise ,column wise and diagonal wise to replace the repeated elements only once and the empty spaces by '*'
 *DATE     :10/06/020
 *AUTHOR   :RESHMA.T
 */
#include<iostream>
#include<string.h>
using namespace std;
//variables declared globally
int Row,Column,irow,icolumn;
char inputmatrix[50][50],outputmatrix[50][50];

void readmatrix();
void showmatrix();
void rowwise();
void columnwise();
void diagonal();
void cornercase();
//main function
int main(int argc,char **argv)
{
    if(argc>=2)
    {
      if(strcmp(argv[1],"-h")==0)					//help command
       {
        cout<<" ***********PROGRAM USAGE*************** "<<endl;
        cout<<"This program is coded to process the elements of the matrix in row wise ,column wise and diagonal wise to replace the repeating elements by one time and fill the remaing spaces by'*'"<<endl;
        cout<<" ------------for each processing you have to give the input again---------------"<<endl;
        cout<<"************to check if the matrix falls under cornercase I have written the code for row matrix amd column matrix*******************"<<endl;
        cout<<"********Reason to check only row matrix and column matrix in cornercase is according to my knowledge  that only such type of matrix can have cornercase"<<endl;
       }
       else
       {
           cout<<"you have given wrong help command "<<endl;
       }
    }   
    else
   {
    int choice;
    cout<<"Enter the number of rows"<<endl;
    cin>>Row;
    cout<<"enter the number of columns"<<endl;
    cin>>Column;
    cout<<"Enter the elements of the matrix as either 0 or 1"<<endl;
    readmatrix();
    cout<<"The matrix is"<<endl;
    showmatrix();
    cout<<"The operations can be performed are:"<<endl;
    cout<<"1 --- rowwise"<<endl;
    cout<<"2 --- columnwise"<<endl;
    cout<<"3 --- diagonalwise"<<endl;
    cout<<"4 --- cornercase"<<endl;
    cout<<"Enter the choice:";
    cin>>choice;
    switch(choice)
    {
        case 1:
              cout<<"Your choice is 1:rowwise"<<endl;
              rowwise();
              break;
        case 2:
              cout<<"Your choice is 2:columnwise"<<endl;
              columnwise();
              break;
        case 3:
              cout<<"Your choice is 3:diagonalwise"<<endl;
              diagonal();
              break;
        case 4:
              cout<<"Your choice is 4:cornercase"<<endl;
              cornercase();
              break;
        default:
              cout<<"Invalid choice"<<endl;
    }
   }    
}
/*
function name:readmatrix
return type:void
function usage:To read the elements of the matrix by user
*/
void readmatrix()
{
    
    for(irow=0;irow<Row;irow++)
    {
        for(icolumn=0;icolumn<Column;icolumn++)
        {
            
            cin>>inputmatrix[irow][icolumn];
        }
        
    }
}
/*
function name:showmatrix
return type:void
function usage:To display the elements of the matrix by user
*/

void showmatrix()
{
    for(irow=0;irow<Row;irow++)
    {
        for(icolumn=0;icolumn<Column;icolumn++)
        {
            cout<<inputmatrix[irow][icolumn]<<" " ;
        }
            cout<<endl;
    }      
}
/*
function name:rowwise
return type:void
function usage:To process the elements of the matrix in rowwise 
*/

void rowwise()
{
    for(irow=0;irow<Row;irow++)
    {
        for(icolumn=0;icolumn<Column-1;icolumn++)
        {
            if(inputmatrix[irow][icolumn]==inputmatrix[irow][icolumn+1])
            {
                outputmatrix[irow][icolumn]=inputmatrix[irow][icolumn];
                outputmatrix[irow][icolumn+1]='*';
            }
            else
            {
                 outputmatrix[irow][icolumn]=inputmatrix[irow][icolumn];
                 
                 outputmatrix[irow][icolumn+1]=inputmatrix[irow][icolumn+1];
            }
           if(icolumn>=1)
            {
              
                  if(inputmatrix[irow][icolumn-1]==inputmatrix[irow][icolumn+1])
                   {
                       if(inputmatrix[irow][icolumn]==inputmatrix[irow][icolumn+1])
                       {
                           outputmatrix[irow][icolumn+1]='*' ;
                           outputmatrix[irow][icolumn]='*';
                       }
                       else
                       {
                           
                         outputmatrix[irow][icolumn]=inputmatrix[irow][icolumn] ;
                         //outputmatrix[irow][icolumn+1]='*';
                       }
                   }   
                  else
                     {
                         outputmatrix[irow][icolumn]=inputmatrix[irow][icolumn+1];
                         outputmatrix[irow][icolumn+1]='*';
                        
                     }
                    
            }
        }
    }
   for(irow=0;irow<Row;irow++)
   {
       for(icolumn=0;icolumn<Column;icolumn++)
       {
          if((outputmatrix[irow][icolumn]=='*')&&(outputmatrix[irow][icolumn+1]=='*'))
           {
               outputmatrix[irow][icolumn]='*';
               outputmatrix[irow][icolumn+1]='*';
               outputmatrix[irow][icolumn+2]='*';
           }
           if(outputmatrix[irow][icolumn]==outputmatrix[irow][icolumn+1])
           {
               //outputmatrix[irow][icolumn+1]=outputmatrix[irow][icolumn-1];
               outputmatrix[irow][icolumn]=outputmatrix[irow][icolumn];
               outputmatrix[irow][icolumn+1]=outputmatrix[irow][icolumn+2];
               outputmatrix[irow][icolumn+2]='*';
           }
           if((outputmatrix[irow][icolumn]==1||0)&&(outputmatrix[irow][icolumn+1]=='*'))
           {
               outputmatrix[irow][icolumn]=outputmatrix[irow][icolumn+1];
               outputmatrix[irow][icolumn+1]='*';
               outputmatrix[irow][icolumn+2]='*';
           }
       }   
   } 
   for(irow=0;irow<Row;irow++)
   {
       for(icolumn=0;icolumn<Column;icolumn++)
       {
           if(outputmatrix[irow][icolumn]=='*')
           {
               outputmatrix[irow][icolumn]=outputmatrix[irow][icolumn+1];
               outputmatrix[irow][icolumn+1]='*';
               outputmatrix[irow][Column-1]='*';
           }
           cout<<outputmatrix[irow][icolumn]<<" ";
       }
         cout<<endl;
   }
}

/*
function name:columnwise
return type:void
function usage:To process the elements of the matrix in columnwise 
*/


void columnwise()
{
    for(icolumn=0;icolumn<Column;icolumn++)
    {
        for(irow=0;irow<Row-1;irow++)
        {
            if(inputmatrix[irow][icolumn]==inputmatrix[irow+1][icolumn])
            {
                outputmatrix[irow][icolumn]=inputmatrix[irow][icolumn];
                outputmatrix[irow+1][icolumn]='*';
            }
            else
            {
                 outputmatrix[irow][icolumn]=inputmatrix[irow][icolumn];
                 
                 outputmatrix[irow+1][icolumn]=inputmatrix[irow+1][icolumn];
            }
           if(irow>=1)
            {
              
                  if(inputmatrix[irow-1][icolumn]==inputmatrix[irow+1][icolumn])
                   {
                       if(inputmatrix[irow][icolumn]==inputmatrix[irow+1][icolumn])
                       {
                           outputmatrix[irow+1][icolumn]='*' ;
                           outputmatrix[irow][icolumn]='*';
                       }
                       else
                       {
                           
                         outputmatrix[irow][icolumn]=inputmatrix[irow][icolumn] ;
                         
                       }
                   }   
                  else
                     {
                         outputmatrix[irow][icolumn]=inputmatrix[irow+1][icolumn];
                         outputmatrix[irow+1][icolumn]='*';
                        
                     }
                    
            }
        }
    }
   for(icolumn=0;icolumn<Column;icolumn++)
   {
       for(irow=0;irow<Row;irow++)
       {
          if((outputmatrix[irow][icolumn]=='*')&&(outputmatrix[irow+1][icolumn]=='*'))
           {
               outputmatrix[irow][icolumn]='*';
               outputmatrix[irow+1][icolumn]='*';
               outputmatrix[irow+2][icolumn]='*';
           }
           if(outputmatrix[irow][icolumn]==outputmatrix[irow+1][icolumn])
           {
               
               outputmatrix[irow][icolumn]=outputmatrix[irow+1][icolumn];
               outputmatrix[irow+1][icolumn]=outputmatrix[irow+2][icolumn];
               outputmatrix[irow+2][icolumn]='*';
           }
           if((outputmatrix[irow][icolumn]==1||0)&&(outputmatrix[irow+1][icolumn]=='*'))
           {
               outputmatrix[irow][icolumn]=outputmatrix[irow+1][icolumn];
               outputmatrix[irow+1][icolumn]='*';
               outputmatrix[irow+2][icolumn]='*';
           }
       }   
   } 
   for(icolumn=0;icolumn<Column;icolumn++)
   {
       for(irow=0;irow<Row;irow++)
       {
           if(outputmatrix[irow][icolumn]=='*')
           {
               outputmatrix[irow][icolumn]=outputmatrix[irow+1][icolumn];
               outputmatrix[irow+1][icolumn]='*';
               outputmatrix[Row-1][icolumn]='*';
               
           }
       }
   }
   for(irow=0;irow<Row;irow++)
   {
       for(icolumn=0;icolumn<Column;icolumn++)
       {
           cout<<outputmatrix[irow][icolumn]<<" ";
           
       }
       cout<<endl;
   }
}

/*
function name:diagonal
return type:void
function usage:To process the elements of the diagonals of matrix
*/


void diagonal()
{
    char diagonalmatrix[50][50];
    //first diagonal processing
   // cout<<"first diagonal"<<endl;
   for(irow=0;irow<Row-1;irow++)
    {
        if(inputmatrix[irow][irow]==inputmatrix[irow+1][irow+1])
        {
            outputmatrix[irow][irow]=inputmatrix[irow][irow];
            outputmatrix[irow+1][irow+1]='*';
        }
        else
        {
            outputmatrix[irow][irow]=inputmatrix[irow][irow];
            outputmatrix[irow+1][irow+1]=inputmatrix[irow+1][irow+1];
        }
        if(irow>1)
        {
            if(inputmatrix[irow-1][irow-1]==inputmatrix[irow+1][irow+1])
                   {
                       if(inputmatrix[irow][irow]==inputmatrix[irow+1][irow+1])
                       {
                           outputmatrix[irow+1][irow+1]='*' ;
                           outputmatrix[irow][irow]='*';
                       }
                       else
                       {
                           
                         outputmatrix[irow][irow]=inputmatrix[irow][irow] ;
                         outputmatrix[irow+1][irow+1]='*';
                         
                       }
                   }   
                  else
                        {
                           outputmatrix[irow][irow]=inputmatrix[irow+1][irow+1];
                           outputmatrix[irow+1][irow+1]='*'; 
                        }
        }
    }
   for(irow=0;irow<Row;irow++)
   {
          if((outputmatrix[irow][irow]=='*')&&(outputmatrix[irow+1][irow+1]=='*'))
           {
               outputmatrix[irow][irow]='*';
               outputmatrix[irow+1][irow+1]='*';
               outputmatrix[irow+2][irow+2]='*';
           }
           if(outputmatrix[irow][irow]==outputmatrix[irow+1][irow+1])
           {
               
               outputmatrix[irow][irow]=outputmatrix[irow][irow];
               outputmatrix[irow+1][irow+1]='*';
               outputmatrix[irow+2][irow+2]='*';
           }
           if((outputmatrix[irow][irow]==1||0)&&(outputmatrix[irow+1][irow+1]=='*'))
           {
               outputmatrix[irow][irow]=outputmatrix[irow+1][irow+1];
               outputmatrix[irow+1][irow+1]='*';
               outputmatrix[irow+2][irow+2]='*';
           }
         
   } 
   
   for(irow=0;irow<Row;irow++)
   {
           if(outputmatrix[irow][irow]=='*')
           {
               outputmatrix[irow][irow]=outputmatrix[irow+1][irow+1];
               outputmatrix[irow+1][irow+1]='*';
               outputmatrix[Row-1][Row-1]='*';
           }
    }
    for(irow=0;irow<Row;irow++)
    {
        for(icolumn=0;icolumn<Column;icolumn++)
        {
            if(irow!=icolumn)
            {
                outputmatrix[irow][icolumn]=inputmatrix[irow][icolumn];
            }
           
        } 
            
    }
    
    //second diagonal processing
   
    for(irow=0;irow<Row;irow++)
    {
        for(icolumn=Column-1;icolumn>0;icolumn--)
        {
            if(icolumn==((Column-1)-irow))
            {
                if(outputmatrix[irow][icolumn]==outputmatrix[irow+1][icolumn-1])
                 {
                     diagonalmatrix[irow][icolumn]=outputmatrix[irow][icolumn];
                     diagonalmatrix[irow+1][icolumn-1]='*';
                 }
                else
                {
                   diagonalmatrix[irow][icolumn]=outputmatrix[irow][icolumn];
                   diagonalmatrix[irow+1][icolumn-1]=outputmatrix[irow+1][icolumn-1];
                }
               if(irow>1)
               {
                 if(outputmatrix[irow-1][icolumn+1]==outputmatrix[irow+1][icolumn-1])
                   {
                       if(outputmatrix[irow][icolumn]==outputmatrix[irow+1][icolumn-1])
                       {
                           diagonalmatrix[irow+1][icolumn-1]='*' ;
                           diagonalmatrix[irow][icolumn]='*';
                       }
                       else
                       {
                           
                         diagonalmatrix[irow][icolumn]=outputmatrix[irow][icolumn] ;
                         diagonalmatrix[irow+1][icolumn-1]='*';
                         
                       }
                   }   
                  else
                     {
                            diagonalmatrix[irow][icolumn]=outputmatrix[irow+1][icolumn-1];
                            diagonalmatrix[irow+1][icolumn-1]='*';  
                      }
                        
                     
               }    
            
            }
        }
        
    } 
   for(irow=0;irow<Row;irow++)
   {
       for(icolumn=Column-1;icolumn>0;icolumn--)
       {
         if(icolumn==((Column-1)-irow))
         {
          if((diagonalmatrix[irow][icolumn]=='*')&&(diagonalmatrix[irow+1][icolumn-1]=='*'))
           {
               diagonalmatrix[irow][icolumn]='*';
               diagonalmatrix[irow+1][icolumn-1]='*';
               diagonalmatrix[irow+2][icolumn-2]='*';
           }
           if(diagonalmatrix[irow][icolumn]==diagonalmatrix[irow+1][icolumn-1])
           {
               
               diagonalmatrix[irow][icolumn]=diagonalmatrix[irow][icolumn];
               diagonalmatrix[irow+1][icolumn-1]='*';
               diagonalmatrix[irow+2][icolumn-2]='*';
           }
           if((diagonalmatrix[irow][icolumn]==1||0)&&(diagonalmatrix[irow+1][icolumn-1]=='*'))
           {
               diagonalmatrix[irow][icolumn]=diagonalmatrix[irow+1][icolumn-1];
               diagonalmatrix[irow+1][icolumn-1]='*';
               diagonalmatrix[irow+2][icolumn-2]='*';
           }
       } 
       }
   } 
   
   for(irow=0;irow<Row;irow++)
   {
       for(icolumn=Column-1;icolumn>0;icolumn--)
       {
          if(icolumn==((Column-1)-irow))
          {
            if(diagonalmatrix[irow][icolumn]=='*')
            {
               diagonalmatrix[irow][icolumn]=diagonalmatrix[irow+1][icolumn-1];
               diagonalmatrix[irow+1][icolumn-1]='*';
               diagonalmatrix[Row-1][0]='*';
            }
          }  
       }
    }
    for(irow=0;irow<Row;irow++)
    {
        for(icolumn=0;icolumn<Column;icolumn++)
        {
            if(icolumn!=((Column-1)-irow))
            {
                diagonalmatrix[irow][icolumn]=outputmatrix[irow][icolumn];
            }
            cout<<diagonalmatrix[irow][icolumn]<<" ";
        } 
            cout<<endl;
    }
    
    
   
}

/*
function name:cornercase
return type:void
function usage:To process the elements of the matrix in rowwise and columnwise to check whether the given matrix falls under cornercase
*/


void cornercase()
{
    int count=0;
    if(Row==1)
    {
        for(irow=0;irow<Row;irow++) //row matrix
        {
            if(irow<1)
            {
               for(icolumn=0;icolumn<Column;icolumn++)
               {
                       rowwise();
               } 
            }
        } 
        for(irow=0;irow<Row;irow++)
        {
           for(icolumn=0;icolumn<Column;icolumn++)
               {
                 if(irow<1)
                 {
                     if(outputmatrix[irow][icolumn]==inputmatrix[irow][icolumn])
                        {
                            count=count+1;
                        }
                 }
               } 
        if(count==Column)
        {
             cout<<"Matrix has cornercase"<<endl;
        }
        else
        {
            cout<<"Matrix has no cornercase"<<endl;
        }
    } 
    }
else
    {
      for(icolumn=0;icolumn<Column;icolumn++)   //column matrix 
        {
            if(icolumn<1)
            {
               for(irow=0;irow<Row;irow++)
               {
                       columnwise();
               } 
            }
        } 
        for(icolumn=0;icolumn<Column;icolumn++)
        {
           for(irow=0;irow<Row;irow++)
               {
                 if(icolumn<1)
                 {
                     if(outputmatrix[irow][icolumn]==inputmatrix[irow][icolumn])
                        {
                            count=count+1;
                        }
                 }
               } 
        if(count==Row)
        {
             cout<<"Matrix has cornercase"<<endl;
        }
        else
        {
            cout<<"Matrix has no cornercase"<<endl;
        }
     } 
    }
    }    
        

