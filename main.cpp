#include "creating.h"
int main()
{
  cout<< "Iveskite kiek studentu sugeneruoti: ";
  int duomenu_sk;
  cin >> duomenu_sk;
  cout << duomenu_sk << " elementu uzpildymas: "<<endl;
  cout <<"_________________________________________________"<<endl;
  string name = "studentai.txt";
  generavimas(duomenu_sk, name);
  cout <<"Laiko matavimas, kai naudojamas vektorius: "<<endl;
  double vect (string name);
  vect (name);
  cout <<"_________________________________________________"<<endl;
  cout<<"Laiko matavimas, kai naudojamas sarasas: "<<endl;
  double listai (string name);
  listai (name);
  return 0;
}
