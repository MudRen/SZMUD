// Code of ShenZhou
// /d/huanghe/changle/npc/gaosan.c ��������
// by aln 2 / 98

inherit NPC;

void create()
{
        set_name("��������", ({ "gao san", "gao" }));
        set("title", "����ׯŮׯ��");
        set("long", 
                "��Ů�����м�����ɫ��������ȹ����ϵ���廨����\n"
                "������������������Ŷ̵���\n");
        set("gender", "Ů��");
        set("age", 35);
        set("attitude", "friendly");
        set("shen_type", 1);
        set("str", 23);
        set("int", 30);
        set("con", 28);
        set("dex", 25);

        set("max_qi", 500);
        set("max_jing", 300);
        set("max_neili", 300);
        set("neili", 300);
        set("jiali", 20);
        set("combat_exp", 70000);
        set("score", 3500);

        set_skill("force", 65);
        set_skill("dodge", 65);
        set_skill("parry", 65);
        set_skill("cuff",  65);
        set_skill("blade", 70);

        set_skill("ding-force", 65);
        set_skill("wuxingbu", 65);
        set_skill("wuxing-quan", 65);
        set_skill("luan-blade", 70);

        map_skill("force", "ding-force");
        map_skill("dodge", "wuxingbu");
        map_skill("cuff", "wuxing-quan");
        map_skill("parry", "luan-blade");
        map_skill("blade", "luan-blade");

        prepare_skill("cuff", "wuxing-quan");

        set("chat_chance", 3);
        set("chat_msg", ({
                "��������ŭ����������������������һ��Ҫ�������ʣ�\n",
        }) );

        set("inquiry",([
                "������" : "�´������������������������ϲ弸�ѷɵ���",
                "���ְ�" : "��Ҳ��Ҫ�����ְ��ɽ��",
                "˾ͽ��" : "��˵���ְ�ļ������ҷ��Ϻ���������",
        ]));

        setup();

        carry_object("/clone/misc/cloth")->wear();
        carry_object("/d/dali/obj/duandao")->wield();
}
