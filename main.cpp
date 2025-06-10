#include "card.h"
#include "Header.h"
#include "leagality.h"
#include <iomanip>    
ostream& operator<<(ostream&, const card&);
ostream& operator<<(ostream& os, const vector<card>& ptr);
vector<Stack> Pile_alloc(const vector<card>& cards);
void printAll(vector<Stack> , vector<Stack> );


int main()
{
    vector<Stack>collection(4);
    vector<card>help(mode());
    vector<card> cards = card::load();
    cards = card::shuf(cards);
    //cout << cards;
    vector<Stack> piles = Pile_alloc(cards);
    //printAll(piles,collection);
    us _pn{}, _cn{}, pn{}, check{};
    bool HelpTaken = {};

    while (true)
    {
        printAll(piles, collection);
        do {
            do{ 
                here:
                if (takeHelp(help, piles) && inputHelp(help,piles)) {
                    goto there;
                }
                if (!sel(_pn, _cn, piles))  goto here;
                check = ask(collection, _pn, _cn, piles);
            } while (check==0);
            if (check == 2) break;
            cout << "Please selct destination pile: "; cin >> pn;
        } while (!Destination_basic(_pn, _cn, pn, piles));
        if (check == 2) { system("cls"); continue; }
        trasnferCard(piles, _pn, pn, _cn);
        there:
        system("cls");
    }
}
 


    

void printAll(vector<Stack> piles, vector<Stack> collection){
    int points{};
        for(auto i : collection) {
            for (int j = 0; j < i.get_size(); j++)
            {
                points+=i.get_nmbr(j);
            }
        }
    
    printf("Your points: %d\n", points);
    printf("Collentions:\n");
    for (int i = 0; i < collection.size(); i++) {
        printf("%d: ", i+1);
        if (collection[i].empty())
            cout << "Empty\n";
        else
            collection[i].print();
       ;
    }
    cout << endl;
    for (int i = 0; i < piles.size(); i++)
    {
        if (i <= 6)
        {
            printf("Pile #%d, %d cards, %d visible\n", i + 1, piles[i].get_size(), piles[i].get_size() - piles[i].get_watch());
            piles[i].print();
            cout << endl;
        }
    }
}
ostream& operator<<(ostream& os, const card& card) {
    string c, t;
    switch (card.typ) {
    case 0: t = "Heart"; break;
    case 1: t = "Dimnd"; break;
    case 2: t = "Club"; break;
    case 3: t = "Spade"; break;
    }
    switch (card.clr) {
    case 0: c = "red"; break;
    case 1: c = "black"; break;
    }
    if (card.ch==0)
    os << setw(4) << left <<  card.nmbr << setw(7) << left << t << c << endl;
    else 
        os << setw(4) << left << card.ch << setw(7) << left << t << c << endl;
    return os;
}
ostream& operator<<(ostream& os, const vector<card> &ptr) {
    for (int i = 0; i < ptr.size(); i++)
        os << ptr[i];
    return os;
}
vector<Stack> Pile_alloc(const vector<card>& cards) {
    vector<Stack> piles(8);
    for (int i = 0, index = 0; i < piles.size(); i++)
    {
        switch (i) {
        case 0: piles[i] = Stack(cards, index, index + 1); index ++; break;
        case 1: piles[i] = Stack(cards, index, index + 2); index += 2; break;
        case 2: piles[i] = Stack(cards, index, index + 3); index += 3; break;
        case 3: piles[i] = Stack(cards, index, index + 4); index += 4; break;
        case 4: piles[i] = Stack(cards, index, index + 5); index += 5; break;
        case 5: piles[i] = Stack(cards, index, index + 6); index += 6; break;
        case 6: piles[i] = Stack(cards, index, index + 7); index += 7; break;
        case 7: piles[i] = Stack(cards, index, 52); break;
        }
    }
    return piles;
}


