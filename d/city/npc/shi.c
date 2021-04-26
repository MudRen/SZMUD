// Code of ShenZhou
// shi.c ʷ��ɽ

#include <ansi.h>
inherit NPC;
inherit F_SKILL;

void create()
{
	set_name("������", ({ "zhao liangdong", "zhao" }));
        set_color("$YEL$");
	set("title", HIY"�����ؽ�"NOR);
	set("gender", "����");
	set("age", 33);
	set("str", 25);
	set("dex", 16);
	set("long", "��������Ϊ������ս�й����½������ٵ������ݡ�������һ���������ӣ��������¡�\n");
	set("combat_exp", 400000);
	set("shen_type", 0);
	set("attitude", "heroism");
        set("inquiry", ([
		"ΤС��" : "���Τ��ү���¹���Я���¹ٸм�������\n",
		"Τ��ү" : "���Τ��ү���¹���Я���¹ٸм�������\n",
	]));

	set_skill("unarmed", 100);
	set_skill("force", 100);
	set_skill("sword", 100);
	set_skill("dodge", 100);
	set_skill("parry", 100);
	set_skill("taiji-jian", 80);
        set_skill("tiyunzong", 80);
	map_skill("parry", "taiji-jian");
	map_skill("sword", "taiji-jian");
        map_skill("dodge", "tiyunzong");
	set_temp("apply/attack", 90);
	set_temp("apply/defense", 90);
	set_temp("apply/armor", 90);
	set_temp("apply/damage", 40);

	set("max_qi", 1000);
	set("neili", 1000); 
	set("max_neili", 1000);
	set("jiali", 50);

	setup();
	carry_object(__DIR__"obj/gangjian")->wield();
	carry_object(__DIR__"obj/tiejia")->wear();
}

int accept_fight(object me)
{
	command("say �Ϸ��δ�ͽ����˶��ֹ����ˣ�����Ҳ����������");
	return 0;
}


int accept_kill(object me)
{
        command("say �󵨵��񣬾���ıɱ���٣�\n");
        me->apply_condition("killer", 100);
        kill_ob(me);
        return 1;
}

void init()
{
        object ob;
        ::init();
        if (interactive(ob = this_player()) &&
                (int)ob->query_condition("killer")) {
                remove_call_out("kill_ob");
                call_out("kill_ob", 1, ob);
        }
}
