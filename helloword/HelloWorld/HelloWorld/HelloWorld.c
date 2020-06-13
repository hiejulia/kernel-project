//
//  HelloWorld.c
//  HelloWorld
//
//  Created by la-hien.nguyen on 13.6.2020.
//  Copyright © 2020 com.osxkernel. All rights reserved.
//

#include <mach/mach_types.h>
// Header file 
#include <libkern/libkern.h>


kern_return_t HelloWorld_start(kmod_info_t * ki, void *d);
kern_return_t HelloWorld_stop(kmod_info_t *ki, void *d);

kern_return_t HelloWorld_start(kmod_info_t * ki, void *d)
{
    printf("Hello world\n");
    return KERN_SUCCESS;
}

kern_return_t HelloWorld_stop(kmod_info_t *ki, void *d)
{
    printf("Goodbye world\n");
    
    return KERN_SUCCESS;
}
