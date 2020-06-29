#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <WinUser.h>
#include <thread>
#include <stdlib.h>
#include <vector>


const int columns = 22;
const int rows = 14;

int p = 0;

using namespace std;
void newgraph(char line[rows][columns]);
void bar(int e, int d);
//void right_bar(char line[rows][columns], int b);
void ball();

//char** line = new char* [14];

char line[rows][columns] = { {'-', '-','-','-','-','-','-', '-','-','-','-','-','-','-','-','-','-','-','-','-','-','-'}, {'|', ' ',' ',' ',' ',' ',' ', ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|'},
{'|', ' ',' ',' ',' ',' ',' ', ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|'},{'|', ' ',' ',' ',' ',' ',' ', ' ',' ',' ',' ',' ',' ', ' ',' ',' ',' ',' ',' ',' ',' ','|'},
{'|', ' ',' ',' ',' ',' ',' ', ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|'},{'|', ' ',' ',' ',' ',' ',' ', ' ',' ',' ',' ',' ',' ', ' ',' ',' ',' ',' ',' ',' ',' ','|'},
{'|', ' ',' ',' ',' ',' ',' ', ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|'},{'|', ' ',' ',' ',' ',' ',' ', ' ',' ',' ',' ',' ',' ', ' ',' ',' ',' ',' ',' ',' ',' ','|'},
{'|', ' ',' ',' ',' ',' ',' ', ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|'},
{'|', ' ',' ',' ',' ',' ',' ', ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|'},{'|', ' ',' ',' ',' ',' ',' ', ' ',' ',' ',' ',' ',' ', ' ',' ',' ',' ',' ',' ',' ',' ','|'},
{'|', ' ',' ',' ',' ',' ',' ', ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|'},
{'|', ' ',' ',' ',' ',' ',' ', ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|'},{'-', '-','-','-','-','-','-', '-','-','-','-','-','-','-','-','-','-','-','-','-','-','-'} };


//char score[2][3] = { {'1','2','3'},{'1','2','3'} };





int t = 200;

char b = 'O';

//char** line = new char* [rows];

int main()
{
	/*char** line = new char* [14];

	for (int i = 0; i < 14; i++)
	{
		line[i] = new char[22];
	}
	new_array(line);*/

	system("color f2");
	cout << "first player uses keys w and s for up and down respectively and second player uses keys p and l as the up and down keys" << endl;
	cout << "Press any key to start and be ready!" << endl;
	cout << endl;
	cout << "After the first play, you will need to restart the program, game does not work very well after automatic restart" << endl;
	_getch();
	Sleep(3000);
	system("CLS");

	line[1][19] = ' ';
	line[2][19] = ' ';
	line[3][19] = ' ';
	line[4][19] = ' ';
	line[5][19] = '|';
	line[6][19] = '|';
	line[7][19] = '|';
	line[8][19] = ' ';
	line[9][19] = ' ';
	line[10][19] = ' ';
	line[11][19] = ' ';
	line[12][19] = ' ';

	line[1][2] = ' ';
	line[2][2] = ' ';
	line[3][2] = ' ';
	line[4][2] = ' ';
	line[5][2] = '|';
	line[6][2] = '|';
	line[7][2] = '|';
	line[8][2] = ' ';
	line[9][2] = ' ';
	line[10][2] = ' ';
	line[11][2] = ' ';
	line[12][2] = ' ';

		int e = 6;
		int d = 6;


		//thread* second = new thread(ball);

		thread first(bar, e, d);
		thread second(ball);

		first.join();
}

void ball()
{
	int r = 6;

	int c = 3;

	line[r][c] = b;

	while (1)
	{
			if (line[r][columns-4] == b && line[r][columns - 3] != '|')
			{
				cout << "Right player wins, press enter for next try" << endl;
				cin.get();

				/*char** line = new char* [14];

				for (int i = 0; i < 14; i++)
				{
					line[i] = new char[22];
				}
				new_array(line);
				
				delete_array(line);*/

				main();
			
			}

			if (line[r][columns - 4] == b && line[r][columns - 3] == '|' && line[r+1][columns - 3] == '|' && line[r+2][columns - 3] == '|')
			{
				
				while (c < columns - 3 && c > 2)   // i < 17 && i > 13 && h >2
				{

					if (r == 1)
					{
						//cout << "in r == 0" << endl;
						//Sleep(2000);

						while (c < columns - 3 && c > 2)
						{
							

							line[r][c] = ' ';
							line[r + 1][c - 3] = b;
							system("CLS");
							newgraph(line);
							Sleep(t*2);
		
							if (c < columns - 3 && c > 2)
							{
								r = r + 1;
								c = c - 3;

							}

							if (c == 3)
							{
								break;
							}
						}

					}

					else if (r != 1)
					{
						
						line[r][c] = ' ';
						line[r - 1][c - 3] = b;
						system("CLS");
						newgraph(line);
						Sleep(t*2);

						if (c < (columns - 3) && c > 2)
						{
							r = r - 1;
							c = c - 3;
						}
					}

					

					if (c == 3)
					{
						break;
					}

					
				}

				
			}

			else if (line[r][columns - 4] == b && line[r-2][columns - 3] == '|' && line[r-1][columns - 3] == '|' && line[r][columns - 3] == '|')
			{
				
				while (c < columns - 3 && c > 2)   // i < 17 && i > 13 && h >2
				{                                  //// r = 9, c =4 ==> r = 10, c = 1?
					
					if (r == 13)
					{
						while (c < (columns - 4) && c > 2)
						{
							line[r][c] = ' ';
							line[r - 1][c - 3] = b;
							system("CLS");
							newgraph(line);
							Sleep(t*2);

							if (c < (columns - 4) && c > 2)
							{
								r = r - 1;
								c = c - 3;
							}

							if (c == 3)
							{
								break;
							}
						}
					}

					else if (r != 13)
					{
						
						line[r][1] = ' ';
						line[r][c] = ' ';
						line[r + 1][c - 3] = b;
						system("CLS");
						newgraph(line);
						Sleep(t*2);

						if (c < columns - 3 && c > 2)
						{
							
							r = r + 1;
							c = c - 3;

						}
					}

					if (c == 3)
					{
						break;
					}
				}

				
				
			}

			/*cout << " line[r][c] = " << line[r][c] << ", r = " << r << ", c = " << c << endl;
			Sleep(2000);*/

			else if (line[r][columns - 19] == b && line[r + 2][columns - 20] == '|' && line[r + 1][columns - 20] == '|' && line[r][columns - 20] == '|')
			{
				//c = 1;
				while (c < columns - 4 && c > 2)   // i < 17 && i > 13 && h >2
				{
					
					
					if (r == 1)
					{

						while (c < columns - 4 && c > 2)
						{
							

							line[r][c] = ' ';
							line[r + 1][c + 3] = b;
							system("CLS");
							newgraph(line);
							Sleep(t*2);

							if (c < columns - 4 && c > 2)
							{
								r = r + 1;
								c = c + 3;

							}

							if (c == 3)
							{
								break;
							}
						} 
					}

					 else if (r != 1)
					{

						line[r][c] = ' ';
						line[r - 1][c + 3] = b;
						system("CLS");
						newgraph(line);
						Sleep(t*2);

						if (c < columns - 4 && c > 2)
						{

							r = r - 1;
							c = c + 3;

						}

						
					}

					if (c == 3)
					{
						break;
					}

				}

				
			}

			else if (line[r][columns - 19] == b && line[r - 2][columns - 20] == '|' && line[r - 1][columns - 20] == '|' && line[r][columns - 20] == '|')
			{
				//c = 1;
				while (c < columns - 4 && c > 2)   // when the ball goes diagonal from right to left it iterates too many times
				{                                    // causing the o to replace the |  
					if(r == 13)
					{ 
						while (c < (columns - 4) && c > 2)
						{
							line[r][c] = ' ';
							line[r - 1][c + 3] = b;
							system("CLS");
							newgraph(line);
							Sleep(t*2);

							if (c < (columns - 4) && c > 2)
							{
								r = r - 1;
								c = c + 3;
							}

							if (c == 19)
							{
								break;
							}
						}
					}

					else if (r != 13)
					{

						line[r][1] = ' ';
						line[r][c] = ' ';
						line[r + 1][c + 3] = b;
						system("CLS");
						newgraph(line);
						Sleep(t*2);

						if (c < columns - 4 && c > 2)
						{
							r = r + 1;
							c = c + 3;

						}
					}

						if (c == 19)
						{
							break;
						}
				}

				
			}

			else if (line[r][columns - 19] == b && line[r][columns - 20] == '|' && line[r - 1][columns - 20] == ' ' && line[r+1][columns - 20] == '|')
			{

				while (c < columns - 4 && c > 2)
				{


					line[r][c] = ' ';
					line[r - 1][c + 3] = b;
					system("CLS");
					newgraph(line);
					Sleep(t*2);

					if (c < columns - 4 && c > 2)
					{
						r = r - 1;
						c = c + 3;

					}

				}

				
			}

			else if (line[r][columns - 19] == b && line[r][columns - 20] == '|' && line[r - 1][columns - 20] == '|' && line[r + 1][columns - 20] == ' ')
			{

			while (c < columns - 4 && c > 2)
			{


				line[r][c] = ' ';
				line[r + 1][c + 3] = b;
				system("CLS");
				newgraph(line);
				Sleep(t*2);

				if (c < columns - 4 && c > 2)
				{
					r = r + 1;
					c = c + 3;

				}

			}
			
			}

			else if (line[r][columns - 4] == 'o' && line[r][columns - 3] == '|' && line[r - 1][columns - 3] == ' ' && line[r + 1][columns - 3] == '|')
			{

			while (c < columns - 3 && c > 3)
			{

				line[r][c] = ' ';
				line[r - 1][c - 3] = b;
				system("CLS");
				newgraph(line);
				Sleep(t*2);

				if (c < columns - 3 && c > 3)
				{
					r = r - 1;
					c = c - 3;

				}

			}
			
			}

			else if (line[r][columns - 4] == 'o' && line[r][columns - 3] == '|' && line[r - 1][columns - 3] == '|' && line[r + 1][columns - 3] == ' ')
			{

			while (c < columns - 3 && c > 3)
			{

				line[r][c] = ' ';
				line[r + 1][c - 3] = b;
				system("CLS");
				newgraph(line);
				Sleep(t*2);

				if (c < columns - 3 && c > 3)
				{
					r = r + 1;
					c = c - 3;

				}

			}
			
			}

			else if (line[r][columns - 19] == b && line[r][columns - 20] == '|')
			{
			
				//c = 1;
				while (c < (columns - 4) && c > 2)
				{
					line[r][c] = ' ';
					line[r][c + 1] = b;

					system("CLS");
					newgraph(line);
					Sleep(t);

					if (c < (columns - 4) && c > 2)
					{
						c = c + 1;
					}

				}
				
			}

			else if (line[r][columns - 4] == b && line[r][columns - 3] == '|')
			{

					while (c < (columns-3) && c > 3)
					{
						line[r][c] = ' ';
						line[r][c - 1] = b;

						system("CLS");
						newgraph(line);
						Sleep(t);

						if (c < (columns - 3) && c > 3)
						{
							c = c - 1;
						}
					}
					
			}

			

			
			 if (c > 3 && c < 20)
			 {

				 line[r][c - 1] = ' ';

			 }

			//cout << "line[r][c] =  " << line[r][c] << ", r = " << r << ", c = " << c << endl;

			
			Sleep(350);
			system("CLS");
			newgraph(line);
			


	}
}

void bar(int e, int d)
{
	
	char p = 'p';
	char l = 'l';
	char s = 's';
	char w = 'w';
	char o = 'o';
	char k = 'k';

	while (1)
	{
		if (line[d][columns - 4] == b && line[d][columns - 3] != '|')
		{
			cout << "ok cool" << endl;

			/*char** line = new char* [14];

			for (int i = 0; i < 14; i++)
			{
				line[i] = new char[22];
			}
			new_array(line);
			delete_array(line);*/

			main();
		}

		//GetAsyncKeyState('A') == 1

		while (_getch() == l)
		{

			if (d < 11)
			{

				line[d + 2][columns - 3] = ' ';
				line[d + 1][columns - 3] = '|';
				line[d][columns - 3] = '|';
				line[d - 1][columns - 3] = '|';
				line[d - 2][columns - 3] = ' ';

				d = d + 1;

			}
			else if (d == 11)
			{
				line[d + 1][columns - 3] = '|';
				line[d][columns - 3] = '|';
				line[d - 1][columns - 3] = '|';
				line[d - 2][columns - 3] = ' ';

				d = d + 1;
			}
			else if (d == 12)
			{
				line[d][columns - 3] = '|';
				line[d - 1][columns - 3] = '|';
				line[d - 2][columns - 3] = ' ';
			}

		}

		while (_getch() == p)

		{
			if (d > 3)
			{

				line[d + 1][columns - 3] = ' ';
				line[d][columns - 3] = '|';
				line[d - 1][columns - 3] = '|';
				line[d - 2][columns - 3] = '|';
				line[d - 3][columns - 3] = ' ';

				d = d - 1;

			}
			else if (d == 3)
			{
				line[d + 1][columns - 3] = ' ';
				line[d][columns - 3] = '|';
				line[d - 1][columns - 3] = '|';
				line[d - 2][columns - 3] = '|';

				d = d - 1;
			}
			else if (d == 2)
			{
				line[d + 1][columns - 3] = ' ';
				line[d][columns - 3] = '|';
				line[d - 1][columns - 3] = '|';
			}


		}

					while (_getch() == s)
					{
						if (e < 11)
						{
							line[e + 2][columns - 20] = ' ';
							line[e + 1][columns - 20] = '|';
							line[e][columns - 20] = '|';
							line[e - 1][columns - 20] = '|';
							line[e - 2][columns - 20] = ' ';

							e = e + 1;

						}
						else if (e == 11)
						{
							line[e + 1][columns - 20] = '|';
							line[e][columns - 20] = '|';
							line[e - 1][columns - 20] = '|';
							line[e - 2][columns - 20] = ' ';

							e = e + 1;
						}
						else if (e == 12)
						{
							line[e][columns - 20] = '|';
							line[e - 1][columns - 20] = '|';
							line[e - 2][columns - 20] = ' ';
						}
						
					}

					while (_getch() == w)

					{
						if (e > 3)
						{

							line[e + 1][columns - 20] = ' ';
							line[e][columns - 20] = '|';
							line[e - 1][columns - 20] = '|';
							line[e - 2][columns - 20] = '|';
							line[e - 3][columns - 20] = ' ';

							e = e - 1;

						}
						else if (e == 3)
						{
							line[e + 1][columns - 20] = ' ';
							line[e][columns - 20] = '|';
							line[e - 1][columns - 20] = '|';
							line[e - 2][columns - 20] = '|';

							e = e - 1;
						}
						else if (e == 2)
						{
							line[e + 1][columns - 20] = ' ';
							line[e][columns - 20] = '|';
							line[e - 1][columns - 20] = '|';
						}
							
					}
							
	}
	
}

//void delete_array()
//{
//	for (int i = 0; i < 14; ++i) {
//		delete[] line[i];
//	}
//	//Free the array of pointers
//	delete[] line;
//}
//
//void new_array()
//{
//
//	for (int i = 0; i < 14; i++)
//	{
//		line[i][0] = '|';
//		line[i][21] = '|';
//	}
//
//	for (int i = 0; i < 22; i++)
//	{pot
//		line[0][i] = '-';
//		line[13][i] = '-';
//	}
//
//	for (int i = 1; i < 13; i++)
//	{
//		for (int j = 1; j < 21; j++)
//		{
//			line[i][j] = ' ';
//		}
//	}
//}

void newgraph(char line[rows][columns])
{
	
	for (int x = 0; x < rows; x++)
	{
		for (int y = 0; y < columns; y++)
		{
			cout << line[x][y];
		}
		cout << endl;

	}

	/*for (int x = 0; x < 3; x++)
	{
		for (int y = 0; y < 3; y++)
		{
			cout << score[x][y];
		}
		cout << endl;
	}*/
}

	