 //Пинчукова Гертруда ИВТ-22
 #ifndef MODUL136A_H
 #define MODUL136A_H
#include <string>
#include <vector>
#include <iostream>
using namespace std; 

namespace ArrayEl{
//array -массив 
//size -размер
//nameF-имя файла 
//max min - максимальное и минимальное значение для заполнения рандомно
 void FillArray(float* array, unsigned size, int max, int min);                 //заполнение массива
 
 
 void printArray(float* array, unsigned size);                                  //вывод массива на экран

 /*template<typename T>
void printArray(const vector<T>& array ) { //const Element * array, unsigned size                                   //вывод массива на экран
    for (unsigned i = 0; i < array.size(); i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}
*/
 float SummEL(float* array, unsigned size);                                     //поиск суммы элементов

 void ArrayFromFile (float* array, unsigned size, const string  &NameF);        //заполнение массива из файла

 unsigned ArraySFromFile(const string  &NameF);                                         // поиск размера массива в файле 

 void printArrayToFile(float* array, unsigned size, const string  &NameF);       //вывод массива в файл

         //ввод массива в бинарный файл
    void WtiteToBin(float* array,  unsigned size, const string& NameF); 

///массив из бинарного файла
    void WriteFromBin(float* array,  unsigned& size, const string& NameF);

}
#endif
