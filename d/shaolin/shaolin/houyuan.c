// Code of ShenZhou
// Room: /d/shaolin/houyuan1.c
// xiaojian Aug.23,2000
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "������Ժ");
        set("long", @LONG
���ǳ����ĺ�Ժ��Ժ��������˸���������Ҳ���,����
û�����֮��,�����þ�û�˴�ɨ�ˡ�
LONG
        );

        set("exits", ([
        "south" : __DIR__"chufang",
	     ]));

        set("outdoors", "shaolin");
        set("cost", 1);

        setup();
		replace_program(ROOM);
}
