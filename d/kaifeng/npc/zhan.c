//npc: /d/kaifeng/zhan.c
//by bravo
#include <ansi.h>

inherit NPC;

void create()
{
        set_name("չ��", ({"zhan zhao","zhan"}));
       set("long",
                "һλ�������ݵĲ�ͷ����Ĳ��ߣ�������������\n"
                "��˵��ԭһ���Ĳݿܶ��������֡�\n"
        );
       set("nickname", HIR" ��è"NOR);
        set("gender", "����");
        set("attitude", "peaceful");
        
        set("age", 25);
        set("shen", 10000);
        set("str", 35);
        set("int", 20);
        set("con", 30);
        set("dex", 35);
        set("per",35);
        set("max_qi", 2000);
        set("max_jing", 2000);
        set("neili", 3500);
        set("max_neili", 3500);
        set("jiali", 120);
        set("combat_exp", 350000);
        set("startroom","/d/kaifeng/ximen");

        set_skill("force", 200);
        set_skill("buddhism",200);
        set_skill("claw",200);
        set_skill("hunyuan-yiqi",200);
        set_skill("longzhua-gong", 200);
        set_skill("dodge", 200);
        set_skill("shaolin-shenfa", 200);
        set_skill("parry", 200);
        set("chat_chance", 20);
        set("chat_msg", ({
               "չ��ͦ��ͦ�ظ�������Ц��������˵�������ˣ���ЩΪ������������һ���ŷ���ӡ� \n",
               (: random_move :)
       }) );
        map_skill("force", "hunyuan-yiqi");


        map_skill("dodge", "shaolin-shenfa");
        map_skill("parry", "longzhua-gong");
        map_skill("claw", "longzhua-gong");
       prepare_skill("claw", "longzhua-gong");

        setup();
        carry_object("/clone/armor/armor")->wear();
}

void init()
{
        object me, ob;

        ::init();

        ob = this_player();
        me = this_object();
        if (interactive(ob) 
        && !environment(ob)->query("no_fight")
        && (int)ob->query("PKS",1) >36 )
        {
 


         command("say  ��˵��������˲��ٻ��£�����ͺͱ�����һ�ˡ�\n");
         remove_call_out("hiting_ob");
         call_out("hiting_ob", 1, ob);
                 
        }       
}
int hiting_ob(object ob)
{
        object me;
        me=this_object();
        me->set_leader(ob);
         ob->fight_ob(me);
        me->fight_ob(ob);
        remove_call_out("moving_ob");
        call_out("moving_ob",1,ob);
}
int moving_ob(object ob)
{
        if (!ob) return 0;
       if (!living(ob)&&present(this_player(), environment(this_object()))){
        switch( random(3) ) {
        case 0:

                command("say �ڿ��⸮��Ұ�����ܣ����㳢���ҵ�������");

        break;
        case 1:
                command("say  ���������ʵʵȥ���Űɡ�");
        break;
        case 2:
                command("nod");
        break;
        }
        ob->move("/d/city/dalao"); 
        ob->set("eff_jing",1);           
        }
        else {
        remove_call_out("hiting_ob");
        call_out("hiting_ob",1,ob);
        }
}
