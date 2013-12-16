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
NGLIBS        += -lMinuit 
GLIBS          = $(filter-out -lNew, $(NGLIBS))


INCLUDEDIR           = ./
OUTLIB               = ./lib/

.SUFFIXES: .cc,.C,.hh,.h
.PREFIXES: ./lib/

# DataFormats libs
$(OUTLIB)DataFormatsEventHeader.o: $(INCLUDEDIR)/DataFormats/src/EventHeader.cc
	$(CXX) $(CXXFLAGS) -c -I$(INCLUDEDIR) -o $(OUTLIB)DataFormatsEventHeader.o $<
$(OUTLIB)DataFormatsVecbosEvent.o: $(INCLUDEDIR)/DataFormats/src/VecbosEvent.cc
	$(CXX) $(CXXFLAGS) -c -I$(INCLUDEDIR) -o $(OUTLIB)DataFormatsVecbosEvent.o $<
$(OUTLIB)DataFormatsCandidate.o: $(INCLUDEDIR)/DataFormats/src/Candidate.cc
	$(CXX) $(CXXFLAGS) -c -I$(INCLUDEDIR) -o $(OUTLIB)DataFormatsCandidate.o $<
$(OUTLIB)DataFormatsRecoCandidate.o: $(INCLUDEDIR)/DataFormats/src/RecoCandidate.cc \
	$(OUTLIB)DataFormatsCandidate.o
	$(CXX) $(CXXFLAGS) -c -I$(INCLUDEDIR) -o $(OUTLIB)DataFormatsRecoCandidate.o $<
$(OUTLIB)DataFormatsTrack.o: $(INCLUDEDIR)/DataFormats/src/Track.cc \
	$(OUTLIB)DataFormatsRecoCandidate.o
	$(CXX) $(CXXFLAGS) -c -I$(INCLUDEDIR) -o $(OUTLIB)DataFormatsTrack.o $<

# Analysis libs
$(OUTLIB)AnalysisVecbosEventContent.o: $(INCLUDEDIR)/Analysis/src/VecbosEventContent.C
	$(CXX) $(CXXFLAGS) -c -I$(INCLUDEDIR) -o $(OUTLIB)AnalysisVecbosEventContent.o $<
$(OUTLIB)AnalysisAnalysisBase.o: $(INCLUDEDIR)/Analysis/src/AnalysisBase.cc \
	$(OUTLIB)AnalysisVecbosEventContent.o
	$(CXX) $(CXXFLAGS) -c -I$(INCLUDEDIR) -o $(OUTLIB)AnalysisAnalysisBase.o $<

VecbosApp: $(INCLUDEDIR)/Analysis/src/VecbosApp.cc \
	$(OUTLIB)AnalysisVecbosEventContent.o \
	$(OUTLIB)AnalysisAnalysisBase.o \
	$(OUTLIB)DataFormatsVecbosEvent.o \
	$(OUTLIB)DataFormatsEventHeader.o \
	$(OUTLIB)DataFormatsTrack.o
	$(CXX) $(CXXFLAGS) -I$(INCLUDEDIR) -ldl -o VecbosApp $(OUTLIB)/*.o $(GLIBS) $(LDFLAGS) $ $<

clean:
	rm -f lib/*o
