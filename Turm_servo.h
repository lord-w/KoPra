class Turm_servo{
  public:
    void    initServo();
    uint_8  pitch(uint_8 pitch);
  private:
    Servo   myServo;
    uint_8  currentPos;
}