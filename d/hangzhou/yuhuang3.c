// Code of ShenZhou
// ���ɽ��
// Dong  11/03/1996.

#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
   set("short", "���ɽ��");
   set("long", @LONG
�������ɽ�����ɽ�£����Կ��������������˵���ǻʵۼ�
��ũʱ�׸��ļ��ɽ���и��ǹۣ�����Ƴ�������������һ�غͰ�
ʯ��������������ͤ���������߸���һ����ɽ��·��
LONG
        );

   set("exits", ([ /* sizeof() == 2 */ 
                  "eastdown" : __DIR__"yuhuang2", 
                  "westdown" : __DIR__"yuhuang4", 
                ])
       );

	set("cost", 3);
        set("fjing", 1);
        set("outdoors", "hangzhou");
   setup();
   replace_program(ROOM);
}
