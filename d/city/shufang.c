//Cracked by Yujie
// Room: /city/shufang.c
// by 2001/9/13

#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "�챦���鷿");
        set("long", @LONG�����ݡ�����������ǳ������СС������
�����з���һ����Ĺ�����������һ��һ���³ɵĲݸ壬�Ա�Χ��һȺ����
��ͷ����Ļ��ѧͽ�������鷿������һ��Ũ������ζ��
LONG
        );
        set("exits", ([
                "out" : __DIR__"beidajie1",
        ]));

        set("objects", ([
                "/d/huanghe/npc/shutong" : 1,
        ]));

        set("no_fight",1);
        set("no_sleep",1);
        set("cost", 0);
        setup();
}

void init() 
{ 
  write(HIG"һ�߽�����ӭ�������һ�����㣬���ʱ������ˬ����������꽭��ٲ���������硣\n"NOR);
        add_action("do_exercise",  "exercise");
        add_action("do_exercise",  "dazuo");
        add_action("do_respirate",  "respirate");
        add_action("do_respirate",  "tuna");
        add_action("do_practice",  "practice");
        add_action("do_practice",  "lian");

}

int do_exercise(string arg)
{
        object me = this_player();
        tell_object(me, "�����㻹��ר�ĳ���ɣ�\n");
        return 1;
}

int do_respirate(string arg)
{
        object me = this_player();
        tell_object(me, "�����㻹��ר�ĳ���ɣ�\n");
        return 1;
}
int do_practice(string arg)
{
        object me = this_player();
        tell_object(me, "�������鷿�����ֻ��ŵĿɲ��Ź�Ŷ��\n");
        return 1;
}


int valid_leave(object me, string dir) 

{ 

if (present("booktool",me))

return notify_fail("����Ҫ��ʼ����Ŷ����;���Ͽɲ��ԡ�\n"); 

return ::valid_leave(me, dir); 
}



