#include <iostream>
#include <vector>

using namespace std;

// Abstract(sanal) sınıf: Animal
class Animal {
public:
    virtual void makeSound() const = 0; // Saf sanal fonksiyon
};

// Türetilmiş Sınıflar; Köpek, Kedi, Kuş
class köpek : public Animal {
public:
    void makeSound() const override {
        cout << "Haw haw" << endl;
    }
};
class kedi : public Animal {
public:
    void makeSound() const override {
        cout << "Miyav" << endl;
    }
};
class kus : public Animal {
public:
    void makeSound() const override {
        cout << "Cik cik" << endl;
    }
};

int main()
{
    // Animal tipinden bir vektör oluşturuyoruz
    vector<Animal*> hayvanlar;
    // Burada * kullanılmasının sebebi; hayvanlar vektörü Animal sınıfının pointerlarını tutar.
    // Pointer kullanmak, genellikle polymorphism ile birlikte dinamik bellek yönetimi için terci edilir.
    // Dinamik bellek yönetimi ise new operatörü ile elde edilen bellek bloklarının işaretçilerle tutulmasını sağlar

    // Farklı hayvan türlerinden nesneler ekliyoruz
    hayvanlar.push_back(new köpek);
    hayvanlar.push_back(new kedi);
    hayvanlar.push_back(new kus);

    // Her bir hayvanın sesini çıkaran döngü
    for(const auto& hayvan:hayvanlar)
    {
        hayvan->makeSound();
    }
    // Belleği temizle
    for (const auto& hayvan: hayvanlar)
    {
        delete hayvan;
    }
    return 0;
}
