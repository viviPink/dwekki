//Пинчукова Гертруда ИВТ-22
#include <math.h>
#include <iostream> 
#include <ctime>
#include <fstream>
#include <iomanip>
#include <execution>
#include <vector>
 using namespace std;   


namespace ArrayEl{
/// вывод массива в файл
 //array -массив 
 //size -размер
 //nameF-имя файла 
void printArrayToFile(vector<float> &array, unsigned size, const string  &NameF)
{
   ofstream file(NameF);                        //открытие файла Out file stream
  if (!file.is_open())                              
            {
                cout << "File not found:" << endl; //если файл не открыт         
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
void ArrayFromFile (vector<float> &array, unsigned size, const string &NameF)
{
 ifstream file(NameF);                             //открытие файла
  if  (!file.is_open()) 
    {
                cout << "File not found:" << endl; // Если файл не найден->ошибка
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
                cout << "File not found:" << endl;          
                
            }
        while (getline(file, line))   // кол-во строк,кол-во элементов массива
            {
                res++;                //  делает переходы -> идет цикл
               
            }
        file.close();// Закрыть файл
         if (res==0)
         throw runtime_error("empty file");   //если файл пустой-> ошибка
                      
        return res;
      

    }

/// заполнение массива рвндомными числами, в пределах пользователя
 //array -массив 
 //size -размер
 //nameF-имя файла 
 void FillArray(vector<float> &array, unsigned size, int max, int min)
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
void printArray(vector<float> &array, unsigned size)
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
float SummEL(vector<float> &array, unsigned size)
{
 float u=0;                                     //переменна я для записи суммы
  for (int i = 0; i < size; i++)
  {
  u=array[i]+u;
  }
  return u;                                    
}

 /// Функция вывода массива из векторов arr размера на экран
        void print_vector(vector<float> &arr )
        {
        for (int i = 0; i < arr.size(); ++i)
            cout << setprecision(3) << arr[i] << " ";
        }

}