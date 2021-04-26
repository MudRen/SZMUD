// Code of ShenZhou
// niu. ţ�ƹ�

#include <ansi.h>
#include <dbase.h>

inherit NPC;
inherit F_DEALER;

string ask_me();

void create()
{
        set_name("ţ�ƹ�", ({ "niu zhanggui", "niu" }));
        set_color("$YEL$");
        set("title", "�۽���ƹ�");
        set("shen_type", 1);

        set("str", 20);
        set("gender", "����");
        set("age", 35);
        set("long", "ţ�ƹ�һ�������ܸɵ����ӣ���ʽ�����鱦��һ�۱���˵����Ǯ����\n");
        set("combat_exp", 20000);
        set("qi", 300);
        set("max_qi", 300);
        set("attitude", "friendly");
        set_skill("unarmed", 60);
        set_skill("dodge", 60);
        set_temp("apply/attack", 30);
        set_temp("apply/defense", 30);
        set("vendor_goods", ({
                  __DIR__"obj/mirror",
                  __DIR__"obj/pring",
                "/d/city/obj/ring-pearl",
                "/d/city/obj/ring-ivory",
                "/d/city/obj/ring-jade",
                "/d/city/obj/ring-silver",
                "/d/city/obj/ring-iron",
                "/d/city/obj/ring-diamond",
                  __DIR__"obj/necklace",
                "/d/city/obj/necklace-silver",
                "/d/city/obj/necklace-amber",
                "/d/city/obj/necklace-ivory",
                "/d/city/obj/necklace-pearl",
                "/d/city/obj/necklace-diamond",
                "/d/city/obj/earring-amber",
                "/d/city/obj/earring-ivory",
                "/d/city/obj/earring-jade",
                "/d/city/obj/earring-pearl",
                "/d/city/obj/earring-diamond",
                  
        }));
                
        setup();
//         add_money("silver", 20);
        add_money("coin", 100);
}

void init()
{
        object ob;

        ::init();
        if ( interactive(ob=this_player()) ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }

        add_action("do_list", "list");
        add_action("do_buy", "buy");
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;

        command("say ��ӭ���٣���λ"+RANK_D->query_respect(ob)+"�����ιۡ�С�걣֤�����ʵ��");
}

int accept_kill(object me)
{
        command("say ���컯��֮�¾�������ɱ�ˣ�û��������\n");
        me->apply_condition("killer", 100);
        kill_ob(me);
        return 1;
}
