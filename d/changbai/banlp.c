// Code of ShenZhou
// Room: banlp.c

inherit ROOM;

#include "/d/changbai/caishen.h";

void create()
{
	set("short", "����ư");
	set("long", @LONG
����ï�ܵ�ɭ�֣���ǰ����һ�����ʵ�ɽ�壬����Ҫ������ǰ�����뷭
������ɽ���С�����ɽ���ư��ư����������������խ��ɽ�崦����ϸ
խ���ʣ�����ư��һ����
LONG	);
	set("exits", ([ 
              "northwest" : __DIR__"erld",
              "northeast" : __DIR__"pubu",
        ]));

        set("objects",([
		__DIR__"npc/cb_fox" : 1,
	]));
	
        set("outdoors", "changbai");
        set("cost", 3);

        set("count", random(3)+1);

	setup();
}
