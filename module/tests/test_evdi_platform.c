// SPDX-License-Identifier: GPL-2.0-only
/*
 * Copyright (c) 2026 DisplayLink (UK) Ltd.
 *
 * This file is subject to the terms and conditions of the GNU General Public
 * License v2. See the file COPYING in the main directory of this archive for
 * more details.
 */

#include <kunit/test.h>
#include <kunit/device.h>
#include "tests/evdi_test.h"

static void test_evdi_platform_add_devices_rejects_overflow(struct kunit *test)
{
	struct device *device = kunit_device_register(test, "evdi_platform_test");
	int ret;

	KUNIT_ASSERT_NOT_ERR_OR_NULL(test, device);
	ret = evdi_kunit_test_platform_add_overflow(device);
	KUNIT_EXPECT_EQ(test, ret, 0);
	kunit_device_unregister(test, device);
}

static struct kunit_case evdi_platform_test_cases[] = {
	KUNIT_CASE(test_evdi_platform_add_devices_rejects_overflow),
	{}
};

static struct kunit_suite evdi_platform_test_suite = {
	.name = "drm_evdi_platform_tests",
	.test_cases = evdi_platform_test_cases,
};

kunit_test_suite(evdi_platform_test_suite);
