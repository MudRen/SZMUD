  // Code of ShenZhou
// gate.c

#include <ansi.h>

inherit ROOM;


int update_player(object me);

void create()
{
        set("short", HIW "���Ź�" NOR);
        set("long", 
                "�������������������ڡ����Źء���������ǰ������һ���ߴ��\n"
                "��ɫ��¥����\���������޿�������ж�ǰ������Ϊһ�����Źؾ��޷���\n"
                "�������ˡ�\n");
        set("exits", ([
                "north" : "/d/death/gateway",
        ]) );
        set("objects", ([
                __DIR__"npc/wgargoyle":1
        ]) );
        set("no_fight", 1);
        set("cost", 0);
        setup();
}

void init()
{

        object *inv, me=this_player();
        int i;

        inv = all_inventory(me);
                for(i=0; i<sizeof(inv); i++) {
                        if( inv[i]->is_character())continue;
                destruct(inv[i]);
                }

        me->clear_condition();
        me->delete("get_pinang");
        me->delete_temp("pixie");

        if ( me->query_temp("sanxiao") )
        {
        me->delete_temp("sanxiao");
        me->delete_temp("smile");
        }

        add_action("do_suicide","suicide");
        me->set("jingli", me->query("max_jingli"));

                if(me->query("name")!="���޳�")
                {
                        if(!me->query("death_update"))
                        {
                                me->set("death_update", 1);
                                update_player(me);
                        }
                }
}


int update_player(object me)
{
        object env, link_ob, obj;

        env = environment(me);

        // First, create the new body.
        link_ob = me->query_temp("link_ob");
        obj = LOGIN_D->make_body(link_ob);
        if (!obj) return 0;

        // Save the data and exec the player to his/her link object.
        me->save();
        exec(link_ob, me);
        destruct(me);

        // Restore new body and exec to it via enter_world in LOGIN_D
        obj->restore();
        LOGIN_D->enter_world(link_ob, obj, 1);

        write("���������ϡ�\n\n");
        obj->move(env);
        obj->write_prompt();

        return 1;
}


int do_suicide(string arg)
{
        object me = this_player();
        tell_object(me, "�㻹�����ء�\n");
        return 1;
}
