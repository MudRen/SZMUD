// Code of ShenZhou
// /d/forest/npc/cl_lu.c
// by aln  2 / 98

inherit NPC;

void create()
{
        set_name("����ƽ", ({ "lu zhengping", "lu" }));
        set("title", "�쵶��������");
        set("long", 
"ֻ����һ�Ź��ַ���������һ����ף��������������û�ˡ�\n");
        set("gender", "����");
        set("age", 40);
        set("attitude", "friendly");
        set("shen_type", 1);
        set("str", 28);
        set("int", 30);
        set("con", 28);
        set("dex", 25);

        set("max_qi", 500);
        set("max_jing", 300);
        set("max_neili", 300);
        set("neili", 300);
        set("jiali", 20);
        set("combat_exp", 80000);
        set("score", 4000);

        set_skill("force", 70);
        set_skill("dodge", 70);
        set_skill("parry", 70);
        set_skill("cuff", 70);
        set_skill("blade", 80);

        set_skill("ding-force", 70);
        set_skill("wuxingbu", 70);
        set_skill("wuxing-quan", 70);
        set_skill("taiji-dao", 80);

        map_skill("force", "ding-force");
        map_skill("dodge", "wuxingbu");
        map_skill("cuff", "wuxing-quan");
        map_skill("parry", "taiji-dao");
        map_skill("blade", "taiji-dao");

        prepare_skill("cuff", "wuxing-quan");

        set("chat_chance", 8);
        set("chat_msg", ({
        "����ƽ˵�������ְ��˾ͽ����밳���й����Ľ��飬����ȥ�ݷ������˼ҡ�\n",
        }) );

        set("inquiry",([
                "������" : "�´���������������������ȫ�����ʮ������",
                "���ְ�" : "��Ҳ��Ҫ�����ְ��ɽ��",
                "˾ͽ���" : "˾ͽ�����¾����ֵ��ҵ��¡�",
                "˾ͽ��" : "��˵���ְ�ļ������ҷ��Ϻ���������",
        ]));

        setup();

        carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/gangdao")->wield();
}

