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
	//printf("Данная программа выполняет арифметические действия над введенными числами(векторами)\n");
	//возможные операции и их обозначение
	//printf("Возможные операции:\n");
	//printf("сложение(+),вычитание(-),умножение(*),деление(/),\n");
	//printf("возведение в степень(^),факториал(!),целочисленное деление(:),деление с остатком(;)\n");
	//printf("Для работы с векторами (v)\n");

    double num1,num2, res; // 1 и 2  введенное число, результат действия
    char sign; //знак арифметического действия
    char agree; //переменная отвечающая за повтор программы
    double *Vec1, *Vec2; //1 и 2 введенный вектор
    int size; // размер векторов
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);
    do { //цикл
    // файлы
    FILE *input, *output;
    char input_name[259], output_name[259]; // имена файлов ввода и вывода данных
    printf("Введите название файла для чтения данных, формата '.txt'");
    scanf("%s", input_name);
    printf("Введите название файла для записи данных формата '.txt'");
    scanf("%s", output_name);
    input = fopen(input_name,"r");
    output = fopen(output_name,"w");
    while(fscanf(input, " %c", &sign) != EOF){

    //выполнение арифметического действия и вывод результата
    switch(sign) {
    	case 'v': // операции с векторами
    		fscanf(input, " %c",&sign);
    		//Вводиться размер векторов
    		fscanf(input, " %i",&size);
    		Vec1 = malloc(size*sizeof(double));
    		Vec2 = malloc(size*sizeof(double));
    		//"Введите координаты первого вектора:
    		for(int i=0;i<size;i++) {
    			fscanf(input, " %lf",&Vec1[i]);
    		}
    		//"Введите координаты второго вектора:
    		for(int i=0;i<size;i++) {
    		    fscanf(input, " %lf",&Vec2[i]);
    		}
    		switch(sign) {
    			case '+':// сложение векторов
    				fprintf(output, "("); //доп скобки
    				for(int  i= 0; i < size; i++) {
    					fprintf(output,"%lf ",Vec1[i]); // вывод 1 вектора
    				}
    				fprintf(output, ") + ("); // доп скобки
    				for(int  i= 0; i < size; i++) {
    				    fprintf(output,"%lf ",Vec2[i]); // вывод 2 вектора
    				}
    				fprintf(output, ") = ("); // доп скобки
    				for(int  i= 0; i < size; i++) {     // вывод результата
    					fprintf(output,"%lf ", Vec1[i] + Vec2[i]);
    				}
    				fprintf(output, ")\n"); // закрывающие скобки
    				break;
    			case '-': // вычитание векторов
    				fprintf(output, "("); //доп скобки
    				for(int  i= 0; i < size; i++) {
    					fprintf(output,"%lf ",Vec1[i]); // вывод 1 вектора
    				}
    				fprintf(output, ") - ("); // доп скобки
    				for(int  i= 0; i < size; i++) {
    				    fprintf(output,"%lf ",Vec2[i]); // вывод 2 вектора
    				}
    				fprintf(output, ") = ("); // доп скобки
    				for(int  i= 0; i < size; i++) {     // вывод результата
    					fprintf(output,"%lf ", Vec1[i] - Vec2[i]);
    				 }
    				fprintf(output, ")\n"); // закрывающие скобки
    				break;
    			case '*': // скалярное произведение векторов
    				fprintf(output, "("); //доп скобки
    				for(int  i= 0; i < size; i++) {
    					fprintf(output,"%lf ",Vec1[i]); // вывод 1 вектора
    				}
    				fprintf(output, ") + ("); // доп скобки
    				for(int  i= 0; i < size; i++) {
    				    fprintf(output,"%lf ",Vec2[i]); // вывод 2 вектора
    				}
    				fprintf(output, ") = "); // доп скобки
    				for(int i = 0; i < size; i++) {
    					res += Vec1[i] * Vec2[i];
    				}
    				fprintf(output,"%lf\n", res);
    				break;
    			default:
    				fprintf(output,"\nНет такой операции");
    		} // конец вложенного switch
    		free(Vec1); //освобождение памяти
    		free(Vec2);
			break;
    	case '+':	//сложение
    		fscanf(input, " %lf",&num1);
    		fscanf(input," %lf",&num2);
    		res = num1 + num2;
    		fprintf(output,"\n%lf + %lf = %lf",num1,num2,res);
    		break;
    	case '-':	//вычитание
    		fscanf(input, " %lf",&num1);
    		fscanf(input," %lf",&num2);
    	    res = num1 - num2;
    	    fprintf(output,"\n%lf - %lf = %lf",num1,num2,res);
    	    break;
    	case '*':	//умножение
    		fscanf(input, " %lf",&num1);
    		fscanf(input," %lf",&num2);
    	    res = num1 * num2;
    	    fprintf(output,"\n%lf * %lf = %lf",num1,num2,res);
    	    break;
    	case '/':	//деление
    		fscanf(input, " %lf",&num1);
    		fscanf(input," %lf",&num2);
    	    res = num1 / num2;
    	    fprintf(output,"\n%lf / %lf = %lf",num1,num2,res);
    	    break;
    	case '^':	//возведение в степень
    		fscanf(input, " %lf",&num1);
    		fscanf(input," %lf",&num2);
    		res = 1;
    	    for (double i = 1; i < num2; i++) {
    	    	res = res * num1;
    	    }
    	    fprintf(output,"\n%lf ^ %lf = %lf",num1,num2,res);
    	    break;
    	case '!':	//факториал
    		fscanf(input," %lf",&num1);
    		if (num1 > 0) {
    			double temp = num1;
    			for(double i = 1; i < num1; i++) {
    				temp = temp * (num1 - i);
    			}
    			fprintf(output,"\n%lf! = %lf", num1, temp);
    		}
    		else if (num1 == 0) {
    			fprintf(output,"0! = 1");
    		}
    		else {
    			fprintf(output,"Введено не корекктное число");
    		}
    		break;
    	case ':':	//целочисленное деление
    		fscanf(input, " %lf",&num1);
    		fscanf(input," %lf",&num2);
    		res = (long int)num1 / (long int)num2;
		    fprintf(output,"\n%lf : %lf = %lf",num1,num2,res);
		    break;
    	case ';':	//деление с остатком
    		fscanf(input, " %lf",&num1);
    		fscanf(input," %lf",&num2);
    		res = num1 - (((long int)num1 / (long int)num2) * num2);
            fprintf(output,"\n%lf ; %lf = %lf",num1,num2,res);
    	    break;
    	default:	//в случае не правильного ввода
    	    fprintf(output,"\nНет такой операции");
    }
    }
    fclose(input); // закрытие
    fclose(output);
    printf("\nХотите повторить рассчет(y-да/n-нет):"); // повтор программы
    scanf(" %c", &agree);
    } while (agree == 'y');

	return 0;
}
