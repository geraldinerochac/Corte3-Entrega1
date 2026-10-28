#include <vector>

using namespace std;

class ATM {
private:
    long long banknotes[5]; // Almacena la cantidad de billetes de cada denominación: $20, $50, $100, $200, $500
    const int values[5] = {20, 50, 100, 200, 500};

public:
    ATM() {
        for (int i = 0; i < 5; ++i) {
            banknotes[i] = 0;
        }
    }
    
    void deposit(vector<int> banknotesCount) {
        for (int i = 0; i < 5; ++i) {
            banknotes[i] += banknotesCount[i];
        }
    }
    
    vector<int> withdraw(int amount) {
        vector<int> toWithdraw(5, 0);
        long long tempBanknotes[5];
        
        // Copiamos temporalmente el inventario por si la transacción falla
        for (int i = 0; i < 5; ++i) {
            tempBanknotes[i] = banknotes[i];
        }
        
        // Empezamos desde el billete de mayor valor ($500 -> índice 4) hasta el menor ($20 -> índice 0)
        for (int i = 4; i >= 0; --i) {
            if (amount <= 0) break;
            
            long long needed = amount / values[i];
            long long take = min(needed, tempBanknotes[i]);
            
            toWithdraw[i] = take;
            amount -= take * values[i];
            tempBanknotes[i] -= take;
        }
        
        // Si aún queda dinero por entregar, significa que no se pudo completar la cantidad exacta
        if (amount > 0) {
            return {-1};
        }
        
        // Si fue exitoso, actualizamos permanentemente el inventario del cajero
        for (int i = 0; i < 5; ++i) {
            banknotes[i] = tempBanknotes[i];
        }
        
        return toWithdraw;
    }
};
