// Code of ShenZhou
// Room: jiaxz.c

inherit ROOM;

#include "/d/changbai/caishen.h";

void create()
{
	set("short", "������");
	set("long", @LONG
��������ɽ֮���һ��ɽ�꣬ƽ����紵�����˴�������������ů��
һ�㡣�������¸ߴ����ľ�м䣬������һƬƬ�Ϻ�ɫ�Ľ���������ڰ���
��ѩ�͵����������У��Եø���Ѥ�����ˡ�
LONG	);
	set("exits", ([ 
              "westup" : __DIR__"heifk",
              "southup" : __DIR__"erld",
        ]));

        set("objects",([
		__DIR__"npc/cb_xiong" : 1,
	]));
	
        set("outdoors", "changbai");
        set("cost", 4);

        set("count", random(3)+1);

	setup();
}
