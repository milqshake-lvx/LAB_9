#include <stdio.h>
#include <locale.h>
#define ROW 7 /*По оси OY 7 клеток, не меняется*/

int check(double x, double y) {
	int state = (1 <= y <= 7) && (2 * x + 13 >= y) && (-2 * x + 15 >= y);
	return state;
}

void paint() {
	int COL = -6;
	for (int row = ROW; row >= 1; row--) {
		for (int col = 7; col >= COL; col--) {
			printf("%-3d", check(col, row));
		}
		printf("\n");
	}
}

int main() {
	setlocale(LC_CTYPE, ".utf-8");
	double x, y;
	int num;

	puts("------------------------------------------------------------------");
	printf("Введите 1 - Если хотите проверить лежит ли точка в области\n"
		"Введите 2 - Если хотите вывести фигуру\n"
		"Введите 0 - Чтобы завершить программу\n");
	puts("------------------------------------------------------------------");
	puts("------------------------------------------------------------------");
	puts("------------------------------------------------------------------");
	scanf("%d", &num);
	while (num != 0) {
		switch (num) {
			case 1:
				printf("Введи x y: ");
				scanf("%lf %lf", &x, &y);
				printf("Ответ: %d\n", check(x, y));
				break;
			case 2:
				puts("Фигура: ");
				paint();
				break;
			default:
				puts("Введено неверное число\n");
		}
		puts("------------------------------------------------------------------");
		printf("Меню: ");
		scanf("%d", &num);
	}


	return 0;
}