// Code of ShenZhou
// ������
// Dong  11/03/1996.
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{   set("short", "����");
    set("long", @LONG
�����񷶥�ϵ�ʯ���������һ����⣬��������һ���족����
�ϱ�����ɽ��·��
LONG);
    set("exits", ([ /* sizeof() == 1 */ 
        "southeast" : __DIR__"feilai1",
        ])
       );
	set("cost", 3);
    setup();
    replace_program(ROOM);
}