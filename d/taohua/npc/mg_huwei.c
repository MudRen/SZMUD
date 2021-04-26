// Code of ShenZhou
inherit NPC;
#include <ansi.h>

void create()
{
        set_name("����", ({ "hu wei", "wei" }));
        set("long", "һ�������⺷���ɹŴ󺺣��Ǿ��н��ٵ���ӣ�������ϰ����֮����\n");
        set("gender", "����");
        set("age", 25);
        set("attitude", "heroism");
        set("str", 25);
        set("con", 25);
        set("int", 15);
        set("dex", 20);
        
        set("max_qi", 1000);
        set("eff_qi", 1000);
        set("qi", 1000);
        set("max_jing", 800);
        set("jing", 800);
        set("neili", 200);
        set("max_neili", 200);
        set("jiali", 50);
        set_skill("blade", 100);
        set_skill("strike", 100);
        set_skill("force", 100);
        set_skill("parry", 100);
        set_skill("dodge", 100);
        set("combat_exp", 50000);
        set("shen_type", -1);
        setup();
        carry_object("/d/city/obj/gangjian")->wield();
        carry_object("/d/city/obj/tiejia")->wear();
}

int start_check(object ob)
{
        object me = this_object();
        call_out("leave", 1 ,ob);
}

void leave(object ob)
{
        object me = this_object();

	if(!ob){
        message_vision("$N�Ҵ�ææ���뿪�ˡ�\n"NOR,me);
        destruct(me);
        }
	else {
        call_out("leave", 1 ,ob,me);
        }
        return;
}
int accept_fight(object me)
{
        command("say ��̸�ƨ��������ү�����㣡\n");
        kill_ob(me);
        return 1;
}
