#define CATCH_CONFIG_MAIN
#include "catch_amalgamated.hpp"
#include "frac.hpp"

TEST_CASE("Dodawanie ulamkow") {
    SECTION("Ten sam mianownik"){
        frac u1(1, 6);
        frac u2(5, 6);
        frac result = u1 + u2;
        REQUIRE(result.getLicznik() ==1);
        REQUIRE(result.getMianownik() == 1);
    }
    SECTION("Różne mianowniki"){
        frac u1(1, 3);
        frac u2(1, 2);
        frac result = u1 + u2;
        REQUIRE(result.getLicznik() == 5);
        REQUIRE(result.getMianownik() == 6);
        
    }
    SECTION("Liczby ujemne"){
        frac u1(-3, 4);
        frac u2(-1, -8);
        frac result = u1 + u2;
        REQUIRE(result.getLicznik() == -5);
        REQUIRE(result.getMianownik() == 8);
    }
    SECTION("Liczba całkowita i ułamek"){
        frac u1(1, 2);
        int n = 2;
        frac result = n + u1;
        REQUIRE(result.getLicznik() == 5);
        REQUIRE(result.getMianownik() == 2);
    }

}
TEST_CASE("Mnozenie i dzielenie ulamkow"){
    SECTION("Mnozenie przez liczbę całkowitą")
    {
        frac u(1, 3);
        int n = 4;
        frac result = u * n;
        REQUIRE(result.getLicznik() == 4);
        REQUIRE(result.getMianownik() == 3);
    }
    SECTION("Liczby dodatnie"){
        frac u1(3, 7);
        frac u2(2, 3);
        frac result1 = u1 * u2;
        frac result2 = u1 / u2;
        REQUIRE(result1.getLicznik() == 2);
        REQUIRE(result1.getMianownik() == 7);
        REQUIRE(result2.getLicznik() == 9);
        REQUIRE(result2.getMianownik() == 14);
    }
    SECTION("Liczby ujemne"){
        frac u1(-5, 6);
        frac u2(-1 ,7);
        frac u3(1, 7);
        frac result1 = u1 * u2;
        frac result2 = u1 / u2;
        frac result3 = u1 * u3;
        frac result4 = u1 / u3;
        REQUIRE(result1.getLicznik() == 5);
        REQUIRE(result1.getMianownik() == 42);
        REQUIRE(result2.getLicznik() == 35);
        REQUIRE(result2.getMianownik() == 6);
        REQUIRE(result3.getLicznik() == -5);
        REQUIRE(result3.getMianownik() == 42);
        REQUIRE(result4.getLicznik() == -35);
        REQUIRE(result4.getMianownik() == 6);
    }
}
TEST_CASE("Reszta z dzielenia"){
    SECTION("Dodatnie"){
        frac u1(3, 5);
        frac u2(1, 7);
        frac result = u1 % u2;
        REQUIRE(result.getLicznik() == 1);
        REQUIRE(result.getMianownik() == 35);
    }
    SECTION("Ujemne"){
        frac u1(3, 5);
        frac u2(-1, 7);
        frac result = u1 % u2;
        REQUIRE(result.getLicznik() == 1);
        REQUIRE(result.getMianownik() == 35);
    }
}
TEST_CASE("Odejmowanie ulamkow"){
    SECTION("Ten sam mianownik"){
        frac u1(1, 6);
        frac u2(-5, 6);
        frac result = u1 - u2;
        REQUIRE(result.getLicznik() == 1);
        REQUIRE(result.getMianownik() == 1);
    }
    SECTION("Różne mianowniki"){
        frac u1(1, 3);
        frac u2(1, 2);
        frac result = u1 - u2;
        REQUIRE(result.getLicznik() == -1);
        REQUIRE(result.getMianownik() == 6);
        
    }
    SECTION("Liczby ujemne"){
        frac u1(-3, 4);
        frac u2(-1, -8);
        frac result = u1 - u2;
        REQUIRE(result.getLicznik() == -7);
        REQUIRE(result.getMianownik() == 8);
    }
    SECTION("Liczba całkowita i ułamek"){
        frac u(1,2);
        int n = 2;
        frac result = u - n;
        REQUIRE(result.getLicznik() == -3);
        REQUIRE(result.getMianownik() == 2);
    }
}
TEST_CASE("Porównania"){
    SECTION("Równe lub nierówne"){
        frac u1(1,2);
        frac u2(2,4);
        frac u3(3,4);
        bool result1 = u1 == u2;
        bool result2 = u1 == u3;
        bool result3 = u1 != u2;
        bool result4 = u1 != u3;
        REQUIRE(result1 == true);
        REQUIRE(result2 == false);
        REQUIRE(result3 == false);
        REQUIRE(result4 == true);
        
    }
    SECTION("Większy lub mniejszy"){
        frac u1(1, 2);
        frac u2(-1, 2);
        frac u3(2, 4);
        frac u4(-2, 4);
        bool result1 = u1 > u2;
        bool result2 = u1 >= u3;
        bool result3 = u1 < u2;
        bool result4 = u2 <= u4;
        REQUIRE(result1 == true);
        REQUIRE(result2 == true);
        REQUIRE(result3 == false);
        REQUIRE(result4 == true);
        
    }
}
