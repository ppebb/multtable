#include <iostream>
#include <ctime>
#include <iomanip>

const unsigned int ROWS = 10;
const unsigned int COLUMNS = 10;

void randomValue(unsigned int &, unsigned int &, unsigned int &);

int main() 
{   
  unsigned int rValue;
  unsigned int cValue;
  unsigned int pValue;

  unsigned int rowError; 
  unsigned int columnError;
  unsigned int productError;

  unsigned int userRowGuess;
  unsigned int userColumnGuess;

  char choice;  

  do 
  { 
    randomValue(rValue, cValue, pValue); 

    std::cout << "\033[2J\033[0;0H"; // This code clears the screen 
    std::cout << std::endl << std::endl;       
    std::cout << std::setw(35) << "++++++++++++++++++++++++" << std::endl;
    std::cout << std::setw(35) << "+ Multiplication Table +" << std::endl;
    std::cout << std::setw(35) << "++++++++++++++++++++++++" << std::endl;
    std::cout << std::endl << std::endl;   

    while (true)
    { 
      rowError = rValue;
      columnError = cValue;
      productError = pValue;

      if (productError == rowError * columnError)
      {
        productError--;
      }

      for (unsigned int row = 1; row <= ROWS; row++)
      {
        for (unsigned int column = 1; column <= COLUMNS; column++)
        {
          if (row == rowError && column == columnError)
          { 
            std::cout << "\t" << "" << productError;       
          }
          else
          {
            std::cout << "\t" <<  row * column;
          }
        }
      std::cout << std::endl;
      }  
      break;
    }


    std::cout << std::endl << std::endl;
    std::cout << "\t\t" << "Type in the column number " << std::endl;
    std::cout << "\t\t" << "of the location of the    " << std::endl;
    std::cout << "\t\t" << "error & then press        " << std::endl;
    std::cout << "\t\t" << "[Enter]: ";
    std::cin >> userColumnGuess;
    std::cout << std::endl;

    std::cout << "\t\t" << "Type in the row number " << std::endl;
    std::cout << "\t\t" << "of the location of the    " << std::endl;
    std::cout << "\t\t" << "error & then press        " << std::endl;
    std::cout << "\t\t" << "[Enter]: ";
    std::cin >> userRowGuess;
    std::cout << std::endl;

    if (userRowGuess != rowError && userColumnGuess != columnError)
    {
      std::cout << "\t\t" << "Your answer was incorrect!" << std::endl << std::endl;
      std::cout << "\t\t" << "Error value '" << productError << "' is located" << std::endl;
      std::cout << "\t\t" << "on row " << rowError << ", column " << columnError << "." << std::endl;
    }
    else
    {
      std::cout << "\t\t" << "You are correct! You win!" << std::endl;
    }


    std::cout << std::endl;
    std::cout << "\t\t" << "Would you like to play again?" << std::endl << std::endl;
    std::cout << "\t\t" << "Type in 'Y' for yes or 'N'" << std::endl;
    std::cout << "\t\t" << "for no & then press [Enter]: ";
    std::cin >> choice;

    while (choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N')
    {
      std::cout << std::endl;
      std::cout << "\t\t" << "Invalid entry. Only 'Y' or 'N'" << std::endl;
      std::cout << "\t\t" << "are accepted answers." << std::endl << std::endl;
      std::cout << "\t\t" << "Would you like to play again?" << std::endl << std::endl;
      std::cout << "\t\t" << "Type in 'Y' for yes or 'N' for" << std::endl;
      std::cout << "\t\t" << "no & then press [Enter]: ";
      std::cin >> choice;
    }   
    std::cout << std::endl;

  } while (choice == 'y' || choice == 'Y'); 

  std::cout << "\t\t" << "Press [Enter] to continue....." << std::endl;
  std::cin.get();
  std::cin.get();

  return 0;
}

void randomValue(unsigned int &rValue, unsigned int &cValue, unsigned int &pValue)
{ 
  srand((unsigned)time(NULL));

  unsigned int r = rValue = (rand() % ROWS) + 1;
  unsigned int c = cValue = (rand() % COLUMNS) + 1;
  unsigned int p = pValue = (rand() % (ROWS * COLUMNS)) + 1;
}
