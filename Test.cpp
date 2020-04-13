#include "doctest.h"
#include "FamilyTree.hpp"
using namespace family;

#include <string>
using namespace std;



TEST_CASE("correlation Test") 
{
    Tree Arborvitae("James");
    Arborvitae.addFather("James", "John")
        .addMother("James", "Mary")
        .addFather("John", "Robert")
        .addMother("John", "Patricia")
        .addFather("Mary", "Michael")
        .addMother("Mary", "Jennifer")
        .addFather("Robert", "William")
        .addMother("Robert", "Linda")
        .addFather("Patricia", "David")
        .addMother("Patricia", "Elizabeth")
        .addFather("Michael", "Richard")
        .addMother("Michael", "Barbara")
        .addFather("Jennifer", "Joseph")
        .addMother("Jennifer", "Susan")
        .addFather("William", "Thomas")
        .addFather("William", "Charles")
        .addFather("Gabriel", "Christopher")
    CHECK(Arborvitae.relation("James") == "me");
    CHECK(Arborvitae.relation("John") == "father");
    CHECK(Arborvitae.relation("Mary") == "mother");
    CHECK(Arborvitae.relation("Robert") == "grandfather");
    CHECK(Arborvitae.relation("Michael") == "grandfather");
    CHECK(Arborvitae.relation("Patricia") == "grandmother");
    CHECK(Arborvitae.relation("Jennifer") == "grandmother");
    CHECK(Arborvitae.relation("William   ") == "great-grandfather");
    CHECK(Arborvitae.relation("David") == "great-grandfather");
    CHECK(Arborvitae.relation("Richard") == "great-grandfather");
    CHECK(Arborvitae.relation("Joseph") == "great-grandfather");
    CHECK(Arborvitae.relation("Simona") == "great-grandmother");
    CHECK(Arborvitae.relation("Elizabeth") == "great-grandmother");
    CHECK(Arborvitae.relation("Barbara") == "great-grandmother");
    CHECK(Arborvitae.relation("Susan") == "great-grandmother");
    CHECK(Arborvitae.relation("Thomas") == "great-great-grandfather");
    CHECK(Arborvitae.relation("Charles") == "great-great-great-grandfather");
    CHECK(Arborvitae.relation("Christopher") == "great-great-great-great-grandfather");
  

    Tree Black Ash("Daniel");
    Black Ash.addMother("Daniel", "Lisa")
        .addFather("Lisa", "Matthew")
        .addMother("Matthew", "Dorothy")
        .addFather("Dorothy", "Anthony")
        .addMother("Anthony", "Sandra");
    CHECK(Black Ash.relation("Daniel") == "me");
    CHECK(Black Ash.relation("Lisa") == "mother");
    CHECK(Black Ash.relation("Matthew") == "grandfather");
    CHECK(Black Ash.relation("Dorothy") == "great-grandmother");
    CHECK(Black Ash.relation("Anthony") == "great-great-grandfather");
    CHECK(Black Ash.relation("Sandra") == "great-great-great-grandmother");

    Tree Basswood("Kenneth");
    Basswood.addFather("Kenneth", "Joshua")
        .addFather("Joshua", "George")
        .addFather("George", "Kevin")
        .addFather("Kevin", "Brian")
        .addFather("Brian", "Edward")
        .addFather("Edward", "Ronald")
        .addFather("Ronald", "Timothy")
        .addFather("Timothy", "Jason")
        .addFather("Jason", "Jeffrey")
        .addFather("Jeffrey", "Ryan")
        .addFather("Ryan", "Jacob")
        .addFather("Jacob", "Gary")
        .addFather("Gary", "Nicholas");

    SUBCASE("relation Test") 
    {
        CHECK(Basswood.relation("Kenneth") == "me");
        CHECK(Basswood.relation("Joshua") == "father");
        CHECK(Basswood.relation("George") == "grandfather");
        CHECK(Basswood.relation("Kevin") == "great-grandfather");
        CHECK(Basswood.relation("Brian") == "great-great-grandfather");
        CHECK(Basswood.relation("Edward") == "great-great-great-grandfather");
        CHECK(Basswood.relation("Ronald") == "great-great-great-great-grandfather");
        CHECK(Basswood.relation("Timothy") == "great-great-great-great-great-grandfather");
        CHECK(Basswood.relation("Jason") == "great-great-great-great-great-great-grandfather");
        CHECK(Basswood.relation("Jeffrey") == "great-great-great-great-great-great-great-grandfather");
        CHECK(Basswood.relation("Ryan") == "great-great-great-great-great-great-great-great-grandfather");
        CHECK(Basswood.relation("Jacob") == "great-great-great-great-great-great-great-great-great-grandfather");
        CHECK(Basswood.relation("Gary") == "great-great-great-great-great-great-great-great-great-great-grandfather");
        CHECK(Basswood.relation("Nicholas") == "great-great-great-great-great-great-great-great-great-great-great-grandfather");
    }
}


