// Code of ShenZhou
//ROOM/d/murong/lianwu1
//arthurgu 1999.9

#include "room.h"
inherit ROOM;

void create()
{
        set("short", "���䳡");
        set("long", @LONG
   ����������������䳡�����ܷ�����ʮ�˰��������˵
Ľ����ͨ�������似�����ܴ��Բ��顣���߿յ���һ��ʯ��,
�����Ϸ·���ϡ�е�ǳǳ��ָ�ۡ�
LONG
        );
      
        set("cost", 1);
        set("exits", ([ 
        "enter" : __DIR__"huayuan3",
        "west" : __DIR__"lianwu",
        "east" : __DIR__"sishu.c",
                      ]));
        set("outdoors", "murong");
        create_door("enter","ľ��","out", DOOR_CLOSED);
	 setup();
}

void init()
{
        add_action("do_draw", "draw");
        add_action("do_draw", "hua");
}

int do_draw(string arg)
{
object me = this_player();
        if ( !arg || arg != "table" )
             return notify_fail( "ʲô��\n");
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("ʲô��\n");
if ((int)me->query_skill("finger",1) <= 120 ) {
             me->improve_skill("finger", me->query("str"));
             write( "�������ָ������ʯ���ϻ�����ȥ,�е���ָ��ʹ���ˡ�\n");
          
me->add("jingli", -35);
} else { write( "�������ָ��ʯ���ϻ���,ʯм�������ء�\n");
}
return 1;
}