// Code of ShenZhou
// ������
// Dong  11/03/1996.

#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{   
   set("short", "������");
   set("long", @LONG
�����£�ԭ����������Ժ���ֽ��˽��¡�������������������ӵ
��Ȼͦ�������ɽ�������ͻص�����ϡ�
LONG        );

   set("exits", ([ /* sizeof() == 2 */ 
                  "north" : __DIR__"road72", 
                  "enter" : __DIR__"jingci2", 		  
                ])
       );

	set("cost", 1);
   setup();
   replace_program(ROOM);
}
