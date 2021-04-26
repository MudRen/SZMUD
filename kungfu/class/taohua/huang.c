// Code of ShenZhou
// Kane,
// maco
// mantian 

inherit NPC;
#include <ansi.h>
int auto_perform();
int ask_shagu();
int ask_chengfeng();
int ask_fenfu();
string* xuedao = ({
	"���Ѩ", "�縮Ѩ", "ǿ��Ѩ", "��׵Ѩ", "����Ѩ",
	"�ٻ�Ѩ", "��̨Ѩ", "̫��Ѩ", "����Ѩ", "����Ѩ",
	});

void create()
{
	set_name("��ҩʦ", ({ "huang yaoshi", "huang" }));
	set("title", "�һ�����");
	set("nickname", "��а");
	set("long",
		"�������������µ��һ���������а����ҩʦ��������������񳣬\n"
		"������ˬ��տȻ����һϮ���ۣ�������һ֧�����ɫ֮��\n"
		"����һ������ɽ�ֵ�������\n");
	set("gender", "����");
	set("age", 55);
	set("attitude", "friendly");
	set("shen_type", 0);
	set("str", 30);
	set("int", 40);
	set("con", 30);
	set("dex", 35);

	set("max_qi", 4500);
	set("max_jing", 4500);
	set("neili", 5000);
	set("max_neili", 5000);
	set("jiali", 200);
	set("combat_exp", 3600000);
	set("score", 5000);
	set_temp("apply/armor", 50);
	set_temp("apply/attack", 50);
	set_temp("apply/dodge", 50);	
	set("th_jianyi", 6);

	set_skill("force", 400);
	set_skill("dodge", 400);
	set_skill("parry", 360);
	set_skill("sword", 400);
	set_skill("whip", 360);
	set_skill("qimen-dunjia", 400);
	set_skill("strike", 360);
	set_skill("hand",360);
	set_skill("finger", 400);
	set_skill("yuxiao-jian", 400);
	set_skill("canglang-bian", 360);
	set_skill("bitao-xuangong", 400);
	set_skill("luoying-shenjian",400);
	set_skill("luoying-shenfa", 400);
	set_skill("kick", 360);
	set_skill("xuanfeng-saoye", 360);
	set_skill("lanhua-fuxue", 360);
	set_skill("tanzhi-shentong", 400);
	set_skill("throwing", 400);
	set_skill("literate", 101);
	set_skill("music", 400);

	map_skill("force", "bitao-xuangong");
	map_skill("parry", "tanzhi-shentong");
	map_skill("sword", "yuxiao-jian");
	map_skill("finger", "tanzhi-shentong");
	map_skill("strike", "luoying-shenjian");
	map_skill("dodge", "luoying-shenfa");
	map_skill("kick", "xuanfeng-saoye");
	map_skill("hand", "lanhua-fuxue");

	if (random(2) == 1) {
		prepare_skill("strike", "luoying-shenjian");
		prepare_skill("kick", "xuanfeng-saoye");
	} 
	else prepare_skill("finger", "tanzhi-shentong");
//	prepare_skill("hand", "lanhua-fuxue");

	set("chat_chance_combat", 40);
	set("chat_msg_combat", ({
		(: auto_perform :),
	}) );

	create_family("�һ���", 1, "������");
	set("inquiry", ([
		"�һ���" : "�㲻�����һ������𣿣�",
		"�Ż���¶��" : "���Ǳ��ŵ�һ�鵤��ҩ���ɾ����滨�峿¶ˮ�����������ҩ���Ƴɣ���Ч�����ޱȡ�",
		"���Ŷݼ�" : "����ѧ�ʲ������Ƭ��ֻ�����ܾ��ߡ�",
		"����" : "�����̡��ǡ��硢��Ϊ������",
		"ʮ����" : "����ʮ��������Ϊ�ɣ�����Ϊ��������ͳ������ֱ�Ϊ����̫������ϴ��ި�����������䡣���������������ֱ�Ϊ���ӡ�������Ӧ�ӡ����������ӡ�������",
		"����" : "���Ѿͷ��֪���ַ���ȥ�ˣ����첻����Ӱ��",
		"����" : "��ɵС��һ�������Ҿ�������",
		"Ů��" : "���һ���аƽ���������ǲ�����ʿ�����ȴ���˸�ɵŮ���������������ˣ�",
		"������" : "��������ǰ�������ͽ�����֣�",
		"÷����" : "��������ǰ�������ͽ�����֣�",
		"�����" : "��籾�������书��ǿ�ĵ��ӣ���������һ�ϣ�һ���书�ɾ�......", 
		"½�˷�" : (:ask_chengfeng:),//"�˷����Բ���ϰ�䣬����Ҳ�����ޡ�",
		"��Ĭ��" : "Ĭ�������С��ȴ�ѵ���ʦ���洫��",
		"���߷�" : "�߷���������ȴ�ù����ڡ�",
		"����" : "���������䲻������Ů�����������վã�Ҳѧ�����ٶ�����ǧ��Ҫ��Ϊ�����С��С��������",
		"��Ӣ" : "���������䲻������Ů�����������վã�Ҳѧ�����ٶ�����ǧ��Ҫ��Ϊ�����С��С��������",
		"���߹�" : "�Ͻл��þò�������֪������Σ���˵��һ��С�л���Զ����Եû��˶��ӡ�",
		"�Ͻл�" : "�Ͻл��þò�������֪������Σ���˵��һ��С�л���Զ����Եû��˶��ӡ�",
		"��ؤ" : "��ؤ����ؤ��������Ͻл����߹���",
		"ŷ����" : "�϶���������ڰ���ɽ��¶�棬���ڵ����µ��Ӱɡ�",
		"�϶���" : "�϶���������ڰ���ɽ��¶�棬���ڵ����µ��Ӱɡ�",
		"����" : "�Ǿ����������ɽׯׯ�����϶���ŷ���档",
		"�ϵ�" : "�����ǵ�������һ��֮�����������һ��ָ�ĵ�ϵ���˶����ˡ�",
		"�λ�ү" : "�λ�ү�Ѿ��þ�û��������Ϣ�ˡ�",
		"������" : "�����˲����Ƕλ�ү��",
		"����а" : "����а�����ң��Ҿ��ǻ���а��",
		"��а" : "��а��ҩʦ�����ң��Ҿ��Ƕ�а��ҩʦ��",
		"��ҩʦ" : "��а��ҩʦ�����ң��Ҿ��Ƕ�а��ҩʦ��",
		"name" : "��а��ҩʦ�����ң��Ҿ��Ƕ�а��ҩʦ��",
		"�Ϲ���" : "�������ֵڶ��Ŵ�ɵ�ϣ���һ���ǹ�����",
		"��" : "������ͨ��������С�ĵ�λ��ԼҪһ����ͭǮ��ֵ��һ��������",
		"��ɽ�۽�" : "��ʮ��ǰ�����϶���Ͻл����λ�ү���������ڻ�ɽ֮���۽�������ҹ�������������Ϊ���µ�һ��",
		"����": "��޿����޿����ҹҹΪ�㴵������ü��᣿�����Բ�������ʧ̬�ˡ�",
		"����" : "��޿����޿����ҹҹΪ�㴵������ü��᣿�����Բ�������ʧ̬�ˡ�",
		"����" : "��޿����޿����ҹҹΪ�㴵������ü��᣿�����Բ�������ʧ̬�ˡ�",
		"��޿" : "�㵨��ֱ���ҷ��˵����֣�",
		"����ͯ" : "����ͯ�����ܲ�ͨ������ɶ���ʵģ�",
		"�ܲ�ͨ" : "�ܲ�ͨ������ͨ��������ʦ�ܣ�ȫ�������������ĻҲ���Ǹ�������",
		"��⬼�" : "�����һ�����֮���������ʻ�����ɱ��֮����",
		"����ͨ" : "�Ǿ���ȫ�������������",
		"������" : "����������е�����ͨ��Ҳ��ȫ��̿�ɽ��ʦ��",
		"�����澭" : "�������µ�һ��ѧ�ܼ���û���±����ʣ�",
		"����" : "��ĳ�������˾��ӣ������Ϻųơ���а������ȻҲ��м�����˾���Ϊ�顣�������ۣ�Խ��а��Խ�ǳ������⡣",
		"rumors" : "û�С�",
		"ɵ��" : (: ask_shagu :),
	]));
	setup();
	carry_object("/d/xixia/obj/robe")->wear();
	if (clonep()) carry_object("/clone/unique/yuxiao", "/d/taohua/obj/tiexiao")->wield(); 
}

