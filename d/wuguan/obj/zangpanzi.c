// ������100�����II
// panzi.c ϴ�õ�����
// ����lywin 2000/6/1 ��ͯ��
// recode by sinan@sz 2002_3_29
// ������ϴ��������ӣ���ϴ���ӵķ���set("can_wash",1)

#include <ansi.h>
inherit ITEM;


void create()
{
        set_name( "������" , ({"zang panzi"}));
        set_weight(3);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ���ո��ù��������ӡ�\n");
                set("value",0);
        }
        
        setup();
}

/*
void init()
{
        add_action("do_xi","xi");
}


int do_xi(string arg)
{
        object me, ob; 
        me=this_player();
        
        if ( !me->query_temp("gongzuo/xipanzi") )
                return notify_fail("�㻹����ȥ����С������к��ɡ�\n");
        if ( !arg || arg != "panzi" )
                return notify_fail("��Ҫϴʲô��\n");
                
        if ( !environment(me) || !environment(me)->query("can_wash"))
                return notify_fail("��ֻ���ڳ�����ϴ���ӡ�\n");
                
        if ( !(ob = present("zang panzi", this_player() )) )
                return notify_fail("��û�������ӣ���ô��ϴ�أ���\n");
        if ( (int)me->query("jing")<20)
                return notify_fail("��̫���ˣ�ЪϢ�°ɡ�\n");
        if ( me->query_temp("gongzuo/xipanzi") >= 6 )
                return notify_fail("����ϴ���ˣ��ͻص�С���Ƕ��ɡ�\n");
   
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
*/
