// Created on: 1993-02-22
// Created by: Mireille MERCIEN
// Copyright (c) 1993-1999 Matra Datavision
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

#ifndef _TCollection_ExtendedString_HeaderFile
#define _TCollection_ExtendedString_HeaderFile

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Handle.hxx>

#include <Standard_PExtCharacter.hxx>
#include <Standard_Integer.hxx>
#include <Standard_CString.hxx>
#include <Standard_Boolean.hxx>
#include <Standard_ExtString.hxx>
#include <Standard_Character.hxx>
#include <Standard_ExtCharacter.hxx>
#include <Standard_Real.hxx>
#include <Standard_OStream.hxx>
#include <Standard_PCharacter.hxx>
class Standard_NullObject;
class Standard_OutOfRange;
class Standard_NumericError;
class Standard_NegativeValue;
class TCollection_AsciiString;


//! A variable-length sequence of "extended"
//! (UNICODE) characters (16-bit character type). It
//! provides editing operations with built-in memory
//! management to make ExtendedString objects
//! easier to use than ordinary extended character arrays.
//! ExtendedString objects follow "value
//! semantics", that is, they are the actual strings,
//! not handles to strings, and are copied through
//! assignment. You may use HExtendedString
//! objects to get handles to strings.
class TCollection_ExtendedString 
{
public:

  DEFINE_STANDARD_ALLOC

  
  //! Initializes a ExtendedString to an empty ExtendedString.
  Standard_EXPORT TCollection_ExtendedString();
  
  //! Creation by converting a CString to an extended
  //! string.  If <isMultiByte> is true then the string is
  //! treated as having UTF-8 coding.  If it is not a UTF-8
  //! then <isMultiByte> is ignored and each character is
  //! copied to ExtCharacter.
  Standard_EXPORT TCollection_ExtendedString(const Standard_CString astring, const Standard_Boolean isMultiByte = Standard_False);
  
  //! Creation by converting an ExtString to an extended string.
  Standard_EXPORT TCollection_ExtendedString(const Standard_ExtString astring);
  
  //! Initializes a AsciiString with a single character.
  Standard_EXPORT TCollection_ExtendedString(const Standard_Character aChar);
  
  //! Initializes a ExtendedString with a single character.
  Standard_EXPORT TCollection_ExtendedString(const Standard_ExtCharacter aChar);
  
  //! Initializes a ExtendedString with <length> space allocated.
  //! and filled with <filler>.This is useful for buffers.
  Standard_EXPORT TCollection_ExtendedString(const Standard_Integer length, const Standard_ExtCharacter filler);
  
  //! Initializes an ExtendedString with an integer value
  Standard_EXPORT TCollection_ExtendedString(const Standard_Integer value);
  
  //! Initializes an ExtendedString with a real value
  Standard_EXPORT TCollection_ExtendedString(const Standard_Real value);
  
  //! Initializes a ExtendedString with another ExtendedString.
  Standard_EXPORT TCollection_ExtendedString(const TCollection_ExtendedString& astring);
  
  //! Creation by converting an Ascii string to an extended
  //! string. The string is treated as having UTF-8 coding.
  //! If it is not a UTF-8 then each character is copied to ExtCharacter.
  Standard_EXPORT TCollection_ExtendedString(const TCollection_AsciiString& astring);
  
  //! Appends the other extended string to this extended string.
  //! Note that this method is an alias of operator +=.
  //! Example: aString += anotherString
  Standard_EXPORT void AssignCat (const TCollection_ExtendedString& other);
void operator += (const TCollection_ExtendedString& other)
{
  AssignCat(other);
}
  
  //! Appends <other> to me.
  Standard_EXPORT TCollection_ExtendedString Cat (const TCollection_ExtendedString& other) const;
TCollection_ExtendedString operator + (const TCollection_ExtendedString& other) const
{
  return Cat(other);
}
  
  //! Substitutes all the characters equal to aChar by NewChar
  //! in the ExtendedString <me>.
  //! The substitution can be case sensitive.
  //! If you don't use default case sensitive, no matter wether aChar
  //! is uppercase or not.
  Standard_EXPORT void ChangeAll (const Standard_ExtCharacter aChar, const Standard_ExtCharacter NewChar);
  
  //! Removes all characters contained in <me>.
  //! This produces an empty ExtendedString.
  Standard_EXPORT void Clear();
  
