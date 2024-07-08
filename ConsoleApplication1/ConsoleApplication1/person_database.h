#ifndef PERSON_DATABASE_H
#define PERSON_DATABASE_H

#include <string>
#include <vector>
#include <fstream>
#include <locale>


struct Person {
    std::string name;
    std::string surname;
    std::string gender;
    std::string birthdate;
    std::string address;
};

class PersonDatabase {
public:
    void addPerson(const Person& person);
    void updatePerson(int index, const Person& person);
    void removePerson(int index);
    std::vector<Person> getAllPersons();
    void saveToFile(const std::string& filename);
    void loadFromFile(const std::string& filename);

private:
    std::vector<Person> persons;
};

#endif // PERSON_DATABASE_H
