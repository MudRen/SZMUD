// room /d/wulin/houyuan.c
//updated by Lara 2001/10/17
#include <ansi.h>
inherit ROOM;

void create()
{   
   set("short", "��Ժ");
   set("long", @LONG
����һ�������Ժ�ӣ����ÿ�����㣬��ʵ��߽��ġ������������
�ͻ�������������������������������ɾգ������������̤ѩ��һ��
�����Ժ����;�������ƽ�ͣ������������еķ�����
LONG   );

    set("exits", ([
		"north" : __DIR__"lvzhulin",
                "south" : __DIR__"dating",
    ]));
    
    setup();
}
void init()
{
    object me;
    me=this_player();
    if (!interactive(me)) return;
    me->delete_temp("houyuan");
    return;
}
