#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

char welcome_message();
int gamemode(int);
void game();
int countMines(int s1, int s2, int grid[s1][s2], int x, int y);
void clearInputBuffer();
int scoresCount=0,scores[10];


int main()
{
    int mode = 0, sz1 = 0, sz2 = 0;
	welcome_message(); // Welcomes the user and asks for their name.
    mode = gamemode(mode);// Calls the gamemode function for the user to choose (1 for 8x8, 2 for 16x16, 3 for 32x16).
    if (mode == 1)
    {
        sz1 = 8;
        sz2 = 8;
    }
    else if (mode == 2)
    {
        sz1 = 16;
        sz2 = 16;
    }
    else if (mode == 3)
    {
        sz1 = 32;
        sz2 = 16;
    }
    game(sz1, sz2);
    return 0;
}

char welcome_message()
{
    char name[500];
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\tM-I-N-E-S-W-E-E-P-E-R\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n\n");
    printf("--------------\nWELCOME\n--------------\n");
    printf("Enter name:");// The player is asked to enter their name so it can be recorded later in the appropriate table.
    scanf("%s", &name);
    printf("\nPlayer Name:%s\n", name);
    char answer;
    int good=0;
}

int gamemode(int m)
{
	// Input validation check
    printf("Choose gamemode:\nType \n-1 for 8x8\n-2 for 16x16\n-3 for 32x16\n");
    int good = 0;
    do
    {
        if (scanf("%d", &m) == 0)
        {
            printf("\nWrong Input: Please type 1 or 2 or 3.\n");
            clearInputBuffer();
            continue;
        }
        if (m == 1 || m == 2 || m == 3)
        {
            good = 1;
        }
        else
        {
            printf("\nWrong Input: Please type 1, 2, or 3.\n");
            good = 0;
        }

        clearInputBuffer();
    } while (good != 1);

    return m;    
}