void init()
{
	object ob;
	
	::init();
	if (interactive(ob=this_player()))
	{
		if (ob->query_temp("th_tomb_thief"))
		{
			command("say "+RANK_D->query_rude(ob)+"������˽���ҷ���Ĺ�ң���������\n");
			start_busy(1);
//			command("follow " + ob->query("id"));
			kill_ob(ob);
		}
		if (ob->query("th_killer") || ob->query_temp("th_killer"))
		{
			command("sneer "+ob->query("id"));
			command("say ��ͽ�ô��ӣ���Ȼͬ�ŵ���������У�");
			message_vision(HIR"��ҩʦ˵��һ̧�֣�һָ����$N��"+xuedao[random(sizeof(xuedao))]+"�ϡ�\n"NOR, ob);	
			call_out("move_it", 1, ob);
		}
// change to if player ��ʦ meet huang he'll auto kill him once
// mantian may/09/2001 
		if( ob->query("gender") == "����" && ob->query("family/family_name") == "�һ���" && ob->query("family/master_id") == "huang yaoshi")
		{
			command("say "+ob->query("name")+"��ô��ӣ������һ����Ӿ�Ȼȥ�������߹���");
			command("expell " + ob->query("id"));
			command("say �����������Ҽ�����");
		}
		else if ( ob->query("kill_th_traitor") 
			&& ob->query("help_chengfeng")
			&& ob->query("help_lingfeng")
			&& ob->query("help_mofeng")
			&& ob->query("family/family_name") != "�һ���" )
		{
			command("say "+ob->query("name")+"�㱳��ʦ�Ż������������ң��ô��ӣ�");
			ob->delete("kill_th_traitor");
			ob->delete("help_chengfeng");
			ob->delete("help_lingfeng");
			ob->delete("help_mofeng");
			kill_ob(ob);
			ob->start_busy(10);
		}
		else if ( ob->query("kill_th_traitor") 
			&& ob->query("help_chengfeng")
			&& ob->query("help_lingfeng")
			&& ob->query("help_mofeng")
			&& ob->query("family/family_name") == "�һ���" )
		{
			ob->set_temp("huang_recr",1);
			command("smile " + ob->query("id"));
		}
	}
	add_action("do_looko","kick");
	add_action("do_looko","papaya");
	add_action("do_looko","slap");
	add_action("do_looko","slogan");
	add_action("do_looko","cut");
	add_action("do_looko","shutup");
	add_action("do_looko","slash");
	add_action("do_looko","knife");
	add_action("do_looko","nofear");
	add_action("do_looko","points");
	add_action("do_looko","admit");
	add_action("do_looko","loveshoe");

	add_action("do_fearo","hug");
	add_action("do_fearo","kiss");
	add_action("do_fearo","mo97");
	add_action("do_fearo","lovelook");
	add_action("do_fearo","rose");
	add_action("do_fearo","deadlove");
	add_action("do_fearo","joycup");
}
void move_it(object ob)
{
	object *inv;
	int k;

	if(ob)
	{
		ob->set("eff_qi", 10);
		ob->set("eff_jing", 10);
		ob->set("water", 0);
		ob->set("jingli", 0);
		ob->delete("th_killer");
		ob->delete_temp("th_killer");
		inv = all_inventory(ob);
		for(k=0; k<sizeof(inv); k++)
		{
			if(( inv[k]->query("armor_prop") && inv[k]->query("equipped"))
			|| inv[k]->query("no_get")) continue;
			destruct(inv[k]);
		}
		ob->unconcious();
		ob->move("/d/taohua/maze/maze"+(random(63)+1));
	}
}

