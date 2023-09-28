//Пинчукова Гертруда ИВТ-22
#include "modul136a.h"
#include <iostream> 
#include <math.h> 
#include <ctime>
#include <cassert> 
#include <cstdlib>
#include <fstream>  
 using namespace std;   


int main()
{

    srand(time(nullptr));
   //проверка assert//
 unsigned size=3;

     float* array_test = new float[size] {1,2,3};     //выделение памяти под массив
     assert ( SummEL(array_test, size)== 6);
      delete[] array_test ;                           //освобождение мамяти

      float* array_test_2 = new float[size] {2,3,4};  //выделение памяти под массив
     assert ( SummEL(array_test_2, size)== 9);
      delete[] array_test_2 ;                         //освобождение мамяти

float* array_test_3 = new float[size] {0,2,3};        //выделение памяти под массив
     assert ( SummEL(array_test_3, size)== 5);
      delete[] array_test_3 ;                         //освобождение мамяти


    
 float p;
 unsigned arraySize;                                    //размер массива
 char check;   
 int max_nam, min_nam;                                  // Переменная для проверки условия 
 string NameF ;                // переменная файла для записи массива      

 cout << "Create a new array? y/n " << endl;           
 cin >> check;

if ((check == 'Y') or (check == 'y'))   
{   //создание нового массива рандомными числами

    cout << "Array size: ";                             //ввод размера массива
    cin >> arraySize;
       //запрашиваем у пользователя максимальное число значения эл-та массива
    cout<< "write max value of numbers "<<endl;      
    cin>> max_nam;
       //запрашиваем у пользователя минимальное число значения эл-та массива
    cout<< "write min value of numbers "<<endl;
    cin>>min_nam;

    float* array = new float[arraySize];               //выделение памяти под массив

    FillArray(array, arraySize, max_nam,min_nam);      //заполнгение массива
    

    cout << "Array:" <<endl;

    printArray(array, arraySize);                      //вывод массива
    p=SummEL(array, arraySize);                        //поиск суммы элементов
    cout << "sum of array:" << p<<endl;

    
     cout << "Save array? y/n" << endl;
    cin >> check;
    if ((check == 'Y') or (check == 'y'))               // Если да, то выводим массив в файл
        {
            cout<<"Name of file?"<<endl;
            cin>>NameF;
            printArrayToFile(array, arraySize,NameF);   // Вывод массива в файл
        }

   
    delete[] array;                                     //освобождение памяти
}
else {///вывод массива из файла
    cout<<"Name of file?"<<endl;
            cin>>NameF;
            
    cout<<"array was loaded from file"<<endl;

    size=ArraySFromFile(NameF);                         //поиск размера массива
     float* array = new float[arraySize];               //выделение памяти под массив
ArrayFromFile(array,arraySize,NameF);                   //заполнение массива из файла
printArray(array, size);                                //вывод массива на экран

  p=SummEL(array, arraySize);                           //поиск суммы элементов
 cout << "sum of array:" << p <<endl;

 delete[] array;                                        //освобождение памяти
}
}