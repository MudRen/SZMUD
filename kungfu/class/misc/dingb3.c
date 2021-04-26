// Code of ShenZhou
// dingb3.c ������
// xQin 8/00 

#include <ansi.h>
inherit	NPC;
inherit F_MASTER;

void init();
void do_say(string);
void do_fear();

string ask_nick(object);
string ask_dingdang();

void create()
{
	set_name("������", ({"ding busan", "ding", "busan" }));
	set("long",
		"ֻ�������뷢�Ȼ��ü����Ц���Ǹ���Ŀ�������ͷ����\n"
		"������Ŀ��һ������ʱ���������Ļ���������ս������\n"
		"�������һ���������ݵ��׺�֮�⣬����һ��֮�£�����\n"
		"�е�һ�ɺ��⣬����Ҫ�䵽������ȥ��\n");
	set("nickname", WHT"һ�ղ�����"NOR);
	set("gender", "����");
	set("attitude", "heroism");
	set("age", 65);
	set("shen_type", -1);
	
        set("str", 22);
        set("int", 24);
        set("con", 26);
        set("dex", 20);
        
        set("qi", 3000);
        set("max_qi", 3000);
        set("jing", 1000);
        set("max_jing", 1000);
        set("neili", 3000);
        set("max_neili", 3000);
        set("jiali", 50);

        set("combat_exp", 500000);
        set("score", 500000);

	set_skill("force", 180);
	set_skill("parry", 160);
	set_skill("dodge", 160);
	set_skill("hand", 180);
	set_skill("taixuan-gong", 160);
	set_skill("ding-dodge", 160);
	set_skill("dingjia-qinnashou", 170);
	set_skill("literate", 60);
	
	map_skill("force", "taixuan-gong");
	map_skill("parry", "dingjia-qinnashou");
	map_skill("hand", "dingjia-qinnashou");
	map_skill("dodge", "ding-dodge");
	prepare_skill("hand", "dingjia-qinnashou");
	
	set("inquiry", ([
	"nickname" : (:ask_nick:),
	"���" : (:ask_nick:),
	"һ�ղ�����" : (:ask_nick:),
	"����" : (:ask_dingdang:),
	"��������" : (:ask_dingdang:),
	"����": (:ask_dingdang:),
	"�����̻��" : ""+RANK_D->query_rude(this_player()) +"�ں�˵�˵�Щʲô����\n",
	"ѩɽ��" : "�ߣ�ѩɽ��ûһ�����ˣ��������Ǹ������ڣ����Գ�ʲô�������������������Ĺ�ƨ��\n",
	"xueshan" : "�ߣ�ѩɽ��ûһ�����ˣ��������Ǹ������ڣ����Գ�ʲô�������������������Ĺ�ƨ��\n",
	]));
	 
	set("chat_chance",6);
        set("chat_msg", ({
        	"������������˵���������⡸һ�ղ���������Ȼ���е���ֻ��ϧ�������˶������������е����\n",
        	"�����������ƿ���๾��ĺ��˼��ڡ�\n",
        	"����������������Ǹ�Ѿͷ��֪������ȥ�ˣ���Ȼ��үү�ĳ�������Ҳ͵���ˣ�\n"
        	"��������������˵��������ɱ��һ�ղ��������ñ��������ꡢ���򴺣���ֻ�������ѡ�\n",
        }));
        set_temp("first/ask", 1);
        setup();
        carry_object("/d/city/npc/wine/nuerhong");
	carry_object("/d/city/obj/qcloth")->wear();
        carry_object("/d/city/obj/zi_shoes")->wear();
}

void init()
{
	object me;
	me=this_player();
	
	if( me->query("family/family_name") == "ѩɽ��") 
        {
        command("look "+getuid(me));
        command("sneer "+getuid(me));
	}
	add_action("do_say","say");
	add_action("do_fear","fear");
}


string ask_nick(object me)
{
        me=this_player();
	
	if (query_temp("first/ask") > 1)
	{
	command("say ����һ�������˽��ƣ��������ն�ɱ������һ��Ҳ����һǧ���ο��������ղ�ɱ��ɱ����Ҳ����ֻһ���ˡ�");
	command("idea "+me->query("id"));
	return "����үү��������ô����������ʵʵ��үү˵��Ҫ��үү���ˣ���Ȼ����ô���";
	}
	add_temp("first/ask", 1);
	return "���ӵ���ɱ��̫�࣬�������¹�أ�һ��֮��ɱ�˲��ù�������";

}

void do_say(string arg)
{
        object me;
        me=this_player();
        
        if (arg=="үү�����ֺܺ�����" || arg=="үү����źܺ�����") {
        if (me->query("got/wine") > 10) 
        {
        command("goodkid "+me->query("id"));
        return;
	}
	if (query_temp("first/ask") > 1)
	{
	command("haha");
	command("haha "+me->query("id"));
	command("pat "+me->query("id"));
	command("say ���������ҵ����ֶ��ŷ�ɥ�����ѵ��㻹���ľ���үү����ź�����");
	command("secret "+me->query("id"));
	message_vision("��������ס$N��$N�Ķ�������˵��Щ����\n",me);
	command("whisper " +me->query("id") + " " + "үү�������������������үү�ġ������̻�ơ��������Ǹ�Ѿͷ͵���ˣ���������ҵ��������Ұ���Ȱ���������ⱦ��������ɣ�");
	command("say ���ˣ���ȥ��أ�");
	me->set_temp("find/dddd", 1);
	return;
	} 
	else {
	command("en "+me->query("id"));
	command("say �㶮ʲô��������ʵ�����������ƨ��");
	command("consider "+me->query("id"));
	me->add_temp("potential/victim", 1);
	return;
	}
	}
}

string ask_dingdang()
{
	object me;
	me=this_player();
	
	if (me->query_temp("find/dddd"))
	{
	command("whisper " +me->query("id") + " " + "������Ѿͷ���������ְ��Ƿ������ˣ��ǵ�ҪȰ��������");
	return "������ȥ��ĥ��ʲô����";	
	}
	else {
	return "������Ѿͷ��֪������ȥ�ˡ�";
	}
}

void do_fear()
{
	object ob, me;
	ob=this_object();
	me=this_player();
	
	if ( environment(me)==find_object("/d/city/jiuguan2.c")
	&& ob->query_temp("did/kill") < 3) {
	if (me->query_temp("potential/victim") > 2)
	{
	command("hehe");
	command("kill "+me->query("id"));
	ob->add_temp("did/kill", 1);
	me->delete_temp("potential/victim");
	return;
	} 
	else {
	command("hmm");
	me->add_temp("potential/victim", 2);
	return;
	}
		}
	else {
	command("say ���ӽ���ɱ���ˣ����������������ʰ�ɣ�");
	return;
	}
			
}

	