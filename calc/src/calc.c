/*
 ============================================================================
 Name        : calc.c
 Author      : Nikita Pirogov
 Version     :
 Copyright   : 
 Description : calculator of two numbers or vectors
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc,char *argv[]) {
	//что делает программа
	printf("Данная программа выполняет арифметические действия над введенными числами(векторами)\n");
	//возможные операции и их обозначение
	printf("Возможные операции:\n");
	printf("сложение(+),вычитание(-),умножение(*),деление(/),\n");
	printf("возведение в степень(^),факториал(!),целочисленное деление(:),деление с остатком(;)\n");
	printf("Для работы с векторами (v)\n");

    double num1,num2, res; // 1 и 2  введенное число, результат действия
    char sign; //знак арифметического действия
    char agree; //переменная отвечающая за повтор программы
    double *Vec1, *Vec2; //1 и 2 введенный вектор
    int size; // размер векторов
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);
    do { //цикл
    //повтор операций
    printf("\nВыберите операцию(+ - * / ^ ! : ;)");
    printf("\nДля работы с векторами (v)\n");
    scanf(" %c",&sign);
    //выполнение арифметического действия и вывод результата
    switch(sign) {
    	case 'v': // операции с векторами
    		printf("Введите размер векторов: ");
    		scanf("%i",&size);
    		Vec1 = malloc(size*sizeof(double));
    		Vec2 = malloc(size*sizeof(double));
    		printf("Введите координаты первого вектора: ");
    		for(int i=0;i<size;i++) {
    			scanf(" %lf",&Vec1[i]);
    		}
    		printf("Введите координаты второго вектора: ");
    		for(int i=0;i<size;i++) {
    		    scanf(" %lf",&Vec2[i]);
    		}
    		printf("Выберите операцию(+,-,*): "); // повтор операций для векторов
    		scanf(" %c",&sign);
    		switch(sign) {
    			case '+':
    				printf("Vector1 + Vector2 = "); // сложение векторов
    				for(int  i= 0; i < size; i++) {
    					printf("%lf ", Vec1[i] + Vec2[i]);
    				}
    				break;
    			case '-':
    				printf("Vector1 - Vector2 = "); // вычитание векторов
    				for(int  i= 0; i < size; i++) {
    				    printf("%lf ", Vec1[i] - Vec2[i]);
    				}
    				break;
    			case '*':
    				printf("Vector1 * Vector2 = "); // скалярное произведение векторов
    				for(int i = 0; i < size; i++) {
    					res += Vec1[i] * Vec2[i];
    				}
    				printf("%lf", res);
    				break;
    			default:
    				printf("\nНет такой операции");
    		} // конец вложенного switch
    		free(Vec1); //освобождение памяти
    		free(Vec2);
			break;
    	case '+':	//сложение
    		printf("\nВведите первое число:");
    		scanf(" %lf",&num1);
    		printf("\nВведите второе число:");
    		scanf(" %lf",&num2);
    		res = num1 + num2;
    		printf("\n%lf + %lf = %lf",num1,num2,res);
    		break;
    	case '-':	//вычитание
    		printf("\nВведите первое число:");
    		scanf(" %lf",&num1);
    		printf("\nВведите второе число:");
    		scanf(" %lf",&num2);
    	    res = num1 - num2;
    	    printf("\n%lf - %lf = %lf",num1,num2,res);
    	    break;
    	case '*':	//умножение
    		printf("\nВведите первое число:");
    		scanf(" %lf",&num1);
    		printf("\nВведите второе число:");
    		scanf(" %lf",&num2);
    	    res = num1 * num2;
    	    printf("\n%lf * %lf = %lf",num1,num2,res);
    	    break;
    	case '/':	//деление
    		printf("\nВведите первое число:");
    		scanf(" %lf",&num1);
    		printf("\nВведите второе число:");
    		scanf(" %lf",&num2);
    	    res = num1 / num2;
    	    printf("\n%lf / %lf = %lf",num1,num2,res);
    	    break;
    	case '^':	//возведение в степень
    		printf("\nВведите первое число:");
    		scanf(" %lf",&num1);
    		printf("\nВведите положительную степень:");
    		scanf(" %lf",&num2);
    		res = 1;
    	    for (double i = 1; i < num2; i++) {
    	    	res = res * num1;
    	    }
    	    printf("\n%lf ^ %lf = %lf",num1,num2,res);
    	    break;
    	case '!':	//факториал
    		printf("\nВведите число:");
    		scanf(" %lf",&num1);
    		if (num1 > 0) {
    			double temp = num1;
    			for(double i = 1; i < num1; i++) {
    				temp = temp * (num1 - i);
    			}
    			printf("%lf! = %lf", num1, temp);
    		}
    		else if (num1 == 0) {
    			printf("0! = 1");
    		}
    		else {
    			printf("Введено не корекктное число");
    		}
    		break;
    	case ':':	//целочисленное деление
    		printf("\nВведите первое число:");
    		scanf(" %lf",&num1);
    		printf("\nВведите второе число:");
    		scanf(" %lf",&num2);
    		res = (long int)num1 / (long int)num2;
		    printf("\n%lf : %lf = %lf",num1,num2,res);
		    break;
    	case ';':	//деление с остатком
    		printf("\nВведите первое число:");
    		scanf(" %lf",&num1);
    		printf("\nВведите второе число:");
    		scanf(" %lf",&num2);
    		res = num1 - (((long int)num1 / (long int)num2) * num2);
            printf("\n%lf ; %lf = %lf",num1,num2,res);
    	    break;
    	default:	//в случае не правильного ввода
    	    printf("\nНет такой операции");
    }
    printf("\nХотите повторить рассчет(y-да/n-нет):");
    scanf(" %c", &agree);
    } while (agree == 'y');

	return 0;
}