  //! Copy <fromwhere> to <me>.
  //! Used as operator =
  Standard_EXPORT void Copy (const TCollection_ExtendedString& fromwhere);
void operator = (const TCollection_ExtendedString& fromwhere)
{
  Copy(fromwhere);
}
  
  //! Frees memory allocated by ExtendedString.
  Standard_EXPORT void Destroy();
~TCollection_ExtendedString()
{
  Destroy();
}
  
  //! Insert a Character at position <where>.
  Standard_EXPORT void Insert (const Standard_Integer where, const Standard_ExtCharacter what);
  
  //! Insert a ExtendedString at position <where>.
  Standard_EXPORT void Insert (const Standard_Integer where, const TCollection_ExtendedString& what);
  
  //! Returns True if this string contains no characters.
    Standard_Boolean IsEmpty() const;
  
  //! Returns true if the characters in this extended
  //! string are identical to the characters in the other extended string.
  //! Note that this method is an alias of operator ==
  Standard_EXPORT Standard_Boolean IsEqual (const Standard_ExtString other) const;
Standard_Boolean operator == (const Standard_ExtString other) const
{
  return IsEqual(other);
}
  
  //! Returns true if the characters in this extended
  //! string are identical to the characters in the other extended string.
  //! Note that this method is an alias of operator ==
  Standard_EXPORT Standard_Boolean IsEqual (const TCollection_ExtendedString& other) const;
Standard_Boolean operator == (const TCollection_ExtendedString& other) const
{
  return IsEqual(other);
}
  
  //! Returns true if there are differences between the
  //! characters in this extended string and the other extended string.
  //! Note that this method is an alias of operator !=.
  Standard_EXPORT Standard_Boolean IsDifferent (const Standard_ExtString other) const;
Standard_Boolean operator != (const Standard_ExtString other) const
{
  return IsDifferent(other);
}
  
  //! Returns true if there are differences between the
  //! characters in this extended string and the other extended string.
  //! Note that this method is an alias of operator !=.
  Standard_EXPORT Standard_Boolean IsDifferent (const TCollection_ExtendedString& other) const;
Standard_Boolean operator != (const TCollection_ExtendedString& other) const
{
  return IsDifferent(other);
}
  
  //! Returns TRUE if <me> is less than <other>.
  Standard_EXPORT Standard_Boolean IsLess (const Standard_ExtString other) const;
Standard_Boolean operator < (const Standard_ExtString other) const
{
  return IsLess(other);
}
  
  //! Returns TRUE if <me> is less than <other>.
  Standard_EXPORT Standard_Boolean IsLess (const TCollection_ExtendedString& other) const;
Standard_Boolean operator < (const TCollection_ExtendedString& other) const
{
  return IsLess(other);
}
  
  //! Returns TRUE if <me> is greater than <other>.
  Standard_EXPORT Standard_Boolean IsGreater (const Standard_ExtString other) const;
Standard_Boolean operator > (const Standard_ExtString other) const
{
  return IsGreater(other);
}
  
  //! Returns TRUE if <me> is greater than <other>.
  Standard_EXPORT Standard_Boolean IsGreater (const TCollection_ExtendedString& other) const;
Standard_Boolean operator > (const TCollection_ExtendedString& other) const
{
  return IsGreater(other);
}
  
  //! Returns True if the ExtendedString contains only
  //! "Ascii Range" characters .
  Standard_EXPORT Standard_Boolean IsAscii() const;
  
  //! Returns number of characters in <me>.
  //! This is the same functionality as 'strlen' in C.
  Standard_EXPORT Standard_Integer Length() const;
  
  //! Displays <me> .
  Standard_EXPORT void Print (Standard_OStream& astream) const;
friend Standard_EXPORT Standard_OStream& operator << (Standard_OStream& astream,const TCollection_ExtendedString& astring);
  
  //! Removes every <what> characters from <me>.
  Standard_EXPORT void RemoveAll (const Standard_ExtCharacter what);
  
  //! Erases <ahowmany> characters from position <where>,<where> included.
  Standard_EXPORT void Remove (const Standard_Integer where, const Standard_Integer ahowmany = 1);
  
  //! Searches a ExtendedString in <me> from the beginning
  //! and returns position of first item <what> matching.
  //! it returns -1 if not found.
  Standard_EXPORT Standard_Integer Search (const TCollection_ExtendedString& what) const;
  
