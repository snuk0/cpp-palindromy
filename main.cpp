#include <iostream>
#include <bits/stdc++.h>
#include <stdlib.h>

using namespace std;

class program {
    ofstream plik2;
    fstream plik;
    public:
    bool czy_palindrom(string a) {
        for(int i = 0, j = a.size()-1; i < j; i++, j--)
            if(a[i] != a[j])
                return false;
        return true;
    }
    void usun(string& tekst)
    {
        for(int i = 0; i < tekst.size(); i++)
        {
            if(tekst[i] == ' ')
            {
                tekst.erase(tekst.begin()+i);
                i--;
            }
        }
    }
    void wczytaj() {
        plik.open("a.txt", ios::in);
        plik2.open("b.html");
        if(plik.good()) {

            vector <string> linia;
            while(!plik.eof()) {
                string tekst;
                getline(plik, tekst);
                if(tekst.empty())
                    continue;
                linia.push_back(tekst);
            }
            plik2 <<
                     "<html>"
                     "<head>"
                     "<title>Palindromy</title>"
                     "</head>"
                     "<body>"
                     "[ \n";

            for(int i = 0; i < linia.size(); i++)
            {
                string tekst = linia[i];
                string zm = tekst;
                usun(tekst);
                string wynik = ((czy_palindrom(tekst)) ? "TAK" : "NIE");
                cout << wynik << "\n";
                char x = '#'-1;
                plik2 <<
                         " { \n" << "   " << x << "string" << x << ":" << x << zm << x << "\n"
                         "   " << x << "palindrom" << x << ":" << x << wynik << x << "\n }";
                if(i != linia.size()-1)
                    plik2 << ",";
                plik2 << "\n";

            }
            plik2 << "] \n"
                     "</body>"
                     "</html>";
        }
        plik2.close();
        plik.close();
    }
};

int main()
{
    program z;
    z.wczytaj();
    return 0;
}
