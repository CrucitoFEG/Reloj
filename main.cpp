#include <iostream>
#include <ctime>
#include <chrono>
#include <thread>
#include <vector>

using namespace std;

// Estructura para representar una alarma
struct Alarm {
    int hour;
    int minute;
    int second;
    string message;
};

// Función para mostrar la hora actual
void displayTime() {
    time_t now = time(nullptr);
    tm* localTime = localtime(&now);
    cout << "Hora actual: " << localTime->tm_hour << ":" << localTime->tm_min << ":" << localTime->tm_sec << endl;
}

// Función para verificar si una alarma está activa
bool isAlarmActive(const Alarm& alarm) {
    time_t now = time(nullptr);
    tm* localTime = localtime(&now);
    return (localTime->tm_hour == alarm.hour && localTime->tm_min == alarm.minute && localTime->tm_sec == alarm.second);
}

int main() {
    vector<Alarm> alarms;

    // Ejemplo: Agregar una alarma
    Alarm alarm1 = {10, 30, 0, "¡Es hora de despertar!"};
    alarms.push_back(alarm1);

    while (true) {
        displayTime();

        // Verificar si alguna alarma está activa
        for (const Alarm& alarm : alarms) {
            if (isAlarmActive(alarm)) {
                cout << "ALARMA: " << alarm.message << endl;
            }
        }

        // Esperar un segundo antes de actualizar la hora
        this_thread::sleep_for(chrono::seconds(1));
    }

    return 0;
}
