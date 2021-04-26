// Code of ShenZhou
// wujiang.c �佫

#include <ansi.h>

inherit NPC;
inherit F_SKILL;

void create()
{
        set_name("����Ӫ�佫", ({ "wu jiang", "wu", "jiang" }));
        set_color("$YEL$");
        set("title","����");
        set("gender", "����");
        set("age", random(10) + 30);
        set("weight", 100000);
        set("str", 25);
        set("dex", 16);
        set("long", "��վ�������ȷ��˵���������硣\n");
        set("combat_exp", 75000);
        set("shen_type", 0);
        set("attitude", "peaceful");

        set_skill("unarmed", 60);
        set_skill("force", 60);
        set_skill("sword", 60);
        set_skill("dodge", 60);
        set_skill("parry", 60);
        set_temp("apply/attack", 50);
        set_temp("apply/defense", 50);
        set_temp("apply/armor", 50);
        set_temp("apply/damage", 30);

        set("neili", 400); 
        set("max_neili", 400);
        set("jiali", 10);

        setup();
}

void init()
{
        object me = this_player();        

        ::init();

        if( interactive(me) )
        {
                remove_call_out("greeting");
                call_out("greeting", 1, me);
        }
}

void greeting(object me)
{
        command("say ֻҪ��Ǯׯ�ﻹ������ͭǮ������ﵽʮ�򣬾Ϳ���������"+HBRED+HIW"(caolian)"NOR"��\n");
}
