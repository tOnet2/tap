/* 1. 	Вычислить значение функции ln(1 + x) с точночтью до 10^(-6), используя разложение в ряд:
 * 		ln(1+x) = (x / 1) - (x^2 / 2) + (x^3 / 3) + ... + (((-1)^(n-1) * x^n) / n) - ...
 * 		проверить результат с результатом функции из библиотеки ЯП
 * 2. 	Входные данные - x (агрумент),
 * 	Выходные данные - y - Результат при использовании функции рязложения в ряд
 * 			  log(x) - результат при использовании встроенной библиотечной фукнции
 * 			  Доп. данные:
 * 			  log() - функция библиотеки
 * 			  U = (-1)^(n-1) * x^n / n
 * 	   	 	  Un = (-1)^(n+1-1) * x^(n+1) / (n+1)
 * 			  Un = k * U
 * 			  k = Un / U = ((-1)^(n+1-1) * x^(n+1) / (n+1)) / ((-1)^(n-1) * x^n / n) = -(x * n / (n + 1))
 * 			  Un = -(-1)^(n-1) * x^(n+1) / (n + 1)
 * 			  e = 10^(-6)
 * 3. 	Псевдокод:
 * 		Начало
 *	 		ввод(х);
 *			e = 10^(-6);
 *			n = 1;
 *			y = x; // при n = 1: Un = x^n / n = x^1 / 1 = x
 *			power = -x * x;
 *			Un = (-1)^(n-1) * power / n;
 *			пока |Un| > e
 *			{
 *				y = y + Un;
 *				++n;
 *				power = power * -x;
 *				Un = power / n;
 *			}
 *	 		вывод(y);
 * 			вывод(log(1 + x));
 * 		Конец
 * 			
 * 4.	x = 0.1
 * 		y = 0.095310
 * 		z = 0.095310
 *
 * 	x = -0.6
 * 		y = -0.916289
 * 		z = -0.916291
 *
 * 	x = 0.6
 * 		y = 0.470004
 * 		z = 0.470004
 *	
 *	x = 0
 *		y = 0.000000
 *		z = 0.000000
 *
 *	x = 1
 *		y = 0.693148
 *		z = 0.693147
 *
 *	x = -0.9
 *		y = -2.302576
 *		z = -2.302585
 *
 * 5.                                       */
#include <stdio.h>
#include <math.h>

static double Un, x, y, power;
static int n;

int main()
{
	printf("x = ");
	scanf("%lf", &x);
	power = y = x;
	x = -x;
	n = 1;
	while ((Un = (power *= x) / ++n) < -1e-6 || Un > 1e-6) {
		y += Un;
	}
	printf("y = %.6f\n", y);
	printf("z = %.6f\n", log(1 - x));
	return 0;
}