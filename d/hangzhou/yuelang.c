// Code of ShenZhou
// ����
// Dong  11/03/1996.

#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
   set("short", "����");
   set("long", @LONG
������������ǡ��������ա��ĸ����֡����������������
������������������š����Һ�ɽ�������ߵ���ͨ�����أ�������
��ȥ��·��
LONG
        );

   set("exits", ([ /* sizeof() == 2 */ 
                  "north" : __DIR__"yuefen", 
                  "south" : __DIR__"road14", 
                ])
       );

	set("cost", 1);
   setup();
   replace_program(ROOM);
}