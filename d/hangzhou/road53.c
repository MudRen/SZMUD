// Code of ShenZhou
// ����ɽ
// Dong  11/03/1996.
#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
   set("short", "��·");
   set("long", @LONG
·�Ķ�����һ��Сɽ��ɽ�������дУ�����������ɽ�ϱ���һ��
���������ĺõط�����ȴ��������ռΪ˽�С���·�򶫱��������졣
LONG
      );

   set("exits", ([ /* sizeof() == 2 */ 
                  "northeast" : __DIR__"road52", 
                  "south" : __DIR__"road54", 
                ])
       );
	set("objects",([
                "/d/taishan/npc/tiao-fu" : 1,
        ]));   
	set("cost", 1);
        set("outdoors", "hangzhou");
   setup();
   replace_program(ROOM);
}
