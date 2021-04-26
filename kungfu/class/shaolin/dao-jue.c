// Code of ShenZhou
// Npc: /kungfu/class/shaolin/dao-jue.c
// Date: YZC 96/01/19
// xQin 8/00

inherit NPC;
inherit F_MASTER;
string ask_for_huansu();

void create()
{
	set_name("������ʦ", ({
		"daojue chanshi",
		"daojue",
		"chanshi",
	}));
	set("long",
		"����һλ��ĸߴ������ɮ�ˣ����۴�׳��������Բ�����ֱֳ�\n"
		"�У���һϮ�Ҳ�������ģ��ƺ���һ�����ա�\n"
	);


	set("gender", "����");
	set("attitude", "friendly");
	set("class", "bonze");

	set("inquiry",([
	"����" : (:ask_for_huansu:),
	
	]));
	
	set("age", 40);
	set("shen_type", 1);
	set("str", 22);
	set("int", 20);
	set("con", 21);
	set("dex", 22);
	set("max_qi", 500);
	set("max_jing", 300);
	set("neili", 450);
	set("max_neili", 450);
	set("jiali", 40);
	set("combat_exp", 80000);
	set("score", 100);

	set_skill("force", 50);
	set_skill("hunyuan-yiqi", 50);
	set_skill("dodge", 50);
	set_skill("shaolin-shenfa", 50);
        set_skill("cuff", 52);
        set_skill("luohan-quan", 52);
	set_skill("hand", 53);
	set_skill("fengyun-shou", 53);
	set_skill("parry", 50);
	set_skill("buddhism", 50);
	set_skill("literate", 50);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("hand", "fengyun-shou");
	map_skill("cuff", "luohan-quan");
	map_skill("parry", "fengyun-shou");

	prepare_skill("cuff", "luohan-quan");
        prepare_skill("hand", "fengyun-shou");

	create_family("������", 39, "����");

	setup();

        carry_object("/d/shaolin/obj/dao-cloth")->wear();
}

string ask_for_huansu()
{
	object ob, me;
	me=this_player();
	ob=this_object();
	
	if (me->query("gender") != "����" )
	{
	return "�����ӷ�"+RANK_D->query_respect(me)+"������ƶɮ��������Ц��";
	}
	if (me->query("class") != "bonze" )
	{
	return "�����ӷ�"+RANK_D->query_respect(me)+"���Ƿ������ˣ�����д�һ�ʣ�";
	}
	if (me->query("family/family_name") != "������" )
	{
	return "�����ӷ�"+RANK_D->query_respect(me)+"�Ǳ������ˣ�����һ��ƶɮ����������";
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
#include "/kungfu/class/shaolin/dao.h"

