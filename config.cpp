/* This file is part of KDevelop
   Copyright 2006-2008 Hamish Rodda <rodda@kde.org>
   Copyright 2009 Andreas Pakulat <apaku@gmx.de>

   This program is free software; you can redistribute it and/or
   modify it under the terms of the GNU General Public
   License as published by the Free Software Foundation; either
   version 2 of the License, or (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; see the file COPYING.  If not, write to
   the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.
*/

#include "config.h"
#include "job.h"

// Generic valgrind mode
namespace valgrind
{
GenericLaunchMode::GenericLaunchMode()
    : m_toolname("UNSET TOOL")
{
}

QIcon GenericLaunchMode::icon() const
{
    return QIcon();
}

QString   GenericLaunchMode::id() const
{
    return "valgrind_generic";
}

QString GenericLaunchMode::name() const
{
    return "Valgrind";
}

QString GenericLaunchMode::tool() const
{
    return m_toolname;
}

}
