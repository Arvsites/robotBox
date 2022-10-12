class Motor
{
public:
  Motor(byte levelPin, byte directionPin){
    pinMode(levelPin, OUTPUT);
    pinMode(directionPin, OUTPUT);
    _levelPin = levelPin;
    _directionPin = directionPin;
  };

  void go(int speed){ //in percent
    char blindSpot = 7;
    _speed = speed;
    if (_speed > 100){_speed = 100;}
    if (_speed < -100){_speed = -100;}
    // _speed = _speed;
    if (_speed > blindSpot)
    {
      digitalWrite(_directionPin, LOW);
      analogWrite(_levelPin, _speed);
    }
    else if (_speed < - blindSpot)
    {
      digitalWrite(_directionPin, HIGH);
      analogWrite(_levelPin, - _speed );
    }
    else {
      digitalWrite(_directionPin, LOW);
      analogWrite(_levelPin, 0);
    }
//    Serial.print(_speed);
//    Serial.println(_speed);
  }
private:
  int _speed;
  byte _direction;
  byte _levelPin;
  byte _directionPin;
};
