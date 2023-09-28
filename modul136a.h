 //Пинчукова Гертруда ИВТ-22
 #ifndef MODUL136A_H
 #define MODUL136A_H
#include <string>
using namespace std; 

 void FillArray(float* array, unsigned size, int max, int min);                 //заполнение массива
 
 void printArray(float* array, unsigned size);                                  //вывод массива на экран

 float SummEL(float* array, unsigned size);                                    //поиск суммы элементов

 void ArrayFromFile (float* array, unsigned size, const string  &NameF);       //заполнение массива из файла

 unsigned ArraySFromFile(const string  &NameF);                                // поиск размера массива в файле 

 void printArrayToFile(float* array, unsigned size, const string  &NameF);     //вывод массива в файл

#endif
