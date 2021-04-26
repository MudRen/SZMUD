// Code of ShenZhou
// xian. ���ϰ�

#include <ansi.h>
#include <dbase.h>

inherit NPC;
inherit F_VENDOR;
// inherit F_DEALER;

string ask_me();

void create()
{
        set_name("���ϰ�", ({ "xian laoban", "xian" }));
        set_color("$YEL$");
        set("title", "����¥�ϰ�");
        set("shen_type", 1);

        set("str", 20);
        set("gender", "����");
        set("age", 45);
        set("long", "���ϰ徭Ӫ�洫����������¥���ж��ꡣ\n");
        set("combat_exp", 50000);
        set("qi", 300);
        set("max_qi", 300);
        set("attitude", "friendly");
        set_skill("unarmed", 60);
        set_skill("dodge", 60);
        set_temp("apply/attack", 30);
        set_temp("apply/defense", 30);
        set("vendor_goods", ({
                __DIR__"obj/hdjiudai",
                __DIR__"obj/kaoya",
                __DIR__"obj/nuerhong",
                __DIR__"obj/ham",
                      "/d/city/obj/wine", 
                      "/d/city/obj/tofu", 
                      "/d/city/obj/xihulongjing", 
                "/d/city/obj/yrou",
                "/d/city/obj/thfish",
                "/d/city/obj/santaoya",
//"/u/missing/tangyuan",  
        }));
        set("inquiry", ([
            "ϲ��" : (: ask_me :),
            "ϲ��" : (: ask_me :),
            "��ϲ��" : (: ask_me :),
            "��ϲ��" : (: ask_me :),
            "���ϯ" : (: ask_me :),
        ]) );
                
        setup();
//         add_money("gold", 1);
}

void init()
{
        ::init();
        add_action("do_buy", "buy");
        add_action("do_list", "list");
}

int ask_me()
{
        object me, bride, *players;
        
        if (query_temp("busy")) {
                write("Ӵ����Ǹ�����������æ���ء��������Ժ�\n");
                return 1;
        }
                                
        me = this_player();
        
        if( objectp(me->query_temp("marriage/accept")) ) {
                message_vision(CYN "$NЦ���еض�$n˵����������ô������? ���ɹٶ��Ķ�ȥ��? \n" NOR,
                        this_object(), me);
                return 1;
        }       
        
        if( objectp(me->query_temp("marriage/ring")) ) {
                message_vision(CYN "$NЦ���еض�$n˵��ϲ�ƶ����ˣ��Ͻ����ָ�ɣ�\n" NOR,
                        this_object(), me);
                return 1;
        }       
                        
        if( !objectp(bride = me->query_temp("marriage/banquet")) ) {
                message_vision(CYN "$NЦ���еض�$n˵����ϲ���ǿ��������˵��¡�\n" NOR,
                        this_object(), me);
                return 1;
        }
                
        if( !objectp(present(bride, environment(me))) ) {
                message_vision(CYN "$NЦ���еض�$n˵����ô����������? \n" NOR,
                        this_object(), me);
                return 1;
        }
        
        switch (MONEY_D->player_pay(me, 100000)) {
        case 0:
                message_vision(CYN "$NЦ���еض�$n˵�����Ȱ�Ǯ׼���ã������̾Ͱ죡\n" NOR,
                        this_object(), me);
                return 1;
        default:
                set_temp("busy", 1);
                message_vision(CYN "$NЦ���еص��ͷ˵������͸����ǰ죡\n" NOR,
                        this_object(), me);
                command("chat " + me->name() + "��" + bride->name() + 
                        "����ϲ����Ե������¥�ϴ�ϲ�磬������λ�͹⣡");      
                log_file("test/marry",
                         sprintf("%s %s married %s %s on %s\n", me->name(), me->query("id"), bride->name(), bride->query("id"), ctime(time())));

                players = users();
                map_array(players, (: new(__DIR__"obj/kaoya")->move($1) :) );
                map_array(players,
                        (: tell_object($1, HIM"��õ�һֻ��Ѽ��\n"NOR) :) );
                map_array(players, (: new(__DIR__"obj/nuerhong")->move($1) :) );
                map_array(players,
                        (: tell_object($1, HIM"��õ�һƿŮ���졣\n"NOR) :) );
                me->delete_temp("marriage/banquet");
                me->set_temp("marriage/ring", bride);
                bride->delete_temp("marriage/accept");
                bride->set_temp("marriage/ring", me);
        }        
                        
        remove_call_out("enough_rest");
        call_out("enough_rest", 1);
        return 1;
}
int accept_kill(object me)
{
        command("say ���컯��֮�¾�������ɱ�ˣ�û��������\n");
        me->apply_condition("killer", 100);
        kill_ob(me);
        return 1;
}
