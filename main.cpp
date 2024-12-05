#include "Device.h"
#include <iostream>
#include <thread>
#include <mutex>

// Глобальный мьютекс для синхронизации вывода
std::mutex coutMutex;

// Функция для запуска устройства в отдельном потоке
void runDevice(Device* device, const std::string& deviceName) {
    // Заблокировать вывод для одного потока
    {
        std::lock_guard<std::mutex> lock(coutMutex);
        std::cout << deviceName << " output: ";
    }
    device->getData();
}

int main() {
    // Создаем устройства
    Device* deviceA = new DeviceA();
    Device* deviceB = new DeviceB();
    Device* deviceC = new DeviceC();

    // Запускаем устройства в отдельных потоках
    std::thread threadA(runDevice, deviceA, "Device A");
    std::thread threadB(runDevice, deviceB, "Device B");
    std::thread threadC(runDevice, deviceC, "Device C");

    // Ожидаем завершения всех потоков
    threadA.join();
    threadB.join();
    threadC.join();

    // Очищаем память
    delete deviceA;
    delete deviceB;
    delete deviceC;

    return 0;
}
