#pragma once

#include <QtCore/QLoggingCategory>
#include <all/mavlink.h>
#include <memory>
#include <vector>

#define QGC_LOGGING_CATEGORY(name, ...) Q_LOGGING_CATEGORY(name, __VA_ARGS__)

class LinkInterface
{
public:
    uint8_t mavlinkChannel() const { return 2; }
    bool connected = true;
};
using SharedLinkInterfacePtr = std::shared_ptr<LinkInterface>;
using WeakLinkInterfacePtr = std::weak_ptr<LinkInterface>;

class VehicleLinkManager
{
public:
    WeakLinkInterfacePtr primaryLink() const { return link; }
    SharedLinkInterfacePtr link = std::make_shared<LinkInterface>();
};

class Vehicle
{
public:
    int id() const { return 2; }
    VehicleLinkManager *vehicleLinkManager() { return &links; }
    bool sendMessageOnLinkThreadSafe(LinkInterface *link, mavlink_message_t message)
    {
        if (!link->connected) { return false; }
        sent.push_back(message);
        return true;
    }
    VehicleLinkManager links;
    std::vector<mavlink_message_t> sent;
};

class MultiVehicleManager
{
public:
    static MultiVehicleManager *instance() { static MultiVehicleManager value; return &value; }
    Vehicle *activeVehicle() const { return vehicle; }
    Vehicle *vehicle = nullptr;
};

class MAVLinkProtocol
{
public:
    static MAVLinkProtocol *instance() { static MAVLinkProtocol value; return &value; }
    int getSystemId() const { return 255; }
    static int getComponentId() { return 190; }
};
