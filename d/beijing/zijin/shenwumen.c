//Cracked by Roath
// Room: /d/beijing/zijincheng/shenwumen.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�����Ͻ��ǵĺ��ţ��������ͳ����Ͻ��ǡ�
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"shunzhenmen",
  "west" : __DIR__"tongdao8",
  "north" : "/d/beijing/jingshan",
  "east" : __DIR__"tongdao7",
]));
  	set("objects", ([
		 "/d/beijing/npc/shiwei1" : 4,
	]));
	set("no_clean_up", 0);
	set("outdoors", "beijing");

	setup();
}
int valid_leave(object me, string dir)
{
        int i;
        if ((dir=="south" || dir=="west" || dir=="east") && me->query("class")!="officer" && (objectp(present("yideng shiwei", environment(me)))))
                return notify_fail("����������ǰ��ס�㣬����˵�����ʹ����أ���ֹ�����˵ȳ��룡\n");
        return ::valid_leave(me, dir);
}
