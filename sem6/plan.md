
1. Mini-baza danych
Student
| Imie | Nazwisko | Nr Albumu | Kod przedmiotu | Nazwa przedmiotu | Ocena |

Cel - zrobić ranking studentów

2. Struktura danych student. (typedef)

```
typedef struct _student {
    char * imie;
    char * nazwisko;
    char * nr_albumu;
    char * kod_przedmiotu;
    char * nazwa_przedmiotu;
    float ocena;
} student, *pstudent;
```

3. Wczytywanie przy pomocy `strtok`, `fgets`
4. Zadanie: Potrzebujemy wyznaczyc ranking wg średniej.
5. Algorytm: najpierw znajdz wszystkich studentow i zbuduj slownik (2 tablice - jedna do int a druga do sum float)
6. Potem przejdz jeszcze raz przez wszystkie. Złożonosć obliczeniowa n^2!!!

7. Na następnym wykładzie: Mapa z wynikami średniej
typedef struct _mapa {
    char * klucz;
    float suma;
    float ile;
}

-------------------------------------------------------------------
a) Dynamiczna alokacja pamieci - napisy. Scalanie. 

float * pf = (float*) malloc(10 * sizeof(struct moja_struktura))

