// Code of ShenZhou
// Npc: /kungfu/class/shaolin/cheng-zhi2.c
// Date: YZC 96/01/19
// xQin 8/00
inherit NPC;
inherit F_MASTER;
string ask_for_huansu();
int auto_perform();

void create()
{
	set_name("��־", ({
		"chengzhi luohan",
		"chengzhi",
		"guangming",
		"luohan",
	}));
	set("long",
		"����һλ�뷢���׵���ɮ����һϮ��ߺڲ����ġ�������ݸߣ�\n"
		"̫��Ѩ�߸߹����ƺ��������书��\n"
	);

	set("nickname", "�����޺�");
	set("gender", "����");
	set("attitude", "peaceful");
	set("class", "bonze");
	
	set("inquiry",([
		"����" : (:ask_for_huansu:),
	]));
	
	set("age", 60);
	set("shen_type", 1);
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 25);
	set("max_qi", 1000);
	set("max_jing", 1000);
	set("neili", 1500);
	set("max_neili", 1500);
	set("jiali", 100);
	set("combat_exp", 500000);
	set("score", 5000);

	set_skill("force", 100);
	set_skill("hunyuan-yiqi", 100);
	set_skill("dodge", 100);
	set_skill("shaolin-shenfa", 100);
        set_skill("cuff", 80);
        set_skill("luohan-quan", 80);
        set_skill("jingang-quan", 120);
        set_skill("club", 80);
        set_skill("weituo-gun", 80);
        set_skill("strike", 100);
        set_skill("sanhua-zhang", 90);
        set_skill("banruo-zhang", 120);
        set_skill("hand", 100);
        set_skill("qianye-shou", 100);
	set_skill("finger", 140);
        set_skill("nianhua-zhi", 90);
	set_skill("yizhi-chan", 140);

	set_skill("parry", 100);
	set_skill("buddhism", 100);
	set_skill("literate", 100);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("finger", "yizhi-chan");
	map_skill("parry", "yizhi-chan");

	prepare_skill("finger", "yizhi-chan");

        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: auto_perform :),
        }) );

	create_family("������", 37, "����");

	setup();

        carry_object("/d/shaolin/obj/cheng-cloth")->wear();
}

int auto_perform()
{
        object target = select_opponent();

        if( !objectp(target) )  return 0;

        return perform_action("finger.jingmo");
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
#include "/kungfu/class/shaolin/cheng.h"

