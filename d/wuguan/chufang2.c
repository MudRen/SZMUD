// Room: /d/wuguan/chufang2.c
// ϴ��������֮����

#include <ansi.h>
inherit ROOM;

void create ()
{
        set ("short", "����");
        set ("long", @LONG
�����Ȫ����ݵĳ������ɾ����룬ǽ�ߵĹ�����������������
�;ߡ�������һ����һ��СС��ˮ�أ������������ˮ������������
ϴ��xi��Щʲô��
LONG);
        set("no_dazuo",1);
        set("no_kill",1);
        set("no_fight",1);
        set("out_door","pingan");
        set("can_wash",1);
        
        set("exits", ([ /* sizeof() == 1 */
               "east" : __DIR__"chufang",
        ]));
        setup();
}

void init()
{
        add_action("do_xi","xi");
}

int do_xi(string arg)
{
        object me, ob; 
        me=this_player();
        
        if ( !arg || arg != "panzi" )
                return notify_fail("��Ҫϴʲô��\n");
        
        if ( !me->query_temp("gongzuo/xipanzi") )
                return notify_fail("�㻹����ȥ�������Ӵ���к��ɡ�\n");
        if ( !(ob = present("zang panzi", this_player() )) )
                return notify_fail("��û�������ӣ���ô��ϴ�أ�\n");
        if ( (int)me->query("jing")<20)
                return notify_fail("��̫���ˣ�ЪϢ�°ɡ�\n");
        if ( me->query_temp("gongzuo/xipanzi") >= 6 )
                return notify_fail("����ϴ���ˣ��ͻ��������Ƕ��ɡ�\n");
   
        message_vision("$N�ӳ���������ˮ����ʼ������ϴ���ӡ�\n",me);
        me->add("jing",-(10 + random(10)) );
        me->add_temp("gongzuo/xipanzi", random(3) );
        if ( (int)me->query_temp("gongzuo/xipanzi") >=6 ) {
                
                message_vision(CYN"$Nϴ�����ã����ڽ�����ȫ��ϴ���ˡ�\n"NOR, me);
                tell_object(me,"���۵�ֱ���������ˣ�����Ϣһ�°ɣ�\n");
                me->start_busy(3);
                
                ob->set_name( "����" , ({"pan zi"}));
                ob->set("long","һ����ϴ�õ����ӡ�\n");
        }
        return 1;
} 