void game(int s1, int s2)
{
    int grid[s1][s2], revealed[s1][s2];
    printf("Selected gamemode:%5dx%d\n", s1, s2);
	// Initialize the grid array and fill all positions of the revealed array with 'X'
    int i = 0, j = 0;
    for (i = 0; i < s1; i++)
    {
        for (j = 0; j < s2; j++)
        {
            grid[i][j] = 0;
            revealed[i][j] = 'X';
        }
    }
	 // User enters the number of mines.
    int b = 0;
    printf("Enter number of mines(0-%d):\n", (s1 * s2 - 1));
    int good = 0;
    do
    {
        if ((scanf("%d", &b)) == 0)
        {
            printf("Wrong Input!Please type a number that is between 0 and %d\n", (s1 * s2 - 1));
            clearInputBuffer();
            continue;
        }
        if (b >= 0 && b < (s1 * s2))
        {
            good = 1;
        }
        else
        {
            printf("Wrong Input!Please type a number that is between 0 and %d\n", (s1 * s2 - 1));
            good = 0;
        }
        clearInputBuffer();
    } while (good != 1);
	// Place the mines in the grid array.
    srand(time(NULL));
    int mines = 0;
    while (mines < b)
    {
        int gram = rand() % s1;
        int sthlh = rand() % s2;
        if (grid[gram][sthlh] != 1)
        {
            grid[gram][sthlh] = 1;
            mines++;
        }
    }
	// Print the initial grid with hidden cells.
    int maxDigits = 1;
    int k = 0;
    int maxNumber = s1 * s2 - 1;
    while (maxNumber >= 10)
    {
        maxNumber /= 10;
        maxDigits++;
    }

    printf("\n");
    printf("%*s", maxDigits + (2 * (1 / 2)), "");
    for (k = 0; k < s2; k++)
    {
        printf("%*d", maxDigits, k);
    }
    printf("\n");
    for (i = 0; i < s1; i++)
    {
        printf("%*d", maxDigits, i);
        for (j = 0; j < s2; j++)
        {
            printf("%*c", maxDigits, revealed[i][j]);
        }
        printf("\n");
    }
	// User enters coordinates and the game responds accordingly.
    int gram = 0, sthlh = 0;
    printf("(Leave game:x=555)\n");
    printf("Enter coordinates(x,y):");
    int good1 = 0, good2 = 0, bust = 0, score = 0, cor = 0;
    do
    {
        do
        {
            do
            {
                if ((scanf("%d", &gram)) == 0)
                {
                    printf("Wrong Input!Please type a number that is between 0 and %d\n", (s1 - 1));
                    clearInputBuffer();
                    continue;
                }
                if (gram==555)
                {
                	break;
				}
                if (gram >= 0 && gram < s1)
                {
                    good1 = 1;
                }
                else
                {
                    printf("Wrong Input!Please type a number that is between 0 and %d\n", (s1 - 1));
                    good1 = 0;
                }
                clearInputBuffer();
            } while (good1 != 1);
            do
            {
            	  if (gram==555)//Code-number to exit game before the game is finished by itself.
                {
                	break;
				}
                if ((scanf("%d", &sthlh)) == 0)
                {
                    printf("Wrong Input!Please type a number that is between 0 and %d\n", (s2 - 1));
                    clearInputBuffer();
                    continue;
                }
                if (sthlh >= 0 && sthlh < s2)
                {
                    good2 = 1;
                }
                else
                {
                    printf("Wrong Input!Please type a number that is between 0 and %d\n", (s2 - 1));
                    good2 = 0;
                }
                clearInputBuffer();
            } while (good2 != 1);
              if (gram==555)
                {
                	break;
				}
            if (good1 == 1 && good2 == 1)
            {
                if (grid[gram][sthlh] == 1)//Case where the cell contains a mine.
                {
                	int i=0;
                	scores[scoresCount]=score;
					scoresCount++;
                    printf("Score:%d", score);
                    int maxDigits = 1;
                    int maxNumber = s1 * s2 - 1;
                    while (maxNumber >= 10)
                    {
                        maxNumber /= 10;
                        maxDigits++;
                    }

                    printf("\n");
                    printf("%*s", maxDigits + (2 * (1 / 2)), "");
                    for (k = 0; k < s2; k++)
                    {
                        printf("%*d", maxDigits, k);
                    }
                    printf("\n");
                    for (i = 0; i < s1; i++)
                    {
                        printf("%*d", maxDigits, i);
                        for (j = 0; j < s2; j++)
                        {
                            if (grid[i][j] == 1)
                            {
                                printf("%*c", maxDigits, '&');
                            }
                            else if (grid[i][j] == 0)
                            {
                                printf("%*c", maxDigits, '-');
                            }
                            else
                            {
                                printf("%*d", maxDigits, revealed[i][j]);
                            }
                        }
                        printf("\n");
                    }
                    printf("Game over!You hit a mine!\n");
                    printf("Total Score:%d\n", score);
                    bust = 1;
                    if (scoresCount>10)
					{
						scoresCount=0;
						for (i=0;i<10;i++)
						{
							scores[i]=0;
						}
					}
                    break;
                }
                else if (grid[gram][sthlh] == -1)//Case where the cell has already been revealed.
                {
                    printf("Cell already revealed!\n");
                    good1 = 0;
                    good2 = 0;
                }
                else if (grid[gram][sthlh] == 0)//Case where the cell does not contain a mine and has not been yet revealed.
                {

                    cor++;
                    score = score + 10;
                    grid[gram][sthlh] = -1;
                    revealed[gram][sthlh] = countMines(s1, s2, grid, gram, sthlh);
                    good = 2;
                    printf("Score:%d", score);
                    int maxDigits = 1;
                    int maxNumber = s1 * s2 - 1;
                    while (maxNumber >= 10)
                    {
                        maxNumber /= 10;
                        maxDigits++;
                    }

                    printf("\n");
                    printf("%*s", maxDigits + (2 * (1 / 2)), "");
                    for (int k = 0; k < s2; k++)
                    {
                        printf("%*d", maxDigits, k);
                    }
                    printf("\n");
                    for (int i = 0; i < s1; i++)
                    {
                        printf("%*d", maxDigits, i);
                        for (int j = 0; j < s2; j++)
                        {
                            if (revealed[i][j] == 'X')
                            {
                                printf("%*c", maxDigits, revealed[i][j]);
                            }
                            else
                            {
                                printf("%*d", maxDigits, revealed[i][j]);
                            }
                        }
                        printf("\n");
                    }
                }
            }
        } while (good != 2);
          if (gram==555)
                {
                	clearInputBuffer();
                	break;
				}
        printf("\n%d\t%d\n", gram, sthlh);
        if (bust == 1)
        {
            break;
        }
    } while (cor != (s1 * s2 - mines));
    if (cor == (s1 * s2 - mines))//Win Case.
    {
        printf("You Won!\n");
        printf("Total Score:%d\n", score);
    }
    printf("New Game?(Y/N)\n");
    char ans;
    do
    {
        good = 0;
        if (((scanf("%c", &ans)) == 0) || (ans != 'Y' && ans != 'N' && ans !='y' && ans!='n'))
        {
            printf("Wrong Input!Please type 'Y' to continue or 'N' to close game.\n");
            printf("New Game?(Y/N)");
            clearInputBuffer();
            continue;
        }
        else
        {
            good = 1;
        }
        clearInputBuffer();
    } while (good != 1);
    int m = 0;
    if (ans == 'Y'|| ans=='y')
    {
    	main();
    }
    else if (ans=='N'|| ans=='n')
    {
        exit(1);
    }
}
//Calculates the number of mines surrounding a selected cell.
int countMines(int s1, int s2, int grid[s1][s2], int x, int y)
{
    int count = 0;
    int i, j;
    for (i = x - 1; i <= x + 1; i++)
    {
        for (j = y - 1; j <= y + 1; j++)
        {
            if (i >= 0 && i < s1 && j >= 0 && j < s2 && grid[i][j] == 1)
            {
                count++;
            }
        }
    }
    return count;
}
//Function to clear the input buffer.
void clearInputBuffer() 
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}
