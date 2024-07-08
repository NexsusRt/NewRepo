#include <iostream>
#include "person_database.h"

int main() {
    setlocale(LC_CTYPE, "Russian");
    PersonDatabase db;
    int choice = 0;
    std::vector<Person> persons;
    Person newPerson;
    std::string filename = "persons.txt";

    while (true) {
        std::cout << "1. Просмотреть данные" << std::endl;
        std::cout << "2. Добавить данные" << std::endl;
        std::cout << "3. Сохранить данные" << std::endl;
        std::cout << "4. Загрузить данные" << std::endl;
        std::cout << "5. Выход" << std::endl;
        std::cout << "Выберите действие: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            // Просмотр данных
            persons = db.getAllPersons();
            for (const auto& person : persons) {
                std::cout << "Имя: " << person.name << ", Фамилия: " << person.surname << ", Пол: " << person.gender << ", Дата рождения: " << person.birthdate << ", Место жительства: " << person.address << std::endl;
            }
            break;
        case 2:
            // Добавление данных
            std::cout << "Введите имя: ";
            std::cin >> newPerson.name;
            std::cout << "Введите фамилию: ";
            std::cin >> newPerson.surname;
            std::cout << "Введите пол: ";
            std::cin >> newPerson.gender;
            std::cout << "Введите дату рождения: ";
            std::cin >> newPerson.birthdate;
            std::cout << "Введите место жительства: ";
            std::cin >> newPerson.address;
            db.addPerson(newPerson);
            std::cout << "Данные добавлены." << std::endl;
            break;
        case 3:
            // Сохранение данных
            db.saveToFile(filename);
            std::cout << "Данные сохранены в файл " << filename << "." << std::endl;
            break;
        case 4:
            // Загрузка данных
            db.loadFromFile(filename);
            std::cout << "Данные загружены из файла " << filename << "." << std::endl;
            break;
        case 5:
            // Выход
            return 0;
        default:
            std::cout << "Неверный выбор. Попробуйте еще раз." << std::endl;
            break;
        }
    }
}