// Code of ShenZhou
// �����͵�
// Dong  1/20/1996.

// NTD:  NPC and object. ��ơ�

#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{   set("short", "�����͵�");
    set("long", @LONG
��ҿͽ���������Ϊ�˷�����Щ����������ο͡������װ�ι�
�ӣ����Ҳʮ�����顣
LONG);

    set("exits", ([ /* sizeof() == 1 */ 
                   "out" : __DIR__"beihai", 
                 ])
       );

    setup();
    replace_program(ROOM);
}