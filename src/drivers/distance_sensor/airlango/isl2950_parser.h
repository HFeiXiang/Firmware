/****************************************************************************
 *
 *   Copyright (c) 2014 PX4 Development Team. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name PX4 nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/

/**
 * @file sf0x_parser.cpp
 * @author Lorenz Meier <lm@inf.ethz.ch>
 *
 * Declarations of parser for the Lightware SF0x laser rangefinder series
 */

#pragma once

// frame start delimiter
#define TOF_SFD1      0xA5
#define TOF_SFD2      0x5A

typedef enum {
  TFS_NOT_STARTED = 0,
  TFS_GOT_SFD1,
  TFS_GOT_SFD2,
  TFS_GOT_DATA1,
  TFS_GOT_DATA2,
  TFS_GOT_CHECKSUM1,
  TFS_GOT_CHECKSUM2,
} TofFramingState;

enum IslWorkingMode {
  KEEP_HEIGHT = 0,
  NUM_WORKING_MODE
};


// SF0X STYLE
enum ISL2950_PARSE_STATE {
	ISL2950_PARSE_STATE0_UNSYNC = 0,
	ISL2950_PARSE_STATE1_SYNC,
	ISL2950_PARSE_STATE2_GOT_DIGIT0,
	ISL2950_PARSE_STATE3_GOT_DOT,
	ISL2950_PARSE_STATE4_GOT_DIGIT1,
	ISL2950_PARSE_STATE5_GOT_DIGIT2,
	ISL2950_PARSE_STATE6_GOT_CARRIAGE_RETURN
};


int isl2950_parser(const uint8_t* buffer, int length, bool* full_frame, int* dist);