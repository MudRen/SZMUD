// Code of ShenZhou
// /clone/board/wudang_b.c

inherit "/inherit/misc/sboard.c";
#include <ansi.h>

void create()
{
	set_name(WHT "谈经论道" NOR, ({ "board" }) );
	set("location", "/u/lisser/workroom");
	set("board_id", "lisser_mb");
	set("long", "这是叶枫和其他巫师交流的留言板。\n" );
	setup();
	set("capacity", 200);
        replace_program("/inherit/misc/sboard.c");
}

