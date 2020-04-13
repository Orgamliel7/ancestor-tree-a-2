#include "doctest.h"
#include "FamilyTree.hpp"
using namespace family;

#include <string>
using namespace std;

TEST_CASE("Test add methods.") {
    Tree t("Yosef");
    t.addFather("Yosef", "Yaakov");
    t.addFather("Yaakov", "Isaac");
    t.addFather("Isaac", "Avraham");
    t.addFather("Avraham", "Terah");

    SUBCASE("Test Demo Tree addFather method.") {
        CHECK(t.find("father") == "Yaakov");
        CHECK(t.find("grandfather") == "Isaac");
        CHECK(t.find("great-grandfather") == "Avraham");
        CHECK(t.find("great-great-grandfather") == "Terah");
    }

    t.addMother("Yosef", "Rachel");
    t.addMother("Yaakov", "Rivka");

    SUBCASE("Test Demo Tree addMother method.") {
        CHECK(t.find("mother") == "Rachel");
        CHECK(t.find("grandmother") == "Rivka");
    }

    Tree t2("Gabby");
    t2.addFather("Gabby", "Tad")
        .addMother("Gabby", "Adalia")
        .addFather("Tad", "Hank")
        .addMother("Tad", "Hanna")
        .addFather("Adalia", "Danny")
        .addMother("Adalia", "Kacy")
        .addFather("Hank", "Gabriel")
        .addMother("Hank", "Karing")
        .addFather("Hanna", "Eddy")
        .addMother("Hanna", "Kate")
        .addFather("Danny", "Eliot")
        .addMother("Danny", "Isabella")
        .addFather("Kacy", "Nikolai")
        .addMother("Kacy", "Kaira")
        .addFather("Gabriel", "Pablo")
        .addFather("Gabriel", "Gus")
        .addFather("Gabriel", "Lamar")
        .addFather("Gabriel", "Jacob");

    SUBCASE("Test 8 level's Tree.") {
        CHECK(t2.find("father") == "Tad");
        string ans = t2.find("grandfather");
        CHECK((ans == "Hank" || ans == "Danny"));
        ans = t2.find("great-grandfather");
        CHECK((ans == "Gabriel" || ans == "Eddy" || ans == "Eliot" || ans == "Nikolai"));
        ans = t2.find("great-great-grandfather");
        CHECK(ans == "Pablo");
        ans = t2.find("great-great-great-grandfather");
        CHECK(ans == "Gus");
        ans = t2.find("great-great-great-great-grandfather");
        CHECK(ans == "Lamar");
        ans = t2.find("great-great-great-great-great-grandfather");
        CHECK(ans == "Jacob");
    }

    Tree t3("Gabby");
    t3.addMother("Gabby", "Adalia")
        .addFather("Adalia", "Danny")
        .addMother("Danny", "Isabella")
        .addFather("Isabella", "Pablo")
        .addMother("Pablo", "Kate");

    SUBCASE("Test 'zigzag' Tree") {
        CHECK(t3.find("me") == "Gabby");
        CHECK(t3.find("mother") == "Adalia");
        CHECK(t3.find("grandfather") == "Danny");
        CHECK(t3.find("great-grandmother") == "Isabella");
        CHECK(t3.find("great-great-grandfather") == "Pablo");
        CHECK(t3.find("great-great-great-grandmother") == "Kate");
    }
}

