#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <string>
#include "FamilyTree.hpp"

using namespace std;
using namespace Family;

TEST_CASE("check add father:")
{
    Tree tree("Yossi");

    tree.addFather("Yossi", "Ben").addFather("Ben", "Shalom").addFather("Shalom", "Yaacov").addFather("Yaacov", "Jack").addFather("Jack", "Joe").addFather("Joe", "Nick").addFather("Nick", "Bill").addFather("Bill", "David").addFather("David", "Malo");
    CHECK((tree.root->father->name).compare("Ben") == 0);
    CHECK((tree.root->father->father->name).compare("Shalom") == 0);
    CHECK((tree.root->father->father->father->name).compare("Yaacov") == 0);
    CHECK((tree.root->father->father->father->father->name).compare("Jack") == 0);
    CHECK((tree.root->father->father->father->father->father->name).compare("Joe") == 0);
    CHECK((tree.root->father->father->father->father->father->father->name).compare("Nick") == 0);
    CHECK((tree.root->father->father->father->father->father->father->father->name).compare("Bill") == 0);
    CHECK((tree.root->father->father->father->father->father->father->father->father->name).compare("David") == 0);
    CHECK((tree.root->father->father->father->father->father->father->father->father->father->name).compare("Malo") == 0);
}

TEST_CASE("check add mother:")
{
    Tree tree("Reut");

    tree.addMother("Reut", "Shira").addMother("Shira", "Shoshi").addMother("Shoshi", "Yaara").addMother("Yaara", "Janny").addMother("Janny", "Joli").addMother("Joli", "Nina").addMother("Nina", "Tali").addMother("Tali", "Dana").addMother("Dana", "Miley");
    CHECK((tree.root->mother->name).compare("Shira") == 0);
    CHECK((tree.root->mother->mother->name).compare("Shoshi") == 0);
    CHECK((tree.root->mother->mother->mother->name).compare("Yaara") == 0);
    CHECK((tree.root->mother->mother->mother->mother->name).compare("Janny") == 0);
    CHECK((tree.root->mother->mother->mother->mother->mother->name).compare("Joli") == 0);
    CHECK((tree.root->mother->mother->mother->mother->mother->mother->name).compare("Nina") == 0);
    CHECK((tree.root->mother->mother->mother->mother->mother->mother->mother->name).compare("Tali") == 0);
    CHECK((tree.root->mother->mother->mother->mother->mother->mother->mother->mother->name).compare("Dana") == 0);
    CHECK((tree.root->mother->mother->mother->mother->mother->mother->mother->mother->mother->name).compare("Miley") == 0);
}

TEST_CASE("check the method 'relation': find a relation by name")
{
    Tree T("Yossi");
    T.addFather("Yossi", "Ben").addFather("Ben", "Shalom").addMother("Ben", "Rivka").addFather("Shalom", "Yaacov").addMother("Shalom", "Lea").addMother("Yossi", "Shira").addMother("Shira", "Ruti").addFather("Shira", "Jack").addMother("Ruti", "Nina").addFather("Ruti", "Joe");
    CHECK(T.relation("Ben").compare("father") == 0);
    CHECK(T.relation("Shira").compare("mother") == 0);
    CHECK(T.relation("Shalom").compare("grandfather") == 0);
    CHECK(T.relation("Rivka").compare("grandmother") == 0);
    CHECK(T.relation("Lea").compare("great-grandmother") == 0);
    CHECK(T.relation("Yaacov").compare("great-grandfather") == 0);
    CHECK(T.relation("Ruti").compare("grandmother") == 0);
    CHECK(T.relation("Jack").compare("grandfather") == 0);
    CHECK(T.relation("Nina").compare("great-grandmother") == 0);
    CHECK(T.relation("Joe").compare("great-grandfather") == 0);
}

