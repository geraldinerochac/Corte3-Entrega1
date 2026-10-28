#include <unordered_map>
#include <map>

using namespace std;

class AuctionSystem {
private:
    // itemId -> (userId -> bidAmount) para consultas y actualizaciones rápidas
    unordered_map<int, unordered_map<int, int>> bidsByItem;
    
    // itemId -> (bidAmount -> set de userIds) para mantener ordenadas las mayores pujas
    // Usamos map con greater para que el begin() apunte directamente a la puja más alta
    unordered_map<int, map<int, int, greater<int>>> highestBidsByItem;

public:
    AuctionSystem() {
        // Constructor vacío
    }
    
    void addBid(int userId, int itemId, int bidAmount) {
        // Si el usuario ya tenía una puja previa para este ítem, debemos removerla primero de los registros ordenados
        if (bidsByItem[itemId].count(userId)) {
            int oldBid = bidsByItem[itemId][userId];
            highestBidsByItem[itemId][oldBid]--;
            if (highestBidsByItem[itemId][oldBid] == 0) {
                highestBidsByItem[itemId].erase(oldBid);
            }
        }
        
        // Registramos la nueva puja
        bidsByItem[itemId][userId] = bidAmount;
        highestBidsByItem[itemId][bidAmount]++;
    }
    
    void updateBid(int userId, int itemId, int newAmount) {
        // Al garantizarse que existe, podemos reutilizar la lógica de addBid ya que reemplaza/actualiza
        addBid(userId, itemId, newAmount);
    }
    
    void removeBid(int userId, int itemId) {
        if (bidsByItem[itemId].count(userId)) {
            int oldBid = bidsByItem[itemId][userId];
            bidsByItem[itemId].erase(userId);
            
            highestBidsByItem[itemId][oldBid]--;
            if (highestBidsByItem[itemId][oldBid] == 0) {
                highestBidsByItem[itemId].erase(oldBid);
            }
        }
    }
    
    int getHighestBidder(int itemId) {
        // Si no hay pujas para este ítem o el mapa está vacío
        if (highestBidsByItem.find(itemId) == highestBidsByItem.end() || highestBidsByItem[itemId].empty()) {
            return -1;
        }
        
        // Obtenemos la puja máxima (es el primer elemento gracias a greater<int>)
        int maxBid = highestBidsByItem[itemId].begin()->first;
        
        // Buscamos cuál es el usuario que tiene esta puja máxima
        // En caso de empate, podemos retornar el userId correspondiente (por lo general el de mayor ID o el primero que coincida)
        int bestUser = -1;
        for (auto& pair : bidsByItem[itemId]) {
            if (pair.second == maxBid) {
                if (bestUser == -1 || pair.first > bestUser) {
                    bestUser = pair.first;
                }
            }
        }
        
        return bestUser;
    }
};