#ifndef  GSM_ABSTRACT_
#deffine GSM_ABSTRACT_

#include "serial_abstract.h"

enum MODEM_SIM_STATE{SIM_UNKNOWN, SIM_NOT_EXIST, SIM_OK};
enum MODEM_REG_STATE{MODEM_REG, MODEM_NOT_REG};
enum MODEM_SMSC{MODEM_SMSC_OK, MODEM_SMSC_FAILED};


class AbstractGsm{

public :

	struct ModemState{
		MODEM_REG_STATE 		regisetred;
		double					ant;
		MODEM_SIM_STATE			sim_state;
		MODEM_SMSC				modem_smsc_state;
	};

	AbstractSerial*				serial_port;

	virtual bool 				initModem() = 0;
	virtual bool 				initDataCnn() = 0;
	virtual bool 				closeDataCnn() = 0;
	virtual bool 				isModemOk() = 0;

	virtual double 				checkAnten() = 0;
	virtual MODEM_REG_STATE 	checkRegister() = 0;
	virtual bool 				checkDataCnn() = 0;
	virtual SIM_STATE 			checkSimCard() = 0;
	virtual MODEM_SMSC 			checkSmsc() = 0;
	virtual ModemState 			getModemState() = 0;
	
	virtual bool 				resetModem() = 0;
	virtual bool 				reRegister() = 0;
	
	virtual string 				readSimName() = 0;
	virtual string 				readOperatorName() = 0;
	virtual string 				readModemData() = 0;

	virtual bool				sendSms(string msg, string tel_no) = 0;
	virtual bool[]				sendSmsToAll(string msg, string[] tel_no) = 0;
	virtual string				readSmsAt(uint8_t loc) = 0;
	virtual string[]			readAllSms() = 0;

	virtual bool				deleteSmsat(int loc) = 0;
	virtual bool[]				deleteAllSms() = 0;
	
	

protected :

	virtual string				runAtCmd(string cmd, uint16_t time_out=0) = 0;
	ModemState					modem_state;
	



};	/* GSM_ABSTRACT_ */




#endif