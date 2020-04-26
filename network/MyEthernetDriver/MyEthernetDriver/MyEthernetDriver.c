//
//  MyEthernetDriver.c
//  MyEthernetDriver
//
//  Created by la-hien.nguyen on 26.4.2020.
//  Copyright © 2020 la-hien.nguyen. All rights reserved.
//

#include <mach/mach_types.h>

kern_return_t MyEthernetDriver_start(kmod_info_t * ki, void *d);
kern_return_t MyEthernetDriver_stop(kmod_info_t *ki, void *d);

kern_return_t MyEthernetDriver_start(kmod_info_t * ki, void *d)
{
    return KERN_SUCCESS;
}

kern_return_t MyEthernetDriver_stop(kmod_info_t *ki, void *d)
{
    return KERN_SUCCESS;
}
