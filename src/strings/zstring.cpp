#include "zstring.hpp"
//    strings/zstring.cpp - Functions for zstring.hpp
//
//    Copyright © 2013 Ben Longbons <b.r.longbons@gmail.com>
//
//    This file is part of The Mana World (Athena server)
//
//    This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with this program.  If not, see <http://www.gnu.org/licenses/>.

#include <cstdio>
#include <cstring>

#include "rstring.hpp"
#include "astring.hpp"
#include "tstring.hpp"
#include "literal.hpp"

#include "../poison.hpp"


namespace tmwa
{
namespace strings
{
    ZString::ZString()
    {
        *this = ZString(""_s);
    }
    ZString::ZString(const RString& s)
    : _b(&*s.begin()), _e(&*s.end()), _base(s.base())
    {}
    ZString::ZString(const AString& s)
    : _b(&*s.begin()), _e(&*s.end()), _base(s.base())
    {}
    ZString::ZString(const TString& s)
    : _b(&*s.begin()), _e(&*s.end()), _base(s.base())
    {}
    ZString::ZString(const LString& s)
    : _b(&*s.begin()), _e(&*s.end()), _base(s.base())
    {}
    ZString::ZString(const char *b, const char *e, const RString *base_)
    : _b(b), _e(e), _base(base_)
    {}
    ZString::ZString(decltype(really_construct_from_a_pointer), const char *s, const RString *base_)
    : _b(s), _e(s + strlen(s)), _base(base_)
    {}

    ZString::iterator ZString::begin() const
    {
        return _b;
    }
    ZString::iterator ZString::end() const
    {
        return _e;
    }
    const RString *ZString::base() const
    {
        return _base;
    }
    const char *ZString::c_str() const
    {
        return &*begin();
    }

    const char *decay_for_printf(const ZString& zs)
    {
        return zs.c_str();
    }
} // namespace strings
} // namespace tmwa
