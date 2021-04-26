// Code of ShenZhou
// wu.c ���ϰ�

#include <ansi.h>
#include <dbase.h>

inherit NPC;
inherit F_DEALER;

string ask_me();

void create()
{
	set_name("���ϰ�", ({ "wu laoban", "wu" }));
        set_color("$YEL$");
	set("title", "�������¥�ϰ�");
	set("shen_type", 1);

	set("str", 20);
	set("gender", "����");
	set("age", 55);
	set("long", "���ϰ�һ�ֿ������������¥����Ȫ�ݡ�\n");
	set("combat_exp", 60000);
        set("qi", 300);
        set("max_qi", 300);
	set("attitude", "friendly");
	set_skill("unarmed", 60);
        set_skill("dodge", 60);
        set_temp("apply/attack", 30);
        set_temp("apply/defense", 30);

	set("vendor_goods", ({
		__DIR__"obj/hdjiudai",
		__DIR__"obj/fotiao",
	}));
            	
	setup();
//          add_money("gold", 1);
}

void init()
{
	::init();
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}

int accept_kill(object me)
{
        command("say ���컯��֮�¾�������ɱ�ˣ�û��������\n");
        me->apply_condition("killer", 100);
        kill_ob(me);
        return 1;
}
