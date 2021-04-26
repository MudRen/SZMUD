// Code of ShenZhou
// xiaoer.c

#include <ansi.h>

inherit NPC;

string ask_me(string, object);

void create()
{
        set_name("��С��", ({ "xiao er", "xiao", "waiter" }) );
        set("gender", "����" );
        set("age", 22);
        set("long",
                "��λ��С����Ц�����æ��������ʱ������ڲ����ϵ�Ĩ��������\n");
        set("combat_exp", 100);
        set("attitude", "friendly");
        set("rank_info/respect", "С����");

        set("chat_chance", 3);
        set("chat_msg", ({
                "��С�������͹٣��������֪������Ļ������ҿ����Ҷ����ˣ� ������ ������ ... \n",
                "��С�����������ӱ�����������úܣ� ���������Ĵ�ү�������С���Ǽ���Ǯ�����еû��ˣ�\n",
        }) );

        set("inquiry", ([
                "��ľ��"   : (: ask_me, "heimuya" :),
                "��ľ��" : "�������ߵĲ�Զ�и���ľ�֣���ǰ�кܶ��Է�ȥ��ľȴ��Ҳû�л�������\n",
                "���½�"   : (: ask_me, "ryj" :),
                "�������"   : (: ask_me, "rysj" :),
                "rumors" : (: ask_me, "yaoyan"  :),
                "here" : (: ask_me, "fengtu"  :),
        ]));

        setup();
}

void init()
{       
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() && !query_temp("leading")) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(2) ) {
                case 0:
                        say( "��С��Ц�����˵������λ" + RANK_D->query_respect(ob)
                                + "�������ȱ��裬ЪЪ�Ȱɡ�\n");
                        break;
                case 1:
                        say( "��С���ò����ϵ�ë��Ĩ��Ĩ�֣�˵������λ" + RANK_D->query_respect(ob)
                                + "����������\n");
                        break;
        }
}

int accept_object(object who, object ob)
{
        if (ob->query("money_id") && ob->value() >= 500) 
        {
                tell_object(who, "С��һ������˵������л���ϣ�С�ĸ���ͷǰ��·���͹��������¥ЪϢ��\n");
                who->set_temp("rent_paid",1);
                set_temp("leading", 1);
                remove_call_out("do_up");
                call_out("do_up", random(5), this_object(), who);
                return 1;
        }

        else if (ob->query("money_id") && ob->value() >= 10) 
        {
                tell_object(who, "С��æ����Ц�ݣ�˵������л���ϣ���ʲô�����������ʣ���\n");
                who->set_temp("ready_ask",1);
                return 1;
        }

        return 0;
}

string ask_me(string name, object ob)
{
        if ( name == "heimuya" )
        command("fear");

        if ( name == "ryj" )
        command("fear");

        if ( name == "rysj" )
        command("fear");

        if ( name == "yaoyan" )
        command("shake2");

        if ( name == "fengtu" )
        command("smile2");

        return 0;
}

int accept_kill(object obj)
{
        command("chat ��λ�͹پ������� " + obj->name() + "���" + RANK_D->query_rude(obj
) + "Ҫɱ���ң�");
}

void do_up(object me, object who)
{
        who->set_leader(me);
        command("go up");                        
        
        tell_object(who, "С��Ц������˵���͹������ҶԵط��ˣ���������Ǳ�����ɾ��Ŀ͵ꡣ
С����˵�ߴ�����ժ��һ��Կ�ף��ҳ�һ�������㿪�š�\n");

        remove_call_out("do_enter");
        call_out("do_enter", random(5), me, who);
}

void do_enter(object me, object who)
{
        who->set_leader(me);
        command("go enter");
        
        tell_object(who, "С������ЦЦ��˵���ⷿ��ܲ����!
�͹����ú���Ϣ��С��ȥæ�ˣ���ʲô�¾��ܷԸ���\n");

        who->set_leader(0);
        command("go out");
        command("go down");
        me->set_temp("leading", 0);
}
