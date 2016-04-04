#include "breakpad_wrapper.h"
#include "client/linux/handler/exception_handler.h"
#include <stdio.h>

static bool breakpadDumpCallback(const google_breakpad::MinidumpDescriptor& descriptor,
                                                                void* context,
                                                                bool succeeded)
{
        /* Do the desired exit process here*/
        printf("breakpad Call back ..................................................");
        printf("Print descriptor path: %s\n", descriptor.path());
        return succeeded;
}


void breakpad_ExceptionHandler()

{

        printf("\t\t\t\t ********ENTER breakpad_ExceptionHandler****************** \n");
	static google_breakpad::ExceptionHandler* excHandler = NULL;
       if (excHandler)
       {
           printf("Handler exist \n");
           return ;
       }
	excHandler = new google_breakpad::ExceptionHandler(google_breakpad::MinidumpDescriptor("/tmp"), NULL, breakpadDumpCallback, NULL, true, -1);
        printf("\t\t\t\t ******** breakpad_ExceptionHandler EXIT****************** \n");
}

