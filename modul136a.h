 //Пинчукова Гертруда ИВТ-22
 #ifndef MODUL136A_H
 #define MODUL136A_H
#include <string>
#include <vector>
using namespace std; 

namespace ArrayEl{
//array -массив 
 //size -размер
 //nameF-имя файла 
//max min - максимальное и минимальное значение для заполнения рандомно
 void FillArray(vector<float> &array, unsigned size, int max, int min);                 //заполнение массива
 
 void printArray(vector<float> &array, unsigned size);                                  //вывод массива на экран

 float SummEL(vector<float> &array, unsigned size);                                    //поиск суммы элементов

 void ArrayFromFile (vector<float> &array, unsigned size, const string  &NameF);       //заполнение массива из файла

 unsigned ArraySFromFile(const string  &NameF);                                       // поиск размера массива в файле 

 void printArrayToFile(vector<float> &array, unsigned size, const string  &NameF);     //вывод массива в файл

  void print_vector(vector<float> &arr );                                              //вывод вектора
}
#endif
