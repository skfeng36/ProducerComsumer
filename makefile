
.PHONY: all clean

SRC_DIR = ./src


all:
	@if [ -d "./conf" ]; then   echo "./conf------------yes"; else   mkdir "./conf"; fi
	@if [ -d "./bin" ]; then   echo "./bin------------yes"; else   mkdir "./bin"; fi
	make -C $(SRC_DIR)


install:
	@if [ -d "/usr/local/skcode/bin" ];         then  echo "/usr/local/skcode/bin------------ yes"; else   mkdir -p "/usr/local/skcode/bin";        fi
	@if [ -d "/usr/local/skcode/conf" ];    then  echo "/usr/local/skcode/conf------- yes"; else   mkdir "/usr/local/skcode/conf";      fi
	@if [ -d "/usr/local/skcode/logs" ];    then  echo "/usr/local/skcode/logs------- yes"; else   mkdir "/usr/local/skcode/logs";      fi

	@chmod 777 /usr/local/skcode/logs

	make -C $(SRC_DIR) install

	cp ./bin/* /usr/local/skcode/bin
	cp ./conf/* /usr/local/skcode/conf

clean:
	make -C $(SRC_DIR) clean
	rm   -f ./bin/*

