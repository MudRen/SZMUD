// Code of ShenZhou
// Npc: /kungfu/class/shaolin/hui-he.c
// Date: YZC 96/01/19
// xQin 8/00

inherit NPC;
inherit F_MASTER;
string ask_for_huansu();
string ask_me();

void create()
{
	set_name("�ۺ�����", ({
		"huihe zunzhe",
		"huihe",
		"zunzhe",
	}));
	set("long",
		"����һλ���ް߰׵���ɮ����һϮ�಼������ġ�������Ըߣ�\n"
		"̫��Ѩ΢͹��˫Ŀ��������\n"
	);


	set("gender", "����");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 50);
	set("shen_type", 1);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("max_qi", 650);
	set("max_jing", 300);
	set("neili", 600);
	set("max_neili", 600);
	set("jiali", 50);
	set("combat_exp", 200000);
	set("score", 100);

	set_skill("force", 70);
	set_skill("hunyuan-yiqi", 70);
	set_skill("dodge", 70);
	set_skill("shaolin-shenfa", 70);
	set_skill("cuff", 78);
	set_skill("luohan-quan", 78);
	set_skill("parry", 70);
	set_skill("buddhism", 70);
	set_skill("literate", 70);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("cuff", "luohan-quan");

	prepare_skill("cuff", "luohan-quan");

	create_family("������", 38, "����");

	set("inquiry", ([
		"����" :    (: ask_me :),
		"����" : (:ask_for_huansu:),
	]));

	setup();

        carry_object("/d/shaolin/obj/hui-cloth")->wear();
}

#include "/kungfu/class/shaolin/hui.h"

string ask_me()
{
	return "������ �������ֲ�ȱ���� ǰ�����ǲ��Ǹ�����һ�����飬������ʲô�ĸ����𣿣�";
}

string ask_for_huansu()
{
	object ob, me;
	me=this_player();
	ob=this_object();
	
	if (me->query("gender") != "����" )
	{
	return "�����ӷ�"+RANK_D->query_respect(me)+"���������Ŀ�������Ц��";
	}
	if (me->query("class") != "bonze" )
	{
	return "�����ӷ�"+RANK_D->query_respect(me)+"���Ƿ������ˣ�����д�һ�ʣ�";
	}
	if (me->query("family/family_name") != "������" )
	{
	return "�����ӷ�"+RANK_D->query_respect(me)+"�Ǳ������ˣ�����һ�����Ĳ���������";
	}
	if (me->query("family/master_id") == ob->query("id"))
	{
	add_action("do_jueding", "�������");
	me->set_temp("pending/quit_bonze", 1);
	command("sigh "+me->query("id"));
	return "��Ȼ�������Ե��ΪʦҲ����ǿ�󣬵����㽫�����ʦ�ǣ����Ҫ������ˡ�\n"
	       "(type �������)";
	} 
	else {
	return "����һ�»�����Ϊ"+RANK_D->query_respect(me)+"�ͱ��������������飬ƶɮ����������\n";
	}
}

int do_jueding()
{
	object ob,me;
	me=this_player();
	ob=this_object();
	
	if (!me->query_temp("pending/quit_bonze"))
	return 0;
	
	command("sigh "+me->query("id"));
	message_vision("$N���������Ĺ��£�����˵��������ˡͽ����Ф����\n",me);
	message_vision("$n��$N�����������ָ���$Nһ�����¡�\n",ob,me);
	command("say ʩ�����أ�������Ϊ֮��");
	me->delete_temp("pending/quit_bonze");
	me->set("quit/bonze", 1);
	me->delete("class", "bonze");
	ob=new("/clone/misc/cloth.c");
	ob->move(me);
	command("expell "+me->query("id"));
	return 1;
}