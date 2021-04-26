// Code of ShenZhou
// d/emei/npc/wenhui.c ����Сʦ̫
// Shan 96/06/29

inherit NPC;

void greeting(object);
void serve_tea(object);

void create()
{
	set_name("����Сʦ̫", ({"wenhui", "wen hui"}) );
	set("rank_info/respect", "Сʦ̫");
	set("gender", "Ů��" );
	set("age", 12+random(6));
	set("long",
	  "���Ǹ����䲻��ü��Ŀ���Сʦ̫����һ��������������Ц�Ź�ȥ�д���\n");
	set("attitude", "friendly");
        set("shen_type", 1);
        set("class", "bonze");

        set("str", 20);
        set("int", 28);
        set("con", 24);
        set("dex", 20);

        set("max_qi", 150);
        set("max_jing", 100);
        set("neili", 150);
        set("max_neili", 150);

		set("combat_exp", 1000+random(800));
        set("score", 1000);

        set_skill("force", 30);
        set_skill("dodge", 20);
        set_skill("unarmed", 15+random(10));
        set_skill("parry", 20);
        set_temp("apply/attack", 10);
        set_temp("apply/defense", 15);
        set_temp("apply/damage", 3);

        create_family("������", 5, "����");

        set("inquiry", ([
            "����" : "��ȥ���Ǳߵľ���ʦ��ɡ�\n",
        ]));

        setup();
        
	carry_object("/d/emei/npc/obj/nun-cloth")->wear();
        carry_object("/d/emei/npc/obj/emei-shoes")->wear();

}

void init()
{	
	object ob;

	::init();

	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;

	say("����Сʦ̫˵������λʩ����������������͸����ϲ�㡣\n");
}

void serve_tea(object who)
{
	object ob;
	object room;

	if( !who || environment(who) != environment() ) return;

//	if( !who->query_temp("marks/sit") ) return;
	
	if( !objectp(room = environment()) ) return;

	message_vision("�����ó�һ�����ʵ�ˮ���ң������˱�����$N��\n", who);
	ob = new("d/wudang/obj/xiangcha");
	ob->move(this_player());
 	ob = new("d/wudang/obj/mitao");
	ob->move(this_player());
	message_vision("������$NһЦ����æ���к���������ȥ�ˡ�\n", who);
	
	return;
}
