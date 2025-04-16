#include <iostream> 
#include <fstream> 
using namespace std;

struct WeatherData {
    char date[11];    // Дата (DD-MM-YYYY)
    int temperature;  // Температура в градусах Цельсия
    int humidity;     // Влажность в процентах
    double windspeed; // Скорость ветра в м/с
    bool sunny;       // Солнечно ли
};

int compareDates(const char* date1, const char* date2) {
    int day1 = (date1[0] - '0') * 10 + (date1[1] - '0');
    int month1 = (date1[3] - '0') * 10 + (date1[4] - '0');
    int year1 = (date1[6] - '0') * 1000 + (date1[7] - '0') * 100 + (date1[8] - '0') * 10 + (date1[9] - '0');

    int day2 = (date2[0] - '0') * 10 + (date2[1] - '0');
    int month2 = (date2[3] - '0') * 10 + (date2[4] - '0');
    int year2 = (date2[6] - '0') * 1000 + (date2[7] - '0') * 100 + (date2[8] - '0') * 10 + (date2[9] - '0');

    // Сравниваем год
    if (year1 < year2) return -1;
    if (year1 > year2) return 1;

    // Если год одинаковый, сравниваем месяц
    if (month1 < month2) return -1;
    if (month1 > month2) return 1;

    // Если месяц одинаковый, сравниваем день
    if (day1 < day2) return -1;
    if (day1 > day2) return 1;

    return 0; // Даты равны
}
int main() 
{
    setlocale(LC_ALL, "RU");
    ifstream in("Prognoz.txt");
    ofstream out("sort.bin", ios::binary);
    WeatherData w[100];
    if (!in)
    {
        cout << "Can't open file!" << endl;
        exit(-1);
    }
    int count = 0;
    WeatherData x;
    while (in >> x.date >> x.temperature >> x.humidity >> x.windspeed >> x.sunny)
    {
        if ((-10 <= x.temperature <= 25) && (30 <= x.humidity <= 50) &&
        (x.windspeed <= 5.5) && (x.sunny))
        {
            w[count] = x;
            count++;
        }
    }
    in.close();
    // Сортировка массива по дате (пузырьком)
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (compareDates(w[j].date, w[j + 1].date) > 0) {
                WeatherData temp = w[j];
                w[j] = w[j + 1];
                w[j + 1] = temp;
            }
        }
    }
    cout << "Отфильтровано и отсортировано " << count << " записей." << endl;
    for (int i = 0; i < count; i++)
        out.write((char*)&w[i], sizeof(struct WeatherData));
    out.close();
    ifstream in_bin("sort.bin", ios::binary);
    ofstream outf("out.txt");
    for (int i = 0; i < count; i++)
    {
        in_bin.read((char*)&x, sizeof(struct WeatherData));
        outf << x.date << "  " << x.temperature << "°C  " << x.humidity << "%  " << x.windspeed << " м/с  солнечно." << endl;
    }
    in_bin.close();
    outf.close();
    return 0;
}