TEST_CASE("irregularity behavior Test") // execptions throwing
{
    Tree Cherry("Wayne");
    Cherry.addFather("Wayne", "Eugene")
        .addMother("Wayne", "Beverly")
        .addFather("Eugene", "Logan")
        .addMother("Eugene", "Denise")
        .addFather("Beverly", "Russell")
        .addMother("Beverly", "Marilyn")
        .addFather("Logan", "Vincent")
        .addMother("Logan", "Amber")
        .addFather("Denise", "Philip")
        .addMother("Denise", "Danielle")
        .addFather("Russell", "Bobby")
        .addMother("Russell", "Rose")
        .addFather("Marilyn", "Johnny")
        .addMother("Marilyn", "Diana")
        .addFather("Vincent", "Bradley")
        .addFather("Vincent", "Ramy")
        .addFather("Vincent", "Meo")
        .addFather("Vincent", "Yarim");
   
    SUBCASE("addFather&addMother functions Test") 
    {
        CHECK_THROWS(Cherry.addFather("Logan", "Abdul"));
        CHECK_THROWS(Cherry.addFather("Russell", "Abdul"));
        CHECK_THROWS(Cherry.addMother("Marilyn", "Habib"));
        CHECK_THROWS(Cherry.addMother("Denise", "Habib"));
        CHECK_THROWS(Cherry.addMother("Russell", "Habib"));
        CHECK_THROWS(Cherry.addMother("Logan", "Habib"));
        CHECK_THROWS(Cherry.addFather("Vincent", "Abdul"));
        CHECK_THROWS(Cherry.addFather("Ramy", "Abdul"));
        CHECK_THROWS(Cherry.addFather("Meo", "Abdul"));
        CHECK_THROWS(Cherry.addMother("Wayne", "Habib"));
    }

    SUBCASE("remove root node test")
    {
        CHECK_THROWS(Cherry.remove("Wayne"));
    }
    SUBCASE("remove phantom names Test")
    {
        CHECK_THROWS(Cherry.remove("Abdulon"));
        CHECK_THROWS(Cherry.remove("meo"));
    }
    SUBCASE("remove removed names Test") 
    {
        Cherry.remove("Simona");
        CHECK_THROWS(Cherry.remove("Simona"));
        Cherry.remove("Vincent");
        CHECK_THROWS(Cherry.remove("Vincent"));
        CHECK_THROWS(Cherry.remove("Bradley"));
        CHECK_THROWS(Cherry.remove("Ramy"));
        CHECK_THROWS(Cherry.remove("Meo"));
        CHECK_THROWS(Cherry.remove("Yarim"));
    }
  
    SUBCASE("addFather&addMother for phantom names Test")
    {
        CHECK_THROWS(Cherry.addFather("Baboon", "Abdul"));
        CHECK_THROWS(Cherry.addMother("Camel", "Habib"));
        CHECK_THROWS(Cherry.addMother("Abdulon", "Habib"));
        CHECK_THROWS(Cherry.addMother("Cat", "Habib"));
        CHECK_THROWS(Cherry.addMother("  Logan", "Habib"));
        CHECK_THROWS(Cherry.addFather("Vinc ent", "Abdul"));
        CHECK_THROWS(Cherry.addFather("Chicken", "Abdul"));
        CHECK_THROWS(Cherry.addFather("Cobra", "Abdul"));
        CHECK_THROWS(Cherry.addMother("Dog", "Habib"));
        CHECK_THROWS(Cherry.addMother("   ", "Abdul"));
    }
}

