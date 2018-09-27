/**
* @file 3dof_functions.cpp
*
* @brief OSVR 3DOF Functions
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

#include "./customhid.h"

// ----------------------------------------------------------------------------------
// Variables
// ----------------------------------------------------------------------------------


// ----------------------------------------------------------------------------------
// Function definitions
// ----------------------------------------------------------------------------------			

// ----------------------------------------------------------------------------------
// Public	
static const uint8_t _hidReportDescriptor[] PROGMEM = 	
{		
	0x06, 0xFF, 0xFF,  // Usage Page (Vendor Defined 0xFFFF)
	0x09, 0x01,        // Usage (0x01)
	0xA1, 0x01,        // Collection (Application)
				
	0x09, 0x02,        //   Usage (0x02)
	0x09, 0x03,        //   Usage (0x03)
	0x15, 0x00,        //   Logical Minimum (0)
	0x26, 0xFF, 0x00,  //   Logical Maximum (255)
	0x75, 0x08,        //   Report Size (8)
	0x95, 0x10,        //   Report Count (16)
	0x81, 0x02,        //   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position)

	0x09, 0x04,        //   Usage (0x04)
	0x09, 0x05,        //   Usage (0x05)
	0x15, 0x00,        //   Logical Minimum (0)
	0x26, 0xFF, 0x00,  //   Logical Maximum (255)
	0x75, 0x08,        //   Report Size (8)
	0x95, 0x40,        //   Report Count (64)
	0x91, 0x02,        //   Output (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile)

	0x09, 0x06,        //   Usage (0x06)
	0x09, 0x07,        //   Usage (0x07)
	0x15, 0x00,        //   Logical Minimum (0)
	0x26, 0xFF, 0x00,  //   Logical Maximum (255)
	0x75, 0x08,        //   Report Size (8)
	0x95, 0x10,        //   Report Count (16)
	0xB1, 0x02,        //   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile)
	0xC0,              // End Collection

	// 53 bytes
};
						 	
customHID_::customHID_(void)
{
	static HIDSubDescriptor node(_hidReportDescriptor, sizeof(_hidReportDescriptor));
	HID().AppendDescriptor(&node);
}

uint8_t customHID_ :: begin(void)
{		
}

void customHID_ :: setup(void)
{
}

void customHID_ :: end(void)
{
}
						
size_t customHID_ :: loop(void)
{					
	customHIDreport.HIDbyte1 = 0x00;
	customHIDreport.HIDbyte2 = 0x00;
	customHIDreport.HIDbyte3 = 0x00;
	customHIDreport.HIDbyte4 = 0x00;
	customHIDreport.HIDbyte5 = 0x00;
	customHIDreport.HIDbyte6 = 0x00;
	customHIDreport.HIDbyte7 = 0x00;
	customHIDreport.HIDbyte8 = 0x00;
	customHIDreport.HIDbyte9 = 0x00;
	customHIDreport.HIDbyte10 = 0x00;
	customHIDreport.HIDbyte11 = 0x00;
	customHIDreport.HIDbyte12 = 0x00;
	customHIDreport.HIDbyte13 = 0x00;
	customHIDreport.HIDbyte14 = 0x00;
	customHIDreport.HIDbyte15 = 0x00;
	customHIDreport.HIDbyte16 = 0x00;
	
	sendHIDReport(&customHIDreport);
}

// ----------------------------------------------------------------------------------
// Private
void customHID_ :: sendHIDReport(customHIDreport* report)
{
	// Endpoint 0x04
	USBDevice.send(0x04, report, sizeof(customHIDreport_t));
}

customHID_ custom_HID;