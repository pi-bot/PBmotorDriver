#ifndef PBmotorDriver_h
#define PBmotorDriver_h

#include <Arduino.h>

class PBmotorDriver
{
  public:
    static void setLMpwr(int pwr);
    static void setRMpwr(int pwr);
    static void setPwrs(int LMpwr, int RMpwr);

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
