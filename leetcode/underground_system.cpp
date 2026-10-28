#include <unordered_map>
#include <string>
#include <utility>

using namespace std;

class UndergroundSystem {
private:
    // Estructura para guardar el check-in activo de cada usuario: id -> {stationName, t}
    unordered_map<int, pair<string, int>> ongoingTrips;
    
    // Estructura para guardar la estadística de las rutas: "start->end" -> {tiempo_total, total_viajes}
    unordered_map<string, pair<long long, int>> routeStats;

public:
    UndergroundSystem() {
        // Constructor vacío
    }
    
    void checkIn(int id, string stationName, int t) {
        ongoingTrips[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        // Recuperamos los datos del check-in del usuario
        auto& trip = ongoingTrips[id];
        string startStation = trip.first;
        int startTime = trip.second;
        
        // Creamos la llave única para la ruta
        string routeKey = startStation + "->" + stationName;
        
        // Actualizamos el tiempo total y el contador de viajes
        int travelTime = t - startTime;
        routeStats[routeKey].first += travelTime;
        routeStats[routeKey].second += 1;
        
        // Opcional: limpiar el viaje activo si ya finalizó
        ongoingTrips.erase(id);
    }
    
    double getAverageTime(string startStation, string endStation) {
        string routeKey = startStation + "->" + endStation;
        auto& stats = routeStats[routeKey];
        
        // Retornamos el promedio dividiendo el tiempo acumulado entre el número de viajes
        return (double)stats.first / stats.second;
    }
};