int attempt_apprentice(object ob)
{
	object obj;
	string name, new_name, str;
	string* m_names = ({
		"��", "��", "ս", "��", "��", "Ӣ", "��", "��", "��", "��",
		"��", "��", "��", "��", "��", "��", "��", "��", "��", "��",
		"��", "��", "��", "˷", "��", "��", "��", "��", "��", "ڤ",
		"Ǳ", "��", "��", "��", "��", "��", "͢", "��", "��", "��",
		"��", "��", "�", "��", "��", "��", "��", "��", "��", "Ѱ",
		"��",}); 

	string* f_names = ({
		"��", "��", "��", "��", "��", "��", "��", "ѩ", "��", "��",
		"��", "˪", "��", "��", "��", "��", "��", "��", "��", "��",
		"��", "��", "��", "��", "ڤ", "ܰ", "��", "��", "��", "�",
		"��", "��", "��", "��", "��", "ӯ", "Ľ", "��", "��", "��",
		"��", "��", "ʫ", "Ʈ", "��", "��", "��", "��", "ӭ", "��",
		"ң",}); 

	if ( !ob->query_temp("huang_recr") )
		return notify_fail("��ҩʦ�����Ҳ���ǡ�\n");	

	name = this_player()->query("name");
	
	if( this_player()->query("gender") == "����") str = m_names[random(sizeof(m_names))];
	else str = f_names[random(sizeof(f_names))];
	new_name = name[0..01] + str + "��";

	this_player()->set("name", new_name);
	command("recruit " + ob->query("id"));
	obj=new("/d/taohua/obj/bagua");
	obj->move(this_object());
	command("give "+this_player()->query("id")+" bagua");
	command("say �ӽ��Ժ�������ֽ���"+new_name+"��");
	this_player()->delete_temp("huang_recr");
	
	if ( environment(this_object())->query("short") != "��ҩʦ�Ӵ�" )
	{
		write("˵�꣬��ҩʦƮȻ��ȥ��\n");
		destruct(this_object());
	}
	return 1;
}

