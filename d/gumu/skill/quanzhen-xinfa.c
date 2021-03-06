// qunzhen-xinfa.c 古墓派全真心法--玉女心经基础之一
// by April 01/08/06

#include <combat.h>

inherit FORCE;

string check() { return "force"; }

#include "/kungfu/skill/force_list.h"

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
// 不可学
{
	return notify_fail("还是自行学习吧，将来可以修习玉女心经。\n");
}

int practice_skill(object me)
// 不可练
{
	return notify_fail("要练成更高级的全真派武功，只能从师全真派。\n");
}

string exert_function_file(string func)
{
	return __DIR__"yunu-xinjing/" + func;
}