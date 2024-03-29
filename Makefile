# Copyright 2016, Pablo Ridolfi
# All rights reserved.
#
# This file is part of Workspace.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are met:
#
# 1. Redistributions of source code must retain the above copyright notice,
#    this list of conditions and the following disclaimer.
#
# 2. Redistributions in binary form must reproduce the above copyright notice,
#    this list of conditions and the following disclaimer in the documentation
#    and/or other materials provided with the distribution.
#
# 3. Neither the name of the copyright holder nor the names of its
#    contributors may be used to endorse or promote products derived from this
#    software without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
# AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
# IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
# ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
# LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
# CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
# SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
# INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
# CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
# ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
# POSSIBILITY OF SUCH DAMAGE.

# application name
PROJECT_NAME := $(notdir $(PROJECT))

# Modules needed by the application
PROJECT_MODULES := modules/$(TARGET)/sapi \
                   modules/$(TARGET)/base \
                   modules/$(TARGET)/board \
                   modules/$(TARGET)/chip

# source files folder
PROJECT_SRC_FOLDERS := $(PROJECT)/src \
                       $(PROJECT)/gen \
                      $(PROJECT)/GENERADOR_FRECUENCIA
#                     $(PROJECT)/SCT_1_1                      
#                     $(PROJECT)/SCT_1_2
#                     $(PROJECT)/SCT_2_1
#                     $(PROJECT)/SCT_2_2
#                     $(PROJECT)/SCT_3_1
#                     $(PROJECT)/SCT_3_2
#                     $(PROJECT)/GENERADOR_FRECUENCIA
#                     $(PROJECT)/PUERTA_CORREDIZA
#                     $(PROJECT)/PORTON_DE_COCHERA
#                     $(PROJECT)/ESCALERA_MECANICA
#                     $(PROJECT)/HORNO_MICROONDAS

# header files folder
PROJECT_INC_FOLDERS := $(PROJECT)/inc \
                       $(PROJECT)/gen \
	                   $(PROJECT)/GENERADOR_FRECUENCIA
#                     $(PROJECT)/SCT_1_1                      
#                     $(PROJECT)/SCT_1_2
#                     $(PROJECT)/SCT_2_1
#                     $(PROJECT)/SCT_2_2
#                     $(PROJECT)/SCT_3_1
#                     $(PROJECT)/SCT_3_2
#                     $(PROJECT)/GENERADOR_FRECUENCIA
#                     $(PROJECT)/PUERTA_CORREDIZA
#                     $(PROJECT)/PORTON_DE_COCHERA
#                     $(PROJECT)/ESCALERA_MECANICA
#                     $(PROJECT)/HORNO_MICROONDAS

# source files
PROJECT_C_FILES := $(wildcard $(PROJECT)/src/*.c) \
                   $(wildcard $(PROJECT)/gen/*.c) \
				   $(wildcard $(PROJECT)/GENERADOR_FRECUENCIA/*.c)
#				   $(wildcard $(PROJECT)/SCT_1_1/*.c)
#				   $(wildcard $(PROJECT)/SCT_1_2/*.c)
#				   $(wildcard $(PROJECT)/SCT_2_1/*.c)
#				   $(wildcard $(PROJECT)/SCT_2_2/*.c)
#				   $(wildcard $(PROJECT)/SCT_3_1/*.c)
#				   $(wildcard $(PROJECT)/SCT_3_2/*.c) 
#				   $(wildcard $(PROJECT)/GENERADOR_FRECUENCIA/*.c) 
#				   $(wildcard $(PROJECT)/PUERTA_CORREDIZA/*.c) 
#				   $(wildcard $(PROJECT)/PORTON_DE_COCHERA/*.c) 
#				   $(wildcard $(PROJECT)/ESCALERA_MECANICA/*.c) 
#				   $(wildcard $(PROJECT)/HORNO_MICROONDAS/*.c) 
				   
PROJECT_ASM_FILES := $(wildcard $(PROJECT)/src/*.S)
