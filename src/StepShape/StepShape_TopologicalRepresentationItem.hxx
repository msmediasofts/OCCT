// Created on: 1995-12-01
// Created by: EXPRESS->CDL V0.2 Translator
// Copyright (c) 1995-1999 Matra Datavision
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

#ifndef _StepShape_TopologicalRepresentationItem_HeaderFile
#define _StepShape_TopologicalRepresentationItem_HeaderFile

#include <Standard.hxx>
#include <Standard_Type.hxx>

#include <StepRepr_RepresentationItem.hxx>


class StepShape_TopologicalRepresentationItem;
DEFINE_STANDARD_HANDLE(StepShape_TopologicalRepresentationItem, StepRepr_RepresentationItem)


class StepShape_TopologicalRepresentationItem : public StepRepr_RepresentationItem
{

public:

  
  //! Returns a TopologicalRepresentationItem
  Standard_EXPORT StepShape_TopologicalRepresentationItem();




  DEFINE_STANDARD_RTTI(StepShape_TopologicalRepresentationItem,StepRepr_RepresentationItem)

protected:




private:




};







#endif // _StepShape_TopologicalRepresentationItem_HeaderFile
