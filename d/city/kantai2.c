// Code of ShenZhou
// ��̨

#include <ansi.h>
inherit ROOM;
int do_practice(string arg);
int do_study(string arg);

void create()
{
        set("short", HIG"��̨"NOR);
        set("long",
"��������ʱ����ı��俴̨������������Ĵ�����һ���ų��ʣ��м��ϴ�
һ��յأ�������һ����̨, ���²���һ����죬�׵׺컨�����š�"+HIR"��������"NOR+"��
�ĸ����֣�������������ȭ����ȥ�Ĵ�����֣�������̨������ˮй��ͨ���Ȳ�
��һ��߹�һ��\n"
        );



        set("valid_startroom", 1);

        set("no_fight", 1);
        set("no_practice", 1);

        set("exits", ([
                "up" : __DIR__"leitai",
                "north": "/d/city/yuelao",
        ]));

        set("objects", ([
                 "/d/city/obj/tulip" : 2,
                __DIR__"npc/mu":1,
        ]));

        setup();
        "/clone/board/broker_b"->foo();
        //      replace_program(ROOM);
}

void init()
{
                  add_action("do_practice",  "practice");
                  add_action("do_practice",  "lian");
                  add_action("do_study",  "study");
                  add_action("do_study",  "du");
                  add_action("do_bai", "bai");
                  add_action("do_bai", "apprentice");
}

int valid_leave(object me, string dir)
{
        if( dir=="up" ) {
                if( wizardp(me) || me->query_temp("organizer") ) return 1;
                else return notify_fail("�㲻���Լ���ȥ��\n");
        }

        if( dir=="north" ) {
                if( wizardp(me) || (!me->query_temp("admitted") && !me->query_temp("zhaoqing"))
                  ) return 1;
                else
                {
                        if( me->query_temp("zhaoqing") )
                        {
                                return notify_fail("����Ů����,���ڲ����뿪��\n");
                        }
                        else return notify_fail("����ѡ��,���ڲ����뿪��\n");
                }
        }

        if( dir=="enter" ) {
                if( wizardp(me) ) return 1;
                else return notify_fail("�㲻�ܽ�ȥ��\n");
        }

        return ::valid_leave(me, dir);

}


int do_practice(string arg)
{
                  object me = this_player();
                  tell_object(me, "���ﲻ׼����!\n");
                  return 1;
}

int do_study(string arg)
{
                  object me = this_player();
                  tell_object(me, "���ﲻ׼����!\n");
        return 1;
}

int do_bai(string arg)
{
	object me = this_player();
	tell_object(me, "�������������ʦ��\n");
	return 1;
}
	

