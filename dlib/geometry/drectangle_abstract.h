// Copyright (C) 2015  Davis E. King (davis@dlib.net)
// License: Boost Software License   See LICENSE.txt for the full license.
#undef DLIB_DRECTANGLe_ABSTRACT_H_
#ifdef DLIB_DRECTANGLe_ABSTRACT_H_

#include "rectangle_abstract.h"

namespace dlib
{

// ----------------------------------------------------------------------------------------

    class drectangle
    {
        /*!
            INITIAL VALUE
                The initial value of this object is defined by its constructor.                

            WHAT THIS OBJECT REPRESENTS
                This object is just like dlib::rectangle except that it stores the
                coordinates of the rectangle using double rather than long variables.  As
                such, this object represents a rectangular region inside a Cartesian
                coordinate system.  The region is the rectangle with its top left corner at
                position (left(),top()) and its bottom right corner at (right(),bottom()).

                Note that the origin of the coordinate system, i.e. (0,0), is located at
                the upper left corner.  That is, points such as (1,1) or (3,5) represent
                locations that are below and to the right of the origin.

                Also note that rectangles where top() > bottom() or left() > right()
                represent empty rectangles.
        !*/
    public:

        drectangle (
        );
        /*!
            ensures
                - #left() == 0
                - #top() == 0
                - #right() == -1 
                - #bottom() == -1 
                - #is_empty() == true
        !*/

        drectangle (
            double left_,
            double top_,
            double right_,
            double bottom_
        );
        /*!
            ensures
                - #left() == left_
                - #top() == top_
                - #right() == right_
                - #bottom() == bottom_
        !*/

        drectangle (
            const vector<double,2>& p
        );
        /*!
            ensures
                - #left()   == p.x()
                - #top()    == p.y()
                - #right()  == p.x()
                - #bottom() == p.y()
        !*/

        template <typename T, typename U>
        drectangle (
            const vector<T,2>& p1,
            const vector<U,2>& p2
        );
        /*!
            ensures
                - #*this == drectangle(p1) + drectangle(p2)
        !*/

        drectangle (
            const drectangle& rect
        );
        /*!
            ensures
                - #*this represents the same rectangle as rect
        !*/

        drectangle (
            const rectangle& rect
        );
        /*!
            ensures
                - left()   == rect.left()
                - top()    == rect.top()
                - right()  == rect.right()
                - bottom() == rect.bottom()
        !*/

        operator rectangle (
        ) const;
        /*!
            ensures
                - rounds the left, top, right, and bottom coordinates of *this to the
                  nearest integers and returns the resulting rectangle.
        !*/

        double left (
        ) const;
        /*!
            ensures
                - returns the x coordinate for the left side of this rectangle
        !*/

        double& left (
        );
        /*!
            ensures
                - returns a non-const reference to the x coordinate for the left side 
                  of this rectangle
        !*/

        double top (
        ) const;
        /*!
            ensures
                - returns the y coordinate for the top of this rectangle
        !*/

        double& top (
        );
        /*!
            ensures
                - returns a non-const reference to the y coordinate for the 
                  top of this rectangle
        !*/

        double right (
        ) const;
        /*!
            ensures
                - returns the x coordinate for the right side of this rectangle
        !*/

        double& right (
        );
        /*!
            ensures
                - returns a non-const reference to the x coordinate for the right 
                  side of this rectangle
        !*/

        double bottom (
        ) const;
        /*!
            ensures
                - returns the y coordinate for the bottom of this rectangle
        !*/
       
        double& bottom (
        );
        /*!
            ensures
                - returns a non-const reference to the y coordinate for the bottom 
                  of this rectangle
        !*/
       
        const vector<double,2> tl_corner (
        ) const;
        /*!
            ensures
                - returns vector<double,2>(left(), top()) 
                  (i.e. returns the top left corner point for this rectangle)
        !*/

        const vector<double,2> bl_corner (
        ) const;
        /*!
            ensures
                - returns vector<double,2>(left(), bottom()) 
                  (i.e. returns the bottom left corner point for this rectangle)
        !*/

        const vector<double,2> tr_corner (
        ) const;
        /*!
            ensures
                - returns vector<double,2>(right(), top()) 
                  (i.e. returns the top right corner point for this rectangle)
        !*/

        const vector<double,2> br_corner (
        ) const;
        /*!
            ensures
                - returns vector<double,2>(right(), bottom()) 
                  (i.e. returns the bottom right corner point for this rectangle)
        !*/

        double width (
        ) const;
        /*!
            ensures
                - if (is_empty()) then
                    - returns 0
                - else
                    - returns the width of this rectangle.
                      (i.e. right() - left())
        !*/

        double height (
        ) const;
        /*!
            ensures
                - if (is_empty()) then
                    - returns 0
                - else
                    - returns the height of this rectangle.
                      (i.e. bottom() - top())
        !*/

        double area (
        ) const;
        /*!
            ensures
                - returns width()*height()
        !*/

        bool is_empty (
        ) const;
        /*!
            ensures
                - if (top() > bottom() || left() > right()) then
                    - returns true
                - else
                    - returns false
        !*/

        drectangle operator + (
            const drectangle& rhs
        ) const;
        /*!
            ensures
                - if (rhs.is_empty() == false && this->is_empty() == false) then
                    - returns the smallest rectangle that contains both *this and 
                      rhs.
                - if (rhs.is_empty() == true && this->is_empty() == false) then
                    - returns *this
                - if (rhs.is_empty() == false && this->is_empty() == true) then
                    - returns rhs
                - if (rhs.is_empty() == true && this->is_empty() == true) then
                    - returns a rectangle that has is_empty() == true
        !*/

