/* Copyright (C) 2007-2016  B.A.T.M.A.N. contributors:
 *
 * Marek Lindner, Simon Wunderlich
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of version 2 of the GNU General Public
 * License as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, see <http://www.gnu.org/licenses/>.
 *
 * This file contains macros for maintaining compatibility with older versions
 * of the Linux kernel.
 */

#ifndef _NET_BATMAN_ADV_COMPAT_LINUX_BUG_H_
#define _NET_BATMAN_ADV_COMPAT_LINUX_BUG_H_

#include <linux/version.h>
#include_next <linux/bug.h>

#if LINUX_VERSION_CODE < KERNEL_VERSION(2, 6, 33)

#undef BUILD_BUG_ON_NOT_POWER_OF_2
#ifdef __CHECKER__
#define BUILD_BUG_ON_NOT_POWER_OF_2(n) (0)
#else
/* Force a compilation error if a constant expression is not a power of 2 */
#define BUILD_BUG_ON_NOT_POWER_OF_2(n) \
	BUILD_BUG_ON((n) == 0 || (((n) & ((n) - 1)) != 0))
#endif

#endif /* < KERNEL_VERSION(2, 6, 33) */

#if LINUX_VERSION_CODE < KERNEL_VERSION(3, 0, 0)

#undef BUILD_BUG_ON
#ifdef __CHECKER__
#define BUILD_BUG_ON(condition) (0)
#else /* __CHECKER__ */
#define BUILD_BUG_ON(condition) ((void)sizeof(char[1 - 2 * !!(condition)]))
#endif /* __CHECKER__ */

#endif /* < KERNEL_VERSION(3, 0, 0) */

#endif	/* _NET_BATMAN_ADV_COMPAT_LINUX_BUG_H_ */
