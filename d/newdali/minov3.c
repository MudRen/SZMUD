// Code of ShenZhou
// minority or tribe village and suburban
// Room: /d/dali/minov3.c

#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "�軨ɽ��");
        set("long", @LONG
����ǲ軨ɽ�����棬��Ȼ��Ȼ�д����Ĳ軨ʢ���ţ�����Ȼ����ɽ�ϵ�Ʒ
�ֺ��ˣ�������ȥ������Ʒ��
LONG);
	set("exits", ([
		"northup" : __DIR__"chhill2",
		"southeast" : __DIR__"minov1",
		]));
	set("area", "���ˮ�ٲ�");
	set("cost", 2);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
