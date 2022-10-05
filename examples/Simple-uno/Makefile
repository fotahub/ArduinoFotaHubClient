VERBOSE ?= 
ifdef VERBOSE
Q = 
else
Q = @
endif

vecho = @echo
toCygpath = $(subst \,/,$(1))
hasGitUrlPrefix = $(findstring ://,$(1))
stripGitUrlPrefix = $(if $(call hasGitUrlPrefix,$(1)),$(lastword $(subst /, ,$(1))),$(1))
hasVersionSuffix = $(findstring @,$(1))
stripVersionSuffix = $(if $(call hasVersionSuffix,$(1)),$(firstword $(subst @, ,$(1))),$(1))
extractLibraryName = $(call stripVersionSuffix,$(call stripGitUrlPrefix,$(1)))

ifeq ($(OS),Windows_NT)
MSYS64_HOME ?= /c/msys64
MSYS64_HOME := $(call toCygpath,$(MSYS64_HOME))
BASH = $(MSYS64_HOME)/usr/bin/bash
else
BASH = /bin/bash
endif


ARDUINO_CLI_HOME ?= $(if $(filter Windows_NT,$(OS)),/c/Arduino/arduino-cli,$(HOME)/local/bin)
ARDUINO_CLI_HOME := $(call toCygpath,$(ARDUINO_CLI_HOME))
ARDUINO_CLI_CMD = $(if $(wildcard $(ARDUINO_CLI_HOME)),$(ARDUINO_CLI_HOME)/arduino-cli,arduino-cli)
export ARDUINO_DIRECTORIES_USER ?= $(shell $(ARDUINO_CLI_CMD) config dump | sed -n 's/\s*user: //p')
export ARDUINO_LIBRARY_ENABLE_UNSAFE_INSTALL = true
ARDUINO_PREINSTALLED_LIBRARIES_ROOT = $(ARDUINO_SKETCH_DIR)/../../..
ARDUINO_LIBRARIES_ROOT = $(ARDUINO_DIRECTORIES_USER)/libraries
ARDUINO_CORE_CACHE_DIR ?= $(ARDUINO_DIRECTORIES_USER)/arduino-core-cache
ARDUINO_SKETCH_DIR = $(abspath $(dir $(firstword $(MAKEFILE_LIST))))

BUILDROOT ?= 
OROOT ?= $(if $(BUILDROOT),$(BUILDROOT),$(ARDUINO_SKETCH_DIR)/build)

ARDUINO_VENDOR = arduino
ARDUINO_ARCHITECTURE = avr
ARDUINO_CORE = $(ARDUINO_VENDOR):$(ARDUINO_ARCHITECTURE)
ARDUINO_CORE_AVAILABLE = $(if $(shell $(ARDUINO_CLI_CMD) core list | grep $(ARDUINO_CORE)),true,)
ARDUINO_BOARD = uno
ARDUINO_PORT ?= $(shell $(ARDUINO_CLI_CMD) board list | sed -rn '2 s/(\S+).+/\1/p')
ARDUINO_PREINSTALLED_LIBRARIES = ArduinoFotaHubClient
ARDUINO_LIBRARIES = https://github.com/khoih-prog/WiFiNINA_Generic https://github.com/khoih-prog/TimerInterrupt_Generic
ARDUINO_SKETCH_NAME = Simple-uno

EXTRA_CLEAN_AFKTS ?= 

.PHONY: all allDependencies clean cleanDependencies cleanAll

all: core allDependencies
	$(Q) $(ARDUINO_CLI_CMD) compile --fqbn $(ARDUINO_VENDOR):$(ARDUINO_ARCHITECTURE):$(ARDUINO_BOARD) $(addprefix --library $(ARDUINO_PREINSTALLED_LIBRARIES_ROOT)/,$(ARDUINO_PREINSTALLED_LIBRARIES)) $(addprefix --library $(ARDUINO_LIBRARIES_ROOT)/,$(foreach lib, $(sort $(ARDUINO_LIBRARIES)), $(call extractLibraryName,$(lib)))) --build-path $(OROOT) --build-cache-path $(ARDUINO_CORE_CACHE_DIR) --verbose $(ARDUINO_SKETCH_DIR)/$(ARDUINO_SKETCH_NAME).ino

core: 
ifneq ($(ARDUINO_CORE_AVAILABLE),true)
	$(Q) $(ARDUINO_CLI_CMD) core install $(ARDUINO_CORE)
endif

allDependencies: $(addprefix $(ARDUINO_LIBRARIES_ROOT)/,$(foreach lib, $(sort $(ARDUINO_LIBRARIES)),$(call extractLibraryName,$(lib))))

define InstallArduinoLibraries
$$(addprefix $$(ARDUINO_LIBRARIES_ROOT)/,$(call extractLibraryName,$(1))): 
	$$(Q) $$(ARDUINO_CLI_CMD) lib install $(if $(call hasGitUrlPrefix,$(1)),--git-url $(1),$(1))
endef
$(foreach lib, $(sort $(ARDUINO_LIBRARIES)), $(eval $(call InstallArduinoLibraries,$(lib))))

clean: 
	$(if $(wildcard $(filter-out . ..,$(OROOT))),$(vecho) "RM $(filter-out . ..,$(OROOT))",)
	$(Q) $(RM) -r $(filter-out . ..,$(OROOT))
	$(if $(wildcard $(filter-out . ..,$(EXTRA_CLEAN_AFKTS))),$(vecho) "RM $(filter-out . ..,$(EXTRA_CLEAN_AFKTS))",)
	$(Q) $(RM) -r $(filter-out . ..,$(EXTRA_CLEAN_AFKTS))

cleanDependencies: 
	$(Q) $(RM)-r $(addprefix $(ARDUINO_LIBRARIES_ROOT)/,$(foreach lib, $(sort $(ARDUINO_LIBRARIES)), $(call extractLibraryName,$(lib))))

cleanAll: clean cleanDependencies

upload: all
ifneq ($(ARDUINO_PORT),)
	$(Q) $(ARDUINO_CLI_CMD) upload --fqbn $(ARDUINO_VENDOR):$(ARDUINO_ARCHITECTURE):$(ARDUINO_BOARD) --input-file $(OROOT)\$(ARDUINO_SKETCH_NAME).ino.hex --port $(ARDUINO_PORT) --verify --verbose 
else
	$(error Please connect your $(ARDUINO_BOARD) board to your laptop or computer using a USB cable, and then rerun this command)
endif

monitor: 
ifneq ($(ARDUINO_PORT),)
	$(Q) $(BASH) -c 'trap "exit 0" INT; $(ARDUINO_CLI_CMD) monitor --port $(ARDUINO_PORT)'
else
	$(error Please connect your $(ARDUINO_BOARD) board to your laptop or computer using a USB cable, and then rerun this command)
endif

