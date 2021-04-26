// Code of ShenZhou
// room /d/murong/tingyu.c
// arthurgu  1999.9

#include <ansi.h>
inherit ROOM;

void create()
{   
   set("short", "�����");
   set("long", @LONG
   ���Ǹ������Ǵ���Сľ��,��ս��ں��ϣ�����ȥ
�ƺ���û���ر�֮����ľ�ݵ��м����һ������(qin)��
�����е�Ź�.
LONG   );

   set("item_desc", ([
        "qin" : "���ٱ�֮Ѱ�������ٶ��˳���ȴ�оŸ����ң���ɫ������ͬ��\n"
                "��֪����(tan)�����ò�������\n",
   ]));

    set("exits", ([
		"west" : __DIR__"road1",
    ]));
    
    setup();
}

void init()
{   add_action("do_tan", "tan"); }

int do_tan (string arg)
{   object room;
    object ob = this_player();
    if (!arg||arg!="qin") return notify_fail("��Ҫ��ʲô��\n");
    message_vision("$N�����������һ��������һ����������Ϊ������\n\n"
                   +"ԭ�������ǽ�������.....\n" 
                   +"$N������䣬�����ŵ�һ�飬��������ֱ��.....\n", ob );
    tell_object(ob, "\n���̲�ס��Ӵһ�����������һ������������ڣ�ֻ���Լ��Ѵ���һֻС��֮�С�\n\n" ) ; 
   
    ob->move("/d/murong/boat1") ;

    return 1 ;
}



