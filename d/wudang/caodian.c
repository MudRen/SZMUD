// Code of ShenZhou
// �ݵ� caodian.c
// xQin 11/00

inherit ROOM;


void create()
{
	set("short", "�ݵ�");
	set("long", @LONG
���ǻ���·�Ե�һ��ݵꡣ�������ܻ谵������ʮ�ּ�ª���ݵ���Ļ�
��·������һ������·���������Ƿ�ɽ��������ͨ�����ܣ���������������
��ɽ��·����ⷼ�����һ���к�·�����Ŀ��ˡ�
LONG );

	set("outdoors", "wudang");
	set("exits", ([
		"east" : __DIR__"wdroad6",
		
		]));
	set("objects", ([
	"/d/wudang/npc/huoji" : 1,
	"/d/shaolin/obj/caoliao" : 2,
	
	]));
      setup();
      replace_program(ROOM);
}

