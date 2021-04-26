// Code of ShenZhou
// NPC gan.c
// AceP

#include <ansi.h>

inherit NPC;

int do_say(string arg);

void create()
{
	set_name("�ɹ��", ({ "Gan guanghao","gan" }) );
	set("gender", "����");
	set("age", 30);
	set("long", "��λ���������������������µĵ��ӣ����иɹ����\n");
	set("combat_exp", 35000);
	set("shen_type", -1);
	set("attitude", "heroism");

	set("apply/attack",  60);
	set("apply/defense", 60);

	set_skill("sword", 75);
	set_skill("unarmed", 70);
	set_skill("parry", 70);
	set_skill("dodge", 70);

	setup();
	carry_object("/d/city/obj/changjian")->wield();
	carry_object("/clone/misc/cloth")->wear();
	add_money("silver", 50);
}

void init()
{
	::init();
	add_action("do_say","say");
}

int do_say(string arg)
{
	object me;
	me = this_player();

	if( arg=="��ϲ" && present("Ge guangpei", environment(me))) {
		message_vision("$Nһ���֣�С����������ϲ��λ��ף��λ��ͷ���ϡ��Ǻǡ���\n"
			"��������৵�һ�º��ˡ��ɹ��������������ɵЦ�˼�����\n", me);
		"/d/dali/yubi"->set("exits/west", "/d/dali/xuanya");
		return 1; }
	return 0;
}
