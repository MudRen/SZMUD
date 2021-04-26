// Code of ShenZhou
// Jay 7/12/96

inherit NPC;

void create()
{
        set_name("�����", ({ "xiao banhe", "xiao", "banhe" }) );
        set("gender", "����" );
	set("nickname", "��������");
        set("age", 38);
        set("long", 
		"��������ΰ��������ף���Ȼ�������䡣\n");
        set("str", 45);
        set("dex", 30);
        set("con", 27);
        set("int", 25);
        set("shen_type", 1);

        set_skill("unarmed", 80);
	set_skill("force", 80);
        set_skill("dodge", 75);

        set("combat_exp", 65000);

        set("max_qi", 500);
        set("max_jing", 200);
        set("neili", 800);
        set("max_neili", 800);
	set("jiali",40);


        set("attitude", "peaceful");
        set("inquiry", ([
            "name" : "��ԭ�����壬��Ľ��������̫��֣��Զ��������������"+
		     "���ĵ���������Ͻ����ָ�Ϊ����͡�����˼˵������֣�͵�һ��Ӣ�ۡ�",
            "ԧ�쵶" : "������һ�ԡ�ԧ�쵶�������߿��޵�����¡�",
       ]) );

        setup();
        carry_object("/d/city/obj/cloth")->wear();
        add_money("silver", 10);
}
void init()
{
        object ob;

        ::init();
        if (interactive(ob = this_player()) && !is_fighting()) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object me)
{
	if (present("yuan dao", me) || present("yang dao", me)) {
	command("say �����С�������һ������������ף���������");

	write("\n\n\n");
	kill_ob(me);
	}
	else {
	command("bow "+me->query("id"));
	command("say ͬϲͬϲ��");
	}
}


