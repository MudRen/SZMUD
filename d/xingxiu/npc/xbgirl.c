// Code of ShenZhou
// ryu

inherit NPC;

void create()
{
        set_name("������Ů", ({ "girl" }) );
        set("gender", "Ů��" );
        set("age", 18);
        set("long", "һ��������ȵ���������Ů��\n");
        set("shen", 1000);
        set("combat_exp", 300);
        set("str", 19);
        set("dex", 25);
        set("con", 18);
        set("int", 13);
        set("attitude", "friendly");
        setup();
        set("chat_chance", 2);
        set("chat_msg", ({
                "������Ů������Ц������\n",
                "������Ů����س�������Ұ�ƹ�����������ϣ�������Ҫ�������֮ң��ɳĮ�У�\n"
		"�и�����ȥ�����������᷿ˡ�\n",
        }) );
        carry_object(__DIR__"obj/chouqun")->wear();
	carry_object(__DIR__"obj/hulu");
}

