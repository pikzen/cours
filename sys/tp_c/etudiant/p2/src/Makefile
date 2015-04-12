#------------------------------------------------------------------------
# les variables
#------------------------------------------------------------------------

# fichiers d'entête openCV pour compilation
INC	 = -I/usr/include/opencv2

# bibliothèques openCV pour édition de liens
LIBS = /usr/lib/x86_64-linux-gnu/libopencv_calib3d.so /usr/lib/x86_64-linux-gnu/libopencv_contrib.so \
       /usr/lib/x86_64-linux-gnu/libopencv_core.so /usr/lib/x86_64-linux-gnu/libopencv_features2d.so \
       /usr/lib/x86_64-linux-gnu/libopencv_flann.so /usr/lib/x86_64-linux-gnu/libopencv_gpu.so \
       /usr/lib/x86_64-linux-gnu/libopencv_highgui.so /usr/lib/x86_64-linux-gnu/libopencv_imgproc.so \
       /usr/lib/x86_64-linux-gnu/libopencv_legacy.so /usr/lib/x86_64-linux-gnu/libopencv_ml.so \
       /usr/lib/x86_64-linux-gnu/libopencv_objdetect.so /usr/lib/x86_64-linux-gnu/libopencv_ocl.so \
       /usr/lib/x86_64-linux-gnu/libopencv_photo.so /usr/lib/x86_64-linux-gnu/libopencv_stitching.so \
       /usr/lib/x86_64-linux-gnu/libopencv_superres.so /usr/lib/x86_64-linux-gnu/libopencv_ts.so \
       /usr/lib/x86_64-linux-gnu/libopencv_video.so /usr/lib/x86_64-linux-gnu/libopencv_videostab.so \
       -lopencv_calib3d -lopencv_contrib -lopencv_core -lopencv_features2d -lopencv_flann -lopencv_gpu \
       -lopencv_highgui -lopencv_imgproc -lopencv_legacy -lopencv_ml -lopencv_objdetect -lopencv_ocl \
       -lopencv_photo -lopencv_stitching -lopencv_superres -lopencv_ts -lopencv_video -lopencv_videostab \
       -ldl

# compilateur C++
CXX	 = g++

# options de compilation
CXXFLAGS = -c -Wall -ggdb $(INC) -I../include

# options d'édition de liens
LDFLAGS  = $(LIBS)

# tous les fichiers source C++ du répertoire courant
SRC1	 = $(wildcard *.cc)
SRC2	 = $(wildcard *.cpp)

# les fichiers objet correspondant
OBJ	 = $(patsubst %.cc,../bin/%.o,$(SRC1)) $(patsubst %.cpp,../bin/%.o,$(SRC2))

# le nom du programme exécutable
EXEC	 = ../bin/imagesystem

#------------------------------------------------------------------------
# les règles d'action (compilation, édition de liens, ...)
#------------------------------------------------------------------------

all : $(EXEC)

# compilation : produire un objet à partir d'un source
../bin/%.o : %.cc
	$(CXX) -c $(CXXFLAGS) $< -o $@ -ldl

# idem
../bin/%.o : %.cpp
	$(CXX) -c $(CXXFLAGS) $< -o $@ -ldl

# édition de liens : produire l'exécutable à partir des objets
$(EXEC) : $(OBJ)
	$(CXX) -export-dynamic $^ -o $@ -ldl `pkg-config opencv --cflags --libs`

# un peu de nettoyage
clean :
	-@rm -f *~ ../bin/*.o $(EXEC)