TEST_CASE("remove nodes Test") 
{
    Tree Oak("Wayne");
    Oak.addFather("Wayne", "Eugene")
        .addMother("Wayne", "Beverly")
        .addFather("Eugene", "Logan")
        .addMother("Eugene", "Denise")
        .addFather("Beverly", "Russell")
        .addMother("Beverly", "Marilyn")
        .addFather("Logan", "Vincent")
        .addMother("Logan", "Amber")
        .addFather("Denise", "Philip")
        .addMother("Denise", "Danielle")
        .addFather("Russell", "Bobby")
        .addMother("Russell", "Rose")
        .addFather("Marilyn", "Johnny")
        .addMother("Marilyn", "Diana")
        .addFather("Vincent", "Bradley")
        .addFather("Vincent", "Ramy")
        .addFather("Vincent", "Meo")
        .addFather("Vincent", "Yarim");
    Oak.remove("Yarim");
    CHECK(Oak.relation("Yarim") == "unrelated");
    Oak.remove("Denise");
    CHECK(Oak.relation("Philip") == "unrelated");
    CHECK(Oak.relation("Danielle") == "unrelated");
    Oak.remove("Beverly");
    CHECK(Oak.relation("Russell") == "unrelated");
    CHECK(Oak.relation("Marilyn") == "unrelated");
    CHECK(Oak.relation("Bobby") == "unrelated");
    CHECK(Oak.relation("Rose") == "unrelated");
    CHECK(Oak.relation("Johnny") == "unrelated");
    CHECK(Oak.relation("Diana") == "unrelated");
    CHECK(Oak.relation("Beverly") == "unrelated");
    Oak.remove("Eugene");
    CHECK(Oak.relation("Eugene") == "unrelated");
    CHECK(Oak.relation("Logan") == "unrelated");
    CHECK(Oak.relation("Vincent") == "unrelated");
    CHECK(Oak.relation("Simona") == "unrelated");
    CHECK(Oak.relation("Bradley") == "unrelated");
    CHECK(Oak.relation("Ramy") == "unrelated");
    CHECK(Oak.relation("Meo") == "unrelated");

    Tree Butternut("Wayne");
    Butternut.addMother("Wayne", "Beverly")
        .addFather("Beverly", "Russell")
        .addMother("Russell", "Rose")
        .addFather("Rose", "Bradley")
        .addMother("Bradley", "Danielle");

    SUBCASE("Remove Test") 
    {
        Butternut.remove("Danielle");
        CHECK(Butternut.relation("Danielle") == "unrelated");
        Butternut.remove("Bradley");
        CHECK(Butternut.relation("Bradley") == "unrelated");
        Butternut.remove("Rose");
        CHECK(Butternut.relation("Rose") == "unrelated");
        Butternut.remove("Russell");
        CHECK(Butternut.relation("Russell") == "unrelated");
        Butternut.remove("Beverly");
        CHECK(Butternut.relation("Beverly") == "unrelated");
    }
}

TEST_CASE("addFather function Test")
{
    Tree Apple("drake");
    Apple.addFather("drake", "Maxim");
    Apple.addFather("drake", "guliver");
    Apple.addFather("guliver", "Sami");
    Apple.addFather("Sami", "roni");

    SUBCASE("addFather Test")
    {
        CHECK(Apple.find("father") == "drake");
        CHECK(Apple.find("grandfather") == "guliver");
        CHECK(Apple.find("great-grandfather") == "Sami");
        CHECK(Apple.find("great-great-grandfather") == "roni");
    }

    Apple.addMother("drake", "Noa");
    Apple.addMother("drake", "Lily");

    SUBCASE("addMother Test") 
    {
        CHECK(Apple.find("mother") == "Noa");
        CHECK(Apple.find("grandmother") == "Lily");
    }

    Tree Banana("Wayne");
    Banana.addFather("Wayne", "Eugene")
        .addMother("Wayne", "Beverly")
        .addFather("Eugene", "Logan")
        .addMother("Eugene", "Denise")
        .addFather("Beverly", "Russell")
        .addMother("Beverly", "Marilyn")
        .addFather("Logan", "Vincent")
        .addMother("Logan", "Amber")
        .addFather("Denise", "Philip")
        .addMother("Denise", "Danielle")
        .addFather("Russell", "Bobby")
        .addMother("Russell", "Rose")
        .addFather("Marilyn", "Johnny")
        .addMother("Marilyn", "Diana")
        .addFather("Vincent", "Bradley")
        .addFather("Vincent", "Ramy")
        .addFather("Vincent", "Meo")
        .addFather("Vincent", "Yarim");

    SUBCASE("big family tree Test") 
    {
        CHECK(Banana.find("father") == "Eugene");
        string excpected = Banana.find("grandfather");
        CHECK((excpected == "Logan" || excpected == "Russell"));
        excpected = Banana.find("great-grandfather");
        CHECK((excpected == "Vincent" || excpected == "Philip" || excpected == "Bobby" || excpected == "Johnny"));
        excpected = Banana.find("great-great-grandfather");
        CHECK(excpected == "Bradley");
        excpected = Banana.find("great-great-great-grandfather");
        CHECK(excpected == "Ramy");
        excpected = Banana.find("great-great-great-great-grandfather");
        CHECK(excpected == "Meo");
        excpected = Banana.find("great-great-great-great-great-grandfather");
        CHECK(excpected == "Yarim");
    }

    Tree Mango("Wayne");
    Mango.addMother("Wayne", "Beverly")
        .addFather("Beverly", "Russell")
        .addMother("Russell", "Rose")
        .addFather("Rose", "Bradley")
        .addMother("Bradley", "Danielle");

    SUBCASE("complex family tree Test") 
    {
        CHECK(Mango.find("me") == "Wayne");
        CHECK(Mango.find("mother") == "Beverly");
        CHECK(Mango.find("grandfather") == "Russell");
        CHECK(Mango.find("great-grandmother") == "Rose");
        CHECK(Mango.find("great-great-grandfather") == "Bradley");
        CHECK(Mango.find("great-great-great-grandmother") == "Danielle");
    }
}