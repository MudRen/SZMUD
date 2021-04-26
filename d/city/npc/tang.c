// Code of ShenZhou
// tang.c ���ϰ� 
#include <ansi.h>
inherit NPC;
//inherit F_VENDOR;
inherit F_DEALER;

void create()
{
	set_name("���", ({ "tang nan", "tang" }));
        set_color("$YEL$");
	set("title", "�����ϰ�");
	set("shen_type", 0);

	set("gender", "����");
	set_max_encumbrance(100000000);
	set("age", 35);
	set("long",
		"��˵������Ĵ��Ƽҵĺ����\n");
	set("no_get_from", 1);

	set("dex", 80);
	set( "no_cleanup", 1 );
	set("str", 80);
	set_skill("unarmed", 60);
	set_skill("dodge", 60);
	set("qi", 100000);
	set("max_qi", 100000);
	set("jing", 100000);
	set("max_jing", 100000);
	set_temp("apply/attack", 30);
	set_temp("apply/attack", 30);
	set_temp("apply/damage", 15);

	set("combat_exp", 50000);
	set("attitude", "friendly");
	
	setup();
}

void init()
{
	::init();
        add_action("do_list", "list");
        add_action("do_buy", "buy");
	add_action("do_sell", "sell");
	add_action("do_value", "value");
}

void unconcious()
{
	message_vision("\nͻȻ��ֻ��$N����������̨��һ�����ţ����˽�ȥ���������߰��������ˡ�\n",
		this_object());
	destruct(this_object());
}

void die()
{
	message_vision("\n$N���ˡ�\n", this_object());
	destruct(this_object());
}
int accept_kill(object me)
{
        command("say ���컯��֮�¾�������ɱ�ˣ�û��������\n");
        me->apply_condition("killer", 100);
        return 1;
}

