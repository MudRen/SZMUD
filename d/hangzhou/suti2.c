// Code of ShenZhou
// �յ�
// Dong  11/03/1996.

#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
   set("short", "�յ�");
   set("long", @LONG
�յ��ϣ��ο����е���������������ʫ����̸���ۣ��е����
��ʯ����ˮ�������е��������ߣ���������������ǿ���ţ�������
�����ţ�������ȥ��Ժ��ɡ�
LONG
        );


   set("exits", ([ /* sizeof() == 3 */ 
                  "south" : __DIR__"suti3", 
                  "north" : __DIR__"suti1", 
  		  "west" : __DIR__"quyuan1",
                ])
       );

	set("cost", 1);
        set("fjing", 1);
        set("outdoors", "hangzhou");
   setup();
   replace_program(ROOM);
}
