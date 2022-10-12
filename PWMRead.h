#include <GyverFilters.h>

class PWMRead
{
public:
    PWMRead(
        byte pin
        , int minLevel
        , int maxLevel
        , int centerLevel
    ){
        pinMode(pin, INPUT);
        _pin = pin;

        _minLevel = minLevel;
        _maxLevel = maxLevel;
        _centerLevel = centerLevel;
    };
    int getPWM(){
        _pinRead = pulseIn(_pin, HIGH);
        _pinRead = _testFilter.filtered((int)_pinRead);
        return map(_pinRead, _minLevel, _maxLevel, -100, 100);
    }
private:
    GKalman _testFilter = GKalman(40, 40, 0.5); 
    byte _pin;
    int _pinRead;

    int _minLevel;
    int _maxLevel;
    int _centerLevel;

    char _percentSpeed;
};