TEST_CASE("check the method 'find': find a person by relation")
{
    Tree T("Yossi");
    T.addFather("Yossi", "Ben").addFather("Ben", "Shalom").addMother("Ben", "Rivka").addFather("Shalom", "Yaacov").addMother("Shalom", "Lea").addMother("Yossi", "Shira").addMother("Shira", "Ruti").addFather("Shira", "Jack").addMother("Ruti", "Nina").addFather("Ruti", "Joe").addFather("Yaacov", "Beny").addFather("Beny", "Tom").addFather("Joe", "Germy").addFather("Germy", "Danny").addMother("Lea", "Pninit").addMother("Pninit", "Nofar").addMother("Nina", "Liron").addMother("Liron", "Noa");

    CHECK(T.find("mother") == "Shira");
    CHECK(T.find("father") == "Ben");
    CHECK((T.find("grandfather") == "Shalom" || T.find("grandfather") == "Jack"));
    CHECK((T.find("grandmother") == "Rivka" || T.find("grandmother") == "Ruti"));
    CHECK((T.find("great-grandmother") == "Lea" || T.find("great-grandmother") == "Nina"));
    CHECK((T.find("great-grandfather") == "Yaacov" || T.find("great-grandfather") == "Joe"));
    CHECK((T.find("great-great-grandfather") == "Beny" || T.find("great-great-grandfather") == "Germy"));
    CHECK((T.find("great-great-great-grandfather") == "Tom" || T.find("great-great-great-grandfather") == "Danny"));
    CHECK((T.find("great-great-grandmother") == "Pninit" || T.find("great-great-grandmother") == "Liron"));
    CHECK((T.find("great-great-great-grandmother") == "Nofar" || T.find("great-great-great-grandmother") == "Noa"));
}

TEST_CASE("check remove:")
{
    Tree T("Yossi");
    T.addFather("Yossi", "Ben").addFather("Ben", "Shalom").addMother("Ben", "Rivka").addFather("Shalom", "Yaacov").addMother("Shalom", "Lea").addMother("Yossi", "Shira").addMother("Shira", "Ruti").addFather("Shira", "Jack").addMother("Ruti", "Nina").addFather("Ruti", "Joe").addFather("Yaacov", "Beny").addFather("Beny", "Tom").addFather("Joe", "Germy").addFather("Germy", "Danny").addMother("Lea", "Pninit").addMother("Pninit", "Nofar").addMother("Nina", "Liron").addMother("Liron", "Noa");

    T.remove("Shalom");
    CHECK(T.search_person_by_name("Shalom") == nullptr);
    CHECK(T.search_person_by_name("Yaccov") == nullptr);
    CHECK(T.search_person_by_name("Beny") == nullptr);
    CHECK(T.search_person_by_name("Tom") == nullptr);
    CHECK(T.search_person_by_name("Lea") == nullptr);
    CHECK(T.search_person_by_name("Pninit") == nullptr);
    CHECK(T.search_person_by_name("Nofar") == nullptr);
    T.remove("Shira");
    CHECK(T.search_person_by_name("Shira") == nullptr);
    CHECK(T.search_person_by_name("Ruti") == nullptr);
    CHECK(T.search_person_by_name("Jack") == nullptr);
    CHECK(T.search_person_by_name("Joe") == nullptr);
    CHECK(T.search_person_by_name("Nina") == nullptr);
    CHECK(T.search_person_by_name("Gremy") == nullptr);
    CHECK(T.search_person_by_name("Liron") == nullptr);
    CHECK(T.search_person_by_name("Dany") == nullptr);
    CHECK(T.search_person_by_name("Noa") == nullptr);
}

TEST_CASE("check remove and relation")
{

    Tree T("Yossi");

    T.addFather("Yossi", "Ben").addFather("Ben", "Shalom").addMother("Ben", "Rivka").addFather("Shalom", "Yaacov").addMother("Shalom", "Lea").addMother("Yossi", "Shira").addMother("Shira", "Ruti").addFather("Shira", "Jack").addMother("Ruti", "Nina").addFather("Ruti", "Joe").addFather("Yaacov", "Beny").addFather("Beny", "Tom").addFather("Joe", "Germy").addFather("Germy", "Danny").addMother("Lea", "Pninit").addMother("Pninit", "Nofar").addMother("Nina", "Liron").addMother("Liron", "Noa");

    T.remove("Shalom");
    
}
