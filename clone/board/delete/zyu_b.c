//Created by Zyu on k1-8-1
// zyu_b.c

#include <ansi.h>;
inherit BULLETIN_BOARD;

void create()
{
	set_name(HIR"盘龙大理石柱"NOR, ({ "board" }) );
	set("location", "/u/zyu/workroom");
	set("board_id", "zyu_b");
	set("long", 
 "这就是供"HIC"风儿雨"NOR"和同事们讨论工作用的擎天盘龙大理石柱。\n"
+HIR"上面满是由各种功夫刻下的留言！\n\n"NOR );
	set("wizard_only", 1);
	setup();
	set("capacity", 200);
	replace_program(BULLETIN_BOARD);
}

