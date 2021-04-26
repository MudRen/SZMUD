// Code of ShenZhou
// /d/hangzhou/npc/yang.c   ������
// by aln 2 / 98

inherit NPC;

void create()
{
        set_name("������", ({ "yang tiexin", "yang" }) );
        set("gender", "����");
        set("age", 25);
        set("long",
"һ���׾���Ƥ�ĺ��ӡ�\n"
"���������������������˵ĺ����\n");
        set("combat_exp", 180000);
        set("shen_type",  1);
        set("attitude", "friendly");

        set("str", 28);
        set("con", 30);
        set("int", 20);
        set("dex", 27);

        set("max_qi", 800);
        set("max_jing", 300);
        set("max_neili", 1000);
        set("neili", 1000);
        set("jiali", 30);

        set_temp("apply/armor", 40);

        set_skill("force", 100);
        set_skill("dodge", 100);
        set_skill("parry", 100);
        set_skill("liuhe-qiang", 120);
        set_skill("pike", 120);
        set_skill("unarmed", 100);

        map_skill("pike", "liuhe-qiang");
        map_skill("parry", "liuhe-qiang");

        set("inquiry", ([
                "��Х��" : "���������֡�",
                "��ϧ��" : "�����һ�ҡ�",
                "�" : "����һ�����˸���δ�����Ķ�Ůȡ�����֡�",
                "����" : "���������ֹ�Х��Ĺ��⡣",
                "��Ƽ" : "������ɩ��",
        ]));

        setup();

        carry_object("/clone/weapon/qiang")->wield();
        carry_object("/d/city/obj/cloth")->wear();
}
