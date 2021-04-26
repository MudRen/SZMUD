// Code of ShenZhou
// Room: /d/xiangyang/beijie3.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����������ı����ϣ���������ʤ������಻Զ��·�ϲ�ʱ���Կ���������
ʿ���������Ҳ������һЩ�л����߶���ȴ�������ڵ������֡�������һ��խС
�İ�������������������ϲ�Զ���������������������ӳǡ����˳ǡ���
LONG
	);
	set("no_clean_up", 0);
        set("coordinates", ([ "x" : 0, "y" : 5 ]) );
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"qisheng",
  "east" : __DIR__"chexiang",
  "westup" : __DIR__"furenche",
  "south" : __DIR__"beijie2",
]));
	set("outdoors", "xiangyang");

	setup();
	replace_program(ROOM);
}
