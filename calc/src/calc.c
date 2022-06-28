/*
 ============================================================================
 Name        : calc.c
 Author      : Nikita Pirogov
 Version     :
 Copyright   : 
 Description : calculator of two numbers
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc,char *argv[]) {
	//что делает программа
	printf("Данная программа выполняет арифметические действия над введенными числами\n");
	//возможные операции и их обозначение
	printf("Возможные операции:\n");
	printf("сложение(+),вычитание(-),умножение(*),деление(/),\n");
	printf("возведение в степень(^),факториал(!),целочисленное деление(:),деление с остатком(;)\n");

    double num1,num2, res; // 1 и 2  введенное число, результат действия
    char sign; //знак арифметического действия
    char agree; //переменная отвечающая за повтор программы
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);
    do { //цикл
    //повтор операций
    printf("\nВыберите операцию(+ - * / ^ ! : ;)");
    scanf(" %c",&sign);
    //выполнение арифметического действия и вывод результата
    switch(sign) {
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
