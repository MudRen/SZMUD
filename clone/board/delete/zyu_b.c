//Created by Zyu on k1-8-1
// zyu_b.c

#include <ansi.h>;
inherit BULLETIN_BOARD;

void create()
{
	set_name(HIR"��������ʯ��"NOR, ({ "board" }) );
	set("location", "/u/zyu/workroom");
	set("board_id", "zyu_b");
	set("long", 
 "����ǹ�"HIC"�����"NOR"��ͬ�������۹����õ�������������ʯ����\n"
+HIR"���������ɸ��ֹ�����µ����ԣ�\n\n"NOR );
	set("wizard_only", 1);
	setup();
	set("capacity", 200);
	replace_program(BULLETIN_BOARD);
}

