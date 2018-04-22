#include<iostream>

using namespace std;

int board[20][20] = 
	{ 	
		{0, 0, 0, 1, 0, 0, 0, 0},
		{0, 1, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 1, 0},
		{0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0}
	};
	
int n = 8;
int count = 0;


int countQueens()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if(board[i][j] == 1)
				count++;
		}	
	}
}

void print()
{
	cout<<"--> Giap phap sap xep con hau:\n"<<endl;
	
	cout<<"+ So con hau da duoc xep: "<<count<<endl;
	cout<<endl;
	
	char newboard[20][20];
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if(board[i][j] == 0 || board[i][j] == 2)
				newboard[i][j] = '-';
			else
				newboard[i][j] = 'x';
		}
	}
	
	// xuat
	for (int i = 0; i < n; i++)
	{
		cout<<"| ";
		for (int j = 0; j < n; j++)
		{
			cout<<newboard[i][j]<<" | ";
		}
		cout<<endl;
	}
}


// kiem tra xem co the dat con hau tai vi tri board[row][col]
bool isSafe(int board[20][20], int row, int col)
{
	int i, j;

	// kiem tra phia ben trai hang ngang
	for (j = 0; j < col; j++)
	{
		if (board[row][j] == 1)
			return false;
	}
	
	// kiem tra phia ben phai hang ngang
	for (j = col + 1; j < n; j++)
	{
		if (board[row][j] == 1)
			return false;
	}
	
	
	// kiem tra phia ben trai hang doc
	for (i = 0; i < row; i++)
	{
		if (board[i][col] == 1)
			return false;
	}
	
	// kiem tra phia ben phai hang doc
	for (i = row + 1; i < n; i++)
	{
		if (board[i][col] == 1)
			return false;
	}
	
	
	// kiem tra duong cheo duoi phia ben trai
	for (i = row, j = col; i < n && j >= 0; i++, j--)
	{
		if (board[i][j] == 1)
			return false;
	}
	
	// kiem tra duong cheo tren phia ben trai
	for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
	{
		if (board[i][j] == 1)
			return false;
	}
	
	
	// kiem tra duong cheo duoi phia ben phai
	for (i = row, j = col; i < n && j < n; i++, j++)
	{
		if (board[i][j] == 1)
			return false;
	}

	// kiem tra duong cheo tren phia ben phai
	for (i = row, j = col; i >= 0 && j < n; i--, j++)
	{
		if (board[i][j] == 1)
			return false;
	}
	
	
	// neu khong bi tan cong
	return true;
}

bool checkQueen(int row)
{
	for (int j = 0; j < n; j++)
	{
		if(board[row][j] == 1)
		{
			return false;
		}
	}
	return true;
}


void Deploy(int b[20][20], int temprow, int tempcol)
{
	int i, j;


	for (j = 0; j < tempcol; j++)
	{
		b[temprow][j] = 2;
	}
	
	
	for (j = tempcol + 1; j < n; j++)
	{
		b[temprow][j] = 2;
	}
	
	
	
	for (i = 0; i < temprow; i++)
	{
		b[i][tempcol] = 2;
	}
	
	
	for (i = temprow + 1; i < n; i++)
	{
		b[i][tempcol] = 2;
	}
	
	
	
	for (i = temprow + 1, j = tempcol - 1; i < n && j >= 0; i++, j--)
	{
		b[i][j] = 2;
	}
	
	
	for (i = temprow - 1, j = tempcol -1; i >= 0 && j >= 0; i--, j--)
	{
		b[i][j] = 2;
	}
	
	
	
	for (i = temprow + 1, j = tempcol + 1; i < n && j < n; i++, j++)
	{
		b[i][j] = 2;
	}

	
	for (i = temprow - 1, j = tempcol + 1; i >= 0 && j < n; i--, j++)
	{
		b[i][j] = 2;
	}
}

void Undeploy(int b[20][20], int temprow, int tempcol)
{
	int i, j;
	
	for (j = 0; j < tempcol; j++)
	{
		if(isSafe(b, temprow, j))
		{
			b[temprow][j] = 0;
		}
	}
	
	
	for (j = tempcol + 1; j < n; j++)
	{
		if(isSafe(b, temprow, j))
		{
			b[temprow][j] = 0;
		}
	}
	
	for (i = temprow + 1; i < n; i++)
	{
		if(isSafe(b, i, tempcol))
		{
			b[i][tempcol] = 0;
		}
	}
	
	for (i = temprow + 1, j = tempcol - 1; i < n && j >= 0; i++, j--)
	{
		if(isSafe(b, i, j))
		{
			b[i][j] = 0;
		}
	}
	
	for (i = temprow + 1, j = tempcol + 1; i < n && j < n; i++, j++)
	{
		if(isSafe(b, i, j))
		{
			b[i][j] = 0;
		}
	}
}

