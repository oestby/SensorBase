#ifndef DATA_BASE
#define DATA_BASE

#include <string>
#include <Tools/Time.hpp>

class DataBase {
    public:
        DataBase(std::string sensor_name):
            sensor_name(sensor_name) {
                //Empty
            }

        std::string getSensorName(void) const {
            return sensor_name;
        }

        unsigned int getSensorId(void) const {
            return sensor_id;
        }
        std::string getSensorCreationTime(void) const {
            return time_stamp.getStartTimeString();
        }
    protected:
        tools::Time time_stamp;

    private:
        std::string sensor_name;
        unsigned int sensor_id;

};

#endif //DATA_BASE

