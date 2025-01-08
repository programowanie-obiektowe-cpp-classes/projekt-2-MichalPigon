#include <iostream>
#include <bits/stdc++.h>
class frac{
public:
    frac(): licznik(0), mianownik(1){}
    frac(int x, int y): licznik(x), mianownik(y){uprosc();}
    void print()
    {
        std::cout<<licznik<<"/"<<mianownik<<std::endl;
    }
    void uprosc()
    {   
        if(licznik < 0 && mianownik < 0)
        {
            licznik = -licznik;
            mianownik = -mianownik;
        }
        if (licznik > 0 && mianownik < 0)
        {
            licznik = -licznik;
            mianownik = -mianownik;
        }
        int* zakres;
        if (licznik>mianownik){zakres = &mianownik;}
        else {zakres = &licznik;}
        for (int i = *zakres; i > 1; i--)
        {
            if(licznik % i == 0 && mianownik % i == 0)
            {
                licznik /= i;
                mianownik /= i;
            }
        }
    }
    void pomnoz(int a)
    {
        licznik *= a;
        mianownik *= a;
    }
    int getLicznik(){return licznik;}
    int getMianownik(){return mianownik;}
    void setLicznik(int x){licznik = x;}
    void setMianownik(int y){mianownik = y;}
private:
    int licznik, mianownik;
};
frac operator+(frac u1, frac u2)
{
    if(u1.getMianownik() != u2.getMianownik())
    {
        int NWW;
        NWW = std::lcm(u1.getMianownik(), u2.getMianownik());
        u1.pomnoz(NWW / u1.getMianownik());
        u2.pomnoz(NWW / u2.getMianownik());
        return frac(u1.getLicznik() + u2.getLicznik(), NWW);
    }
    else 
    {
        return frac(u1.getLicznik() + u2.getLicznik(), u1.getMianownik());
    }
    
}
frac operator+(int n, frac u)
{
    return frac(u.getMianownik() * n + u.getLicznik(), u.getMianownik());
}
frac operator+(frac u, int n)
{
    return frac(u.getMianownik() * n + u.getLicznik(), u.getMianownik());
}
frac operator-(frac u1, frac u2)
{
    if(u1.getMianownik() != u2.getMianownik())
    {
        int NWW;
        NWW = std::lcm(u1.getMianownik(), u2.getMianownik());
        u1.pomnoz(NWW / u1.getMianownik());
        u2.pomnoz(NWW / u2.getMianownik());
        return frac(u1.getLicznik() - u2.getLicznik(), NWW);
    }
    else 
    {
        return frac(u1.getLicznik() - u2.getLicznik(), u1.getMianownik());
    }
}
frac operator-(int n, frac u){
    return frac(u.getMianownik() * n - u.getLicznik(), u.getMianownik());
}
frac operator-(frac u, int n)
{
    return frac(u.getLicznik() - u.getMianownik() * n, u.getMianownik());
}
frac operator*(frac u1, frac u2)
{
    return frac(u1.getLicznik() * u2.getLicznik(), u1.getMianownik() * u2.getMianownik());
}
frac operator*(int n, frac u)
{   
    return frac(u.getLicznik() * n, u.getMianownik());
}
frac operator*(frac u, int n)
{
    return frac(u.getLicznik() * n, u.getMianownik());
}
frac operator/(frac u1, frac u2)
{
    return frac(u1.getLicznik() * u2.getMianownik(), u1.getMianownik() * u2.getLicznik());
}
void operator++(frac& u)
{
    u.setLicznik(u.getLicznik() + u.getMianownik());
    u.uprosc();
}
void operator--(frac& u)
{
    u.setLicznik(u.getLicznik() - u.getMianownik());
    u.uprosc();
}
frac operator%(frac u1, frac u2)
{
    int NWW;
    NWW = std::lcm(u1.getMianownik(), u2.getMianownik());
    u1.pomnoz(NWW / u1.getMianownik());
    u2.pomnoz(NWW / u2.getMianownik());
    return frac(u1.getLicznik() % u2.getLicznik(), u1.getMianownik());
}
bool operator==(frac u1, frac u2)
{
    return u1.getLicznik() * u2.getMianownik() == u2.getLicznik() * u1.getMianownik();
}
bool operator!=(frac u1, frac u2)
{
    return u1.getLicznik() * u2.getMianownik() != u2.getLicznik() * u1.getMianownik();
}
bool operator>(frac u1, frac u2)
{
    return u1.getLicznik() * u2.getMianownik() > u2.getLicznik() * u1.getMianownik();
}
bool operator>=(frac u1, frac u2)
{
    return u1.getLicznik() * u2.getMianownik() >= u2.getLicznik() * u1.getMianownik();
}
bool operator<(frac u1, frac u2)
{
    return u1.getLicznik() * u2.getMianownik() < u2.getLicznik() * u1.getMianownik();
}
bool operator<=(frac u1, frac u2)
{
    return u1.getLicznik() * u2.getMianownik() <= u2.getLicznik() * u1.getMianownik();
}
