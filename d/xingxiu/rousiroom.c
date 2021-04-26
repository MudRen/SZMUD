// Code of ShenZhou
// /d/xingxiu/rousiroom
// haowen Mar 31,1999

inherit ROOM;
#include <ansi.h>
void create()

{
        set("short", "��˿����");
        set("long", @LONG
������ƺ���ǧ˿���Ʋ������㣬�������á����ƺ����Գ�������(break)һ�¡�
LONG
        );
        set("indoors", "xingxiu");
        set("cost", 1);
        set("invalid_startroom", 1);
        set("no_fight", "1");
        set("no_steal", "1");
        set("no_sleep_room", "1");

        setup();
//        replace_program(ROOM);
}

void init()
{
        add_action("do_break", "break");
        add_action("do_practice", "practice");
        add_action("do_practice", "lian");
        add_action("do_practice", "dazuo");
        add_action("do_practice", "exercise");
        add_action("do_practice", "tuna");
        add_action("do_practice", "respirate");
        add_action("do_practice", "read");
        add_action("do_practice", "study");
        add_action("do_practice", "quit");
}

int do_practice()
{
        write("�������ֽű������޷��ж���\n");
        return 1;
}

int do_break()
{
        object dest,ob,me,*ob1;
        int i;
        me=this_player();
	if ( !me->query_temp("current_catcher") ) return 0;
        dest=find_player(me->query_temp("current_catcher"));
        if(!dest)
        {
                me->delete_temp("current_catcher");
                me->move("/d/xingxiu/riyuedong");
                tell_object(me,"��֪��ʲôʱ����˿���Ѿ��ɿ���Ҳ��֪����ô�������\n");
                return 1;               }       
//      ob=present("��˿��",dest);


        ob1=all_inventory(dest);
        for (i=0;i<sizeof(ob1);i++)
                {
                if (ob1[i]->query("name")=="��˿��")
                        ob=ob1[i];
                }

        if (!ob || !ob->query_temp("catched")||
		ob->query_temp("catched")!=me->query("id"))/*handle all the errors,won't stuck in here*/
                {
                me->delete_temp("current_catcher");
                me->move("/d/xingxiu/riyuedong");
                if(ob) {ob->delete("no_drop");
                        ob->delete_temp("catched");}
                tell_object(me,"��֪��ʲôʱ����˿���Ѿ��ɿ���Ҳ��֪����ô�������\n");
                return 1;               }
        if (me->query("neili")<100)
                return notify_fail("�������̫�ͣ�����������\n");

        me->add("neili",-200);
        if (random(me->query_skill("force",1)+(me->query("combat_exp")/1000))>random(dest->query_skill("force",1)+(dest->query("combat_exp")/1000)))
                {               
                me->delete_temp("current_catcher");
                ob->delete_temp("catched");
                ob->delete("no_drop");
                me->move(environment(dest));
                message_vision("$N����������һԾ������\n",me);
                }
        else {

tell_object(environment(dest),HIY"��˿���е���ƴ��Ť��Ťȥ������û���κ����á�\n"NOR);  
                tell_object(me,"��ƴ�������������޷�ͻ��������\n");
        }
        return 1;
}