int do_looko(string target)
{
	call_out("do_look", 1, target);
}

int do_fearo(string target)
{
	call_out("do_fear", 1, target);
}

int do_look(string target)
{
	object me;

	me = this_player();
	if (target=="huang" || target=="huang yaoshi" || target=="yaoshi" )
	{
		if (!me->query_temp("abuse_huang"))
		{
			command("sneer "+getuid(me));
			command("say "+RANK_D->query_rude(me)+"����һ�����ԣ���\n");
			me->set_temp("abuse_huang", 1);
		} 
		else
		{
			command("stare "+getuid(me));
			command("say "+"�ϻ����������㵱�ǲ�è���һ�����������Ұ�ĵط���\n");
			command("hit "+getuid(me));
			me->delete_temp("abuse_huang");
		}
	}
}

int do_fear(string target)
{
	object me;

	me = this_player();
	if (target=="huang" || target=="huang yaoshi" || target=="yaoshi" )
	if ((string)me->query("gender") != "Ů��")
	{
		command("fear " + getuid(me));
		command("say "+RANK_D->query_respect(me)+"��Ȼ�������������Ȥ���ã��Ϸ�ɲ��ҷ��㡣\n");
		if (random(2) > 0) command("kick " + getuid(me));
		else command("slap " + getuid(me));
	} 
	else
	{
		command("smile " + getuid(me));
		command("say "+"�Ϸ���׾��ȥ����������ֹˮ��"+RANK_D->query_respect(me)+"��������һ�¡�");
		command("sigh");
		write(CYN"��ҩʦ�������죬Ŀ���ƺ��м��㾫��������\n"NOR);
	}
}

int ask_shagu()
{
	object me, obj;

	me = this_player();

	command("say �⺢�������ڴ����������ʱ�ҵ��ģ��ܿ��������֮Ů����ϧ��֪����ʲ�ᾪ�ţ�����������ӡ�");
	if ( (present("amulet" , me) || me->query_temp("play_with_shagu") > 10 ) 
		&& !me->query_temp("ask_huang_about_shagu") )
	{
		command("say �⺢���Խ̫�ã��ѵ���������ͶԵ���Ҹ�������һ�⣬��������������磬����ת����");
		obj = new("/d/taohua/obj/shouyu");
		obj->move(me);
		me->set_temp("ask_huang_about_shagu", 1);
		message_vision("$N�ݸ�$nһ�����š�\n", this_object(), me);
	}
	command("sigh");
	return 1;
}

int ask_chengfeng()
{
	object me, obj;
	
	me = this_player();
	command("say ����������̫��������˳˷磮����");
	command("sigh");
	if (!query("xfsy_xinfa_given")) {
	command("say �������һ���ķ����ෳ"+RANK_D->query_respect(me)+"����˷磬�������⹦��ȥ�����ͳ���һ����������ȴ�ǲ��ѣ���������");

	obj = new("/d/taohua/obj/xfsy_xinfa");
	obj->move(me);
	set("xfsy_xinfa_given", 1);
	message_vision("$N�ݸ�$nһ�ű�ֽ��\n", this_object(), me);
	}
	return 1;
}

int accept_kill(object me)
{
	kill_ob(me);
	command("exert wuzhuan");
	return 1;
}

#include "/kungfu/class/taohua/auto_perform.h"