
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
 using namespace  ArrayEl;   
int main(int argc, char* argv[])
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




string check;
if (argc>1){

 check=argv[1];
    if (check == "help") {
        cout << "If you want to create a new mass write <y>" << endl;
        cout << "Write a mass size <n>" << endl;
        cout << "write max value of number and min value <max_nam><min_nam>" << endl;
        cout << "If u want to save mass write y" << endl;
        cout << "write name of File" << endl;
}


 float p;
 unsigned arraySize;                                    //размер массива 
 int max_nam, min_nam;                                  // Переменная для проверки условия 
 string NameF ;                                         // переменная файла для записи массива      
 //cout << "Create a new array? y/n " << endl;           
 //cin >> check;

if ((check == "Y") or (check == "y"))   
{   //создание нового массива рандомными числами
 
arraySize = stoi(argv[2]);                            //ввод размера массива
///выделение памяти под массив
 float* array = new float[arraySize]; 

///запрашиваем у пользователя максимальное число значения эл-та массива
     max_nam=stoi(argv[3]);
///запрашиваем у пользователя минимальное число значения эл-та массива
    min_nam=stoi(argv[4]);
 FillArray(array, arraySize, max_nam,min_nam);      //заполнгение массива
cout << "Array:" <<endl;
 printArray(array,arraySize);                                 //вывод массива
 p=SummEL(array, arraySize);                        //поиск суммы элементов
 cout << "sum of array:" << p<<endl;


if(argc==6)
NameF=argv[5];
if (NameF.size() != 0)
        {
        cout << "Entered name of file: " << NameF << endl;    // Просим у пользователя название файла
        bool found = NameF.find(".txt") != std::string::npos;
        if (found)
        {
            cout << "Saved in txt file" << endl;
            printArrayToFile(array, arraySize, NameF);            // Выводим массив в файл
        }
        else
        {
            cout << "Saved in bin file" << endl;
            WtiteToBin(array, arraySize, NameF); 
        }

                                                  
}
 delete[] array;     //освобождение памяти
}

if ((check=="n")||(check=="N")){ 
NameF=argv[2];
///вывод массива из файла
 cout<<"array was loaded from file"<<endl;
  ///проверка 
   try{
   unsigned size_testik=ArraySFromFile(NameF);         //поиск размера массива
    }
    //если файл пустой-> ошибка 
    catch (const  runtime_error &error){
        cout<< error.what();                                    //вывод ошибки
    }   
try{
    size=ArraySFromFile(NameF); 
    }
     //если файл пустой-> ошибка 
    catch (const  runtime_error &error){
        cout<< error.what();                                    //вывод ошибки
    }   
float* array = new float[arraySize];                      
                   //выделение памяти под массив
    try{
    size=ArraySFromFile(NameF); 
    ArrayFromFile(array,arraySize,NameF);                   //заполнение массива из файла
    printArray(array,arraySize);                                      //вывод массива на экран
}//если файл пустой-> ошибка 
    catch (const  runtime_error &error){
        cout<< error.what();                                                                     //вывод ошибки
    }  
  p=SummEL(array, arraySize);                           //поиск суммы элементов
 cout << "sum of array:" << p <<endl;
 delete[] array;                                                //освобождение памяти
    }
}
else {
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

  cout << "Txt or bin? If txt type t" << endl; //  Спрашиваем о сохранении  массива   
            check = 0;
            cin >> check;
            if ((check == 'T') or (check == 't'))         // Если пользователь соглашается...
            {
            cout << "file (.txt): " << endl;    // Просим у пользователя название файла
            cin >> NameF;
            printArrayToFile(array, arraySize, NameF);            // Выводим массив в файл
            }
            else
            {
            cout << "Type name of bin file: " << endl;    // Просим у пользователя название файла
            cin >> NameF;
             WtiteToBin(array,arraySize,NameF); 
            }
   
    delete[] array;                                     //освобождение памяти
}
else {///вывод массива из файла
    cout<<"Name of file?"<<endl;
    cin>>NameF;
cout << "Txt or bin? If txt type t" << endl; //   Спрашиваем о сохранении  
check= 0;
    cin >> check;
    if ((check == 't') or (check == 'T'))         // Если пользователь соглашается...
    {
    size = ArraySFromFile(NameF);                // Находим кол-во элементов мас из файла
    float* array = new float[size];                         // Выделяем память под динамический массив
    ArrayFromFile (array, size,NameF);                // Считываем массив из файла
    printArray(array,size);                                   // Выводим массив на экран
      p=SummEL(array, size);                           //поиск суммы элементов
 cout << "sum of array:" << p <<endl; 
    delete[] array;                                            // Подчищаем память
    }
    else
    {
        size = ArraySFromFile(NameF);                // Находим кол-во элементов мас из файла
        float*array = new float[size]; 
        WriteFromBin(array,size,NameF);
        printArray(array,size);                                  // Выводим массив на экран
          p=SummEL(array, size);                           //поиск суммы элементов
 cout << "sum of array:" << p <<endl; 
        delete[] array;                                            // очищение памяти

    }
}
}
}