        drectangle intersect (
            const drectangle& rhs
        ) const;
        /*!
            ensures
                - if (there is a region of intersection between *this and rhs) then
                    - returns a rectangle that represents the intersection of *this 
                      and rhs.
                - else
                    - returns a rectangle where is_empty() == true
        !*/

        bool contains (
            const vector<double,2>& p
        ) const;
        /*!
            ensures
                - if (the point (p.x(),p.y()) is contained in this rectangle) then
                    - returns true
                - else
                    - returns false
        !*/

        bool contains (
            const drectangle& rect
        ) const
        /*!
            ensures
                - if (rect + *this == *this) then
                    - returns true
                      (i.e. returns true if *this contains the given rectangle)
                - else
                    - returns false
        !*/

        drectangle& operator *= (
            const double& scale
        );
        /*!
            ensures
                - performs: *this = *this*scale;
                - returns #*this
        !*/

        drectangle& operator /= (
            const double& scale
        );
        /*!
            requires
                - scale != 0
            ensures
                - performs: *this = *this*(1.0/scale);
                - returns #*this
        !*/

    };

// ----------------------------------------------------------------------------------------

    void serialize (
        const drectangle& item, 
        std::ostream& out
    );
    /*!
        provides serialization support 
    !*/

    void deserialize (
        drectangle& item, 
        std::istream& in
    );
    /*!
        provides deserialization support 
    !*/

// ----------------------------------------------------------------------------------------

    std::ostream& operator<< (
        std::ostream& out, 
        const drectangle& item 
    );
    /*!
        ensures
            - writes item to out in the form "[(left, top) (right, bottom)]"
    !*/

// ----------------------------------------------------------------------------------------

    std::istream& operator>>(
        std::istream& in, 
        drectangle& item 
    );
    /*!
        ensures
            - reads a drectangle from the input stream in and stores it in #item.  The data
              in the input stream should be of the form [(left, top) (right, bottom)]
    !*/

// ----------------------------------------------------------------------------------------

    vector<double,2> center (
        const drectangle& rect
    );
    /*!
        ensures
            - returns the center of the given rectangle
    !*/

// ----------------------------------------------------------------------------------------

    vector<double,2> dcenter (
        const drectangle& rect
    );
    /*!
        ensures
            - returns the center of the given rectangle.  (Both center() and dcenter() are
              identical when applied to drectangle objects)
    !*/

// ----------------------------------------------------------------------------------------

    drectangle operator* (
        const drectangle& rect,
        const double& scale 
    );
    /*!
        ensures
            - This function returns a rectangle that has the same center as rect but with a
              width and height that are scale times larger.  That is, we return a new
              rectangle R such that:
                - center(R) == center(rect)
                - R.width() == rect.width()*scale
                - R.height() == rect.height()*scale
    !*/

// ----------------------------------------------------------------------------------------

    drectangle operator* (
        const double& scale,
        const drectangle& rect
    );
    /*!
        ensures
            - returns rect*scale
    !*/

// ----------------------------------------------------------------------------------------

    drectangle operator/ (
        const drectangle& rect,
        const double& scale
    );
    /*!
        ensures
            - returns rect*(1.0/scale)
    !*/

// ----------------------------------------------------------------------------------------

    drectangle operator+ (
        const drectangle& r,
        const vector<double,2>& p
    );
    /*!
        ensures
            - returns r + drectangle(p)
              (i.e. returns the rectangle that contains both r and p)
    !*/

// ----------------------------------------------------------------------------------------

    drectangle operator+ (
        const vector<double,2>& p,
        const drectangle& r
    );
    /*!
        ensures
            - returns r + drectangle(p)
              (i.e. returns the rectangle that contains both r and p)
    !*/

// ----------------------------------------------------------------------------------------

    drectangle translate_rect (
        const drectangle& rect,
        const vector<double,2>& p
    );
    /*!
        ensures
            - returns a rectangle R such that:
                - R.left()   == rect.left()   + p.x()
                - R.right()  == rect.right()  + p.x()
                - R.top()    == rect.top()    + p.y()
                - R.bottom() == rect.bottom() + p.y()
    !*/

// ----------------------------------------------------------------------------------------

    drectangle intersect (
        const drectangle& a,
        const drectangle& b
    ); 
    /*!
        ensures
            - returns a.intersect(b)
              (i.e. returns a rectangle representing the intersection of a and b)
    !*/

// ----------------------------------------------------------------------------------------

    double area (
        const drectangle& a
    );
    /*!
        ensures
            - returns a.area()
    !*/

// ----------------------------------------------------------------------------------------

    drectangle centered_drect (
        const vector<double,2>& p,
        const double& width,
        const double& height
    );
    /*!
        ensures
            - returns a rectangle R such that:
                - center(R) == p
                - if (width == 0 || height == 0)
                    - R.width() == 0 
                    - R.height() == 0 
                - else
                    - R.width() == width
                    - R.height() == height 
                - R.tl_corner() == point(p.x()-width/2, p.y()-height/2)
    !*/

// ----------------------------------------------------------------------------------------

}

#endif // DLIB_DRECTANGLe_ABSTRACT_H_

