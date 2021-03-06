/***

Copyright (C) 2015, 2016 Teclib'

This file is part of Armadito core.

Armadito core is free software: you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Armadito core is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with Armadito core.  If not, see <http://www.gnu.org/licenses/>.

***/

#ifndef ARMADITO_CORE_INFO_H
#define ARMADITO_CORE_INFO_H

#include <libarmadito/armadito.h>

struct a6o_info {
	const char *antivirus_version;
	enum a6o_update_status global_status;
	time_t global_update_ts;
	/* NULL terminated array of pointers to struct a6o_module_info */
	struct a6o_module_info **module_infos;
};

const char *a6o_update_status_str(enum a6o_update_status status);

struct a6o_info *a6o_info_new(struct armadito *armadito);

void a6o_info_to_stdout(struct a6o_info *info);

void a6o_info_free(struct a6o_info *info);

#endif
