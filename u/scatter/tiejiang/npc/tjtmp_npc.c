// tjtmp_npc.c
// snowlf by 2001.10.24

#include <ansi.h>
#include <dbase.h>

inherit NPC;
inherit F_VENDOR;
int do_sell(string);
// string ask_liancost();
void create()
{
	set_name("������", ({ "hu qiming", "hu", "qiming" }) );
	set("gender", "����" );
	set("age", 30);
	set("long","������������½���"+HIB+"������������"+NOR+"����ʱ������Ա��������������
�еģ�ֻ����Ϊ����һʱû�к��ʵ��������ܣ�������֮�в���ʱ������ġ�
		
");
	set("combat_exp", 3000);
        set("str", 25);
        set("dex", 20);
        set("con", 20);
        set("int", 22);
	set("attitude", "friendly");
/*
	set("inquiry", ([

		"Ѧȵ" : "����ɽ�����š�\n",
		"����" : "�ڶ�ͥ���ϡ�\n",
                "��ͥ��" : "�ҿɲ���ȥ�ˡ�\n",
		"������" : "�̹���������µ�һ���ˡ�\n",
		"����" : "���õ��������ɵû�һ������ask ������Ǯ����\n",
                "������Ǯ" : (:ask_liancost:),
	]));	

	set("chat_chance", 5);
	set_skill("dodge", 25);
	set_skill("parry", 25);
	set_skill("unarmed", 30);
*/	
	setup();
        carry_object("/d/city/obj/cloth")->wear();
	add_money("coin", 200);
}


void init()
{
	object ob;

        ::init();
	if ( interactive(ob=this_player()) ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}

        add_action("do_buy", "buy");
	add_action("do_list", "list");
	add_action("do_sell", "sell");

}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;

	command("say ��ӭ��λ"+RANK_D->query_respect(ob)+"���٣������ιۡ�");
}
