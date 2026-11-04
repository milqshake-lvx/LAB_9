#include <stdio.h>
#include <locale.h>
#define ROW 7 /*OY: 7 клеток, с 1 до 7*/
#define COL_FROM -6 /*OX: начинается с -6, заканчивается с 7*/
#define COL_TO 7

int check(double x, double y) {
	int state = (1 <= y && y <= 7) && (2 * x + 13 >= y) && (-2 * x + 15 >= y);
	return state;
}

void paint() {
	for (int row = ROW; row >= 1; row--) {
		for (int col = COL_TO; col >= COL_FROM; col--) {
			printf("%-3d", check(col, row));
		}
		putchar('\n');
	}
}

int main() {
	setlocale(LC_CTYPE, ".utf-8");
	double x, y;
	int num;

	puts("------------------------------------------------------------------\n"
		"Введите 1 - Если хотите проверить лежит ли точка в области\n"
		"Введите 2 - Если хотите вывести фигуру\n"
		"Введите 0 - Чтобы завершить программу\n"
		"------------------------------------------------------------------");

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
		puts("------------------------------------------------------------------\n"
			"Меню: ");
		scanf("%d", &num);
	}


	return 0;
}