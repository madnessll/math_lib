#pragma once

namespace math_lib {

    constexpr int INT_MAX_VAL = 2147483647;
    constexpr int INT_MIN_VAL = -2147483648;

    
    inline bool calculateSum(int num1, int num2, int& result) {
        if (num2 > 0 && num1 > INT_MAX_VAL - num2) return false;
        if (num2 < 0 && num1 < INT_MIN_VAL - num2) return false;
        result = num1 + num2;
        return true;
    }

    inline bool calculateDifference(int num1, int num2, int& result) {
        if (num2 < 0 && num1 > INT_MAX_VAL + num2) return false;
        if (num2 > 0 && num1 < INT_MIN_VAL + num2) return false;
        result = num1 - num2;
        return true;
    }

    inline bool calculateMult(int num1, int num2, int& result) {
        if (num1 > 0 && num2 > 0 && num1 > INT_MAX_VAL / num2) return false;
        if (num1 < 0 && num2 < 0 && num1 < INT_MAX_VAL / num2) return false;
        if (num1 > 0 && num2 < 0 && num2 < INT_MIN_VAL / num1) return false;
        if (num1 < 0 && num2 > 0 && num1 < INT_MIN_VAL / num2) return false;
        result = num1 * num2;
        return true;
    }

    inline bool calculateDivision(int num1, int num2, int& result) {
        if (num2 == 0) return false;
        result = num1 / num2;
        return true;
    }

    inline bool calculatePower(int num1, int num2, int& result) {
        if (num2 < 0) return false;
        if (num2 == 0) { 
            result = 1; 
            return true; 
        }
        int end = 1;
        for (int i = 0; i < num2; i++) {
            if (num1 > 0) {
                if ((end > 0 && end > INT_MAX_VAL / num1) ||
                    (end < 0 && end < INT_MIN_VAL / num1))
                    return false;
            } else { 
                if ((end > 0 && end > INT_MIN_VAL / num1) ||
                    (end < 0 && end < INT_MAX_VAL / num1))
                    return false;
            }
            end *= num1;
        }
        result = end;
        return true;
    }

    inline bool calculateFactorial(int num1, int& result) {
        if (num1 < 0) return false;
        if (num1 == 0 || num1 == 1) { 
            result = 1; 
            return true; 
        }

        int prev;
        if (!calculateFactorial(num1 - 1, prev)) return false;

        if (prev > INT_MAX_VAL / num1) return false;
        
        result = num1 * prev;
        return true;
    }
}
