// Code of ShenZhou
// Room: /d/xiangyang/ysting.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������������һ��̫ʦ�Σ����̻�Ƥ��һ�������е�������ϣ����Ը���
С���Ϊ������౳����Ƥ��������������ʯ���磬���������ɸߣ�ʯ��ɽˮ
ľ�������续������һ�㡣���α��ǰ���ʹ�����������������������ڣ���
û��֮ʱ�������������������İ����ѡ�
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"xiansi",
  "south" : __DIR__"huating",
]));
        set("objects", ([
               __DIR__"npc/wende" : 1, 
        ]));
	setup();
	replace_program(ROOM);
}
