#include <iostream>
using namespace std;
int board[8][8];

void set_queen(int i, int j) {

	for (int x = 0; x < 8; ++x)
	{
		++board[x][j]; // По вертикали 
		++board[i][x]; // По горизонтали 
		int foo;
		foo = j - i + x; // По диагонали
		if (foo >= 0 && foo < 8)
			++board[x][foo];
		foo = j + i - x;

		if (foo >= 0 && foo < 8)
			++board[x][foo];

		board[i][j] = -1; // Ставим ферзя 
	}
}


void reset_queen(int i, int j) {

	for (int x = 0; x < 8; ++x)
	{
		--board[x][j]; // По вертикали 
		--board[i][x]; // По горизонтали 
		int foo; // Далее по двум диагоналям 
		foo = j - i + x;
		if (foo >= 0 && foo < 8)
			--board[x][foo];
		foo = j + i - x;

		if (foo >= 0 && foo < 8)
			--board[x][foo];

		board[i][j] = 0; // Ставим ферзя 
	}
}

bool try_queen(int i) { // Получаем номер строки 

	bool result = false; // начальное значение 

	for (int j = 0; j < 8; ++j) // итерирование по КЛЕТКАМ строки
	{

		if (board[i][j] == 0) // поиск клетки, находящейся не под атакой ферзей
		{
			set_queen(i, j); // вызов функции постановки ферзя И обозначения клеток, которые он бьет

			if (i == 7) // достижение последней строки шахматной доски (от 0 до 7)
				result = true; // изменение значения result для досрочного выхода из цикла на посл. строке доски после постановки ферзя (63 стр. кода)

			else if (!(result = try_queen(i + 1))) reset_queen(i, j); /* для отката(удаления ферзя на предыд. строке
																	 еще для перехода на строку выше */
		}

		if (result) break; // досрочный выход из цикла после постановки ферзя на посл. строке доски


	}

	return result; // возвращение значения функции
}

int main()
{
	for (int i = 0; i < 8; ++i) // Сначала обнуляем в 
		for (int j = 0; j < 8; ++j)
			board[i][j] = 0;
	try_queen(0); // Запускаем цикл

	for (int i = 0; i < 8; ++i)
	{ // Выводим все содержимое
		for (int j = 0; j < 8; ++j)
		{
			if (board[i][j] == -1) cout << "[]"; // Так выводится ферзь 
			else cout << ". "; // А так пустые клетки 
		}
		cout << endl;
	}
}
