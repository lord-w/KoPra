class FireControl{

  public: 
    void    Zielerfassung(TOF_sensor sensor, Turm_servo servo);
    void    Feuern(uint_8 firingAngle);
    uint_16 calculateFiringAngle(uint_16 distance, uint_8 currentAngle);
  private:
    void    sprayNPray(uint_8* firingAngle);

}