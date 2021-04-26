// Code of ShenZhou
// song.c ���ϰ�

#include <ansi.h>
#include <dbase.h>

inherit NPC;
inherit F_DEALER;

string ask_me();

void create()
{
	set_name("���ϰ�", ({ "song laoban", "song"}));
	set_color("$YEL$");
	set("title", "̫�;��ϰ�");
	set("shen_type", 1);
	set("str", 20);
	set("gender", "����");
	set("age", 55);
	set("long", "�������ϰ忴��ȥһ������ǿ�ɵ����ӡ�\n");
	set("combat_exp", 60000);
	set("qi", 300);
	set("max_qi", 300);
	set("attitude", "friendly");
	set_skill("unarmed", 60);
	set_skill("dodge", 60);
	set_temp("apply/attack", 30);
	set_temp("apply/defense", 30);
	set("vendor_goods", ({
		"d/city/obj/hdjiudai",
		"d/dali/obj/qiguoji",
		"d/dali/obj/guoqiao",
		}));
	setup();
	carry_object("/d/city/obj/xiupao")->wear();            
	add_money("gold", 1);
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
