// Code of ShenZhou
// Room: milin3.c

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
              "northwest" : __DIR__"milin3",
              "eastup" : __DIR__"heifk",
        ]));
	
        set("outdoors", "changbai");
        set("cost", 4);

        set("count", random(3)+1);

	setup();
}
