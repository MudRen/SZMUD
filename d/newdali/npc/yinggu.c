// Code of ShenZhou
// yinggu.c  dali NPC
// acep , mantian , mantian

inherit NPC;
string ask_me();
int do_answer(string);

void create()
{
	set_name("����", ({ "ying gu", "ying", "gu" }) );
	set("gender", "Ů��" );
	set("age", 48);
	set("long", 
		"��ͷ�����ף����������������ŵ���������һ������Ƭ��"
		"��Ȼ����Ǳ��˼������Ȼ�������˽�����ȴ��̧ͷ��\n");

	set("str", 25);
	set("dex", 35);
	set("con", 27);
	set("int", 25);
	set("shen_type", 1);
	set("max_neili",800);
	set("neili",800);
	set("jiali",30);

	set_skill("unarmed", 80);
	set_skill("dodge", 80);
	set_skill("sword",100);
	set_skill("force", 100);
	set("combat_exp", 100000);

	set("attitude", "peaceful");
	set("inquiry", ([
		"�λ�ү" : "��������ʲô���ߣ�����ҽ���ᣬ���������İɡ�",
		"������" : "��������ʲô���ߣ�����ҽ���ᣬ���������İɡ�",
		"����" :  (: ask_me :),
		]) );

	setup();

	carry_object("/d/forest/npc/obj/gebu-changpao")->wear();
	if (clonep()) carry_object("/clone/weapon/qijue.c", "/clone/weapon/xiuhua.c")->wield();
}

void init()
{
	::init();
	add_action("do_answer","answer");
}

string ask_me()
{
	object who=this_player();
	if (who->query_temp("marks/��")) {
			write("���������˵����һ���㻹û������أ���ʲô��\n");
			return "һ��һ��������\n";
	}
	else {
		write("����̧ͷ������һ�ۣ���λ"+RANK_D->query_respect(who)+"Ҳ��������\n");
		switch(random(2)) 
		{
		case 0:
			write("������ǧ���ٶ�ʮ���ƽ����Ϊ���\n");
			who->set_temp("marks/��", 1);
			break;
		case 1:
			write("���������ݺ�б���������������\n");  
			write("�Ķ�����һ����������һ�ǣ���Ǻ���? \n");
			who->set_temp("marks/��", 2);
			break;
		case 2:
			write("�����ˣ���ȡ��룬���տ���? \n");
			who->set_temp("marks/��", 3);
			break;
		}
		message_vision("��������ض�$N˵�����? \n", who);
		return "�������ͻش�(answer)�ҡ�\n";
	}
}

int do_answer(string arg)
{
	int soln,riddle;
	object me = this_player();
	riddle = this_player()->query_temp("marks/��");

	if (!riddle) {
		write("���ֲ�����ʦ�������ò��Żش��ҡ�\n");
		return 1;
	}

	if( !arg || arg=="" ) {
		write("����յ��ٻش�\n");
		return 1;
	}
	message("vision", me->name() + "�����ش�\n", environment(me), ({me}));

	switch (arg) 
	{
	case "������ʮ��": soln=1; break;
	case "��ʮ" : soln=2; break;
	case "���ز���" : soln=3; break;
	default :
		say("������Ц����������Ū������Ȼ��Ͱ�"+ me->name() +"���˳�ȥ��\n");
		me->move("/d/dali/maze1");
	return 1;
	}

	if (riddle==soln) {
		this_player()->set_temp("marks/��", 0);
		say ("����̧ͷ�����Ƴ��"+me->name()+"һ�ۣ���Ҫ�Ҷ����˴��Һ��ų�ȥ��\n");
		me->move("/d/dali/yideng1");
		write ("���߳�����������һ��Сɽ���£�\n");
		return 1;
	}
	else {
		command("slapsb "+getuid(me));
		say("����ŭ�������㵽�׶�����������������"+ me->name() +"���˳�ȥ��\n");
		me->move("/d/dali/droad2");
	return 1;
	}
}
