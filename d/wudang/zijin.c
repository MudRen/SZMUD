// Code of ShenZhou
// zijin.c �Ͻ�� 
// by Fang 8/20/96

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"�Ͻ��"NOR);
	set("long", @LONG
�����ػ������Ͻ��ǽ���ܳ������ǽ�ɻ���ʯ��ɽ�����ɣ�������
���ž����پ��ڣ�����Ϊ����·�ڣ�����׳�ۡ�
LONG
	);
        set("outdoors", "wudang");

	set("exits", ([
		"north" : __DIR__"jinding",
		"south" : __DIR__"jindian",
	]));
	set("cost", 1);
	setup();
	replace_program(ROOM);
}

