//
//  Time.cpp
//  LagrangianPoint
//
//  Created by Xiaxing Shi on 16/05/16.
//
//

#include "Time.hpp"

using namespace physics;
using namespace std::chrono;


Time::Time() : Time(milliseconds::zero()) {
    
}

Time::Time(milliseconds time) : time(time) {

}

void Time::setTime(std::chrono::milliseconds time) {
    this->time = time;
}

float Time::asSeconds() const {
    return time.count() / 1000.0f;
}