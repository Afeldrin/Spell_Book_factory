#include <iostream> // Тут абстрактная фабрика

using namespace std;

class ISpell_Type {
public:
    virtual void releaseSpell_Type() = 0;
};

class Defensive_Spell : public ISpell_Type {
public:
    void releaseSpell_Type() override {
        cout << "Защитное заклинание" << endl;
    }
};

class Offensive_Spell : public ISpell_Type {
public:
    void releaseSpell_Type() override {
        cout << "Атакующее заклинание" << endl;
    }
};

class ICast {
public:
    virtual void Cast_Spell(ISpell_Type* spell) = 0;
};

class Everyday_Cast : public ICast {
public:
    void Cast_Spell(ISpell_Type* spell) override {
        cout << "Повседневный каст: ";
        spell->releaseSpell_Type();
    }
};

class Unforgivable_Cast : public ICast {
public:
    void Cast_Spell(ISpell_Type* spell) override {
        cout << "Непростительный каст: ";
        spell->releaseSpell_Type();
    }
};

class ISpell_page {
public:
    virtual ISpell_Type* createSpell_Type() = 0;
    virtual ICast* createCast() = 0;
};

class Defensive_Page : public ISpell_page {
public:
    ISpell_Type* createSpell_Type() override {
        return new Defensive_Spell();
    }
    ICast* createCast() override {
        return new Everyday_Cast();
    }
};

class Offensive_Page : public ISpell_page {
public:
    ISpell_Type* createSpell_Type() override {
        return new Offensive_Spell();
    }
    ICast* createCast() override {
        return new Unforgivable_Cast();
    }
};
int main()
{
    setlocale(LC_ALL, "rus");

    ISpell_page* dSpell_page = new Defensive_Page();

    ISpell_Type* dSpell_Type = dSpell_page->createSpell_Type();
    ICast* dCast = dSpell_page->createCast();

    dCast->Cast_Spell(dSpell_Type);

    ISpell_page* ofSpell_page = new Offensive_Page();

    ISpell_Type* ofSpell_Type = ofSpell_page->createSpell_Type();
    ICast* ofCast = ofSpell_page->createCast();

    ofCast->Cast_Spell(ofSpell_Type);

    return 0;
}
