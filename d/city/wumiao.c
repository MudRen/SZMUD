// Code of ShenZhou
// Room: /city/wumiao.c // YZC 1995/12/04
// modified by sdong to add Santa, 12/25/98
// Modified by Sure to add color, /17/2000
// Ssy plan to add a west link from this room to web room 09/22/2000
// Haowen disable door in order to reduce robot flooding 09/28/2000
// Mantian remove Ssy west room path since mirror and @us ppl can't access wiz tree 05/12/2001
//angelo add one more exit "down" to access the histroom for SZ 06/06/02
#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
        set("short", RED"����"NOR);
        set("long", 
"�����������������������������Ϸ������������顰���Һ�ɽ���ĺ�
�ҡ����������Ƕ�š����ұ������ĸ����֡����˵��ˣ��������������Ϲ��Ͼ�
��������ݡ��Ա��ƺ���һ������.��Լ����̨�º�����һ����.\n"
        );

        set("no_fight", "1");
        set("no_steal", "1");
        set("no_sleep_room", "1");
      set("valid_startroom", 1);

        set("objects", ([
                __DIR__"obj/box" : 1,
        ]));

        if( strsrch(ctime(time()), "Dec 25") != -1 )
        {
                set("objects", ([
                        "/kungfu/class/misc/santa" : 1,
                        "/u/lisser/npc/angel" : 1,
                ]));
        }

        set("exits", ([
                "east" : __DIR__"beidajie2",
                "northwest": "/d/wizard/guest_room",
 //              "west": "/u/ssy/webroom",
                      "down": "/u/angelo/histroom", 
//              "north" : "/u/oyxb/zhanbuwu",
        ]));

   //     create_door("northwest", "����", "southeast", DOOR_CLOSED);
        set("cost", 0);
        setup();
        call_other("/clone/board/wumiao_b", "???");
}

void init()
{
        add_action("do_exercise",  "exercise");
        add_action("do_exercise",  "dazuo");
        add_action("do_respirate",  "respirate");
        add_action("do_respirate",  "tuna");
        add_action("do_practice",  "practice");
        add_action("do_practice",  "lian");
        add_action("do_study",  "study");
        add_action("do_study",  "du");
        add_action("do_feed", "feed");
                add_action("do_check", "check");
}

int do_check(string arg)
{
        object me = this_player();
        if(!me->query("shenzhou/pts"))
        {
                tell_object(me, "��Ŀǰû�ж��������κι��ף�\n");
        }

        else
        {
                tell_object(me, "��Ŀǰ�����ݵĹ��׶�Ϊ " + me->query("shenzhou/pts") + " �㣡\n");
        }
        return 1;
}
        

int do_exercise(string arg)
{
        object me = this_player();
        tell_object(me, "�����������ֻ�����Ļ����ң�ȫ��������Ҳ�޷�����������\n");
        return 1;
}

int do_respirate(string arg)
{
        object me = this_player();
        tell_object(me, "�����������ֻ�����Ļ����ң�ȫ������Ҳ�޷�����������\n");
        return 1;
}

int do_practice(string arg)
{
        object me = this_player();
        tell_object(me, "����վ������ȴ���û�����ȫ���᲻��һ˿������������\n");
        return 1;
}

int do_study(string arg)
{
        object me = this_player();
        tell_object(me, "��ֻ�����Դ��﷢�Σ��鱾��һ�����ֶ�������ȥ����Ҳ������ȥ��\n");
        return 1;
}

int do_feed(string arg)
{
        object me = this_player();
        tell_object(me, "�㷢�����еĶ��ﵽ�����ﶼ���Զ�����\n");
        return 1;
}

int valid_leave(object me, string dir)
{
      object *inv;
        int i;
        inv = all_inventory(me);
           if ( dir == "east" || dir = "northwest") {
                // can not got to any where if they take players
                for (i=0; i<sizeof(inv); i++) {
                        if ( userp(inv[i]) )
                        return notify_fail("�㲻�ܴ�����������뿪���\n");
                         }
        }
           me->set_temp("mark/����", 0);
        return ::valid_leave(me, dir);
}          
