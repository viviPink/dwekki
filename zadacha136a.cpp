//Пинчукова Гертруда ИВТ-22
#include "modul136a.h"
#include <iostream> 
#include <math.h> 
#include <ctime>
#include <cassert> 
#include <cstdlib>
#include <fstream> 
#include <execution> 
#include <vector>
 using namespace std;   


int main()
{

    srand(time(nullptr));
   //проверка assert//
 unsigned size=3;

     vector<float> array_test = {1,2,3};     //выделение памяти под массив
     assert ( ArrayEl::SummEL(array_test, size)== 6);
      array_test.clear() ;                           //освобождение мамяти

     vector<float> array_test_2 = {2,3,4};  //выделение памяти под массив
     assert ( ArrayEl::SummEL(array_test_2, size)== 9);
      array_test_2.clear() ;                         //освобождение мамяти

vector<float> array_test_3 = {0,2,3};        //выделение памяти под массив
     assert ( ArrayEl::SummEL(array_test_3, size)== 5);
      array_test_3.clear() ;                         //освобождение мамяти


    
 float p;
 unsigned arraySize;                                    //размер массива
 char check;   
 int max_nam, min_nam;                                  // Переменная для проверки условия 
 string NameF ;                                         // переменная файла для записи массива      

 cout << "Create a new array? y/n " << endl;           
 cin >> check;

if ((check == 'Y') or (check == 'y'))   
{   //создание нового массива рандомными числами

    cout << "Array size: ";                             //ввод размера массива
    cin >> arraySize;
       
     ///выделение памяти под массив
    vector<float> array;                                        
    array.resize(arraySize); 

///запрашиваем у пользователя максимальное число значения эл-та массива
    cout<< "write max value of numbers "<<endl;      
    cin>> max_nam;
///запрашиваем у пользователя минимальное число значения эл-та массива
    cout<< "write min value of numbers "<<endl;
    cin>>min_nam;

            
    ArrayEl::FillArray(array, arraySize, max_nam,min_nam);      //заполнгение массива
    ArrayEl::print_vector(array);

    cout << "Array:" <<endl;

    ArrayEl::printArray(array, arraySize);                      //вывод массива
    p=ArrayEl::SummEL(array, arraySize);                        //поиск суммы элементов
    cout << "sum of array:" << p<<endl;

    
     cout << "Save array? y/n" << endl;
    cin >> check;
    if ((check == 'Y') or (check == 'y'))                       // Если да, то выводим массив в файл
        {
            cout<<"Name of file?"<<endl;
            cin>>NameF;
            ArrayEl::printArrayToFile(array, arraySize,NameF);   // Вывод массива в файл
        }

   
    array.clear();                                              //освобождение памяти
}
else {///вывод массива из файла
    cout<<"Name of file?"<<endl;
            cin>>NameF;

    cout<<"array was loaded from file"<<endl;
  ///проверка 
   try{
   unsigned size_testik=ArrayEl::ArraySFromFile(NameF);         //поиск размера массива
    }
   
    //если файл пустой-> ошибка 
    catch (const exception &error){
        cout<< error.what();                                    //вывод ошибки
    }   


    size=ArrayEl::ArraySFromFile(NameF);  
     vector<float> array;                                        // Дин массив, пустой
    array.resize(size);                    
                   //выделение памяти под массив
ArrayEl::ArrayFromFile(array,arraySize,NameF);                   //заполнение массива из файла
ArrayEl::printArray(array, size);                                //вывод массива на экран

ArrayEl::print_vector(array);
  p=ArrayEl::SummEL(array, arraySize);                           //поиск суммы элементов
 cout << "sum of array:" << p <<endl;

 array.clear();                                                 //освобождение памяти
}
}