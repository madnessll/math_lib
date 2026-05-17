#pragma once

namespace math_lib {

    constexpr int INT_MAX_VAL = 2147483647;
    constexpr int INT_MIN_VAL = -2147483648;

    
    inline bool calculateSum(int num1, int num2, double& result) {
        if (num2 > 0 && num1 > INT_MAX_VAL - num2) return false;
        if (num2 < 0 && num1 < INT_MIN_VAL - num2) return false;
        result = (double)(num1 + num2);
        return true;
    }

    inline bool calculateDifference(int num1, int num2, double& result) {
        if (num2 < 0 && num1 > INT_MAX_VAL + num2) return false;
        if (num2 > 0 && num1 < INT_MIN_VAL + num2) return false;
        result = (double)(num1 - num2);
        return true;
    }

    inline bool calculateMult(int num1, int num2, double& result) {
        if (num1 > 0 && num2 > 0 && num1 > INT_MAX_VAL / num2) return false;
        if (num1 < 0 && num2 < 0 && num1 < INT_MAX_VAL / num2) return false;
        if (num1 > 0 && num2 < 0 && num2 < INT_MIN_VAL / num1) return false;
        if (num1 < 0 && num2 > 0 && num1 < INT_MIN_VAL / num2) return false;
        result = (double)(num1 * num2);
        return true;
    }

    inline bool calculateDivision(int num1, int num2, double& result) {
        if (num2 == 0) return false;
        result = (double)num1 / (double)num2;
        return true;
    }

    inline bool calculatePower(int num1, int num2, double& result) {
        if (num2 < 0) return false;
        if (num2 == 0) { 
            result = 1; 
            return true; 
        }
        int end = 1;
        for (int i = 0; i < num2; i++) {
            if (end > INT_MAX_VAL / num1) return false;
            end *= num1;
        }
        result = (double)end;
        return true;
    }

    inline bool calculateFactorial(int num1, double& result) {
        if (num1 < 0) return false;
        if (num1 == 0 || num1 == 1) { 
            result = 1; 
            return true; 
        }
        double prev;
        if (!calculateFactorial(num1 - 1, prev)) return false;
        double end = (double)num1 * prev;
        if (end > 1.7976931348623157e+308) return false;
        result = end;
        return true;
    }
}
