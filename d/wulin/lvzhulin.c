// room /d/wulin/lvzhulin.c
// Lara 2001/10/13
#include <ansi.h>
inherit ROOM;
void create()
{   
   set("short", "������");
   set("long", @LONG
���߽���һƬ������ε������֣�ʱ���м�ֻС�񷢳����Ľ�����
һ��紵�������ַ���һ���ö������ġ�ɳɳ����������������ʱ��ʱ��
���������γ���һ����������֣��ø�������ң�����ڡ�
LONG   );

    set("exits", ([
		"north" : __DIR__"xiaowu",
                "south" : __DIR__"houyuan",
    ]));
    
    setup();
}
