// Code of ShenZhou
// �غ����
// Dong  11/03/1996.

#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
   set("short", "�غ����");
   set("long", @LONG
һ�����Ĵ����ȴ����ϡ�١�ԭ��������·ס�ŵĶ��Ǵ�ٹ�
�ˡ������羰����֮����ȴ�Ե�һƬ��ɪ��·��������һ��ׯ԰����
�����ϱ����졣
LONG
      );

   set("exits", ([ /* sizeof() == 3 */ 
                  "north" : __DIR__"road15", 
                  "south" : __DIR__"road52", 
                  "west" : __DIR__"guoz1", 
                ])
       );

	set("cost", 1);
        set("outdoors", "hangzhou");
   setup();
   replace_program(ROOM);
}