/**
* @file tracker.h
*
* @brief OSVR 3DOF Functions _H
*
* @copyright
* This library is free software; you can redistribute it and/or
* modify it under the terms of the GNU General Public
* License as published by the Free Software Foundation; either
* version 3.0 of the License, or (at your option) any later version.
*
* @copyright
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*
* @author Arduino LLC
* @author Adam Munich
*/
 
#ifndef _CUSTOMHID_H_
	#define _CUSTOMHID_H_

	#include <Arduino.h>
	#include <HID.h>

	#if !defined(_USING_HID)
		#error "Arduino variant does not have HID support"
	#endif
	
	
	// example 16 byte HID report
	typedef struct
	{
		uint8_t HIDbyte1;
		uint8_t HIDbyte2;
		uint8_t HIDbyte3;
		uint8_t HIDbyte4;
		uint8_t HIDbyte5;
		uint8_t HIDbyte6;
		uint8_t HIDbyte7;
		uint8_t HIDbyte8;
		uint8_t HIDbyte9;
		uint8_t HIDbyte10;
		uint8_t HIDbyte11;
		uint8_t HIDbyte12;
		uint8_t HIDbyte13;
		uint8_t HIDbyte14;
		uint8_t HIDbyte15;
		uint8_t HIDbyte16;
	} customHIDreport_t;

	class customHID_
	{
		private:
		customHIDreport_t customHIDreport;
		void sendHIDReport(customHIDreport_t* report);
		
		public:
		customHID_(void);
		uint8_t begin(void);
		void setup();
		void end(void);
		size_t loop(void);		
	};
	extern customHID_ custom_HID;	

		
#endif
