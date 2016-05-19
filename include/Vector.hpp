//
//  Vector.hpp
//  LagrangianPoint
//
//  Created by Xiaxing SHI on 16/05/16.
//
//

#ifndef Vector_h
#define Vector_h

namespace physics {
    class Vector {
    public:
        float x = 0;
        float y = 0;
        
        Vector(): Vector(0, 0) {
            
        }
        
        Vector(float a, float b): x(a), y(b) {
            
        }
    };
    
    inline Vector operator-(const Vector& right) {
        return Vector(-right.x, -right.y);
    }
    
    inline Vector operator+(const Vector&  left, const Vector& right) {
        return Vector(left.x + right.x, left.y + right.y);
    }
    
    inline Vector& operator+=(Vector& left, const Vector& right) {
        left.x += right.x;
        left.y += right.y;
        return left;
    }
    
    inline Vector operator-(const Vector& left, const Vector& right) {
        return Vector(left.x - right.x, left.y - right.y);
    }
    
    inline Vector& operator-=(Vector&  left, const Vector& right) {
        left.x -= right.x;
        left.y -= right.y;
        return left;
    }
    
    inline Vector operator*(float left, const Vector&  right) {
        return Vector(left * right.x, left * right.y);
    }
    
    inline Vector operator*(const Vector& left, float right) {
        return Vector(left.x * right, left.y * right);
    }
    
    inline Vector& operator*=(Vector& left, float right) {
        left.x *= right;
        left.y *= right;
        return left;
    }
    
    inline Vector operator/(const Vector& left, float right) {
        return Vector(left.x / right, left.y / right);
    }
    
    inline Vector& operator/=(Vector& left, float right) {
        left.x /= right;
        left.y /= right;
        return left;
    }
    
    inline bool operator==(const Vector& left, const Vector& right) {
        return left.x == right.x && left.y == right.y;
    }
    
    inline bool operator!=(const Vector& left, const Vector& right) {
        return left.x != right.x || left.y != right.y;
    }
}

#endif /* Vector_h */
