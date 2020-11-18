#include <iostream>
#include <fstream>
#include <locale>
using namespace std;

int jegyar(int kezd, int veg, int ft)
{
    int km = veg-kezd;
    int km10 = (km-1)/10+1;
    int ar1 = km10*ft;
    int ar2 = ((ar1+2)/5)*5;
    return ar2;
}

int main ()
{
    int jegydb, uthossz, ear;
    int hely[500], fel[500], le[500];
    ifstream fajl;
    fajl.open("eladott.txt");
    fajl >> jegydb >> uthossz >> ear;
    for (int i=0;i<jegydb;i++)
    {
        fajl >> hely[i] >> fel[i] >> le[i];
    }
    fajl.close();
    //cout << jegydb << endl;//

    cout << "2. feladat" << endl;
    cout << "A legutolso jegyvasarlo ulesenek sorszama: " << hely[jegydb-1] << endl;
    cout << "Az altala beutazott tavolsag: " << le[jegydb-1]-fel[jegydb-1] << endl;

    cout << "3. feladat" << endl;
    cout << "Az utat vegigutazo utasok sorszamai: ";
    for (int i=0;i<jegydb;i++)
    {
        if (fel[i]==0 && le[i]==uthossz) cout << i+1 << " ";
    }
    cout << endl;

    cout << "4. feladat" << endl;
    int bevetel = 0;
    for (int i=0;i<jegydb;i++)
    {
        bevetel = bevetel + jegyar(fel[i], le[i], ear);
    }
    cout << bevetel << " Ft bevetele szarmazott a tarsasagnak a jegyekbol" << endl;

    cout << "5. feladat" << endl;
    int utolso = 0;
    for (int i=0;i<jegydb;i++)
    {
        if (fel[i]>utolso) utolso = fel[i];
    }
    //cout << utolso << endl;
    int felszallo = 0;
    int leszallo = 0;
    for (int i=0;i<jegydb;i++)
    {
        if (fel[i] == utolso) felszallo++;
        if (le[i] == utolso) leszallo++;
    }
    /*for (int i=0;i<jegydb;i++)
    {
        if (fel[i]>utolso && fel[i]<uthossz)
        {
            utolso = fel[i];
        }
        if (le[i]>utolso && le[i]<uthossz)
        {
            utolso = le[i];
        }
    }
    int fdb=0, ldb=0;
    for (int i=0;i<jegydb;i++)
    {
        if (fel[i]==utolso)
        {
            fdb ++;
        }
        if (le[i]==utolso)
        {
            ldb ++;
        }
    }*/
    cout << "Felszallo utasok szama: " << felszallo /*<< " " << fdb*/ << endl;
    cout << "Leszallo utasok szama: " << leszallo /*<< " " << ldb*/ << endl;

    cout << "6. feladat" << endl;
    int megallt[201];
    for (int i=0;i<uthossz;i++)
    {
        megallt[i]=0;
    }
    for (int i=0;i<jegydb;i++)
    {
        megallt[fel[i]]=1;
        megallt[le[i]]=1;
    }
    int mszam=0;
    for (int i=1;i<uthossz;i++)
    {
        mszam = mszam+megallt[i];
    }
    cout << "A kiindulo es a celallomas kozott " << mszam << " helyen allt meg" << endl;

    cout << "7. feladat" << endl;
    int ulesek[49];
    for (int i=1;i<=48;i++) ulesek[i]=0;
    int km7;
    cout << "Kerem a kilometert: ";
    cin >> km7;
    for (int i=0;i<jegydb;i++)
    {
        if (fel[i]<=km7 && km7<le[i])
        {
            ulesek[hely[i]]=i+1;
        }
    }
    ofstream fajl2;
    fajl2.open("kihol.txt");
    for (int i=1;i<=48;i++)
    {
        fajl2 << i << ". ules: ";
        if (ulesek[i]!=0)
        {
            fajl2 << ulesek[i] << ". utas" << endl;
        }
        else
        {
            fajl2 << "ures" << endl;
        }
    }
    fajl2.close();

    return 0;
}
