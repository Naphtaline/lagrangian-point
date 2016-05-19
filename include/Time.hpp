//
//  Time.hpp
//  LagrangianPoint
//
//  Created by Xiaxing Shi on 16/05/16.
//
//

#ifndef Time_h
#define Time_h

#include <chrono>

namespace physics {
    class Time {
    private:
        std::chrono::milliseconds time;
    public:
        Time();
        Time(std::chrono::milliseconds time);
        void setTime(std::chrono::milliseconds time);
        
        float asSeconds() const;
    };
}

#endif /* Time_h */
