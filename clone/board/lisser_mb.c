// Code of ShenZhou
// /clone/board/wudang_b.c

inherit "/inherit/misc/sboard.c";
#include <ansi.h>

void create()
{
	set_name(WHT "̸���۵�" NOR, ({ "board" }) );
	set("location", "/u/lisser/workroom");
	set("board_id", "lisser_mb");
	set("long", "����Ҷ���������ʦ���������԰塣\n" );
	setup();
	set("capacity", 200);
        replace_program("/inherit/misc/sboard.c");
}

