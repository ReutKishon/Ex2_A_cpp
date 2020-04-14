#include "FamilyTree.hpp"
#include <iostream>
#include <string>
#include <exception>
using namespace family;
using namespace std;

Person::Person(string name, Gender gender)
{
    this->name = name;
    this->father = nullptr;
    this->mother = nullptr;
    this->gender = gender;
}

Tree::Tree(string name)
{

    this->root = new Person(name);
}

Tree Tree::addFather(string son_name, string father_name)
{

    return *this;
}

Tree Tree::addMother(string son_name, string mother_name)
{

    return *this;
}

string Tree::relation(string name){
    return "relation"}

string Tree::find(string relation)
{
    return "name";
}

void Tree::remove(string name)
{
}

void Tree::display()
{
}
