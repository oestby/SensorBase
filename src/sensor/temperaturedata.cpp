#include <sensor/tempdata.hpp>

TempData::TempData(std::string sensor_name, unsigned int sensor_id, double data):
    SensorData(sensor_id), reading(data) {

    }
