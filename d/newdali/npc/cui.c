// Code of ShenZhou
// banker.c
#include <ansi.h>
inherit NPC;
inherit F_DEALER;
string ask_me();

void create()
{
	set_name("�ް�Ȫ", ({"cui baiquan", "cui", "baiquan"}));
	set("nickname", "������");
	set("long","����һ������ȥ�������һ�������ˣ���ɫ���ơ�\n");
	set("gender", "����");
	set("age", 55);
	set("title", "ƽ�������ܼ�");
	set("str", 28);
	set("int", 24);
	set("dex", 28);
	set("con", 28);

	set("shen", 1000);

	set("combat_exp", 300000);
	set("shen_type", 1);
	set("attitude", "friendly");
	set("env/wimpy", 50);

	set_skill("cuff", 80);
	set_skill("dodge", 80);
	set_skill("hammer", 180);
	set_skill("duanshi-shenfa",80);
	set_skill("jinyu-quan",65);
	map_skill("dodge","duanshi-shenfa");
	map_skill("cuff", "jinyu-quan");
	prepare_skill("cuff", "jinyu-quan");

	set("inquiry", ([
		"��Ǯ" : (: ask_me :),
		]));

	create_family("����μ�",17,"����");
	setup();
	add_money("coin", 188);
	add_money("silver", 88);
	add_money("gold", 1);
	carry_object("/d/city/obj/guazi")->wear();
	carry_object(__DIR__"obj/jinsuanpan")->wield();
}

void enough_rest()
{
	delete_temp("busy");
}

/*void unconcious()
{
        message_vision("\nͻȻ��ֻ��$N����������̨��һ�����ţ����˽�ȥ���������
�߰��������ˡ�\n",
                this_object());
        destruct(this_object());
}
*/
void attempt_apprentice(object ob)
{
	command("haha");
	command("say �����̵ģ�����һ��������������ۣ��̲�����ʲô��");
	return;
}

string ask_me()
{
	int wage;
	object ob = this_player();
	if (ob->query("family/family_name")!="����μ�") {
		command("say ������������" + RANK_D->query_rude(ob) +
				"�۸���������ʵ�����թƭ��������ҹ���");
		command("slap " + ob->query("id"));
		return ("С���������㣡");
	}
	if (ob->query("title")=="�������ү") 
		return ("��ү��Ӧ�������С���ҷ���Ǯѽ��");

	if (ob->query("title")=="�����ƽ�������Ҷ�" ||
		ob->query("title")=="�����ƽ�������Ů" )
		return ("��ү����ڷ��ԾͲ����ˣ�����Ҫ��Ǯ��");

	if (ob->query("title")=="�����ƽ��������ʿ")  
		return ("����Ϊ��ʿ��Ӧ��ר���������ǣ�����Ǯ������ĵġ�");
	
	if (!ob->query("dali/jobdone"))
		return ("��Ҫ��Ҫ������׳Է������ȸɵ�ʲô����Ǯ��");

	else {
		if (ob->query("lastcheck") < ob->query("dali/jobdone") ) {
		if (ob->query("combat_exp")<30000) {
		wage = (ob->query("dali/jobdone")-ob->query("lastcheck"))*500;
	ob->set("lastcheck",ob->query("dali/jobdone"));
	command("say ��������ӵĳ��ͣ��úøɣ�");
	command("say �����ҿ��㱿�ֱ��ŵģ�����ǮҲ�ղ��Σ��ɴ��Ұ�����°ɣ�");
	ob->add("balance", wage);
	return ("���ͼ����ɣ�");
}
	else { 
	wage=(ob->query("dali/jobdone")-ob->query("lastcheck"))*ob->query("combat_exp")/70;
	ob->set("lastcheck",ob->query("dali/jobdone"));
	command("say ��������ӵĳ��ͣ��úøɣ�");
	command("say �����ҿ��㱿�ֱ��ŵģ�����ǮҲ�ղ��Σ��ɴ��Ұ�����°ɣ�");
	ob->add("balance", wage);
	return ("���ͼ����ɣ�");       
}
}
else
	return("���ϴ���нˮ���������Է����ɻ����û��Ĺ�Ǯ��");
}
}
