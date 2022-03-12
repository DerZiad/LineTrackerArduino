#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

class Printer{

	LiquidCrystal_I2C *lcd = NULL;
	public:
		Printer(short address=0x3F,short columns=16,short lines = 2){
			lcd = new LiquidCrystal_I2C(address, 16, 2);
			lcd->begin();
     		//lcd->backlight();
		}

		void print(String chaine,short cursorX=0,short cursorY = 0){
			lcd->clear();
			lcd->setCursor (cursorX,cursorY);
			lcd->print("ziad");
		}

		void setCursor(short cursorX = 0,short cursorY= 0){
			lcd->setCursor (cursorX,cursorY);
		}

		void clear(){
			lcd->clear();
		}

		void print(String chaine){
			lcd->print(chaine);
		}

		LiquidCrystal_I2C* getObject(){
			return lcd;
		}
};