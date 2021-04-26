// Code of ShenZhou
// Room: /d/xiangyang/dongjie2.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����ϱ�ͨ������������ľ��ݽ֣�·�Խ�����С��Ҳ�𽥶�����������
����Զ��һ�����ȥ��·���ÿ�ͣ��ЪϢ�Ŀ�ջ��������ʯ��������߲�Զ��
�Ƕ����š�
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "xiangyang");
	set("no_sleep_room", 1);
        set("coordinates", ([ "x" : 3, "y" : 0 ]) );
	set("exits", ([ /* sizeof() == 5 */
  "east" : __DIR__"dongxin",
  "west" : __DIR__"dongjie1",
  "northeast" : __DIR__"majiu",
  "north" : __DIR__"jzjie1",
  "south" : __DIR__"jzjie4",
]));

	setup();
	replace_program(ROOM);
}
