// Code of ShenZhou
// hs_xiaolu.c ��ɽС·
// xQin 11/00

inherit ROOM;
#include <room.h>
void create()
{
	set("short","��ɽС·");
	set("long", @LONG
�߹����������Ѿ��Ǻ�ɽ��С·����ɽ�����š�Զ����ȥ�м������ɣ�
��ֲ�ͱڣ��������У��֦��չ������ͦ�Σ��������롣����ʫ�����ƣ���
�Ʋ��������Σ��Կ���֦ɨ������
LONG
	);
	set("outdoors", "wudang");
	set("exits", ([
		"north" : __DIR__"zhulin",
		"south" : __DIR__"xiaoyuan",
		]));
		
	create_door("south", "����", "north", DOOR_CLOSED);
	setup();
	replace_program(ROOM);
	
}