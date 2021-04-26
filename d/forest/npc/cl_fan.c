// Code of ShenZhou
// /d/forest/npc/cl-fan.c  ��һ��
// by aln 2 / 98

inherit NPC;

void create()
{
        set_name("��һ��", ({ "fan yifei", "fan" }));
        set("title", "�ױ���������");
        set("long",
"����һ�����ݵ����ߣ�һ�ź�����\n"
"��������йٱʣ��˳ơ��ɶ��ס���\n");
        set("age", 50);
        set("attitude", "friendly");
        set("shen_type", 1);
        set("str", 25);
        set("int", 30);
        set("con", 28);
        set("dex", 25);

        set("max_qi", 600);
        set("max_jing", 300);
        set("max_neili", 400);
        set("neili", 400);
        set("jiali", 20);
        set("combat_exp", 100000);
        set("score", 5000);

        set_skill("force", 80);
        set_skill("dodge", 80);
        set_skill("parry", 80);
	set_skill("cuff", 80);
        set_skill("club", 90);

        set_skill("ding-force", 80);
        set_skill("wuxingbu", 80);
        set_skill("wuxing-quan", 80);
        set_skill("wuhu-gun", 90);

        map_skill("force", "ding-force");
        map_skill("dodge", "wuxingbu");
        map_skill("cuff", "wuxing-quan");
        map_skill("parry", "wuhu-gun");
        map_skill("club", "wuhu-gun");

        prepare_skill("cuff", "wuxing-quan");

        set("chat_chance", 3);
        set("chat_msg", ({
        "��һ��˵�������ְ��˾ͽ����밳���й����Ľ��飬����ȥ�ݷ������˼ҡ�\n",
        }) );

        set("inquiry",([
                "������" : "�´�������������������������ҪѨ����һ�㡣",
                "���ְ�" : "��Ҳ��Ҫ�����ְ��ɽ��",
                "˾ͽ���" : "˾ͽ�����¾����ֵ��ҵ��¡�",
                "˾ͽ��" : "��˵���ְ�ļ������ҷ��Ϻ���������",
        ]));

        setup();

        carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/panguanbi")->wield();
}
        

