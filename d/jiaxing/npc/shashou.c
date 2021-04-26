// Code of ShenZhou
// Jay 8/9/96

inherit NPC;

void create()
{
        set_name("ɱ��", ({ "shashou" }) );
        set("gender", "����" );
        set("age", 22);
        set("long", 
	     "һ��ɱ�����ڵ�ɱ�֡�\n");
        set("shen_type", -1);

        set("combat_exp", 10000);

        set("attitude", "friendly");

        set_skill("unarmed", 50);
        set_skill("dodge", 50);
        set_skill("parry", 50);
        set_skill("blade", 50);

        setup();
        carry_object("/d/city/obj/cloth")->wear();
	carry_object("/d/city/obj/gangdao")->wield();
}

void init()
{
        object ob;

        ::init();
        if ((ob = present("xiang wentian",environment(this_object()))) && !is_fighting()) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object me)
{
	say("ɱ�ִ��һ�������������ߣ�\n");
	kill_ob(me);
}

