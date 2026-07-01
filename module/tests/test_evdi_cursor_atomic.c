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
#include "evdi_drm_drv.h"
#include "tests/evdi_test.h"

static void test_evdi_cursor_atomic_update_null_fb(struct kunit *test)
{
	struct evdi_test_data *data = kunit_kzalloc(test, sizeof(*data), GFP_KERNEL);
	struct drm_device *dev;
	struct drm_plane *plane;
	bool has_cursor = false;

	evdi_test_data_init(test, data);
	dev = evdi_drm_device_create(data->parent);
	KUNIT_ASSERT_NOT_ERR_OR_NULL(test, dev);

	drm_for_each_plane(plane, dev) {
		if (plane->type == DRM_PLANE_TYPE_CURSOR) {
			has_cursor = true;
			break;
		}
	}

	if (!has_cursor) {
		kunit_skip(test, "cursor plane not available on this kernel");
		goto out;
	}

	evdi_kunit_cursor_atomic_update_null_fb(dev);

out:
	evdi_drm_device_remove(dev);
	evdi_test_data_exit(test, data);
	kunit_kfree(test, test->priv);
}

static struct kunit_case evdi_cursor_atomic_test_cases[] = {
	KUNIT_CASE(test_evdi_cursor_atomic_update_null_fb),
	{}
};

static struct kunit_suite evdi_cursor_atomic_test_suite = {
	.name = "drm_evdi_cursor_atomic_tests",
	.test_cases = evdi_cursor_atomic_test_cases,
};

kunit_test_suite(evdi_cursor_atomic_test_suite);
