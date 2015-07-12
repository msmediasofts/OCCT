// Created on: 1997-10-28
// Created by: Roman BORISOV
// Copyright (c) 1997-1999 Matra Datavision
// Copyright (c) 1999-2014 OPEN CASCADE SAS
//
// This file is part of Open CASCADE Technology software library.
//
// This library is free software; you can redistribute it and/or modify it under
// the terms of the GNU Lesser General Public License version 2.1 as published
// by the Free Software Foundation, with special exception defined in the file
// OCCT_LGPL_EXCEPTION.txt. Consult the file LICENSE_LGPL_21.txt included in OCCT
// distribution for complete text of the license and disclaimer of any warranty.
//
// Alternatively, this file may be used under the terms of Open CASCADE
// commercial license or contractual agreement.

#ifndef _Approx_Curve2d_HeaderFile
#define _Approx_Curve2d_HeaderFile

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Handle.hxx>

#include <Standard_Boolean.hxx>
#include <Standard_Real.hxx>
#include <GeomAbs_Shape.hxx>
#include <Standard_Integer.hxx>
class Geom2d_BSplineCurve;
class Adaptor2d_HCurve2d;


//! Makes  an  approximation  for  HCurve2d  from  Adaptor3d
class Approx_Curve2d 
{
public:

  DEFINE_STANDARD_ALLOC

  
  Standard_EXPORT Approx_Curve2d(const Handle(Adaptor2d_HCurve2d)& C2D, const Standard_Real First, const Standard_Real Last, const Standard_Real TolU, const Standard_Real TolV, const GeomAbs_Shape Continuity, const Standard_Integer MaxDegree, const Standard_Integer MaxSegments);
  
  Standard_EXPORT Standard_Boolean IsDone() const;
  
  Standard_EXPORT Standard_Boolean HasResult() const;
  
  Standard_EXPORT Handle(Geom2d_BSplineCurve) Curve() const;
  
  Standard_EXPORT Standard_Real MaxError2dU() const;
  
  Standard_EXPORT Standard_Real MaxError2dV() const;




protected:





private:



  Handle(Geom2d_BSplineCurve) myCurve;
  Standard_Boolean myIsDone;
  Standard_Boolean myHasResult;
  Standard_Real myMaxError2dU;
  Standard_Real myMaxError2dV;


};







#endif // _Approx_Curve2d_HeaderFile
