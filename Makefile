#-------��Ҫ���ݲ�ͬƽ̨���õ�ֵ----------
#make,gmake
#SYSֵ���ݲ�ͬƽ̨�Ķ�win2000,winxp,linux,bsd47,bsd54,bsd70
SYS = winxp
#LV�ǿ�İ汾����ͬ�汾stl��hash����ͷ�ļ����ܲ�ͬ,ȡֵ-D LV���
LV = 
#V_DEBUG�Ƿ���԰汾,-D DEBUG,-D NDEBUG
V_DEBUG = -D DEBUG
#--------end ��Ҫ���ݲ�ͬƽ̨���õ�ֵ-----
CC = g++
OPTIONS = -o3
DEBUG = $(V_DEBUG) -g
DIR_LIB = gms/lib/
EXE = zsye
#MAKE=gmake


SOU_MAIN = main.cpp
#OBJECTS = main.o backprocess.o class_webserver.o class_request.o ini/class_ini.o gms/libgms.a
OBJECTS = main.o commu/libcm.a gms/libgms.a kp/lib_kp.a
include gms/Makefile.lib
complete:$(EXE)
	@echo "make complete"
$(EXE):$(OBJECTS)
	$(CC) $(OPTIONS) $(DEBUG) -o $(EXE) $(OBJECTS) $(LINKLIB) $(LINKS) $(LIBS)
main.o:main.cpp
	$(CC) $(DEBUG) -o $@ -c main.cpp $(INCS) $(CXXINCS)
backprocess.o:backprocess.cpp
	$(CC) $(DEBUG) -o $@ -c backprocess.cpp
ini/class_ini.o:ini/class_ini.cpp
	$(CC) $(DEBUG) -o $@ -c ./ini/class_ini.cpp
class_webserver.o:class_webserver.cpp
	$(CC) $(DEBUG) -o $@ -c class_webserver.cpp
class_request.o:class_request.cpp
	$(CC) $(DEBUG) -o $@ -c class_request.cpp
kp/lib_kp.a:
	cd kp;$(MAKE) lib_kp.a;cd ..;
commu/libcm.a:
	@echo "make libcm.a"
	cd commu;$(MAKE) libcm.a;cd ..;
gms/libgms.a:
	@echo "make libgms.a"
	cd gms;$(MAKE) libgms.a;cd ..;
cleana:
	rm -rf commu/libcm.a gms/libgms.a;
cleanen:
	$(MAKE) -C gms/en cleano;rm -rf gms/libgms.a;
clean:
	rm -f $(OBJECTS) $(EXE) *.exe;cd gms;$(MAKE) clean;cd ..;cd kp;$(MAKE) clean;cd ..;
	@echo "clean is complete"
