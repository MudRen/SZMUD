// Code of ShenZhou
// ����ɽ·
// Dong  11/03/1996.

#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
   set("short", "ɽ·");
   set("long", @LONG
�����������Ǻܿ��ɽ·�ϣ�ֻ�����Է�����������ɫ���ˡ�һ
��СϪ��·������������Ϫ����һũ�ҡ�ɽ��С����ʹ������������
֮�⡣���ϱ㵽�������á����¾��������á�
LONG
        );

   set("exits", ([ /* sizeof() == 2 */ 
                  "southup" : __DIR__"tianzhu3", 
                  "northdown" : __DIR__"tianzhu1", 
                ])
       );

	set("cost", 2);
        set("outdoors", "hangzhou");
   setup();
   replace_program(ROOM);
}