#pragma once

namespace math_lib {

    constexpr double DOUBLE_MAX_VAL = 1.7976931348623157e+308;
    constexpr double DOUBLE_MIN_VAL = -DOUBLE_MAX_VAL;

    // DRY
    inline bool checkOverflow(double res) {
        return res > DOUBLE_MAX_VAL || res < DOUBLE_MIN_VAL;
    }
    
    inline bool calculateSum(double num1, double num2, double& result) {
        double end = num1 + num2;
        if (checkOverflow(end)) return false;
        result = end;
        return true;
    }

    inline bool calculateDifference(double num1, double num2, double& result) {
        double end = num1 - num2;
        if (checkOverflow(end)) return false;
        result = end;
        return true;
    }

    inline bool calculateMult(double num1, double num2, double& result) {
        double end = num1 * num2;
        if (checkOverflow(end)) return false;
        result = end;
        return true;
    }

    inline bool calculateDivision(double num1, double num2, double& result) {
        if (num2 == 0) return false;
        double end = num1 / num2;
        if (checkOverflow(end)) return false;
        result = end;
        return true;
    }

    inline bool calculatePower(double num1, double num2, double& result) {
        if (num2 == 0) {
            result = 1;
            return true;
        }
        if (num2 < 0) return false; 
        double end = 1;
        for (int i = 0; i < (int)num2; i++) {
            end *= num1;
            if (checkOverflow(end)) return false;
        }
        result = end;
        return true;
    }

    inline bool calculateFactorial(double num, double& result) {
        if (num < 0) return false;  
        if (num == 0 || num == 1) {
            result = 1;
            return true;
        }
        double prev;
        if (!calculateFactorial(num - 1, prev)) return false;
        double end = num * prev;
        if (checkOverflow(end)) return false;
        result = end;
        return true;
    }
}