cdef extern from "polygon.h":
    cdef cppclass Polygon:
        Polygon() except +
        int set_values(int a, int b)
        int get_width()
        int get_height()
        int area()

    
    cdef cppclass Rectangle(Polygon):
        Rectangle() except +
    

    cdef cppclass Triangle(Polygon):
        Triangle() except +


cdef class CyPolygon(object):
    """
    follow the class heirarchy of C++ 
    """
    cdef Polygon * poly

    def __cinit__(self):
        '''
        do not initialize Polygon object, just use base
        class to keep common set_values(), area() call
        This is not designed to be instantiated
        '''
        self.poly = NULL

    def __init__(self, int width, int height):
        '''
        again, CyPolygon is a base class and should not be instantiated. It keeps track of common code.
        Could put a check in before invoking self.poly so program doesn't crash. For now, just document it
        and user beware.

        This is just for testing.
        '''
        self.set_values(width, height)

    property width:
        def __get__(self):
            return self.poly.get_width()

    property height:
        def __get__(self):
            return self.poly.get_height()

    def set_values(self, int width, int height):
        self.poly.set_values(width, height)

    def area(self):
        """
        return area if we have a poly defined
        """
        return self.poly.area()


cdef class CyRectangle(CyPolygon):
    def __cinit__(self):
        self.poly = new Rectangle() 

    def __dealloc__(self):
        del self.poly


cdef class CyTriangle(CyPolygon):
    def __cinit__(self):
        self.poly = new Triangle() 

    def __dealloc__(self):
        del self.poly
 
    