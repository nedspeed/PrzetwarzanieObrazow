#include "funkcje.h"

/* funkcja main */

int main() {                    // zmienne uzyte w funkcji glownej to //
  int obraz[MAX][MAX];          // tablica obrazu //
  int wymx,wymy,odcieni;        // wymiar pionowy i poziomy oraz skala szarosci //
  int prog;                     // wartosc progu //
  int n;                        // zmienna potrzebna do wykonania funkcji switch //
  int s;                        // zmienna uzyta do funkcji zapisu obrazu na polecenie uzytkownika //
  int odczytano = 0;            // zmienna uzyta jako wartosc zwracana na koncu funkcji main //
  FILE *plik;                   // plik wgrywany przez uzytkownika //
  FILE *pliczek;                // plik potrzebny do wyswietlenia obrazu wejsciowego po operacji //
  char nazwa[100];              // zmienna znakowa uzyta do zapisu obrazu pod nazwa podana przez uzytkownika //

  /* Wczytanie zawartosci wskazanego pliku do pamieci */
  printf("Podaj nazwe pliku:\n");
  scanf("%s",nazwa);
   do{                      // polecenie do-while umozliwia wykonanie kilku operacji na obrazie podczas 1 cyklu dzialania programu //
  plik=fopen(nazwa,"r");
  if (plik != NULL) {       /* wczytanie zawartosci pliku spowoduje zakomentowanie tego warunku */
    odczytano = czytaj(plik,obraz,&wymx,&wymy,&odcieni);
    fclose(plik);}
    else{
    printf("\nplik niewlasciwy\n");
    return 0;}
  /* menu funkcji */
    pliczek=fopen("tmp.pgm", "w");      // otwarcie pliku tymczasowego uzytego do wyswietlenia obrazu po operacji //
      printf("\n Witaj w menu wyboru operacji, ktora ma byc wykonana na wczytanym obrazie.\n");
      printf("Wybierz jedna z ponizszych cyfr, aby wykonac przypisana jej operacje\n");
      printf(" 1 - negatyw\n 2 - progowanie\n 3 - konturowanie\n 4 - rozciaganie histogramu\n 5 - rozmycie poziome\n 6 - wyjscie\n");
        scanf("%d", &n);      // odczytanie wskazanej wartosci //
        if (n < 1 || n > 6){  //sprawdzenie prawidlowosci danej wejsciowej//
        printf("\nNie wybrano zadnej opcji. Program konczy dzialanie.\n");
        return 0;}
      /* funkcja wyboru scenariusza po wskazaniu wartosci przez uzytkownika */
        switch(n){
          /* przypadek 1. tworzenie negatywu*/
          case 1: negatyw(obraz, wymx, wymy, odcieni);      // wywolanie funkcji negatyw //
                   zapisz(pliczek, obraz, wymx, wymy, odcieni); // wyswietlenie obrazu //
                   wyswietl("tmp.pgm"); 
                   fclose(pliczek);   
                    printf(" \n Czy chcesz zapisac obraz?\n Jesli tak, wybierz 1\n Jesli nie, wybierz 2 \n"); // czy zapisac obraz? //
                     scanf("%d", &s);                    
                     if(s != 1 && s != 2){      // sprawdzenie czy uzytkownik wybral jedna z opcji //
                       printf("\nNie podano zadnej z opcji. Obraz nie zostaje zapisany.\n");      // jesli nie, to... //
                       n = 0;
                       s = 0;
                       return 0;} 
                     
                      if(s == 1){                                       // jesli tak to //
                      printf("Zapisz jako - podaj nazwe pliku:\n");     // podaj nazwe //
                       scanf("%s",nazwa);                               // odczytanie napisu //
                       plik=fopen(nazwa, "w");                          // otwarcie pliku pod nazwa //
                       zapisz(plik, obraz, wymx, wymy, odcieni);        // zapis pliku //
                       n=0;
                       s=0;
                       }
                       if(s==2)                                         // jesli nie to //
                       n=0;
                       s=0;
                        break;                                          // sprawdz warunek while i wroc do poczatku instrukcji do //
          /* przypadek 2. progowanie */
          case 2: printf("podaj prog(sama liczba procentow bez znaku procent):\n");
                   scanf("%d",&prog);                                   // odczytanie wartosci progu //
                    progowanie(obraz,wymx,wymy,odcieni,prog);           // wywolanie funkcji progowania //
                     zapisz(pliczek, obraz, wymx, wymy, odcieni);
                      wyswietl("tmp.pgm");
                      fclose(pliczek);
                    printf("\nCzy chcesz zapisac obraz?\n Jesli tak, wybierz 1\n Jesli nie, wybierz 2\n");
                     scanf("%d", &s);
                     if(s != 1 && s != 2){
                       printf("\nNie podano zadnej z opcji. Obraz nie zostaje zapisany.\n");
                       n = 0;
                       s = 0;
                       return 0;
                       }
                      if(s == 1){
                      printf("Zapisz jako - podaj nazwe pliku:\n");
                       scanf("%s",nazwa);
                       plik=fopen(nazwa, "w");
                       zapisz(plik, obraz, wymx, wymy, odcieni);
                       n = 0;
                       break;
                       }
                       if(s==2)
                       n = 0;
                        break;
          /* przypadek 3. konturowanie */
          case 3: konturowanie(obraz, wymx, wymy, odcieni);             // wywolanie funkcji konturowania //
                   zapisz(pliczek, obraz, wymx, wymy, odcieni);
                    wyswietl("tmp.pgm");
                    fclose(pliczek);
                    printf("\nCzy chcesz zapisac obraz?\n Jesli tak, wybierz 1\n Jesli nie, wybierz 2\n");
                     scanf("%d", &s);
                     if(s != 1 && s != 2){
                       printf("\nNie podano zadnej z opcji. Obraz nie zostaje zapisany.\n");
                       n = 0;
                       s = 0;
                       return 0;
                       }
                      if(s == 1){
                      printf("Zapisz jako - podaj nazwe pliku:\n");
                       scanf("%s",nazwa);
                       plik=fopen(nazwa, "w");
                       zapisz(plik, obraz, wymx, wymy, odcieni);
                       n = 0;
                       break;
                       }
                       if(s==2)
                       n = 0;
                        break; 
          /* przypadek 4. rozciaganie histogramu */
          case 4: histogram(obraz, wymx, wymy, odcieni);                // wywolanie funkcji rozciagania histogramu //
                   zapisz(pliczek, obraz, wymx, wymy, odcieni);
                    wyswietl("tmp.pgm");
                    fclose(pliczek);
                    printf("\nCzy chcesz zapisac obraz?\n Jesli tak, wybierz 1\n Jesli nie, wybierz 2\n");
                     scanf("%d", &s);
                     if(s != 1 && s != 2){
                       printf("\nNie podano zadnej z opcji. Obraz nie zostaje zapisany.\n");
                       n = 0;
                       s = 0;
                       return 0;
                       }
                      if(s == 1){
                      printf("Zapisz jako - podaj nazwe pliku:\n");
                       scanf("%s",nazwa);
                       plik=fopen(nazwa, "w");
                       zapisz(plik, obraz, wymx, wymy, odcieni);
                       n = 0;
                       break;
                       }
                       if(s==2)
                       n = 0;
                        break;
          /* przypadek 5. rozmycie */
          case 5: rozmycie(obraz, wymx, wymy, odcieni);                 // wywolanie funkcji rozmycia poziomego //
                   zapisz(pliczek, obraz, wymx, wymy, odcieni);
                    wyswietl("tmp.pgm");
                    fclose(pliczek);
                    printf("\nCzy chcesz zapisac obraz?\n Jesli tak, wybierz 1\n Jesli nie, wybierz 2\n");
                     scanf("%d", &s);
                     if(s != 1 && s != 2){
                       printf("\nNie podano zadnej z opcji. Obraz nie zostaje zapisany.\n");
                       n = 0;
                       s = 0;
                       return 0;
                       }
                      if(s == 1){
                      printf("Zapisz jako - podaj nazwe pliku:\n");
                       scanf("%s",nazwa);
                       plik=fopen(nazwa, "w");
                       zapisz(plik, obraz, wymx, wymy, odcieni);
                       n = 0;
                       break;
                       }
                       if(s==2)
                       n = 0;
                        break;
          /* przypadek 6. zakonczenie dzialania programu */
          case 6: printf("\n Wybrales opcje wyjscie.\n");
                   return odczytano;                                    // zwrocenie wartosci "odczytano", zakonczenie dzialania programu //
}
   }
   while (n != 6);
return 0;
}


