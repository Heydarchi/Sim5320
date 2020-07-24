#ifndef  SERILA_ABSTRACT_
#deffine SERILA_ABSTRACT_

#include <string.h>

using namespace std;

enum SERIAL_PARITY{PARITY_NONE, PARITY_EVEN, PARITY_ODD};
enum SERIAL_STOP_BITS{STOP_BITS_1, STOP_BITS_1_5, STOP_BITS_2};
enum SERIAL_FLOW_CONTROL{FLOW_ENABLE, FLOW_DISABLE};

class AbstractSerial{

public :

	virtual bool 			setPortName(string port_name) = 0;
	virtual bool 			setParity(uint16_t baud) = 0;
	virtual bool 			setDataBits(uint8_t bits) = 0;
	virtual bool 			setStopBits(SERIAL_STOP_BITS stop_bits) = 0;
	virtual bool 			setFlowControl(SERIAL_FLOW_CONTROL flow_control) = 0;

	virtual bool 			openPort() = 0;
	virtual bool 			closePort() = 0;

	virtual uint16_t  		readData(uint16_t len, uint8_t &data_buffer, uint16_t time_out=0) = 0;
	virtual uint16_t  		readData(uint16_t &data_buffer, uint16_t time_out=0) = 0;
	virtual uint16_t  		writeData(uint16_t len, uint8_t &data_buffer) = 0;



	bool  					isPortOPen() {return is_open;}

protected:

	uint16_t				baud;
	uint8_t					bits;
	SERIAL_STOP_BITS		stop_bits;
	SERIAL_FLOW_CONTROL		flow_control;
	string					port_name;
	bool 					is_open;

};




#endif /*SERILA_ABSTRACT_*/