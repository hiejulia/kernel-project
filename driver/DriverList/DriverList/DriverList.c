//
//  DriverList.c
//  DriverList
//
//  Created by la-hien.nguyen on 13.6.2020.
//  Copyright © 2020 com.osxkernel. All rights reserved.
//

#include <mach/mach_types.h>
#include <CoreFoundation/CoreFoundation.h>
#include <IOKit/IOKitLib.h>

kern_return_t DriverList_start(kmod_info_t * ki, void *d);
kern_return_t DriverList_stop(kmod_info_t *ki, void *d);

kern_return_t DriverList_start(kmod_info_t * ki, void *d)
{
    return KERN_SUCCESS;
}

kern_return_t DriverList_stop(kmod_info_t *ki, void *d)
{
    return KERN_SUCCESS;
}
