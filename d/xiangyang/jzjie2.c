// Code of ShenZhou
// Room: /d/xiangyang/jzjie2.c

inherit ROOM;

void create()
{
	set("short", "���ݽ�");
	set("long", @LONG
�����Ǿ��ݽֵ��жΣ�Ҳ������Ϊ������Ĵ��С�·�Ե����ﻨ�����̡�
������Ŀ�������ս��δʹ������������ȫ����·�ϵ�������ǻ����������
���ķ������������ȥ�������ı��֡�
LONG
	);
        set("coordinates", ([ "x" : 3, "y" : 4 ]) );
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"jzjie3",
  "west" : __DIR__"beijie2",
  "south" : __DIR__"jzjie1",
]));
	set("outdoors", "xiangyang");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
