#include "laikas.h"
#include "creating.h"

double vect (string name){
Timer t;
std::ifstream read;
  read.open(name);
  do{
    try{
    if (!read.is_open()){
        throw std::runtime_error("Tokio failo nera projekto deriktorijoje \n");
    }
    }
     catch (const std::runtime_error& e) {
      std::cout << e.what();
      cout<<"Iveskite reikiamo failo pavadinima: ";
      cin>>name;
      read.open(name);}
  }while (!read.is_open()== true);
  int eilutes;
  eilutes = eilute(name)-1;
    srand(time(NULL));
    vector<duomuo> Eil_vect;
    string vardas, pavarde;
    int integer;
    int pazym;
    read>>vardas>>pavarde;
    int kiek=0;
    while(vardas!="EGZ")
    {
      read>>vardas;
      kiek++;
    }
    kiek-=1;

    for(int i=0;i<eilutes;i++)
    {
        Eil_vect.push_back(duomuo());
        auto it = std::next(Eil_vect.begin(), i);
        read>>vardas;
        read>>pavarde;
        it->Vard = vardas;
        it->Pav = pavarde;
        for(int j=0;j<(kiek);j++)
        {
          read>>pazym;
          if (pazym >=1 && pazym <=10){
          it->paz.push_back(pazym);
          it->GP+=it->paz[j];
          it->mediana.push_back(pazym);
          }
          else {
            printf("Faile yra netinkamo formato pazymys");
            return 0;}
        }
          read>>integer;
          if (integer >=1 && integer <=10){
          it->egz=integer;
          it->mediana.push_back(integer);
          }
          else {
            printf("Faile yra netinkamo formato pazymys");
            return 0;}
    }
    double pabaiga2 = t.elapsed();
    std::cout << "Duomenu nuskaitymas is failo ir ikelimas i vektioriu uztruko: " << pabaiga2 << " s\n";
      for(int i=0;i<eilutes;i++){
        auto it2 = std::next(Eil_vect.begin(), i);
        if (it2->GP != 0){
          it2->GP = it2->GP / (kiek)/1.0;}
          it2->GP = it2->GP * 0.4 + 0.6 * it2->egz;
          //medianai skaiciuot
          std::sort(it2->mediana.begin(), it2->mediana.end());
          if ((kiek+1) % 2 != 0)
          it2->medianai = it2->mediana[(kiek) / 2];
          else it2->medianai = (it2->mediana[(kiek+1) / 2] + it2->mediana[ (kiek+1) / 2 - 1]) / 2.0;
    }

    std::sort(Eil_vect.begin(), Eil_vect.end(), palyginimas);
    t.reset();
    std :: ofstream F;
    F.open("kietiakiaiV.txt", std::ios::out);
    F<< std::left << std::setw(15)<<"Vardas"
       <<  std::left << std::setw(15)<< "Pavarde";
        for (int k = 1; k<(kiek+1); k++){
          F<< "ND" <<std::left << std::setw(3)<< k;}
        F << "EGZ" << std::endl;
    for (int st= 0; st<eilutes; st++){
      auto it3 = std::next(Eil_vect.begin(), st);
      if (it3->GP >= 5){
        F <<std::left << std::setw(15)<< it3->Vard
        <<std::left << std::setw(15)<<it3->Pav;
        for (int k = 0; k<(kiek); k++){
          F<< std::left<<std::setw(5)<<it3->paz[k];}
        F << it3->egz << std::endl;}
    }
    double pabaiga3 = t.elapsed();
    std::cout << "Kietiaku atskirimas nuo visu studentu ir kartu surasymas i faila uztruko: " << pabaiga3 << " s\n";
    t.reset();
    std:: ofstream G;
    G.open("vargsiukaiV.txt", std::ios::out);
    G<< std::left << std::setw(15)<<"Vardas"
       <<  std::left << std::setw(15)<< "Pavarde";
        for (int k = 1; k<(kiek+1); k++){
          G<< "ND" <<std::left << std::setw(3)<< k;}
        G << "EGZ" << std::endl;

      for (int st= 0; st<eilutes; st++){
      auto it3 = std::next(Eil_vect.begin(), st);
      if (it3->GP < 5){
        G <<std::left << std::setw(15)<< it3->Vard
        <<std::left << std::setw(15)<<it3->Pav;
        for (int k = 0; k<(kiek); k++){
          G<< std::left<<std::setw(5)<<it3->paz[k];}
        G << it3->egz << std::endl;}
    }
    double pabaiga4 = t.elapsed();
    std::cout << "Vargsiuku atskirimas nuo visu studentu ir kartu surasymas i faila uztruko: " << pabaiga4 << " s\n";
      Eil_vect.clear();
    read.close();
    F.close();
    G.close();
    double laikas = pabaiga2 + pabaiga3 + pabaiga4;
    return laikas;
}
