//
//  Clock.cpp
//  LagrangianPoint
//
//  Created by Xiaxing Shi on 16/05/16.
//
//

#include "Clock.hpp"

using namespace physics;
using namespace std::chrono;

Clock::Clock() : lastTimePoint(system_clock::now()) {
    
}

Time Clock::getElapsedTime() const {
    return Time(duration_cast<milliseconds>(system_clock::now() - lastTimePoint));
}

Time Clock::restart() {
    auto old = lastTimePoint;
    lastTimePoint = system_clock::now();
    return Time(duration_cast<milliseconds>(lastTimePoint - old));
}
