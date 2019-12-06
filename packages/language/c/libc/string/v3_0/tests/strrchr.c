//=================================================================
//
//        strrchr.c
//
//        Testcase for C library strrchr()
//
//=================================================================
// ####ECOSGPLCOPYRIGHTBEGIN####                                            
// -------------------------------------------                              
// This file is part of eCos, the Embedded Configurable Operating System.   
// Copyright (C) 1998, 1999, 2000, 2001, 2002 Free Software Foundation, Inc.
//
// eCos is free software; you can redistribute it and/or modify it under    
// the terms of the GNU General Public License as published by the Free     
// Software Foundation; either version 2 or (at your option) any later      
// version.                                                                 
//
// eCos is distributed in the hope that it will be useful, but WITHOUT      
// ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or    
// FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License    
// for more details.                                                        
//
// You should have received a copy of the GNU General Public License        
// along with eCos; if not, write to the Free Software Foundation, Inc.,    
// 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.            
//
// As a special exception, if other files instantiate templates or use      
// macros or inline functions from this file, or you compile this file      
// and link it with other works to produce a work based on this file,       
// this file does not by itself cause the resulting work to be covered by   
// the GNU General Public License. However the source code for this file    
// must still be made available in accordance with section (3) of the GNU   
// General Public License v2.                                               
//
// This exception does not invalidate any other reasons why a work based    
// on this file might be covered by the GNU General Public License.         
// -------------------------------------------                              
// ####ECOSGPLCOPYRIGHTEND####                                              
//=================================================================
//#####DESCRIPTIONBEGIN####
//
// Author(s):     ctarpy, jlarmour
// Contributors:  
// Date:          2000-04-30
// Description:   Contains testcode for C library strrchr() function
//
//
//####DESCRIPTIONEND####

// INCLUDES

#include <pkgconf/isoinfra.h>
#include <string.h>
#include <cyg/infra/testcase.h>


// FUNCTIONS

// Functions to avoid having to use libc strings

static char *my_strcpy(char *s1, const char *s2)
{
    while (*s2 != '\0') {
        *(s1++) = *(s2++);
    }
    *s1 = '\0';

    return s1; 
} // my_strcpy()


#if CYGINT_ISO_MAIN_STARTUP
int main( int argc, char *argv[] )
#else
void cyg_user_start(void)
#endif
{
    char x[300];
    char *ret;

    CYG_TEST_INIT();

    CYG_TEST_INFO("Starting tests from testcase " __FILE__ " for C library "
                  "strrchr() function");
    CYG_TEST_INFO("This testcase provides simple basic tests");

    // Check 1
    my_strcpy(x, "I will not have my fwends widiculed by the common soldiewy");
    ret = strrchr(x, (int) 'c');
    CYG_TEST_PASS_FAIL( (ret == &x[43]), "Simple strrchr()" );

    // Check 2
    my_strcpy(x, "Not bad for a little fur ball. You! Stay here.");
    ret = strrchr(x, (int) 'z');
    CYG_TEST_PASS_FAIL( (ret == NULL), "Character not found");

    // Check 3 (boundary condition)
    my_strcpy(x, "");
    ret = strrchr(x, (int) 'c');
    CYG_TEST_PASS_FAIL( (ret == NULL), "String to search empty" );

    // Check 4 (boundary condition)
    my_strcpy(x, "zx");
    ret = strrchr(x, '\0');
    CYG_TEST_PASS_FAIL( (ret == &x[2]), "Null search character" );

    // Check 5 (boundary condition)
    my_strcpy(x, "");
    ret = strrchr(x, '\0');
    CYG_TEST_PASS_FAIL( (ret == x), "String empty and null search char" );


//    CYG_TEST_NA("Testing is not applicable to this configuration");

    CYG_TEST_FINISH("Finished tests from testcase " __FILE__ " for C library "
                    "strrchr() function");

} // main()

// EOF strrchr.c