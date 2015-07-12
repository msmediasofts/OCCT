// Created on: 2000-05-10
// Created by: Andrey BETENEV
// Copyright (c) 2000-2014 OPEN CASCADE SAS
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

#ifndef _StepBasic_ExternalSource_HeaderFile
#define _StepBasic_ExternalSource_HeaderFile

#include <Standard.hxx>
#include <Standard_Type.hxx>

#include <StepBasic_SourceItem.hxx>
#include <MMgt_TShared.hxx>
class StepBasic_SourceItem;


class StepBasic_ExternalSource;
DEFINE_STANDARD_HANDLE(StepBasic_ExternalSource, MMgt_TShared)

//! Representation of STEP entity ExternalSource
class StepBasic_ExternalSource : public MMgt_TShared
{

public:

  
  //! Empty constructor
  Standard_EXPORT StepBasic_ExternalSource();
  
  //! Initialize all fields (own and inherited)
  Standard_EXPORT void Init (const StepBasic_SourceItem& aSourceId);
  
  //! Returns field SourceId
  Standard_EXPORT StepBasic_SourceItem SourceId() const;
  
  //! Set field SourceId
  Standard_EXPORT void SetSourceId (const StepBasic_SourceItem& SourceId);




  DEFINE_STANDARD_RTTI(StepBasic_ExternalSource,MMgt_TShared)

protected:




private:


  StepBasic_SourceItem theSourceId;


};







#endif // _StepBasic_ExternalSource_HeaderFile
