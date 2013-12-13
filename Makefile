ROOTCFLAGS    = $(shell root-config --cflags)
ROOTLIBS      = $(shell root-config --libs)
ROOTGLIBS     = $(shell root-config --glibs) -lTMVA

CXX           = g++
CXXFLAGS      = -g -fPIC -Wno-deprecated -O -ansi -D_GNU_SOURCE -g -O2
LD            = g++
LDFLAGS       = -g
SOFLAGS       = -shared


ARCH         := $(shell root-config --arch)
PLATFORM     := $(shell root-config --platform)


CXXFLAGS      += $(ROOTCFLAGS)
#CXX           += -I./
LIBS           = $(ROOTLIBS) 

NGLIBS         = $(ROOTGLIBS) 
NGLIBS        += -lMinuit -lMinuit2
GLIBS          = $(filter-out -lNew, $(NGLIBS))


INCLUDEDIR           = ./
OUTLIB               = ./lib/

.SUFFIXES: .cc,.C,.hh,.h
.PREFIXES: ./lib/

# DataFormats libs
$(OUTLIB)DataFormatsEventHeader.o: $(INCLUDEDIR)/DataFormats/include/EventHeader.hh
	$(CXX) $(CXXFLAGS) -c -I$(INCLUDEDIR) -o $(OUTLIB)DataFormatsEventHeader.o $<

$(OUTLIB)DataFormatsVecbosEvent.o: $(INCLUDEDIR)/DataFormats/include/VecbosEvent.hh
	$(CXX) $(CXXFLAGS) -c -I$(INCLUDEDIR) -o $(OUTLIB)DataFormatsVecbosEvent.o $<


# Analysis libs
$(OUTLIB)AnalysisVecbosEventContent.o: $(INCLUDEDIR)/Analysis/include/VecbosEventContent.h
	$(CXX) $(CXXFLAGS) -c -I$(INCLUDEDIR) -o $(OUTLIB)AnalysisVecbosEventContent.o $<

$(OUTLIB)AnalysisAnalysisBase.o: $(INCLUDEDIR)/Analysis/include/AnalysisBase.hh \
	$(OUTLIB)AnalysisVecbosEventContent.o
	$(CXX) $(CXXFLAGS) -c -I$(INCLUDEDIR) -o $(OUTLIB)AnalysisAnalysisBase.o $<

VecbosApp: $(INCLUDEDIR)/Analysis/src/VecbosApp.cc \
	$(OUTLIB)DataFormatsEventHeader.o \
	$(OUTLIB)DataFormatsVecbosEvent.o \
	$(OUTLIB)AnalysisVecbosEventContent.o \
	$(OUTLIB)AnalysisAnalysisBase.o
	$(CXX) $(CXXFLAGS) -I$(INCLUDEDIR) -ldl -o VecbosApp $(OUTLIB)/*.o $(GLIBS) $(LDFLAGS) $ $<

clean:
	rm -f lib/*o
