#include <stdio.h>


int task1(int dec, int i, int * bin_arr){
    //1. Реализовать функцию перевода из 10 системы в двоичную используя рекурсию.
    
    if (dec == 0){
        i--;
        while(i >= 0){
            printf("%i",bin_arr[i]);
            i--;
        }
        return 0;
    }else {
        int temp = dec % 2;
        dec /= 2;
        if(temp == 0) {
            *(bin_arr + i) = 0;
            i++;
        }else{
           *(bin_arr + i) = 1;
           i++;
        }
        task1(dec , i, &bin_arr[0]);
    }
    
    
}
float task2a(){
    /*2. Реализовать функцию возведения числа a в степень b:
    a. без рекурсии;*/
    int a,b;
    float mult;
    printf("Задача 2a.\nВведите число a : ");
    scanf("%i",&a);
    printf("\nВведите число b : ");
    scanf("%i",&b);
    mult = a;
    if (b == 0){
        printf("Число а в степени b : 1");
        return 1;
    }
    if(b > 0){
        for(int i = 1; i < b; i++ ){
            mult = mult * a;
        }
        printf("Число а в степени b : %f",mult);
        return mult;
    }
    if(b < 0){
        for(int i = 1; i < b*(-1); i++ ){
            mult = mult * a;
        }
        printf("Число а в степени b : %f",1/mult);
        return 1/mult;        
        
    }
    
}
float task2b(int a, int b){
    if(!b){
        return 1;
    }
        b--;
        return a*task2b(a,b);
    }
   
int task3a(int start, int stop){
/*3. Исполнитель Калькулятор преобразует целое число, записанное на экране. 
У исполнителя две команды, каждой команде присвоен номер:  
Прибавь 1 2.Умножь на 2 Первая команда увеличивает число на экране на 1,
вторая увеличивает это число в 2 раза. Сколько существует программ, 
которые число 3 преобразуют в число 20? 
а) с использованием массива; 
б) с использованием рекурсии.*/
    int i, arr[20] = {0};
    arr[start] = 1;
    for(i = start + 1; i <= stop; i++){
        if((i % 2) == 0) {
            arr[i] = arr[i - 1] + arr[i / 2];
        }else{
            arr[i] = arr[i - 1];
        }
    }
    return arr[stop];
}
int task3b(int start, int stop){
    if(stop < start){
        return 0;
    }
    if (start == stop){
        return 1;
    }
    return task3b(start + 1, stop) + task3b(start * 2, stop);
}
int main()
{
/*-----------------------------------------------------------------------*/ 

    /*int i = 0, dec = 0;
    int bin_arr[32] = {0};
    
    printf("Задача 1.\nВведите десятичное число : ");
    scanf("%i",&dec);
    task1(dec , i, &bin_arr[0]);*/
    
/*-----------------------------------------------------------------------*/ 

    //task2a();
    
/*-----------------------------------------------------------------------*/    
    /*int a,b;
    printf("Задача 2b.\nВведите число a : ");
    scanf("%i",&a);
    printf("\nВведите число b : ");
    scanf("%i",&b);
    if (b == 0){
        printf("Число а в степени b : 1");
    }else{
        if(b > 0){
            printf("Число а в степени b : %i",(int) task2b(a,b));
        }
        if(b < 0){
            b *= -1;
            printf("Число а в степени b : %f",(float) (1/task2b(a,b)));
        }
    }*/

/*-----------------------------------------------------------------------*/    

   //printf("%i",task3a(3,20));

/*-----------------------------------------------------------------------*/ 
    printf("%i",task3b(3,20));

    return 0;
}