  //! Searches a ExtendedString in another ExtendedString from the
  //! end and returns position of first item <what> matching.
  //! it returns -1 if not found.
  Standard_EXPORT Standard_Integer SearchFromEnd (const TCollection_ExtendedString& what) const;
  
  //! Replaces one character in the ExtendedString at position <where>.
  //! If <where> is less than zero or greater than the length of <me>
  //! an exception is raised.
  Standard_EXPORT void SetValue (const Standard_Integer where, const Standard_ExtCharacter what);
  
  //! Replaces a part of <me> by another ExtendedString see above.
  Standard_EXPORT void SetValue (const Standard_Integer where, const TCollection_ExtendedString& what);
  
  //! Splits this extended string into two sub-strings at position where.
  //! -   The second sub-string (from position
  //! where + 1 of this string to the end) is
  //! returned in a new extended string.
  //! -   this extended string is modified: its last
  //! characters are removed, it becomes equal to
  //! the first sub-string (from the first character to position where).
  //! Example:
  //! aString contains "abcdefg"
  //! aString.Split(3) gives <me> = "abc" and returns "defg"
  Standard_EXPORT TCollection_ExtendedString Split (const Standard_Integer where);
  
  //! Extracts <whichone> token from <me>.
  //! By default, the <separators> is set to space and tabulation.
  //! By default, the token extracted is the first one (whichone = 1).
  //! <separators> contains all separators you need.
  //! If no token indexed by <whichone> is found, it returns an empty AsciiString.
  //! Example:
  //! aString contains "This is a     message"
  //! aString.Token()  returns "This"
  //! aString.Token(" ",4) returns "message"
  //! aString.Token(" ",2) returns "is"
  //! aString.Token(" ",9) returns ""
  //! Other separators than space character and tabulation are allowed :
  //! aString contains "1234; test:message   , value"
  //! aString.Token("; :,",4) returns "value"
  //! aString.Token("; :,",2) returns "test"
  Standard_EXPORT TCollection_ExtendedString Token (const Standard_ExtString separators, const Standard_Integer whichone = 1) const;
  
  //! Returns pointer to ExtString
  Standard_EXPORT const Standard_ExtString ToExtString() const;
  
  //! Truncates <me> to <ahowmany> characters.
  //! Example:  me = "Hello Dolly" -> Trunc(3) -> me = "Hel"
  //! Exceptions
  //! Standard_OutOfRange if ahowmany is greater
  //! than the length of this string.
  Standard_EXPORT void Trunc (const Standard_Integer ahowmany);
  
  //! Returns character at position <where> in <me>.
  //! If <where> is less than zero or greater than the lenght of
  //! <me>, an exception is raised.
  //! Example:
  //! aString contains "Hello"
  //! aString.Value(2) returns 'e'
  //! Exceptions
  //! Standard_OutOfRange if where lies outside
  //! the bounds of this extended string.
  Standard_EXPORT Standard_ExtCharacter Value (const Standard_Integer where) const;
  
  //! Returns a hashed value for the extended string
  //! astring within the range 1..Upper.
  //! Note: if astring is ASCII, the computed value is
  //! the same as the value computed with the HashCode function on a
  //! TCollection_AsciiString string composed with equivalent ASCII characters
    static Standard_Integer HashCode (const TCollection_ExtendedString& astring, const Standard_Integer Upper);
  
  //! Returns true if the characters in this extended
  //! string are identical to the characters in the other extended string.
  //! Note that this method is an alias of operator ==.
    static Standard_Boolean IsEqual (const TCollection_ExtendedString& string1, const TCollection_ExtendedString& string2);
  
  //! Converts the internal <mystring> to UTF8 coding and
  //! returns length of the out CString. A memory for the
  //! <theCString> should be allocated before call!
  Standard_EXPORT Standard_Integer ToUTF8CString (Standard_PCharacter& theCString) const;
  
  //! Returns expected CString length in UTF8 coding.
  //! It can be used for  memory  calculation  before converting
  //! to CString containing symbols in UTF8 coding.
  Standard_EXPORT Standard_Integer LengthOfCString() const;




protected:





private:

  
  //! Returns true if the input CString was successfuly converted
  //! to UTF8 coding
  Standard_EXPORT Standard_Boolean ConvertToUnicode (const Standard_CString astring);


  Standard_PExtCharacter mystring;
  Standard_Integer mylength;


};


#include <TCollection_ExtendedString.lxx>





#endif // _TCollection_ExtendedString_HeaderFile
