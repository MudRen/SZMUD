// Code of ShenZhou
// Room: /d/xiangyang/dufugang.c

inherit ROOM;

void create()
{
	set("short", "�Ÿ���");
	set("long", @LONG
 �㵽��һ��Сɽ֮�ϣ�����Զ����������ˮ�ƺ��������Ľ���Ұ��������
�����д�Ů��ӿ����������ɽ������ȥ���������п�ʯ�������Ͽ���һ�д���
�����ƹ����ɶŸ����Ρ���
LONG
	);
	set("no_clean_up", 0);
        set("coordinates", ([ "x" : 0, "y" : 11 ]) );
	set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"aozhan",
  "southdown" : __DIR__"migonglu",
]));
	set("outdoors", "xiangyang");
	setup();
	replace_program(ROOM);
}
