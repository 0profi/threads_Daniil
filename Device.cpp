#include "Device.h"
#include <iostream>
#include <random>
#include <thread>
#include <chrono>

// Базовый класс Device
Device::Device() : data("") {}

Device::~Device() {}

std::string Device::generateRandomString(const std::string& charset, int minLength, int maxLength) {
    static std::random_device rd;
    static std::mt19937 generator(rd());
    std::uniform_int_distribution<int> lengthDist(minLength, maxLength);
    std::uniform_int_distribution<int> charDist(0, charset.size() - 1);

    int length = lengthDist(generator);
    std::string result;
    for (int i = 0; i < length; ++i) {
        result += charset[charDist(generator)];
    }
    return result;
}

DeviceA::DeviceA() {
    data = generateRandomString("0123456789", 5, 12);
}

void DeviceA::getData() const {
    for (char c : data) {
        std::cout << c;
        std::cout.flush();
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    std::cout << std::endl;
}

DeviceB::DeviceB() {
    data = generateRandomString("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ", 5, 12);
}

void DeviceB::getData() const {
    for (char c : data) {
        std::cout << c;
        std::cout.flush();
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }
    std::cout << std::endl;
}

DeviceC::DeviceC() {
    data = generateRandomString("!\"№;%:?*(){}[]<>#&@^", 5, 12);
}

void DeviceC::getData() const {
    for (char c : data) {
        std::cout << c;
        std::cout.flush();
        std::this_thread::sleep_for(std::chrono::seconds(3));
    }
    std::cout << std::endl;
}