int f1(int b[20][20], int row)
{
	int demmaxf1 = 0;
	
	if(checkQueen(row) == false)
	{
		row = row + 1;
	}
	
	for(int i = row; i < n; i++)
	{
		for(int j = 0; j < n ; j++)
		{
			if(b[i][j] == 0)
				demmaxf1++;
		}
	}
	return demmaxf1;
}

int f2(int b[20][20], int row)
{
	int min = 1000;
	int demmaxf2;
	
	int i = row;
	
	while (i < n)
	{
		if(checkQueen(i) == false)
		{
			i++;
		}
		else
		{
			demmaxf2 = 0;
			for(int j = 0; j < n; j++)
			{
				if(b[i][j] == 0)
					demmaxf2++;
			}
		
			if(min > demmaxf2 && demmaxf2 != 0)	min = demmaxf2;
		
			i++;
		}
	}
	
	return min;
}

void copyBoard(int a[20][20], int b[20][20])
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			a[i][j] = b[i][j];
		}
	}
}

void printBoard(int b[20][20])
{
	for (int i = 0; i < n; i++)
	{
		cout<<"| ";
		for (int j = 0; j < n; j++)
		{
			cout<<b[i][j]<<" | ";
		}
		cout<<endl;
	}
	cout<<endl;
}


bool allQueens(int b[20][20], int row, int col)
{
	// neu da dat du n con hau
	if (row == n)
		return true;

	if(checkQueen(row) == true)
	{
		for (int k = col; k < n; k++)
		{
			if(b[row][k] == 0)
			{
				if (isSafe(b, row, k) == true)
				{
					b[row][k] = 1;
					
					//printBoard(b);

					// chay de qui de dat cac con hau con lai
					if ( allQueens(b, row + 1, 0) == true )
					{
						b[row][k] = 0; 
						return true;
					}

					// neu khong dat duoc con hau nao neu dat con hau tai vi tri hien tai
					// => huy dat con hau
					b[row][k] = 0; 		// Quay lui
				}
			}
		}
	}
	else
	{
		return allQueens(b, row + 1, 0);
	}
	

	// neu khong the dat con hau trong cot nay
	return false;
}


void placeQueens()
{
	int b[20][20];
	
	copyBoard(b, board);
	
	printBoard(b);
	
	int maxf1;
	int maxf2;
	
	int tmpf1;
	int tmpf2;
	
	int bestrow;
	int bestcol;
	
	int i = 0;
	
	while( i < n)
	{
		maxf1 = 0;
		maxf2 = 0;
		
		if(checkQueen(i) == false)
		{
			i++;
		}
		else
		{
			for(int j = 0; j < n; j++)
			{
				if(b[i][j] == 0)
				{
					if(isSafe(b, i ,j) == true)
					{
						if(allQueens(b, i, j) == true)
						{
							b[i][j] = 1;
							
							Deploy(b, i, j);
					
							tmpf1 = f1(b, i);
							tmpf2 = f2(b, i);
					
							if(tmpf1 > maxf1)
							{
								maxf1 = tmpf1;
								bestrow = i;
								bestcol = j;
							}
							else if(tmpf1 == maxf1)
							{
								if(tmpf2 >= maxf2)
								{
									maxf1 = tmpf1;
									maxf2 = tmpf2;
									bestrow = i;
									bestcol = j;
								}
							}
							else
							{
								if(tmpf2 >= maxf2)
								{
									maxf1 = tmpf1;
									maxf2 = tmpf2;
									bestrow = i;
									bestcol = j;
								}
							}
							
							b[i][j] = 0;
							Undeploy(b, i, j);
						}
					}
				}
			}
			
			b[bestrow][bestcol] = 1;
			Deploy(b, bestrow, bestcol);
			//printBoard(b);
			
			i++;
		}
	}
	
	copyBoard(board, b);
}


void solve(int n)
{
	cout<<"Khoi tao ma tran de bai:\n"<<endl;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(board[i][j] == 1)
				Deploy(board, i, j);
		}
	}
	
	placeQueens();
	countQueens();
	
	print();
	if(count < n)
		cout<<"\n--> FAIL! Khong co giai phap dat du 8 con hau !\n";
	else
		cout<<"\n--> SUCCESS! Da tim ra giai phap dat du 8 con hau!\n";
}


int main()
{	
	solve(n);
	return 0;
}
