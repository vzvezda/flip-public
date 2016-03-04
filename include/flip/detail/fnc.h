/*****************************************************************************

      fnc.h
      Copyright (c) 2014 Raphael DINGE

*Tab=3***********************************************************************/



#pragma once



/*\\\ INCLUDE FILES \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

#include "flip/detail/def.h"

#include <memory>
#include <type_traits>

#include <cstdio>



namespace flip
{



class Type;

template <class T>
void              modify (Type & obj, T & before, T & current, T value);
template <class T>
void              modify_move (Type & obj, T & before, T & current, T && value);



#if (flip_PLATFORM == flip_PLATFORM_WIN32)

FILE *   win32_fopen (const char * path_utf8_0, const wchar_t * mode_0);

#endif



}  // namespace flip



#if (flip_LANG_DIALECT == flip_LANG_DIALECT_CPP11) && (flip_COMPILER != flip_COMPILER_MSVC)
namespace std
{

// support for C++14 std::make_unique

template <class T, class... Args>
typename std::enable_if <
   ! std::is_array <T>::value, std::unique_ptr <T>
>::type  make_unique (Args &&... args)
{
   return std::unique_ptr <T> {new T (std::forward <Args> (args)...)};
}  // COV_NF_LINE

template <class T>
typename std::enable_if <
   std::is_array <T>::value, std::unique_ptr <T>
>::type  make_unique (std::size_t size)
{
   return std::unique_ptr <T> {new typename std::remove_extent <T>::type [size] ()};
}

//

}
#endif


#include "flip/detail/fnc.hpp"



/*\\\ EOF \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
