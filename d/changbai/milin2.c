// Code of ShenZhou
// Room: milin2.c

inherit ROOM;

#include "/d/changbai/caishen.h";

void create()
{
	set("short", "����");
	set("long", @LONG
����һƬï�ܵ����֣����ҵ���������б��ɽ���ϡ�ÿ��������������
����ϸ���ߴ�ʮ���ɡ�����֦��Ҷ�ܣ��������ȫ��ס����������Ե���Щ
�谵����ľ֮�䳤�źܶ��ľ�Ӳݣ�ʹ���ߺܼ��ѣ���˵�˲ξ���������Щ
�Ӳ�֮�С�
LONG	);
	set("exits", ([ 
               "westdown" : __DIR__"milin1",
               "southup" : __DIR__"milin3",
        ]));

        set("objects",([
		__DIR__"npc/cb_laohu" : 1,
	]));
	
        set("outdoors", "changbai");
        set("cost", 4);

        set("count", random(3)+1);

	setup();
}
