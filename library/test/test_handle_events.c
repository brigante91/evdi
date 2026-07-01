// SPDX-License-Identifier: LGPL-2.1-or-later
// Copyright (c) 2026 DisplayLink (UK) Ltd.

#include <assert.h>
#include <stdio.h>
#include <libdrm/drm.h>
#include "evdi_lib.h"

int main(void)
{
	const unsigned int hdr = sizeof(struct drm_event);

	assert(evdi_unit_test_drm_event_bounds_valid(hdr + 16, 0, hdr));
	assert(!evdi_unit_test_drm_event_bounds_valid(hdr, 0, 0));
	assert(!evdi_unit_test_drm_event_bounds_valid(hdr, 0, hdr + 1));
	assert(!evdi_unit_test_drm_event_bounds_valid(hdr + 4, 0, hdr + 8));

	printf("test_handle_events: ok\n");
	return 0;
}
