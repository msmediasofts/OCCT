// Created on: 2008-09-01
// Created by: Vladislav ROMASHKO
// Copyright (c) 2008-2014 OPEN CASCADE SAS
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

#ifndef _Voxel_ROctBoolDS_HeaderFile
#define _Voxel_ROctBoolDS_HeaderFile

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Handle.hxx>

#include <Voxel_DS.hxx>
#include <Standard_Real.hxx>
#include <Standard_Integer.hxx>
#include <Standard_Boolean.hxx>


//! A 3D voxel model keeping a boolean flag (1 or 0)
//! value for each voxel, and having an opportunity to split each voxel
//! into 8 sub-voxels recursively.
class Voxel_ROctBoolDS  : public Voxel_DS
{
public:

  DEFINE_STANDARD_ALLOC

  
  //! An empty constructor.
  Standard_EXPORT Voxel_ROctBoolDS();
  
  //! A constructor initializing the voxel model.
  //! (x, y, z) - the start point of the box.
  //! (x_len, y_len, z_len) - lengths in x, y and z directions along axes of a co-ordinate system.
  //! (nb_x, nb_y, nb_z) - number of splits (voxels) along x, y and z directions.
  Standard_EXPORT Voxel_ROctBoolDS(const Standard_Real x, const Standard_Real y, const Standard_Real z, const Standard_Real x_len, const Standard_Real y_len, const Standard_Real z_len, const Standard_Integer nb_x, const Standard_Integer nb_y, const Standard_Integer nb_z);
  
  //! Initialization of the voxel model.
  //! (x, y, z) - the start point of the box.
  //! (x_len, y_len, z_len) - lengths in x, y and z directions along axes of a co-ordinate system.
  //! (nb_x, nb_y, nb_z) - number of splits (voxels) along x, y and z directions.
  Standard_EXPORT virtual void Init (const Standard_Real x, const Standard_Real y, const Standard_Real z, const Standard_Real x_len, const Standard_Real y_len, const Standard_Real z_len, const Standard_Integer nb_x, const Standard_Integer nb_y, const Standard_Integer nb_z) Standard_OVERRIDE;
  
  //! A destructor of the voxel model.
  Standard_EXPORT void Destroy();
~Voxel_ROctBoolDS()
{
  Destroy();
}
  
  //! The method sets all values equal to 0 (false) and
  //! releases the memory.
  Standard_EXPORT void SetZero();
  
  //! The method searches voxels with equal-value of sub-voxels
  //! and removes them (remaining the value for the voxel).
  Standard_EXPORT void OptimizeMemory();
  
  //! Defines a value for voxel with co-ordinates (ix, iy, iz).
  //! If the voxel is split into 8 sub-voxels, the split disappears.
  //! Initial state of the model is so that all voxels have value 0 (false),
  //! and this data doesn't occupy memory.
  //! Memory for data is allocating during setting non-zero values (true).
  Standard_EXPORT void Set (const Standard_Integer ix, const Standard_Integer iy, const Standard_Integer iz, const Standard_Boolean data);
  
  //! Defines a value for a sub-voxel of a voxel with co-ordinates (ix, iy, iz).
  //! If the voxel is not split into 8 sub-voxels yet, this method splits the voxel.
  //! Range of sub-voxels is 0 - 7.
  Standard_EXPORT void Set (const Standard_Integer ix, const Standard_Integer iy, const Standard_Integer iz, const Standard_Integer ioct1, const Standard_Boolean data);
  
  //! Defines a value for a sub-voxel of a sub-voxel of a voxel with co-ordinates (ix, iy, iz).
  //! If the voxel is not split into 8 sub-voxels yet, this method splits the voxel.
  //! Range of sub-voxels is 0 - 7.
  Standard_EXPORT void Set (const Standard_Integer ix, const Standard_Integer iy, const Standard_Integer iz, const Standard_Integer ioct1, const Standard_Integer ioct2, const Standard_Boolean data);
  
  //! Returns true if the voxel is split into 8 sub-voxels.
  Standard_EXPORT Standard_Boolean IsSplit (const Standard_Integer ix, const Standard_Integer iy, const Standard_Integer iz) const;
  
  //! Returns the deepness of splits of a voxel.
  //! 0 - no splits (::IsSplit() being called would return false).
  //! 1 - the voxel is split into 8 sub-voxels.
  //! 2 - the voxels is split into 8 sub-voxels,
  //! and each of the sub-voxels is split into 8 sub-sub-voxels.
  //! 3 - ...
  Standard_EXPORT Standard_Integer Deepness (const Standard_Integer ix, const Standard_Integer iy, const Standard_Integer iz) const;
  
  //! Returns the value of voxel with co-ordinates (ix, iy, iz).
  //! Warning!: the returned value may not coincide with the value of its 8 sub-voxels.
  //! Use the method ::IsSplit() to check whether a voxel has sub-voxels.
  Standard_EXPORT Standard_Boolean Get (const Standard_Integer ix, const Standard_Integer iy, const Standard_Integer iz) const;
  
  //! Returns the value of a sub-voxel of a voxel with co-ordinates (ix, iy, iz).
  //! If the voxel is not split, it returns the value of the voxel.
  //! Range of sub-voxels is 0 - 7.
  Standard_EXPORT Standard_Boolean Get (const Standard_Integer ix, const Standard_Integer iy, const Standard_Integer iz, const Standard_Integer ioct1) const;
  
  //! Returns the value of a sub-voxel of a sub-voxel of a voxel with co-ordinates (ix, iy, iz).
  //! If the voxel is not split, it returns the value of the voxel.
  //! Range of sub-voxels is 0 - 7.
  Standard_EXPORT Standard_Boolean Get (const Standard_Integer ix, const Standard_Integer iy, const Standard_Integer iz, const Standard_Integer ioct1, const Standard_Integer ioct2) const;
  
  //! Returns the center point of a sub-voxel with co-ordinates (ix, iy, iz, i).
  Standard_EXPORT void GetCenter (const Standard_Integer ix, const Standard_Integer iy, const Standard_Integer iz, const Standard_Integer i, Standard_Real& xc, Standard_Real& yc, Standard_Real& zc) const;
  
  //! Returns the center point of a sub-voxel with co-ordinates (ix, iy, iz, i, j).
  Standard_EXPORT void GetCenter (const Standard_Integer ix, const Standard_Integer iy, const Standard_Integer iz, const Standard_Integer i, const Standard_Integer j, Standard_Real& xc, Standard_Real& yc, Standard_Real& zc) const;




protected:





private:





};







#endif // _Voxel_ROctBoolDS_HeaderFile
