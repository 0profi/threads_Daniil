#ifndef DEVICE_H
#define DEVICE_H

#include <string>

class Device {
protected:
    std::string data;

    static std::string generateRandomString(const std::string& charset, int minLength, int maxLength);

public:
    Device();
    virtual ~Device();

    virtual void getData() const = 0;
};

class DeviceA : public Device {
public:
    DeviceA();
    void getData() const override;
};

class DeviceB : public Device {
public:
    DeviceB();
    void getData() const override;
};

class DeviceC : public Device {
public:
    DeviceC();
    void getData() const override;
};

#endif // DEVICE_H
