#ifndef PBmotorDriver_h
#define PBmotorDriver_h

#include <Arduino.h>

class PBmotorDriver
{
  public:
    static void setLMpower(int power);
    static void setRMpower(int power);
    static void setPowers(int LMpower, int RMpower);

  private:
    static void initPinsAndMaybeTimer();
    static const unsigned char _LMDIR;
    static const unsigned char _RMDIR;
    static const unsigned char _LMPWM;
    static const unsigned char _RMPWM;
    
    static inline void init()
    {
      static boolean initialized = false;

      if (!initialized)
      {
        initialized = true;
        initPinsAndMaybeTimer();
      }
    }
};
#endif
