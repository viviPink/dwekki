//Пинчукова Гертруда ИВТ-22
#include <math.h>
#include <iostream> 
#include <ctime>
#include <fstream>
#include <iomanip>
#include <execution>
#include <cstdlib> 
 using namespace std;   


namespace ArrayEl
{

	using ULL= unsigned;           //создаем псевдоним
/// вывод массива в файл
 //array -массив 
 //size -размер
 //nameF-имя файла 
void printArrayToFile(float* array, ULL size, const string  &NameF)
{
   ofstream file(NameF);                        //открытие файла Out file stream
  if (!file.is_open())                              
            {
                 throw  runtime_error( "File not found:" ) ; //если файл не открыт         
            }
  for (int i = 0; i < size; i++)
  {               //вывода массива в файл
    file<< array[i]<<endl; 
  }
    file.close();                               // Закрыть файл
        
}


///чтение и вывод массива из файла
 //array -массив 
 //size -размер
 //nameF-имя файла 
void ArrayFromFile (float* array, ULL size, const string &NameF)
{
 ifstream file(NameF);                             //открытие файла
  if  (!file.is_open()) 
    {
                throw  runtime_error( "File not found:" ); // Если файл не найден->ошибка
        }
        for (unsigned i = 0; i < size; i++)        // чтения массива из файла
        {
            file >> array[i];                      //числа записываются в массив
    }
    file.close();                                  // Закрыть файл
}


/// Функция поиска кол-ва элементов массива в файле
 //array -массив 
 //size -размер
 //nameF-имя файла 
    unsigned ArraySFromFile(const string  &NameF)
    {
        unsigned res = 0;              // счет кол-ва строк
        string line;                   // для поиска кол-ва строк
         ifstream file(NameF);    // Открытие файла 
        if (!file.is_open())                              
            {
                throw runtime_error( "File not found:" );          
                
            }
        while (getline(file, line))   // кол-во строк,кол-во элементов массива
            {
                res++;                //  делает переходы -> идет цикл
               
            }
        file.close();// Закрыть файл
         //if (res==0)
         //throw runtime_error("empty file");   //если файл пустой-> ошибка
                      
        return res;
      

    }

/// заполнение массива рвндомными числами, в пределах пользователя
 //array -массив 
 //size -размер
 //nameF-имя файла 
 void FillArray(float* array, ULL size, int max, int min)
{  //max-мак-ое число,min-минимальное число значения переменных
    int range = max - min;                                
    for (unsigned i = 0; i < size; i++)
    { 
    	//заполнение рандомными числами
    	//тип переменных- с плавающей точкой, range=макс число-мин число
        array[i] =(float)rand()/RAND_MAX*max+min;  
    }

}
  

///вывод массива на экран
//array -массив 
//size -размер
void printArray(float* array, unsigned size)
{
    for (int i = 0; i < size; i++)
    {
    	// set_pecision- 2 знака после запятой 
        cout << setprecision(2)<<array[i]<< " "; //вывод массива с 2 знаками после ," 
    }
    cout << endl;
}

///поиск суммы
//array -массив 
//size -размер
float SummEL(float* array, ULL size)
{
 float u=0;                                     //переменна я для записи суммы
  for (int i = 0; i < size; i++)
  {
  u=array[i]+u;
  }
  return u;                                    
}

 void WtiteToBin(float* array,  unsigned size, const string& NameF) 
        {
            ofstream file(NameF, ios::binary);
            file.write(reinterpret_cast<const char*>(&size), sizeof(size));
            file.write(reinterpret_cast<const char*>(array), sizeof(float) * size);
            file.close();
        }

        ///Выгоняет массив из бинарного файла
        void WriteFromBin(float* array,  unsigned& size, const string& NameF) 
        {
            ifstream file(NameF, ios::binary);
            file.read(reinterpret_cast<char*>(&size), sizeof(size));
            array = new float[size];
            file.read(reinterpret_cast<char*>(array), sizeof(float)*size);
            file.close();
        }

}