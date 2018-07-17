#include <sensor/tempdata.hpp>

TempData::TempData(unsigned int sensor_id, double data):
    SensorData(sensor_id), reading(data) 
{
    //Empty
}

double TempData::getReading(void) const {
    return reading;
}

std::string TempData::getData(void) const {
    std::string data;

    //Data comes on the format
    //[SENSOR ID], [DATA], [TIMESTAMP]
    data += getSensorId();
    data += ", ";
    data += std::to_string(reading);
    data += ", ";
    data += getTimeStamp();

    return data;
}