TEST_CASE("Test relations.") {
    Tree t("Gabby");
    t.addFather("Gabby", "Tad")
        .addMother("Gabby", "Adalia")
        .addFather("Tad", "Hank")
        .addMother("Tad", "Hanna")
        .addFather("Adalia", "Danny")
        .addMother("Adalia", "Kacy")
        .addFather("Hank", "Gabriel")
        .addMother("Hank", "Karing")
        .addFather("Hanna", "Eddy")
        .addMother("Hanna", "Kate")
        .addFather("Danny", "Eliot")
        .addMother("Danny", "Isabella")
        .addFather("Kacy", "Nikolai")
        .addMother("Kacy", "Kaira")
        .addFather("Gabriel", "Pablo")
        .addFather("Gabriel", "Gus")
        .addFather("Gabriel", "Lamar")
        .addFather("Gabriel", "Jacob");
    CHECK(t.relation("Gabby") == "me");
    CHECK(t.relation("Tad") == "father");
    CHECK(t.relation("Adalia") == "mother");
    CHECK(t.relation("Hank") == "grandfather");
    CHECK(t.relation("Danny") == "grandfather");
    CHECK(t.relation("Hanna") == "grandmother");
    CHECK(t.relation("Kacy") == "grandmother");
    CHECK(t.relation("Gabriel") == "great-grandfather");
    CHECK(t.relation("Eddy") == "great-grandfather");
    CHECK(t.relation("Eliot") == "great-grandfather");
    CHECK(t.relation("Nikolai") == "great-grandfather");
    CHECK(t.relation("Karin") == "great-grandmother");
    CHECK(t.relation("Kate") == "great-grandmother");
    CHECK(t.relation("Isabela") == "great-grandmother");
    CHECK(t.relation("Kaira") == "great-grandmother");
    CHECK(t.relation("Pablo") == "great-great-grandfather");
    CHECK(t.relation("Gus") == "great-great-great-grandfather");
    CHECK(t.relation("Lamar") == "great-great-great-great-grandfather");
    CHECK(t.relation("Jacob") == "great-great-great-great-great-grandfather");

    Tree t2("Gabby");
    t2.addMother("Gabby", "Adalia")
        .addFather("Adalia", "Danny")
        .addMother("Danny", "Isabella")
        .addFather("Isabella", "Pablo")
        .addMother("Pablo", "Kate");
    CHECK(t2.relation("Gabby") == "me");
    CHECK(t2.relation("Adalia") == "mother");
    CHECK(t2.relation("Danny") == "grandfather");
    CHECK(t2.relation("Isabella") == "great-grandmother");
    CHECK(t2.relation("Pablo") == "great-great-grandfather");
    CHECK(t2.relation("Kate") == "great-great-great-grandmother");

    Tree t3("A");
    t3.addFather("A", "B")
        .addFather("B", "C")
        .addFather("C", "D")
        .addFather("D", "E")
        .addFather("E", "F")
        .addFather("F", "G")
        .addFather("G", "H")
        .addFather("H", "I")
        .addFather("I", "J")
        .addFather("J", "K")
        .addFather("K", "L")
        .addFather("L", "M")
        .addFather("M", "N");
    SUBCASE("Test very long relation of numberXgreat-grandfather") {
        CHECK(t3.relation("A") == "me");
        CHECK(t3.relation("B") == "father");
        CHECK(t3.relation("C") == "grandfather");
        CHECK(t3.relation("D") == "great-grandfather");
        CHECK(t3.relation("E") == "great-great-grandfather");
        CHECK(t3.relation("F") == "great-great-great-grandfather");
        CHECK(t3.relation("G") == "great-great-great-great-grandfather");
        CHECK(t3.relation("H") == "great-great-great-great-great-grandfather");
        CHECK(t3.relation("I") == "great-great-great-great-great-great-grandfather");
        CHECK(t3.relation("J") == "great-great-great-great-great-great-great-grandfather");
        CHECK(t3.relation("K") == "great-great-great-great-great-great-great-great-grandfather");
        CHECK(t3.relation("L") == "great-great-great-great-great-great-great-great-great-grandfather");
        CHECK(t3.relation("M") == "great-great-great-great-great-great-great-great-great-great-grandfather");
        CHECK(t3.relation("N") == "great-great-great-great-great-great-great-great-great-great-great-grandfather");
    }
}

