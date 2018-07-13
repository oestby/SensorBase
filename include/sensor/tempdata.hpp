#ifndef TEMPERATURE_SENSOR
#define TEMPERATURE_SENSOR

#include <sensor/sensorbase.hpp>
#include <string>

class TempData: public SensorData {
    private:
        double reading;

    public:
        TempData(unsigned int sensor_id, 
                   double data);

        double getReading(void) const;
        
        std::string getData(void) const;

};

#endif // TEMPERATURE_SENSOR

