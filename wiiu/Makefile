#-------------------------------------------------------------------------------
.SUFFIXES:
#-------------------------------------------------------------------------------

ifeq ($(strip $(DEVKITPRO)),)
$(error "Please set DEVKITPRO in your environment. export DEVKITPRO=<path to>/devkitpro")
endif

TOPDIR ?= $(CURDIR)
include $(DEVKITPRO)/wut/share/wut_rules

#-------------------------------------------------------------------------------
# TARGET is the name of the output
# BUILD is the directory where object files & intermediate files will be placed
# SOURCES is a list of directories containing source code
# INCLUDES is a list of directories containing header files
#-------------------------------------------------------------------------------
TARGET		     :=	 gng
BUILD		     :=	 build
SOURCES		     :=	 src
INCLUDES	     :=	 

# WUHB

WHUB_TOOL        :=  /opt/devkitpro/tools/bin/wuhbtool

WHUB_NAME        :=  Grab\'n\'Go
WHUB_SHORT_NAME  :=  $(WHUB_NAME)
WUHB_ICON        :=  content/assets/logo.png
WUHB_CONTENTS    :=  content

#-------------------------------------------------------------------------------
# options for code generation
#-------------------------------------------------------------------------------
CFLAGS		:=	-g -Wall -O2 -ffunction-sections \
			-ffast-math \
			$(MACHDEP)

CFLAGS		+=	$(INCLUDE) -D__WIIU__ -D__WUT__

CXXFLAGS	:=	$(CFLAGS) -std=gnu++14

ASFLAGS		:=	-g $(MACHDEP)
LDFLAGS		:=	-g $(MACHDEP) $(RPXSPECS) -Wl,-Map,$(notdir $*.map)

LIBS		:= -lSDL2_image -lSDL2  -lpng -lbz2 -lz -lwut -lm

#-------------------------------------------------------------------------------
# list of directories containing libraries, this must be the top level
# containing include and lib
#-------------------------------------------------------------------------------
LIBDIRS		:=	$(PORTLIBS) $(WUT_ROOT)


#-------------------------------------------------------------------------------
# no real need to edit anything past this point unless you need to add additional
# rules for different file extensions
#-------------------------------------------------------------------------------
ifneq ($(BUILD),$(notdir $(CURDIR)))
#-------------------------------------------------------------------------------

export OUTPUT	:=	$(CURDIR)/$(TARGET)
export TOPDIR	:=	$(CURDIR)

export VPATH	:=	$(foreach dir,$(SOURCES),$(CURDIR)/$(dir))
export DEPSDIR	:=	$(CURDIR)/$(BUILD)

CFILES		:=	$(foreach dir,$(SOURCES),$(notdir $(wildcard $(dir)/*.c)))
CPPFILES	:=	$(foreach dir,$(SOURCES),$(notdir $(wildcard $(dir)/*.cpp)))
SFILES		:=	$(foreach dir,$(SOURCES),$(notdir $(wildcard $(dir)/*.s)))

#-------------------------------------------------------------------------------
# use CXX for linking C++ projects, CC for standard C
#-------------------------------------------------------------------------------
ifeq ($(strip $(CPPFILES)),)
#-------------------------------------------------------------------------------
	export LD	:=	$(CC)
#-------------------------------------------------------------------------------
else
#-------------------------------------------------------------------------------
	export LD	:=	$(CXX)
#-------------------------------------------------------------------------------
endif
#-------------------------------------------------------------------------------

export SRCFILES		:=	$(CPPFILES) $(CFILES) $(SFILES)
export OFILES		:=	$(CPPFILES:.cpp=.o) $(CFILES:.c=.o) $(SFILES:.s=.o)
export INCLUDE		:=	$(foreach dir,$(INCLUDES),-I$(CURDIR)/$(dir)) \
				$(foreach dir,$(LIBDIRS),-I$(dir)/include) \
				-I$(CURDIR)/$(BUILD)

export LIBPATHS		:=	$(foreach dir,$(LIBDIRS),-L$(dir)/lib)

.PHONY: $(BUILD) clean all

#-------------------------------------------------------------------------------
all: $(BUILD) wuhb

dev: all test

$(BUILD): $(SRCFILES)
	@[ -d $@ ] || mkdir -p $@
	@$(MAKE) --no-print-directory -C $(BUILD) -f $(CURDIR)/Makefile

wuhb:
	cp -r ../assets/ content/
	@$(WHUB_TOOL) $(TARGET).rpx $(TARGET).wuhb --name=$(WHUB_NAME) --short-name=$(WHUB_SHORT_NAME) --icon=$(WUHB_ICON) --content=content

test:
	Cemu -g $(TARGET).rpx

#-------------------------------------------------------------------------------
clean:
	@echo clean ...
	@rm -fr $(BUILD) $(WUHB_CONTENTS)/assets $(TARGET).rpx $(TARGET).elf $(TARGET).wuhb

#-------------------------------------------------------------------------------
else
.PHONY:	all

DEPENDS		:=	$(OFILES:.o=.d)

#-------------------------------------------------------------------------------
# main targets
#-------------------------------------------------------------------------------
all		:	$(OUTPUT).rpx

$(OUTPUT).rpx	:	$(OUTPUT).elf

$(OUTPUT).elf	:	$(OFILES)

-include $(DEPENDS)

#-------------------------------------------------------------------------------
endif
#------------------------------------------------------------------------------- 