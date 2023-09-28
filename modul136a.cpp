//Пинчукова Гертруда ИВТ-22
#include <math.h>
#include <iostream> 
#include <ctime>
#include <fstream>

 using namespace std;   



/// вывод массива в файл
void printArrayToFile(float* array, unsigned size, const string  &NameF){
   ofstream file(NameF);                        //открытие файла Out file stream
  if (!file.is_open())                              
            {
                cout << "File not found:" << endl; //если файл не открыт         
            }
  for (int i = 0; i < size; i++){               //вывода массива в файл
    file<< array[i]<<endl; 
  }
    file.close();                               // Закрыть файл
        
}


///чтение и вывод массива из файла
void ArrayFromFile (float* array, unsigned size, const string &NameF)
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
    
}


/// Функция поиска кол-ва элементов массива в файле
    unsigned ArraySFromFile(const string  &NameF)
    {
        unsigned res = 0;              // счет кол-ва строк
        string line;                   // для поиска кол-ва строк
         std::ifstream file(NameF);    // Открытие файла 
        if (!file.is_open())                              
            {
                cout << "File not found:" << endl;          
                return 0;
            }
        while (getline(file, line))   // кол-во строк,кол-во элементов массива
            {
                res++;                //  делает переходы -> идет цикл
            }
        file.close();                 // Закрыть файл
        return res;
    }

/// заполнение массива рвндомными числами, в пределах пользователя
 void FillArray(float* array, unsigned size, int max, int min)
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
void printArray(float* array, unsigned size)
{
    for (int i = 0; i < size; i++)
    {
    	// set_pecision
        cout << round(array[i]*100)/100 << " "; //вывод массива с 2 знаками после ," 
    }
    cout << endl;
}

///поиск суммы
float SummEL(float* array, unsigned size)
{
 float u=0;                                     //переменна я для записи суммы
  for (int i = 0; i < size; i++)
  {
  u=array[i]+u;
  }
  return u;
}