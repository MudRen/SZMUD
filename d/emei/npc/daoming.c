// Code of ShenZhou
// d/emei/npc/daoming.c ����Сʦ��
// Shan 96/09/24

inherit NPC;

void greeting(object);
void init();

void create()
{
	set_name("����Сʦ��", ({"daoming", "dao ming"}) );
	set("rank_info/respect", "Сʦ��");
	set("gender", "����" );
	set("age", 14+random(6));
	set("long",
	  "���Ǹ����䲻���Сʦ�����������������������ͷЦ��Ц��\n");
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

		set("combat_exp", 2000+random(200));
        set("score", 1000);

        set_skill("force", 30);
        set_skill("dodge", 20);
        set_skill("unarmed", 15+random(10));
        set_skill("parry", 20);
        set_temp("apply/attack", 10);
        set_temp("apply/defense", 15);
        set_temp("apply/damage", 3);

        create_family("������", 5, "����");

//        set("inquiry", ([
//            "����" : "��ȥ���Ǳߵľ���ʦ��ɡ�\n",
//        ]));

        setup();
        
        carry_object("/d/emei/npc/obj/hui-cloth")->wear();
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

	say("����Сʦ������˵������ӭ�������²ؾ�¥����Ҫ��������\n");
}

