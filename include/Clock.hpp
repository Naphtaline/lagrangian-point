//
//  Clock.hpp
//  LagrangianPoint
//
//  Created by Xiaxing Shi on 16/05/16.
//
//

#ifndef Clock_h
#define Clock_h

#include <chrono>
#include "Time.hpp"

namespace physics {
    class Clock {
    private:
        std::chrono::time_point<std::chrono::system_clock> lastTimePoint;
    public:
        Clock();
        Time getElapsedTime() const;
        Time restart();
    };
}

#endif /* Clock_h */
