// Code of ShenZhou
// ��̶ӳ��
// Dong  11/03/1996.
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{   set("short", "��ͤ");
    set("long", @LONG
���ھ���ʯ���ϣ�ֻ�����ű�˯������������ʯ�βҡҷ������
����һ��Сͤ��
LONG);

    set("exits", ([ /* sizeof() == 2 */ 
        "north" : __DIR__"santan5", 
        "south" : __DIR__"santan1", 
                 ])
       );
    setup();
    replace_program(ROOM);
}