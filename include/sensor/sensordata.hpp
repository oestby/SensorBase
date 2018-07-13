#ifndef SENSOR_DATA 
#define SENSOR_DATA

#include <string>
#include <tools/time.hpp>

class SensorData {
    public:
        SensorData(unsigned int sensor_id):
            sensor_id(sensor_id) {
                //Empty
       }

        unsigned int getSensorId(void) const {
            return sensor_id;
        }

        std::string getTimeStamp(void) const {
            return time_stamp.getStartTimestring();
        }

        virtual std::string getData(void) const;

        private:
        tools::Time time_stamp;
        unsigned int sensor_id;

};

#endif //SENSOR_DATA

