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
��������ǰ���У���������м�Ĵ��۱�����Ϊ׳�ۡ����۱��
������㣬��ɫ�������ݶ����ر��Եľ�����ΰ�����ȵ������ڲ���ĺ
���лص������ﶯ�������������ʮ��֮һ���������ӡ���������
LONG        );

   set("exits", ([ /* sizeof() == 1 */ 
                  "out" : __DIR__"jingci1", 
                ])
       );

	set("cost", 1);
   setup();
   replace_program(ROOM);
}
