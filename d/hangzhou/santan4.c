// Code of ShenZhou
// ��̶ӳ��
// Dong  11/03/1996.
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{   set("short", "��ͨ��");
    set("long", @LONG
һ�ػ�����ǽ����������������֮�䣬ǽ�����ˣ������νӣ�ǽ
����Ҷ�ƾ����������ġ�ǽ���ɽ��ˮ��һ����¡��ϱ��ǻ���ͤ��
���߹�������һ��Сͤ��
LONG);

    set("exits", ([ /* sizeof() == 2 */ 
        "south" : __DIR__"santan5", 
        "north" : __DIR__"santan3", 
                 ])
       );
    setup();
    replace_program(ROOM);
}