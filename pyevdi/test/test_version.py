# Copyright (c) 2022 DisplayLink (UK) Ltd.
import PyEvdi

VERSION_MAJOR = 1
VERSION_MINOR = 15
VERSION_PATCH = 0

def testVersion():
    assert PyEvdi.version == (VERSION_MAJOR, VERSION_MINOR, VERSION_PATCH)
