// Code of ShenZhou
// zhongling.c

inherit NPC;

string ask_me();

void create()
{
	set_name("����", ({ "zhong ling","ling" }) );
	set("gender", "Ů��");
	set("age", 16);
	set("long",
		"������������Ů�������飬��������Ц���绨��ʮ��������\n����������������Ҳ��ԲԲ�Ĵ��۾����´����㡣\n");
	set("combat_exp", 10000);
	set("shen_type", 1);
	set("attitude", "peaceful");

	set("apply/attack", 20);
	set("apply/defense", 20);

	set_skill("unarmed", 50);
	set_skill("parry", 50);
	set_skill("dodge", 50);

	set("bm_hints", random(10)+1);
        
	set("inquiry", ([
		"����"   : "���ϴ�͵�ܳ�ȥ�棬������ɽ�����˶δ�磬������һ��������������Ȥ�ˡ�",
		"����ɽ" : "���Ǳ�����Ƭɽ�ˣ�ûɶ����ģ�һȺ��ũ��������ں����������ԡ��� ... �Ƕ���·�����ߡ�",
//		"��·"   : (: ask_me :),
		]));

	setup();

	carry_object("/clone/misc/cloth")->wear();
}

string ask_me()
{
	object me, who;
	me=this_object();
	who=this_player();

	command("look "+getuid(who));
	command("hmm");

	if (me->query("bm_hints")==1) {
		command("nod "+getuid(who));
		command("say �㿴�������Ǹ����ˣ����Ҿ͸�����ɡ�");
		command("whisper "+getuid(who)+" �������ϣ������ϣ�������������ũ��ۼ��ĵط���");
		who->set_temp("bmquest/got_hint1",1);
		return "�ǵط��������ң������Կ�����ǧ�����߱���Ӵ��������\n";
	}
	else {
		return "����㴳�����˵����������������Ǹ��ö��������߿�����ʲôҲ���������ģ�";
	}
}
