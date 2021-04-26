// Code of ShenZhou
// Room: /d/xiangyang/jicang.c

inherit ROOM;

void create()
{
	set("short", "���ֽ�");
	set("long", @LONG
����֮��������һ��֮�������ɹŴ����ʮ�����������������ȫ������
ƽ���뽫ʿ���ģ���������������ݣ�����ʱ���л�����������������ر���
��ɭ�ϣ����˲�����ӽ��˴���
LONG
	);
	set("outdoors", "xiangyang");
	set("no_clean_up", 0);
        set("coordinates", ([ "x" : -1, "y" : 2 ]) );
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"mihua",
  "east" : __DIR__"beijie1",
  "south" : __DIR__"liangc2",
  "north" : __DIR__"liangc",
]));

	setup();
	replace_program(ROOM);
}
