#ifndef DEBOUNCE
#define DEBOUNCE
class Debouncer{
  public:
    Debouncer();
    void begin(int pinN);
	  int getState();
};
#endif
