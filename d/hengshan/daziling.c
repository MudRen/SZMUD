// Room: /d/hengshan/daziling.c
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
�����������ɽ����֮·��ʯ�������� "����" ���֣��߿���
�ɣ������پ��������ۻ롣
LONG);
        set("exits", ([ /* sizeof() == 4 */
           "west"      : __DIR__"yunge",
           "northeast" : __DIR__"zizhiyu",
        ]));
        set("outdoors", "hengshan");
		set("cost", 2);
        setup();
        replace_program(ROOM);
}

