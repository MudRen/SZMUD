#include <ansi.h>
inherit ITEM;
void create()
 {       set_name(HIW"立钟"NOR,({"clock"}));
         set("long","古老的座地钟，既是时间表，又可装饰大厅。\n");
         set("unit","只");
	set("value",100);
	set("no_get",1);
	set("is_jiaju",1);
}
