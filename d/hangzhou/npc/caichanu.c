// Code of ShenZhou
// caichanu.c

inherit NPC;

void create()
{
	set_name("�ɲ�Ů",({ "girl" }) );
        set("gender", "Ů��" );
        set("age", 19);
        set("long", "���Ǹ�ˮ�����ũ��Ů����������������æµ�š�\n");

//      set("shen", -100);
        set("shen_type", 1);
        set("str", 15);
        set("dex", 18);
        set("con", 15);
        set("int", 17);
        set("combat_exp", 200);
        set_temp("apply/attack", 5);
        set_temp("apply/defense", 10);
	set("chat_chance", 5);
	set("chat_msg", ({
                "�ɲ�Ů˵����ٯ����ȥ�������㷥������һ��ȥ����ã�\n",
                "�ɲ�Ů�ش�������Կ�������ٯҪ�ԣ���Ҫ��������ѽ��\n",
		"�ɲ�Ů�ʵ�������ٯ��ȥ�ɻ�����\n",
		"�ɲ�ŮЦ����ٯ�ɰ��ķ��ø�����\n",
        }) );
        set("attitude", "peaceful");
        setup();

        carry_object("/d/city/obj/flower_shoe")->wear();
	carry_object("/d/quanzhou/obj/pink_cloth")->wear();
}

