//
//  test1.c
//  test1
//
//  Created by la-hien.nguyen on 8.4.2020.
//  Copyright © 2020 la-hien.nguyen. All rights reserved.
//

#include <mach/mach_types.h>
#include <libkern/libkern.h>

kern_return_t test1_start(kmod_info_t * ki, void *d);
kern_return_t test1_stop(kmod_info_t *ki, void *d);

kern_return_t test1_start(kmod_info_t * ki, void *d)
{
    printf("Start Test 1 \n");
    return KERN_SUCCESS;
}

kern_return_t test1_stop(kmod_info_t *ki, void *d)
{
    printf("Test1 DONE \n");
    return KERN_SUCCESS;
}
