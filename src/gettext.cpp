/*
   Copyright (C) 2003 - 2014 by David White <dave@whitevine.net>
   Part of the Battle for Wesnoth Project http://www.wesnoth.org/

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY.

   See the COPYING file for more details.
*/

#include <libintl.h>
#include "global.hpp"

#include "gettext.hpp"


#include <cstring>
namespace translation
{
const char* dgettext(const char* domain, const char* msgid)
{
	return ::dgettext(domain, msgid);
}
char const *egettext(char const *msgid)
{
	return msgid[0] == '\0' ? msgid : (::gettext)(msgid);
}

const char* dsgettext (const char * domainname, const char *msgid)
{
	bind_textdomain_codeset(domainname, "UTF-8");
	const char *msgval = dgettext (domainname, msgid);
	if (msgval == msgid) {
		msgval = std::strrchr (msgid, '^');
		if (msgval == NULL)
			msgval = msgid;
		else
			msgval++;
	}
	return msgval;
}

#if 0

const char* sgettext (const char *msgid)
{
	const char *msgval = gettext (msgid);
	if (msgval == msgid) {
		msgval = std::strrchr (msgid, '^');
		if (msgval == NULL)
			msgval = msgid;
		else
			msgval++;
	}
	return msgval;
}

const char* sngettext (const char *singular, const char *plural, int n)
{
	const char *msgval = ngettext (singular, plural, n);
	if (msgval == singular) {
		msgval = std::strrchr (singular, '^');
		if (msgval == NULL)
			msgval = singular;
		else
			msgval++;
	}
	return msgval;
}

#endif 
const char* dsngettext (const char * domainname, const char *singular, const char *plural, int n)
{
	bind_textdomain_codeset(domainname, "UTF-8");
	const char *msgval = dngettext (domainname, singular, plural, n);
	if (msgval == singular) {
		msgval = std::strrchr (singular, '^');
		if (msgval == NULL)
			msgval = singular;
		else
			msgval++;
	}
	return msgval;
}

void bind_textdomain(const char* domain, const char* direcory, const char* encoding)
{
	if(direcory != NULL)
		bindtextdomain(domain, direcory);
	if(encoding != NULL)
		bind_textdomain_codeset(domain, encoding);
}

void set_default_textdomain(const char* domain)
{
	textdomain(domain);
}

}
