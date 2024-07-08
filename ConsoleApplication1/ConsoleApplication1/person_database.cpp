#include "person_database.h"

void PersonDatabase::addPerson(const Person& person) {
    persons.push_back(person);
}

void PersonDatabase::updatePerson(int index, const Person& person) {
    if (index >= 0 && index < persons.size()) {
        persons[index] = person;
    }
}

void PersonDatabase::removePerson(int index) {
    if (index >= 0 && index < persons.size()) {
        persons.erase(persons.begin() + index);
    }
}

std::vector<Person> PersonDatabase::getAllPersons() {
    return persons;
}

void PersonDatabase::saveToFile(const std::string& filename) {
    std::ofstream file(filename, std::ios::out | std::ios::binary); // Открываем файл в бинарном режиме
    if (file.is_open()) {
        file << "\xEF\xBB\xBF"; // Добавляем маркер UTF-8 BOM
        for (const auto& person : persons) {
            file << person.name << "\n"
                << person.surname << "\n"
                << person.gender << "\n"
                << person.birthdate << "\n"
                << person.address << "\n";
        }
        file.close();
    }
}

void PersonDatabase::loadFromFile(const std::string& filename) {
    std::ifstream file(filename, std::ios::in);
    if (file.is_open()) {
        persons.clear();
        std::string line;
        Person person;
        while (std::getline(file, line)) {
            person.name = line;
            std::getline(file, line);
            person.surname = line;
            std::getline(file, line);
            person.gender = line;
            std::getline(file, line);
            person.birthdate = line;
            std::getline(file, line);
            person.address = line;
            persons.push_back(person);
        }
        file.close();
    }
}