/*

WNIOSKI, UWAGI:

Na wstepie chcialbym uswiadomic problem zaistnialy podczas dzialania programu, 
kiedy uzytkownik wpisywal znak zamiast liczby, w miejscu gdzie powinna byc liczba,
program wpadal w nieskonczona petle, w celu unikniecia jej, program konczy dzialanie
w przypadku wpisania nieprawidlowej danej przy wyborze opcji na kazdym etapie dzialania.
Jednoczesnie nie ma po co sie martwic utrata postepow w modyfikowaniu obrazu w przypadku
wykonwania kilku operacji na raz, poniewaz po kazdej operacji uzytkownik ma do wyboru opcje zapisu.

Jesli uzytkownik chcialby wykonac kilka operacji nalozonych na siebie na obrazie w czasie
 1 cyklu dzialania programu, po kazdej operacji musi zapisac obraz wynikowy na tym samym pliku.
W razie niezapisania obrazu mozna wykonywac kolejne operacje na obrazie, ktory uzytkownik poczatkowo
 wgral do programu, o ile nie nadpisal go po udanej operacji.

Nalezy wspomniec, ze w ramach umozliwienia wyswietlania uzytkownikowi obrazu
po wykonanej operacji program tworzy w komputerze uzytkownika plik o nazwie tmp.pgm, ktory caly czas 
jest nadpisywany przy okazji wykonywania kolejnych dzialan.

Doszedlem rowniez do wniosku, ze aby uwidocznic efekt rozmywania poziomego nalezy zwiekszyc
liczbe punktow otaczajacych dana liczbe w poziomie, wiec promien wynosi 2, a nie 1.

Do programu nie mozna wgrac nieistniejacego obrazu lub obrazu z niewlasciwym formatem,
program konczy wtedy dzialanie wyswietlajac stosowny komunikat "plik niewlasciwy".

W przypadku funkcji switch wystepuje powtarzalnosc pewnych elementow, wiec zostaly
opisane tylko w case 1.
*/
