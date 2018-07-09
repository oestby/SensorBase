#ifndef TEMPERATURE_SENSOR
#define TEMPERATURE_SENSOR

#include <Sensor/SensorBase>
#include <string>

class TempData: public SensorBase{
    private:
        double reading;

    public:
        TempSensor(std::string sensor_name, 
                   unsigned int sensor_id, 
                   double data);

        double getReading(void) const;
        std::string getHumanReadableReading(void) const;
};

#endif // TEMPERATURE_SENSOR

