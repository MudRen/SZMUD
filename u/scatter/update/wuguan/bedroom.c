//Modified By Zyu on k1-8-3
// Room: bedroom.c �����Ϣ��

#include <room.h>

inherit ROOM;
void wakeup(object me, object where);
void do_counter();

void create()
{
        set("short", "�����Ϣ��");
        set("long", @LONG
����������ݵ���Ϣ�ҡ���ʰ�÷ǳ��ɾ�������Ҳ�Ƿǳ��ļ򵥡���
ǽ���м���ľ�������Ŵ�����һ�����ӡ�
LONG
        );

        set("no_fight", 1);
        set("exits", ([ 
                "east" : __DIR__"houting",
        ]));

        set("cost", 1);
//          set("sleep_room", 1); 
        setup();
}

void init()
{
      if (this_player()->query_temp("mark/��") && this_player()->query("combat_exp") <= 6000)
        add_action("do_sleep", "sleep");
}

int do_sleep(string arg)
{
        object me, where;
        
        me = this_player();
        where = environment(me);

        seteuid(getuid());


                //ADD BY SCATTER TO ENSURE THAT NO FLOOD SLEEPING
                if(me->query_temp("wuguan/stime"))
                        return notify_fail("˯̫������岻��ร�\n");
                //ADD BY SCATTER TO ENSURE THAT NO FLOOD SLEEPING


        if (me->is_busy())
                return notify_fail("����æ���أ�\n");

        write("��������һ�ɿ�ʼ˯������һ���˯���ˡ�\n");
        me->set_temp("block_msg/all",1);
        message_vision("$N������һ�ɿ�ʼ˯������һ���˯���ˡ�\n",me);

        where->add_temp("sleeping_person", 1);
        
        me->set_temp("sleeped",1);

        me->set("disable_type", "<˯����>");
        me->set_temp("disabled", 1);
        me->disable_commands();
        me->enable_commands();

//      call_out("wakeup",random(30 - me->query("con")), me, where);
        call_out("wakeup",3, me, where);
        return 1;
}

void wakeup(object me, object where)
{
        int sp, new_hp;
        int add_jn, add_nl;
        sp = 10 - (int)me->query_condition("sleep");

        if ( !random(19) )
        {
                add_jn = (int)me->query("max_jingli") + 1;
                add_nl = (int)me->query("max_neili") + 1;
                if ( me->query("max_neili") < 600 )
                        me->set("max_neili", add_nl);
                if ( me->query("max_jingli") < 600 || me->query("eff_jingli") < 600 ){
                        me->set("max_jingli", add_jn);
                        me->add("eff_jingli", 1);}
        }

        new_hp = (int)me->query("eff_qi");
        if (new_hp < 0) new_hp = 0; 
        me->set("qi", new_hp);
        
        new_hp = (int)me->query("eff_jing");
        if (new_hp < 0) new_hp = 0; 
        me->set("jing", new_hp);

        new_hp = (int)me->query("max_jingli");
        if (new_hp < 0) new_hp = 0; 
        me->set("jingli", new_hp);

        new_hp = (int)me->query("max_neili");
        new_hp += ((int)me->query("max_neili") - new_hp)*sp/10;
        if (new_hp < 0) new_hp = 0; 
        if (new_hp > (int)me->query("max_neili") ) new_hp = me->query("max_neili");
        me->set("neili", new_hp);
        
        if (living(me)) return;

        me->enable_player();
        while( environment(me)->is_character() )
                me->move(environment(environment(me)));
        me->apply_condition("sleep", 2 + random(3));

        message_vision("$Nһ�����������һ�½�ǣ���ص����������������\n",me);
        me->set_temp("block_msg/all", 0);
        write("��һ�����������һ�½�ǣ���ص����������������\n");

        where->add_temp("sleeping_person", -1);


                //ADD BY SCATTER TO ENSURE THAT NO FLOOD SLEEPING
                me->add_temp("wuguan/stime", 6);
                do_counter();
                //ADD BY SCATTER TO ENSURE THAT NO FLOOD SLEEPING

                
        setup();
}



//ADD BY SCATTER TO ENSURE THAT NO FLOOD SLEEPING
void do_counter()
{
        object me=this_player();

        if( me->query_temp("wuguan/stime") > 0 )
        {
                me->add_temp("wuguan/stime", -1);
                remove_call_out("do_counter");
                call_out("do_counter", 1);
        }

        if( me->query_temp("wuguan/stime") < 1 )
        {
                me->delete_temp("wuguan/stime");
        }

        return;
}
//ADD BY SCATTER TO ENSURE THAT NO FLOOD SLEEPING
