//  ��Ϯ������������  /clone/board/naihe_b.c
//  by naihe  2002-04-09

#include <ansi.h>
inherit BULLETIN_BOARD;

void create()
{
        set_name(YEL"��ֽ"NOR, ({ "paper" }) );
	switch(random(2))
	{
		case 0:set("location", "/u/naihe/naihe_room");
			break;
		case 1:set("location","/u/spark/spark_room");
			break;
	}
        set("board_id", "naihe_b");
        set("long", "һ�ŷ��Ƶ���ֽ������д��������������С�֡�\n" );
        setup();
        set("capacity", 200);
        replace_program(BULLETIN_BOARD);
}
