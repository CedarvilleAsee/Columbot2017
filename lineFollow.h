#ifndef LINE
#define LINE



class lineSensor{
  public:
  //getters
  int getnumPinsOnLine();
  bool* getisSensorsOnLine();
  void update();//a setter (kinda)

  turn steer();
  lineSensor();
  
  private:
  turn steerMode;
  int numSensorsOnLine;
  bool isSensorsOnLine[8];
}



#endif LINE

