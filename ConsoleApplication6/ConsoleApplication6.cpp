#include <iostream>

#include <vector>

#include <string>


#include <windows.h>

using namespace std;

class Person 
{

public:

    string name;



    Person(const string& name) : name(name) {}

};



class Apartment 
{

private:

    vector<Person> residents;



public:

    void addResident(const Person& person) 
    {

        if (residents.size() >= 3) 
        {

            throw std::runtime_error("Максимум 3 человека в одной квартире.");

        }

        residents.push_back(person);

    }



    void showResidents() const {

        cout << "Жители квартиры:";

        for (const auto& resident : residents) 
        {

            cout << " " << resident.name;

        }

        cout << endl;

    }

};



class House 
{

private:

    vector<Apartment> apartments;



public:

    House(int numApartments) 
    {

        if (numApartments > 6) {

            throw runtime_error("Максимум 6 квартир в доме.");

        }

        apartments.resize(numApartments);

    }



    void addResidentToApartment(int apartmentIndex, const Person& person) 
    {

        if (apartmentIndex < 0 || apartmentIndex >= apartments.size()) {

            throw out_of_range("Неверный индекс квартиры.");

        }

        apartments[apartmentIndex].addResident(person);

    }



    void showApartments() const 
    {

        for (int i = 0; i < apartments.size(); ++i) 
        {

            cout << "Квартира " << i + 1 << ": "<<endl;

            apartments[i].showResidents();

        }

    }

};



int main() {
    system("chcp 1251 > nul");
    setlocale(LC_ALL, "Rus");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    House house(6);



    // Добавляем жителей в квартиры

    house.addResidentToApartment(0, Person("Алексей"));

    house.addResidentToApartment(0, Person("Мария"));

    house.addResidentToApartment(0, Person("Иван"));



    house.addResidentToApartment(1, Person("Светлана"));

    house.addResidentToApartment(1, Person("Дмитрий"));



    house.addResidentToApartment(2, Person("Ольга"));

    house.addResidentToApartment(2, Person("Павел"));

    house.addResidentToApartment(2, Person("Алексей"));

    house.addResidentToApartment(3, Person("Ольга"));

    house.addResidentToApartment(3, Person("Павел"));

    house.addResidentToApartment(3, Person("Роман"));

    house.addResidentToApartment(4, Person("Ольга"));

    house.addResidentToApartment(4, Person("Михаил"));

    house.addResidentToApartment(4, Person("Елена"));


    house.addResidentToApartment(5, Person("Стивен"));


 


    // Вывод информации о квартирах и их жителях

    house.showApartments();



    return 0;

}