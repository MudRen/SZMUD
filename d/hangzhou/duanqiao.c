// Code of ShenZhou
// ����
// Dong  11/03/1996.
#include <ansi.h>
#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
   set("short", HIG"����"NOR);
   set("long", @LONG
�������������������ķ�ˮ���ϡ�����ͤ�����䣬��ӳ����������֮�¡�
��ɽ��ˮ����������������������������������������ľ�ɫ���ڶ���
�Ͽ����������ɽ�ͺ�����ķ�⡣ÿ��ѩ�ᣬվ����ͷ��ֻ��һ�ж���
���ϰ�ѩ��������¥�ĺ�ɽ��ò��������ʮ��֮һ�ġ����Ų�ѩ���������
�������ߴ����еİ���������ɾ����������ġ�
���������߱��ǰ׵��ˡ������߿�ͨ����ʯ�����
LONG
        );


   set("exits", ([ /* sizeof() == 1 */
			"northeast": __DIR__"road11",
                  "west" : __DIR__"baiti", 
                ])
       );
       
	set("cost", 2);
      set("fjing", 1);
        set("outdoors", "hangzhou");
   setup();
   replace_program(ROOM);
}
