#include <ansi.h>
inherit ITEM;
void create()
{	set_name(MAG"檀木大床"NOR,({"bed"}));
	set("long","一张古色古香的檀木大床，正好可以睡两个人。\n");
	set("unit","张");
	set("value",100);
	set("no_get",1);
	set("is_jiaju",1);
}
