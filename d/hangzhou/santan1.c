// Code of ShenZhou
// ��̶ӳ��
// Dong  11/03/1996.
// Need to add connection to boat.

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{   set("short", "������ӡͤ");
    set("long", @LONG
�߽�ͤ������һ������ɿ����Ϻ����е�����ʯ���������в���
�գ����������СԲ����ÿ����µ��գ��ο��Ƿ׷������˴�������
���¹�ӳ̶��Ӱ��Ϊ��������̶ӳ�¡��������������߶���һ��
�غ�ʯ·��������һ������ʯ�š�
LONG);

    set("exits", ([ /* sizeof() == 3 */ 
        "north" : __DIR__"santan6", 
	"northeast" : __DIR__"santan2",
	"northwest" : __DIR__"santan7",
                 ])
       );
    setup();
    replace_program(ROOM);
}