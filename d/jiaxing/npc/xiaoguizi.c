// Code of ShenZhou
// Jay 9/26/96

inherit NPC;

string ask_for_zigong();

void create()
{
        set_name("С����", ({"xiao guizi", "guizi"}));
        set("title", "���ŷ�С̫��");
        set("long",
                "�������ŷ�С̫�࣬��ʮ����������ӣ��Ǻ��Ϲ��ĸ��ࡣ\n"
        );

        set("gender", "����");

        set("attitude", "friendly");
        set("class", "eunach");

        set("age", 15);
        set("shen_type", 1);
        set("str", 25);
        set("int", 20);
        set("con", 20);
        set("dex", 25);
        set("max_qi", 100);
        set("max_jing", 100);
        set("combat_exp", 50);

        setup();

        carry_object("/clone/misc/cloth")->wear();
}

