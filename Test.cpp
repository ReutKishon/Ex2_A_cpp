#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
// #define CHECK DOCTEST_CHECK

#include <string>
#include "FamilyTree.hpp"

using namespace std;
using namespace family;

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
    CHECK(T.relation("Shalom") == "unrelated");
    CHECK(T.relation("Yaccov") == "unrelated");
    CHECK(T.relation("Beny") == "unrelated");
    CHECK(T.relation("Tom") == "unrelated");
    CHECK(T.relation("Lea") == "unrelated");
    CHECK(T.relation("Pninit") == "unrelated");
    CHECK(T.relation("Nofar") == "unrelated");
    T.remove("Shira");
    CHECK(T.relation("Shira") == "unrelated");
    CHECK(T.relation("Ruti") == "unrelated");
    CHECK(T.relation("Jack") == "unrelated");
    CHECK(T.relation("Joe") == "unrelated");
    CHECK(T.relation("Nina") == "unrelated");
    CHECK(T.relation("Gremy") == "unrelated");
    CHECK(T.relation("Liron") == "unrelated");
    CHECK(T.relation("Dany") == "unrelated");
    CHECK(T.relation("Noa") == "unrelated");
}

TEST_CASE("Test tree 1 : check all the functions:")
{
    Tree tree("reut");
    tree.addFather("reut", "shraga");
    tree.addMother("reut", "haidi");
    tree.addFather("shraga", "shmuel");
    tree.addMother("shraga", "pnina");
    tree.addFather("shmuel", "eliezer");
    tree.addMother("shmuel", "ester");
    tree.addMother("pnina", "rachel");

    CHECK(tree.relation("shraga").compare("father") == 0);
    CHECK(tree.relation("haidi").compare("mother") == 0);
    CHECK(tree.relation("shmuel").compare("grandfather") == 0);
    CHECK(tree.relation("pnina").compare("grandmother") == 0);
    CHECK(tree.relation("ester").compare("great-grandmother") == 0);
    CHECK(tree.relation("rachel").compare("great-grandmother") == 0);
    CHECK(tree.relation("eliezer").compare("great-grandfather") == 0);
    CHECK(tree.relation("reut").compare("me") == 0);
    CHECK(tree.find("father") == "shraga");
    CHECK(tree.find("mother") == "haidi");
    CHECK(tree.find("grandfather") == "shmuel");
    CHECK(tree.find("great-grandfather") == "eliezer");
    CHECK(tree.find("grandmother") == "pnina");
    CHECK((tree.find("great-grandmother") == "rachel" || tree.find("great-grandmother") == "ester"));
    CHECK(tree.find("me") == "reut");
    tree.remove("shraga");
    CHECK(tree.relation("shraga") == "unrelated");
    CHECK(tree.relation("shmuel") == "unrelated");
    CHECK(tree.relation("pnina") == "unrelated");
    CHECK(tree.relation("eliezer") == "unrelated");
    CHECK(tree.relation("ester") == "unrelated");
    CHECK(tree.relation("rachel") == "unrelated");
    tree.addFather("reut", "shalom");
    CHECK(tree.find("father") == "shalom");
}

TEST_CASE("Test tree 2 : check all the functions:")
{
    Tree tree("reut");
    tree.addFather("reut", "shraga");
    tree.addMother("reut", "haidi");
    tree.addFather("haidi", "yehuda");
    tree.addMother("haidi", "tzipi");
    tree.addFather("yehuda", "shimshon");
    tree.addMother("yehuda", "malca");
    tree.addMother("tzipi", "eva");

    CHECK(tree.relation("shraga").compare("father") == 0);
    CHECK(tree.relation("haidi").compare("mother") == 0);
    CHECK(tree.relation("yehuda").compare("grandfather") == 0);
    CHECK(tree.relation("tzipi").compare("grandmother") == 0);
    CHECK(tree.relation("malca").compare("great-grandmother") == 0);
    CHECK(tree.relation("eva").compare("great-grandmother") == 0);
    CHECK(tree.relation("shimshon").compare("great-grandfather") == 0);
    CHECK(tree.relation("reut").compare("me") == 0);
    CHECK(tree.find("father") == "shraga");
    CHECK(tree.find("mother") == "haidi");
    CHECK(tree.find("grandfather") == "yehuda");
    CHECK(tree.find("great-grandfather") == "shimshon");
    CHECK(tree.find("grandmother") == "tzipi");
    CHECK((tree.find("great-grandmother") == "eva" || tree.find("great-grandmother") == "malca"));
    CHECK(tree.find("me") == "reut");
    tree.remove("haidi");
    CHECK(tree.relation("haidi") == "unrelated");
    CHECK(tree.relation("yehuda") == "unrelated");
    CHECK(tree.relation("tzipi") == "unrelated");
    CHECK(tree.relation("shimshon") == "unrelated");
    CHECK(tree.relation("malca") == "unrelated");
    CHECK(tree.relation("eva") == "unrelated");
    tree.addMother("reut", "sara");
    CHECK(tree.find("mother") == "sara");
}
