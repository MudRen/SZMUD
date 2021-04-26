// Code of ShenZhou
// Room: /d/xixia/shimen.c

inherit ROOM;

void create()
{
	set("short", "ʯ��");
	set("long", @LONG
������ʯ�ţ������ĵĲ�ʯ��������û�б�������ֻ�б�صİ���ʯ��
�������������ʯ�ذ��������������İ���ʯ�̳ɵġ�ʱ���д����Ŀ���
���ٸ������������û��ûҹ�Ŀ��ɰ���ʯ������˵��º��û����վ��
����������һ������
LONG
	);
	set("cost", 2);
	set("outdoors", "xixia");
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"hsxia",
  "north" : __DIR__"wufosi",
  "northwest" : __DIR__"oldwall",
]));
	set("objects", ([
                __DIR__"npc/xxbing" : 1,
		__DIR__"npc/caishiren" : 2,
        ]));
	setup();
	replace_program(ROOM);
}