TEST_CASE("Test catching exceptions.") {
    Tree t("Gabby");
    t.addFather("Gabby", "Tad")
        .addMother("Gabby", "Adalia")
        .addFather("Tad", "Hank")
        .addMother("Tad", "Hanna")
        .addFather("Adalia", "Danny")
        .addMother("Adalia", "Kacy")
        .addFather("Hank", "Gabriel")
        .addMother("Hank", "Karing")
        .addFather("Hanna", "Eddy")
        .addMother("Hanna", "Kate")
        .addFather("Danny", "Eliot")
        .addMother("Danny", "Isabella")
        .addFather("Kacy", "Nikolai")
        .addMother("Kacy", "Kaira")
        .addFather("Gabriel", "Pablo")
        .addFather("Gabriel", "Gus")
        .addFather("Gabriel", "Lamar")
        .addFather("Gabriel", "Jacob");
    SUBCASE("Test add father/mother when already have one.") {
        CHECK_THROWS(t.addFather("Hank", "Abcd"));
        CHECK_THROWS(t.addFather("Danny", "Abcd"));
        CHECK_THROWS(t.addMother("Kacy", "Zxcv"));
        CHECK_THROWS(t.addMother("Hanna", "Zxcv"));
        CHECK_THROWS(t.addMother("Danny", "Zxcv"));
        CHECK_THROWS(t.addMother("Hank", "Zxcv"));
        CHECK_THROWS(t.addFather("Gabriel", "Abcd"));
        CHECK_THROWS(t.addFather("Gus", "Abcd"));
        CHECK_THROWS(t.addFather("Lamar", "Abcd"));
        CHECK_THROWS(t.addMother("Gabby", "Zxcv"));
    }
    SUBCASE("Test remove father/mother that doesn't exist.") {
        CHECK_THROWS(t.remove("abcd"));
        CHECK_THROWS(t.remove("hank"));
    }
    SUBCASE("Test removing someone who's already removed.") {
        t.remove("Karin");
        CHECK_THROWS(t.remove("Karin"));
        t.remove("Gabriel");
        CHECK_THROWS(t.remove("Gabriel"));
        CHECK_THROWS(t.remove("Pablo"));
        CHECK_THROWS(t.remove("Gus"));
        CHECK_THROWS(t.remove("Lamar"));
        CHECK_THROWS(t.remove("Jacob"));
    }
    SUBCASE("Test remove root.") {
        CHECK_THROWS(t.remove("Gabby"));
    }
    SUBCASE("Test add father/mother to someone who doesn't exist.") {
        CHECK_THROWS(t.addFather("a", "Abcd"));
        CHECK_THROWS(t.addFather("", "Abcd"));
        CHECK_THROWS(t.addMother("avd", "Zxcv"));
        CHECK_THROWS(t.addMother("abcd", "Zxcv"));
        CHECK_THROWS(t.addMother("d", "Zxcv"));
        CHECK_THROWS(t.addMother("  Hank", "Zxcv"));
        CHECK_THROWS(t.addFather("Gabr iel", "Abcd"));
        CHECK_THROWS(t.addFather("Gu  s", "Abcd"));
        CHECK_THROWS(t.addFather("lamar", "Abcd"));
        CHECK_THROWS(t.addMother("Gapby", "Zxcv"));
    }
}

TEST_CASE("Test remove.") {
    Tree t("Gabby");
    t.addFather("Gabby", "Tad")
        .addMother("Gabby", "Adalia")
        .addFather("Tad", "Hank")
        .addMother("Tad", "Hanna")
        .addFather("Adalia", "Danny")
        .addMother("Adalia", "Kacy")
        .addFather("Hank", "Gabriel")
        .addMother("Hank", "Karing")
        .addFather("Hanna", "Eddy")
        .addMother("Hanna", "Kate")
        .addFather("Danny", "Eliot")
        .addMother("Danny", "Isabella")
        .addFather("Kacy", "Nikolai")
        .addMother("Kacy", "Kaira")
        .addFather("Gabriel", "Pablo")
        .addFather("Gabriel", "Gus")
        .addFather("Gabriel", "Lamar")
        .addFather("Gabriel", "Jacob");
    t.remove("Jacob");
    CHECK(t.relation("Jacob") == "unrelated");
    t.remove("Hanna");
    CHECK(t.relation("Eddy") == "unrelated");
    CHECK(t.relation("Kate") == "unrelated");
    t.remove("Adalia");
    CHECK(t.relation("Danny") == "unrelated");
    CHECK(t.relation("Kacy") == "unrelated");
    CHECK(t.relation("Eliot") == "unrelated");
    CHECK(t.relation("Isabella") == "unrelated");
    CHECK(t.relation("Nikolai") == "unrelated");
    CHECK(t.relation("Kaira") == "unrelated");
    CHECK(t.relation("Adalia") == "unrelated");
    t.remove("Tad");
    CHECK(t.relation("Tad") == "unrelated");
    CHECK(t.relation("Hank") == "unrelated");
    CHECK(t.relation("Gabriel") == "unrelated");
    CHECK(t.relation("Karin") == "unrelated");
    CHECK(t.relation("Pablo") == "unrelated");
    CHECK(t.relation("Gus") == "unrelated");
    CHECK(t.relation("Lamar") == "unrelated");

    Tree t2("Gabby");
    t2.addMother("Gabby", "Adalia")
        .addFather("Adalia", "Danny")
        .addMother("Danny", "Isabella")
        .addFather("Isabella", "Pablo")
        .addMother("Pablo", "Kate");

    SUBCASE("Remove backorder.") {
        t2.remove("Kate");
        CHECK(t2.relation("Kate") == "unrelated");
        t2.remove("Pablo");
        CHECK(t2.relation("Pablo") == "unrelated");
        t2.remove("Isabella");
        CHECK(t2.relation("Isabella") == "unrelated");
        t2.remove("Danny");
        CHECK(t2.relation("Danny") == "unrelated");
        t2.remove("Adalia");
        CHECK(t2.relation("Adalia") == "unrelated");
    }
}