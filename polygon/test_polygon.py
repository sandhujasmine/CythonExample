#!/usr/bin/env python
from pytest import mark

from polygon.cy_polygon import CyRectangle, CyTriangle


l_cls = [CyRectangle, CyTriangle]
width = 2
height = 4
    

@mark.parametrize("cls", l_cls)
def test_init(cls):
    """
    test init, set_values, height, width
    """
    obj = cls(width, height)
    assert obj.width == width
    assert obj.height == height


@mark.parametrize("cls", l_cls)
def test_set_values(cls):
    obj = cls(width, height)
    obj.set_values(width * 2, height * 2)
    assert obj.width == width * 2
    assert obj.height == height * 2


@mark.parametrize(("obj", "exp_area"), [(CyRectangle(width, height), width * height),
                                         (CyTriangle(width, height), 0.5 * width * height)])
def test_area(obj, exp_area):
    assert obj.area() == exp_area