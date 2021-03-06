// Code of ShenZhou
// newjob/doctor/npc
// By Blacko

#include <ansi.h>
inherit NPC;


void create()
{
        set_name(HIY"乐尊育"NOR, ({"yue zunyu", "yue"}) );
        set("nickname", YEL"字显扬"NOR);
        set("gender", "男性" );
        set("age", 52);
        set("long",
          "这老汉看上去跟寻常店家无太大的分别但仔细看去发现他面部烧伤严重\n");
	
    set("attitude", "friendly");
    set("shen_type", 1);

        set("str", 20);
        set("int", 20);
        set("con", 20);
        set("dex", 20);


        set("max_qi", 1050);
        set("max_jing", 500);
        set("neili", 1000);
        set("max_neili", 1000);

        set("combat_exp", 500+random(800));
        set("score", 1000);

        set_skill("force", 20);
        set_skill("dodge", 20);
        set_skill("unarmed", 25+random(10));
        set_skill("parry", 20);
        set_skill("cuff", 20);
        set_temp("apply/attack", 10);
        set_temp("apply/defense", 15);
        set_temp("apply/damage", 3);

        create_family("乐家老号", 2, "子孙");

        set("inquiry", ([
            "同仁堂" : "本店现在暂停营业中请等装修后在来光顾。\n"
         

        ]));

        setup();
        
                carry_object("/clone/armor/jinshe-beixin")->wear();
                
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;


        say("乐尊育笑吟吟地说道欢迎这位" + RANK_D->query_respect(ob)
             + "请先入座，" + "父亲马上就来。\n");
}
