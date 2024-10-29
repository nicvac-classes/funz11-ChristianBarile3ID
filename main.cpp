#include <iostream>
#include <ctime>

using namespace std;

string leggiComando() {
    string op;
    
    do {
        cout << "Inserisci l'azione da eseguire" << endl;
        cin >> op;
    } while (op != "R" && op != "P" && op != "S" && op != "X");
    
    return op;
}

void previsioneBudget(int budget) {
    int percentuale, variazione;
    string op;
    
    percentuale = rand() % 31 - 10;
    variazione = budget * ( percentuale / 100);
    budget = budget + variazione;
    cout << "Il budget è diventato: " << budget << endl;
}

int raccoltaFondi(int & budget) {
    int fondi;
    
    cout << "Di quanto vuoi contribuire al budget?" << endl;
    cin >> fondi;
    budget = budget + fondi;

}

int spesaImprevista(int budget) {
    int budgetFinale, imprevisto;
    
    cout << "C'è stato un imprevisto, quanti soldi servono per risolverlo?" << endl;
    cin >> imprevisto;
    if (imprevisto > budget) {
        budgetFinale = 0;
    } else {
        budgetFinale = budget - imprevisto;
    }
    
    return budgetFinale;
}

int main() {
    string azione;
    int budgetIniziale;
    
    cout << "Inserisci un budget iniziale" << endl;
    cin >> budgetIniziale;
    do {
        cout << "Il budget è: " << budgetIniziale << endl;
        azione = leggiComando();
        if (azione == "R") {
            budgetIniziale = raccoltaFondi(budgetIniziale);
        }
        if (azione == "P") {
            previsioneBudget(budgetIniziale);
        }
        if (azione == "S") {
            budgetIniziale = spesaImprevista(budgetIniziale);
        }
    } while (azione != "X");
}

