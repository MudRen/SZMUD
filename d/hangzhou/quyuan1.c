// Code of ShenZhou
// ��Ժ���
// Dong  11/03/1996.
// Xbc 06/21/1997

#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
   	set("short", "��Ժ���");
   	set("long", @LONG
���С���ţ�ӭ����һͤԺ���Ա�����ʯ�������⡰��Ժ��ɡ���
�����ǻ��յ̡�
LONG );

   	set("exits", ([ /* sizeof() == 2 */ 
                  "east" : __DIR__"suti2", 
  		  "enter" : __DIR__"quyuan2",
                ]));

	set("cost", 1);
        set("outdoors", "hangzhou");

   	setup();
   	replace_program(ROOM);
}
