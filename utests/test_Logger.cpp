#include <Tools/Logger.hpp>

using namespace tools;
int main() {
    // Testing all kinds of log messages.
    Logger test_logger("logs/test.log");
    test_logger.info("Unit test starting");
    test_logger.warn("WARNING TEST");
    test_logger.error("ERROR TEST");
    test_logger.debug("DEBUG MSG TEST");
    test_logger.info("Unit test ending");
}
