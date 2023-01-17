/*
 * Unitex
 *
 * Copyright (C) 2001-2012 Université Paris-Est Marne-la-Vallée <unitex@univ-mlv.fr>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA.
 *
 */

#ifndef VariableUtilsH
#define VariableUtilsH

#include "Unicode.h"
#include "LocatePattern.h"

#ifndef HAS_UNITEX_NAMESPACE
#define HAS_UNITEX_NAMESPACE 1
#endif

namespace unitex {

#define VAR_CMP_ERROR -1
#define VAR_CMP_DIFF 0
#define VAR_CMP_EQUAL 1


int compare_variables(unichar* var1,unichar* var2,struct locate_parameters* p,int case_matters);
Ustring* get_variable_content(unichar* name,struct locate_parameters* p);
Ustring* get_output_variable_content(unichar* name,struct locate_parameters* p);
Ustring* get_dic_variable_content(unichar* name,struct locate_parameters* p);

} // namespace unitex

#endif
