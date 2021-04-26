// Code of ShenZhou
// woodcutter.c �Է�
// A.P.

inherit NPC;

string ask_me();

void create()
{
	set_name("�Է�", ({ "qiao fu", "qiao", "woodcutter" }));
	set("long", "һ�������Է򣬿���������ͨͨ������������������һ�ɰ�����\n");
	set("gender", "����");
	set("age", 35);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 25);
	set("int", 30);
	set("con", 25);
	set("dex", 30);
	set("shen", 0);
	set("max_qi", 1800);
	set("max_jing", 1800);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 100);
	set("combat_exp", 10);
	set("score", 5000);
	set_skill("force", 120);
	set_skill("dodge", 120);
	set_skill("parry", 120);
	set_skill("axe", 150);
	set_skill("finger", 120);
	set_skill("yiyang-zhi", 100);
	set_skill("duanshi-shenfa", 100);
	set_skill("kurong-changong", 80);
	map_skill("dodge", "duanshi-shenfa");
	map_skill("force", "kurong-changong");
	map_skill("finger", "yiyang-zhi");
	prepare_skill("finger", "yiyang-zhi");

	set("inquiry", ([
		"��ɽ" : "Ҫ����ɽ���ȹ����������˵��\n",
		]));
	
	setup();
	carry_object("/d/dali/obj/axe1")->wield();
	carry_object("/d/city/obj/cloth")->wear();
}

string ask_me()
{
	set("combat_exp",350000);
	return ;
}

int accept_fight(object ob)
{
	object me = this_object();

	if (environment(me)==find_object("/d/dali/yideng4.c")) {
		set("combat_exp",350000);
		me->set_temp("challenger", ob);
		return 1;
	}
	else { return 1; }
}

int chat()
{
	object axx, me = this_object();
	object ob = me->query_temp("challenger");
	object weapon;

	if ( !objectp(ob) ) return ::chat();

	if (me->is_fighting(ob)) {
		if (objectp(weapon=me->query_temp("weapon"))) {
			command("unwield axe");
			message_vision("�Է���һ������$N��������ָ��\n", ob);
			call_out("fast_hit", 1, me, ob, 0);
			call_out("fast_hit", 2, me, ob, 0);
			call_out("fast_hit", 3, me, ob, 1);
		}
		return ::chat();
        }

	me->delete_temp("challenger");
	remove_call_out("fast_hit");
	if (me->is_fighting()) return ::chat();

	if (me->query("qi")*2 <= me->query("max_qi")) {
		command("say "+"��Ȼ������");
		command("thumb "+getuid(ob));
		axx=new("/d/dali/obj/axe1.c");
		axx->move(me);
		command("give "+getuid(ob)+" axe");
		message_vision("�Է�ת�����ɽ��ȥ��һ����Ͳ�����\n",ob);
		destruct(me);
		return ::chat();
	}
	else {
		if (ob->query("qi")*2 <= ob->query("max_qi")) {
			message_vision("�Է�м�ض�$NƲ��Ʋ�죺������㹦�򣬻�����ɽ����ʦ��������İɣ���\n",ob);
			ob->move("/d/dali/droad2.c");
			set("combat_exp",10);
			if (!present("axe", me)) {
				axx=new("/d/dali/obj/axe1.c");
				axx->move(me);
			}
			weapon = present("axe", me);
			command("wield axe");
			return ::chat();
		}
	}
	return ::chat();
}

void fast_hit(object me, object ob,int a)
{
	COMBAT_D->do_attack(me, ob);
	if (a==1) command("wield axe");
	return;
}
