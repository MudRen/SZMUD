// NPC jiuyi.c// update by firefox
//	2001-10-23
#include <ansi.h>
inherit NPC;
string ask_me();
string ask_jiu();
string ask_zhishang();
string ask_steal();
string ask_xiongshewan();
string ask_dahui();
int kill(string arg); 

void create()
{
	set_name("���ϴ�", ({ "wu laoda", "wu"}));
	set("long",
@LONG�������������������ϴ�����ı��ͯ��δ����������ڴˡ�
LONG	    	   );
//	set("title", "����һƷ�ø���");
	set("gender", "����");
//	set("nickname", HIR "�׶��ھ���֮��" NOR);
	set("age", 40);
	set("shen_type",-1);
	set("attitude", "peaceful");
	set("str", 27);
	set("int", 23);
	set("con", 24);
	set("dex", 30);
	set("max_qi",1000);
	set("eff_qi",100);
 	set("qi", 100);
// 	set("qi", 1000);
	set("jing", 500);
	set("max_jing", 500);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 0);
	set("combat_exp", 1000000);
	set("score", 100000);
	set("no_get",1);
	set("no_fight",1);
	set("inquiry", ([
		"�����ܵ���" : (: ask_me :),
		"���" : (: ask_jiu :),
		"����" : (: ask_zhishang :),	
		"��ת������" : (: ask_xiongshewan :),
		"��ȡ" : (: ask_steal :),
		"���ɴ��" : (: ask_dahui :),
	]));
	set("chat_chance", 3);
        set("chat_msg", ({"���ϴ��૵��������ܵ�������Ǻö�����\n",        }) );
	set("wan_count", 1);
	setup();
}

void init()
{
	::init();
	add_action("do_kill","kill");
}

string ask_me()
{
	mapping fam;
 	object ob;	
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "���չ�")
		return RANK_D->query_respect(this_player()) +"������Ҫ���չ�֮���ɱ����أ�";
	if (query("wan_count") < 1)
		return "������˼���Ѿ����˽����ȵ��ˣ����´������ɡ�\n";
	add("wan_count", -1);
	ob = new("/clone/drug/xiongdan-wan");
	ob->move(this_player());
	return "����������������ҵķ��ϣ���Ű����ܵ���͸���ɡ�\n";
}

string ask_jiu()
{
	mapping fam;
	object ob;
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "���չ�" || 
		!this_player()->query_temp("apply/name/������"))
		return "���Ǻη���ʥ�����չ����Ƕ�����ȥ����֮�أ����Ծ��ң�\n";
	this_player()->set_temp("xiongshe_quest",1);
	command("thank "+this_player()->query("id"));
	return "�������ѱ������ˣ�ֻ�¶�һ����������֮Σ��\n";
}

string ask_zhishang()
{
	if (this_player()->query_temp("xiongshe_quest")) {
		this_player()->set_temp("xiongshe_quest",2);
		return "�����˳��˱���ʥҩ��ת���������ҽ���⣬ֻ��ƽһָ���Ҳ���Ծ��Σ�\n";
	}
}
string ask_xiongshewan()
{
	if (this_player()->query_temp("xiongshe_quest")>=2) {	
		this_player()->set_temp("xiongshe_quest",3);
		return "��ת����������������ʥҩ������������֮��Ч����ͯ�������ղأ����Ū�õ���\n";
	}
}
string ask_steal()
{
	if (this_player()->query_temp("xiongshe_quest")>=3) {		
		this_player()->set_temp("xiongshe_quest",4);
		return "Ҫ��ȡ��ҩ�Ǳȵ��컹�ѣ���������һ���Ա������ɴ��ʱʹ�ã���ϧû�������ϡ�\n";
	}
}
string ask_dahui()
{
	if (this_player()->query_temp("xiongshe_quest")>=4) {
		command("whipse "+this_player()->query("id")+
			" ���ɴ����������ʮ������������ʮ��������������������ɽͯ�ѣ�Ϊ���������֮�࣬\n"+
			"ɱ����ɽͯ�Ѷ���ͬ�ٰ����Ҫ��ᡣ�����¹��ش����ѿ�ǧ�򲻿ɶ����ԡ�\n");
		message_vision("$N�����ϴ�˵��������Ⱥô�ĵ��ӣ�����ı��ͯ�ѣ������ȥ����ͯ�ѡ���Ⱥ�ͯ�ѷ���ɣ�\n",this_player());
		command("ah "+this_player()->query("id"));
		this_player()->set_temp("xiongshe_quest",5);
		message_vision("$N����ƭ�����ϴ�������ɴ������ܣ���¶��������Ŀ��\n",this_player());
		return "�㡭���㵽���ǵ����ѣ�";
	}		
}
int do_kill(string arg)
{
	object ob;
	if ( !arg || !(ob=present(arg,environment(this_object())))) return 0;
	if ( this_player()->query_temp("xiongshe_quest")==6) {
		environment(this_object())->delete("no_fight");
		message_vision("$N�����ϴ�˵�����������������ɣ�\n",this_player());
		write(HIG"ֻ�����һ���������б����Ѵ����ϴ���ǰ�Դ�������ವ�һ���ַɻ�������У�\n"NOR);
		this_player()->set_temp("xiongshe_quest",7);
		ob->die();
		return 1;
	} else {
		if (ob->query("name")=="���ϴ�"){
			write("��������Ѷ�ģ����ϴ������������ͯ�ѽ�����\n");}
		return 0;	
	}
} 