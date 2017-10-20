
#include <iostream>
#include <ctime>

using namespace std;

int main()
{
	cout << "Enter matrix 4x4 : use numbers 2, 4, 8, 16...(Enter each new number after a 'SPACE', go to a new line with 'ENTER'" << endl;
	int mtx[4][4], i = 0, j = 0, k = 0;
	char op;
	for (i = 0; i<4; ++i) 
	{
		for (j = 0; j<4; ++j)
		{
			cin >> mtx[i][j];
		}
	}
	cout << endl << "Use the keys 'j'(move down), 'k'(move up), 'h'(move left), 'l'(move right) to move the tiles" << endl;
	for (i = 0; i<4; ++i) 
	{
		for (j = 0; j<4; ++j) 
		{
			if (mtx[i][j] == 0)
			{
				cout << "* ";
			}
			else 
			{
				cout << mtx[i][j] << " ";
			}
		}
		cout << endl;
	}
	srand(time(NULL));
	int schet = 0;
	while (cin >> op)
	{
		bool f = 0;
		for (i = 0; i<3; ++i) 
		{
			for (j = 0; j<3; ++j)
			{
				if (mtx[i][j] == mtx[i + 1][j] || mtx[i][j] == mtx[i][j + 1] || mtx[i][j] == 0) {
					f = 1;
					break;
				}
			}
			if (f) 
			{ 
				break; 
			}
		}
		if (!f) 
		{ 
			break;
		}
		if (op == 'q') 
		{
			break;
		}
		if (op == 'j')
		{
			int z = 0;
			for (j = 0; j<4; ++j)
			{
				for (i = 3; i >= 0; --i)
				{
					if (mtx[i][j] != 0)
					{
						for (k = i - 1; k >= 0; --k)
						{
							if (mtx[k][j] != 0)
							{
								if (mtx[k][j] == mtx[i][j])
								{
									mtx[i][j] = mtx[i][j] + mtx[k][j];
									mtx[k][j] = 0;
									schet += mtx[i][j];
									z += 1;
								}
								break;
							}
						}
						while (mtx[i + 1][j] == 0)
						{
							if (i<3)
							{
								mtx[i + 1][j] = mtx[i][j];
								mtx[i][j] = 0;
								i = i + 1;
								z += 1;
							}
							else 
							{ 
								break;
							}
						}
						i = k + 1;
					}
				}
			}
			if (z == 0) 
			{
				cout << "Enter another key" << endl;
				f = 0;
			}
		}
		if (op == 'k')
		{
			int z = 0;
			for (j = 0; j<4; ++j)
			{
				for (i = 0; i<4; ++i)
				{
					if (mtx[i][j] != 0)
					{
						for (k = i + 1; k<4; ++k)
						{
							if (mtx[k][j] != 0)
							{
								if (mtx[k][j] == mtx[i][j]) 
								{
									mtx[i][j] = mtx[i][j] + mtx[k][j];
									mtx[k][j] = 0;
									schet += mtx[i][j];
									z += 1;
								}
								break;
							}
						}
						while (mtx[i - 1][j] == 0)
						{
							if (i>0)
							{
								mtx[i - 1][j] = mtx[i][j];
								mtx[i][j] = 0;
								i = i - 1;
								z += 1;
							}
							else 
							{ 
								break;
							}
						}
						i = k - 1;
					}
				}
			}
			if (z == 0) 
			{
				cout << "Enter another key" << endl;
				f = 0;
			}
		}
		if (op == 'h') 
		{
			int z = 0;
			for (i = 0; i<4; ++i)
			{
				for (j = 0; j<4; ++j)
				{
					if (mtx[i][j] != 0) 
					{
						for (k = j + 1; k<4; ++k)
						{
							if (mtx[i][k] != 0)
							{
								if (mtx[i][k] == mtx[i][j])
								{
									mtx[i][j] = mtx[i][j] + mtx[i][k];
									mtx[i][k] = 0;
									schet += mtx[i][j];
									z += 1;
								}
								break;
							}
						}
						while (mtx[i][j - 1] == 0) 
						{
							if (j>0)
							{
								mtx[i][j - 1] = mtx[i][j];
								mtx[i][j] = 0;
								j = j - 1;
								z += 1;
							}
							else 
							{ 
								break;
							}
						}
						j = k - 1;
					}
				}
			}
			if (z == 0) 
			{
				cout << "Enter another key" << endl;
				f = 0;
			}
		}
		if (op == 'l') 
		{
			int z = 0;
			for (i = 0; i<4; ++i) 
			{
				for (j = 3; j >= 0; --j) 
				{
					if (mtx[i][j] != 0)
					{
						for (k = j - 1; k >= 0; --k)
						{
							if (mtx[i][k] != 0)
							{
								if (mtx[i][k] == mtx[i][j])
								{
									mtx[i][j] = mtx[i][j] + mtx[i][k];
									mtx[i][k] = 0;
									schet += mtx[i][j];
									z += 1;
								}
								break;
							}
						}
						while (mtx[i][j + 1] == 0)
						{
							if (j<3) 
							{
								mtx[i][j + 1] = mtx[i][j];
								mtx[i][j] = 0;
								j = j + 1;
								z += 1;
							}
							else 
							{ 
								break;
							}
						}
						j = k + 1;
					}
				}
			}
			if (z == 0) 
			{
				cout << "Enter another key" << endl;
				f = 0;
			}
		}
		if (f) 
		{
			while (1) 
			{
				i = rand() % 4;
				j = rand() % 4;
				if (mtx[i][j] == 0)
				{
					if (rand() % 11<10)
					{
						mtx[i][j] = 2;
					}
					else 
					{
						mtx[i][j] = 4;
					}
					break;
				}
			}
			for (i = 0; i<4; ++i)
			{
				for (j = 0; j<4; ++j)
				{
					if (mtx[i][j] == 0) 
					{
						cout << "* ";
					}
					else 
					{
						cout << mtx[i][j] << " ";
					}
				}
				cout << endl;
			}
		}
	}
	cout << "game over, your score : " << schet << endl;
	return 0;
}
