#ifndef POSITIONSTATE
#define POSITIONSTATE
#include <utility/imumaths.h>
#include <Arduino.h>
#include "BaseState.h"

namespace states {

    class PositionState: public BaseState {
        private:
            imu::Vector<3> euler;
            
        public:
            imu::Vector<3> readPosition();
            void update(imu::Vector<3> e);
            
    };

}
#endif