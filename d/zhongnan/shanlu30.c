// Code of ShenZhou
// road: /zhongnan/shanlu30.c
// by sdong 08/98

inherit ROOM;
#include <ansi.h>
int do_climb(string arg);

void create()
{
                  set("short",HIC"����"NOR);

                  set("long",@LONG
����ǰ��һ�����£������¸ߴ���ʮ�ɣ����ʽ��ƣ���Щ�ط�ֱ��ǽ��һ��
���ͣ��������涼�����ҹ�ʯ���޿���Ԯ (climb)����ֻ�޴�ĺڵ������ڿ��С�
�˶�С·���߶����Ӳݣ������ߵ��˲��࣬���ܵľ�ɫ��Խ��Խ�����������Ѿ�
�쵽ɳĮ�ˡ���������һ��С·������ͨ��ɳĮ��
LONG);

                  set("exits",([ "west" : __DIR__"desert1",
                                                                "southeast" : __DIR__"shanlu29",
                                                  ])
                          );
          set("cost",4);
          set("fjing",1);
          set("outdoors", "zhongnan");
          setup();
}

void init()
{
        add_action("do_climb", "climb");
}

int do_climb(string arg)
{
        object me = this_player();
        int gain,cost;

        if(me->is_busy())
                return notify_fail("�㻹��æ���ء�\n");

        cost = ( 300-me->query_dex()*me->query_skill("dodge")/20 )/10;
        if ( cost<5 )cost = 5;

        if( me->query("jingli") < 30)
                return notify_fail("���۵�ʵ���������ˡ�\n");

        me->add("jingli",-cost);
        gain = me->query("con",1)*2;

        if ( me->query_skill("dodge") > 200 ) gain /= 2;



        if(arg == "up" )
        {
                message_vision( HIY"\n$N�����������ٸ���һ����������ȥ��\n"NOR, me);
                me->move("/d/zhongnan/xuanya1");
                message_vision( HIY"\n$N����������\n"NOR, me);
                me->start_busy( 1 );
                me->improve_skill( "dodge",gain+random( gain ) );
                if( me->query_skill( "jinyangong",1) > 0 )
                        me->improve_skill( "jinyangong",random( gain ) );
                return 1;
        }

        return notify_fail("�Ǹ�����û������\n");
}
