//piao 2001/10/15
// NPC /d/wulin/npc/yishi1.c ����ͬ����ʿ
#include <ansi.h>

inherit NPC;

void create()
{
        set_name("����ͬ����ʿ", ({ "yi shi", "shi", "warrior" }) );
        set("gender", "����");
        set("age", 45);
        set("long",
                "��������ͬ�˵���ͨ������Ա���������ǽ����������\n");
        set("combat_exp", 1000000);
        set("shen_type", 1);
        set("attitude", "heroism");
        
        set("str", 30);
        set("con", 30);
        set("int", 30);
        set("dex", 30);
        set("max_qi", 1000);
        set("eff_qi", 1000);
        set("qi", 1000);
        set("max_jing", 700);
        set("jing", 700);
        set("neili", 2000);
        set("max_neili", 2000);
        set("jingli", 1000);
        set("max_jingli", 1000);
        set("jiali", 100);
        set("shen_type", 0);

        set_temp("apply/attack",  50);
        set_temp("apply/defense", 50);

        set_skill("sword", 200);
        set_skill("unarmed", 200);
        set_skill("parry", 200);
        set_skill("dodge", 200);

        set("no_get", "�㿸������ʿ");

        setup();
        carry_object("/d/city/obj/gangjian")->wield();
        carry_object("/d/city/obj/tiejia")->wear();
}
int accept_object(object me, object obj)
{
      if(obj->name() == "���") {
                command("bow "+me->query("id"));
                message_vision(CYN"�Ҷ�˵����"+RANK_D->query_respect(me)+"ԭ�����������˵�����, ������, ���»����Ե����Ѷ�¥�����ɹ���\n"NOR,me);
                me->set_temp("houyuan",1);
                call_out("destroy_it",1,obj);
                return 1;
        }
        return 0;
}

void destroy_it(object obj)
{
        destruct(obj);
}





