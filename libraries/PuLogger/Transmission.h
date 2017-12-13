#ifndef TRANSMISSION
#define TRANSMISSION

struct Transmission {
  int xmitterID = -1;
  int tempRaw = 0; // Make private, since it's in hundredth-units
  int humRaw = 0; // And this also
  Transmission(int xmitterID, double temp, double hum) : xmitterID(xmitterID), tempRaw(int(temp * 100)), humRaw(int(hum * 100)) {
    
  }
	int getRawTemp() {return (tempRaw + 5) / 10;}
	int getRawHum() {return (humRaw + 5) / 10;}
  float getTemp() { return float(tempRaw) / 10.0;}
  float getHum() { return float(humRaw) / 10.0;}
  bool changed( Transmission other, float tempHys, float humHys) {return (abs(getTemp() - other.getTemp()) > tempHys || abs(getHum() - other.getHum()) > humHys); }
  void printCSV() {printf("%i;%i;\n", int(getTemp()), int(getHum()),
              int(getHum() * 10) % 10);}
};

#endif